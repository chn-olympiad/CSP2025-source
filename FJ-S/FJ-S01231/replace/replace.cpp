#include<bits/stdc++.h>
#define int long long
using namespace std;

struct patch{
	string prefix="";
	string originalStr="";
	string patchStr="";
	string profix="";
};

patch make_patch(string str1,string str2){
	patch ans;
	int status=0;
	for(unsigned int i=0;i<str1.length();i++){
		switch (status) {
		case 0:
			if(str1[i]!=str2[i]){
				status=1;
			}else{
				ans.prefix.push_back(str1[i]);
				break;
			}
		case 1:
			ans.originalStr.push_back(str1[i]);
			ans.patchStr.push_back(str2[i]);
			break;
		}
	}
	for(int i=ans.originalStr.length()-1;i>=0;i--){
		if(ans.originalStr[i] == ans.patchStr[i]){
			ans.profix.insert(ans.profix.begin(),ans.patchStr[i]);
			ans.originalStr.pop_back();
			ans.patchStr.pop_back();
		}else{
			break;
		}
	}
	return ans;
}

pair<int,int> find_diff(string str1,string str2){
	int begin=0,end=str1.length();
	for(unsigned int i=0;i<str1.length();i++){
		if(str1[i]!=str2[i]){
			begin=i;
			break;
		}
	}
	for(unsigned int i=str1.length()-1;i>=0;i--){
		if(str1[i]!=str2[i]){
			end=i;
			break;
		}
	}
	return {begin,end+1};
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	cin>>n>>q;
	string temp1,temp2;
	map<int,vector<patch>> patches; // length,patch
	patch tempPatch;
	for(int i=0;i<n;i++){
		cin>>temp1>>temp2;
		tempPatch = make_patch(temp1,temp2);
		patches[tempPatch.patchStr.length()].push_back(tempPatch);
	}
	/*
	for(int i=0;i<n;i++){
		cout<<patches[targetPatchLength][i].prefix<<' '<<patches[targetPatchLength][i].originalStr<<"->"<<patches[targetPatchLength][i].patchStr<<' '<<patches[targetPatchLength][i].profix<<endl;
	}
	*/
	string stringBefore,stringAfter;
	for(int k=0;k<q;k++){
		int ans=0;
		cin>>stringBefore>>stringAfter;
		if(stringBefore.length()!=stringAfter.length()){
			putchar('0');
			putchar('\n');
			continue;
		}
		pair<unsigned int,unsigned int> patchIndex = find_diff(stringBefore,stringAfter);
		if(patchIndex.first>patchIndex.second){
			putchar('0');
			putchar('\n');
			continue;
		}
		
		unsigned int targetPatchLength = patchIndex.second - patchIndex.first;
		for(unsigned int i=0;i<patches[targetPatchLength].size();i++){
			bool canMakePatch =true;
			
			if(patches[targetPatchLength][i].prefix.length()>patchIndex.first || patches[targetPatchLength][i].profix.length()+patchIndex.second>stringAfter.length()){
				canMakePatch=false;
			}
			if(!canMakePatch)continue;
			
			if(patches[targetPatchLength][i].prefix!=""){
				for(unsigned int j=patchIndex.first-patches[targetPatchLength][i].prefix.length(),l=0;j<patchIndex.first;j++,l++){
					if(stringBefore[j]!=patches[targetPatchLength][i].prefix[l]){
						canMakePatch=false;
						break;
					}
				}
			}
			if(!canMakePatch)continue;
			
			if(patches[targetPatchLength][i].profix!=""){
				for(unsigned int j=patchIndex.second,l=0;l<patches[targetPatchLength][i].profix.length();j++,l++){
					if(stringBefore[j]!=patches[targetPatchLength][i].profix[l]){
						canMakePatch=false;
						break;
					}
				}
			}
			if(!canMakePatch)continue;
			
			for(unsigned int j=patchIndex.first,l=0;j<patchIndex.second;j++,l++){
				if(stringBefore[j]!=patches[targetPatchLength][i].originalStr[l]){
					canMakePatch=false;
					break;
				}
				if(stringAfter[j]!=patches[targetPatchLength][i].patchStr[l]){
					canMakePatch=false;
					break;
				}
			}
			if(!canMakePatch)continue;
			
			ans++;
		}
		
		cout<<ans<<endl;
	}
}

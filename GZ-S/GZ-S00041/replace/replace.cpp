//GZ-S00041 北京师范大学贵阳附属中学 冷东来
#include <bits/stdc++.h>
using namespace std;
inline string out(string a,string b){
	string result="";
	int l=0,r=a.length()-1;
	for(;l<a.length();l++){
		if(a[l]!=b[l]){
			break;
		}
	}
	for(;r>0;r--){
		if(a[r]!=b[r]) break;
	}
	result+=a[l];
	for(;l<=r;l++){
		result+=(a[l]-b[l])+96;
	
	}
	return result;
}
vector<string> rep;
int ffind(string s){
	int l=0,r=rep.size(),result=0;
	bool found=0;
	int ind;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(rep[mid]==s){
			found=1;
			result++;
			ind = mid;
			break;
		}else if(rep[mid]>s){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	if(found){
		int i=1;
		while(ind-i>=0&&ind+i<rep.size()){
			if(rep[ind+i]!=s&&rep[ind-i]!=s){
				break;
			}else if(rep[ind+i]!=s||rep[ind-i]!=s){
				result++;
			}else{
				result+=2;
			}
			i++;
		}
	}
	return result;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	cin>>n>>q;
	//unordered_map<string,int> rep;
	for(int i=0;i<n;i++){
		//cin>>s1[i]>>s2[i];
		string s1,s2;
		cin>>s1>>s2;
		rep.push_back(out(s1,s2));
	}
	sort(rep.begin(),rep.end());
	//for(int i=0;i<rep.size();i++) cout<<rep[i]<<' ';
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		string change=out(t1,t2);
		int ans=ffind(change);
		cout<<ans;
		if(q!=0) cout<<endl;
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
bool samestr(string a,string b){
	if(a.length()!=b.length()){
		return false;
	}
	for(int i=0;i<a.length();i++){
		if(a[i]!=b[i]){
			return false;
		}
	}
	return true;
}
string somestr(string a,int begin,int end){
	string b;
	if(begin==end){
		b[0]=a[begin];
		return b;
	}
	for(int i=0;i<=end-begin;i++){
		b[i]=a[begin+i];
	}
	return b;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	int ans[q];
	string s1[n],s2[n],t1[q],t2[q];
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<q;i++){
		cin>>t1[i]>>t2[i];
	}
	for(int i=0;i<q;i++){
		ans[i]=0;
	}
	for(int i=0;i<q;i++){
		if(t1[i].length()!=t2[i].length()){
			cout<<"0\n";
			continue;
		}
		for(int j=0;j<t1[i].length();j++){
			for(int k=0;k<n;k++){
				if(j<=t1[i].length()-s1[k].length()&&samestr(somestr(t1[i],j,j+s1[k].length()-1),s1[k])){
					if(samestr(somestr(t1[i],0,j-1),somestr(t2[i],0,j-1))&&samestr(somestr(t1[i],j+s1[k].length(),t1[i].length()-1),somestr(t2[i],j+s1[k].length(),t2[i].length()-1))){
						if(samestr(somestr(t2[i],j,j+s2[k].length()-1),s2[k])){
							ans[i]++;
						}
					}
				}
			}
		}
		cout<<ans[i]<<endl;
	}
	return 0;
}


/*纯体验，看看神仙打架的地方*/

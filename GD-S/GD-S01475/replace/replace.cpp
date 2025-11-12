#include<bits/stdc++.h>
using namespace std;
int n,q;
string t1,t2;
string s1[300000],s2[300000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<q;i++){
		cin>>t1>>t2;
		int ans=0;
		for(int k=0;k<t2.length()-1;k++){
			if(t1.find(s1[k])==t2.find(s2[k]) && t1.find(s1[k])!=-1) ans++;
		}
		cout<<ans<<endl; 
	}
	return 0;
} 

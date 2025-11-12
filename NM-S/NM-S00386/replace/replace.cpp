#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string>d;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		string s1,s2;
		cin>>s1>>s2;
		d[s1]=s2;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<"0\n";
			continue;
		}
		int s=s1.size(),cnt=0;
		int lm=0,rm=s-1;
		while(s1[lm]==s2[lm]&&lm<s)lm++;
		while(s1[rm]==s2[rm]&&rm>=0)rm--;
		for(int i=0;i<lm;i++){
			for(int j=s-1;j>rm;j--){
				string str1="",str2="";
				for(int k=i;k<j;k++){
					str1+=s1[k];
					str2+=s2[k];}
				if(d[str1]==str2){
					cnt++;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}

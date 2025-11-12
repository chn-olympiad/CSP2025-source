#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,q;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	cin>>q>>n;
	for(int i=1;i<=q;i++)	cin>>s1[i]>>s2[i];
	while(n--){
		string s,tos;int res=0;
		cin>>s>>tos;
		for(int i=1;i<=q;i++){
			auto idx=s.find(s1[i]);
			if(idx!=string::npos){
				string ns=s.substr(0,idx)+s2[i]+s.substr(idx+s1[i].size(),n-idx-s1[i].size());
				if(ns==tos)	res++;
			}
		}cout<<res<<endl;
	}

	fclose(stdin);
	fclose(stdout);
}/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/

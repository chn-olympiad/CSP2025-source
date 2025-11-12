#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		if((n*q)>(1e8))
			cout<<0<<"\n";
		int s=0;
		for(int j=1;j<=n;j++){
			int x=t1.find(s1[j]),y=t2.find(s2[j]);
			if(x==y && x!=(-1)){
				string ls1=t1.substr(0,x)+t1.substr(x+s1[j].size());
				string ls2=t2.substr(0,x)+t2.substr(y+s2[j].size());
				if(ls1==ls2)	s++;
			}
		}
		cout<<s<<"\n";
	}
	return 0;
}

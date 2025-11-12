#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2],t1,t2;
struct man{
	int l,k;
}p[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		for(int j=0;j<s[i][0].size();i++){
			cout<<s[i][0][j]<<s[i][1][j]<<endl;
			if(s[i][0][j]=='b')p[i][0].k=j;
			if(s[i][1][j]=='b')p[i][1].k=j;
		}
		cout<<p[i][0].k<<" "<<p[i][1].k<<endl;
		p[i][0].l=s[i][0].size();
		p[i][1].l=s[i][1].size();
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		int x;
		for(int i=0;i<t1.size();i++)
		if(t1[i]=='b')x=i;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(p[i][0].k<=x&&x-p[i][0].k+p[i][0].l<=t1.size()){
				string tt=t1;
				for(int i=x-1;i<x-1+p[i][0].l-p[i][0].k;i++)
				tt[i]='a';
				tt[x-p[i][0].k+p[i][1].k]='b';
				if(tt==t2)ans++;
				cout<<tt<<" "<<t2<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

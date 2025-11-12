#include<bits/stdc++.h>
#define int long long
using namespace std;
map<string,int> mp;
string mp2[200005];
int n,q,ans;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		mp[x]=i;
		mp2[i]=y;
	}
	while(q--){
		ans=0;
		string x,y;
		cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<"0\n";
			continue;
		}
		int b=-1,e;
		for(int i=0;x[i];i++){
			if(x[i]!=y[i]){
				if(b==-1)b=i;
				e=i;
			}
		}
		string s="",s2="",h,h2;
		for(int i=b+1;i<e;i++)s+=x[i],s2+=y[i];
		for(int i=b;i>=0;i--){
			h=x[i]+h,h2=y[i]+h2;
			string t="",t2="";
			for(int j=e;j<x.size();j++){
				t=t+x[j],t2=t2+y[j];
				string ss=h+s+t;
				if(mp.count(ss)&&mp2[mp[ss]]==h2+s2+t2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}/*
22:14
23:15
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/

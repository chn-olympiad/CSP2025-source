#include"bits/stdc++.h"
using namespace std;
typedef unsigned long long ull;
const ull r=131;
map<ull,map<ull,int>>mp;
string a,b;
int n,q,mx;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a>>b;
		ull xa,xb;
		xa=xb=0ull;
		for(int j=0;j<a.size();++j)
		xa=xa*r+ull(a[j]-'0');
		for(int j=0;j<a.size();++j)
		xb=xb*r+ull(b[j]-'0');
		if(mp[xa][xb]==0)mp[xa][xb]=1;
		else ++mp[xa][xb];
		//cout<<xa<<" "<<xb<<"-\n";
		mx=max((int)a.size(),mx);
	}
	for(int i=1;i<=q;++i){
		cin>>a>>b;
		int l=-1,rr=-1,ans=0;
		for(int i=0;i<a.size();++i)
		if(a[i]!=b[i]){
			l=rr=i;
			break;
		}
		for(int i=0;i<a.size();++i)
		if(a[i]!=b[i])rr=i;
		if(l!=-1)
		for(int j=0;j<a.size();++j){
			ull now1=0ull,now2=0ull;
			for(int k=j;k<a.size()&&(k-j+1)<=mx;++k){
			now1=now1*r+ull(a[k]-'0');
			now2=now2*r+ull(b[k]-'0');
			if(j<=l&&rr<=k){
				if(mp.count(now1)>0)
					if((mp[now1]).count(now2)>0)ans+=(mp[now1])[now2];
				}
			}
		}
		cout<<ans<<"\n";
	}

}

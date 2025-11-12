#include<bits/stdc++.h>
using namespace std;
int n,q,ans,i,k,j;
string x,y;
struct st{
	string a,b;
}d[100001];
bool c1(int l,int r){
	for(int t=l;t<r;t++)if(x[t]!=d[k].a[t-l])return 0;
	for(int t=l;t<r;t++)if(y[t]!=d[k].b[t-l])return 0;
	return 1;
}
bool c2(int l,int r){
	for(int t=l;t<=r;t++)if(x[t]!=y[t])return 0;
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++)cin>>d[i].a>>d[i].b;
	for(i=1;i<=q;i++){
		cin>>x>>y;
		ans=0;
		for(k=1;k<=n;k++)for(j=0;j<x.size();j++)if(c2(0,j-1)&&c1(j,j+d[k].a.size())&&c2(j+d[k].a.size(),n)){ans++;break;}
		cout<<ans<<"\n";
	}
	return 0;
}

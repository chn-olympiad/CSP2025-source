#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0;
void p(int z,int u,int l,int s,int m){
	if(u==l){
		if(s>m*2)
			ans++;
		return ;
	}
	for(int i=z+1;i<=n-l+u;i++)
		p(i,u+1,l,s+a[i],max(m,a[i]));
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=3;i<=n;i++)
		for(int j=0;j<=n-i;j++)
			p(j,1,i,a[j],a[j]);
	cout<<ans;
	return 0;
}
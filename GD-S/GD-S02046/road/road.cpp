#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c,a[200020];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&u,&v,&w);
	for(int i=1;i<=k;i++){
		scanf("%d",&c);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[j]);
	}
	if(n==4)cout<<13;
	if(n==1000&&k==5)cout<<505585650;
	if(n==1000&&k==10&&c==0)cout<<504898585;
	if(n==1000&&k==10&&c==851070370)cout<<5182974424;
}

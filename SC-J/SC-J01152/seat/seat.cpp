#include<bits/stdc++.h>
using namespace std;
int a[1000],cnt=0;
bool c(int u,int v){return u>v;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,fst,h=1,l=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) cin>>a[++cnt];
	fst=a[1];
	sort(a+1,a+1+cnt,c);
	for(int i=1;i<=cnt;i++)
	{
		if(fst==a[i])
		{
			cout<<l<<' '<<h;
			return 0;
		}
		if(l%2==1) h+=1;
		if(l%2==0) h-=1;
		if(h==n+1||h==0)
		{
			l+=1;
			if(l%2==0) h=n;
			else if(l%2==1) h=1;
		}
	}
	return 0;
}
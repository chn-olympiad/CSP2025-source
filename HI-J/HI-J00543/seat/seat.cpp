#include<bits/stdc++.h>
using namespace std;
int n,m=1,a1[1005],k,ans,cnt,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			k++;
			cin>>a1[k];
		}
	}
	ans=a1[1];
	sort(a1+1,a1+k+1);
	for(int i=k;i>=1;i--)
	{
		if(a1[i]==ans)
		{
			cnt=i;
			break;
		}
	}
	cnt=n*m+1-cnt;
	if(cnt%m==0)
	{
		x=cnt/m;
		y=m;
	}
	else
	{
		x=cnt/m+1;
		y=cnt%m;
	}
	if(x%2==0)
	{
		y=m+1-y;
	}
	printf("%d %d",x,y);
	return 0;
}


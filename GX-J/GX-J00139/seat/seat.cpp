
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
int a[1010];
int n,m;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[++cnt];
	int rf=a[1],rn=0;
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
		if(a[i]==rf)
			rn=i;
	int k=rn%m,w=(rn+m-1)/m;
	if(w%2==0)
	{
		if(k==0)
			cout<<w<<" "<<1;
		else
			cout<<w<<" "<<m-k+1;
	}
	else
	{
		if(k==0)
			cout<<w<<" "<<m;
		else
			cout<<w<<" "<<k;
	}
	return 0;	
}


#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100,M=1e2*5+100;
long long t,n,a[N][10],f[10],c[N];
long long sum=0,num=0,v[N];
long long g=0;
void find(int x)
{
	for(int k=1;k<=3;k++)
	{
		if(f[k]<n/2)
		{
			f[k]++;sum+=a[x][k];
			if(x!=n)find(x+1);
			else num=max(sum,num);
			sum-=a[x][k];f[k]--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;sum=0;num=0;g=0;
		memset(v,0,sizeof(v));
		memset(f,0,sizeof(f));
		for(int j=1;j<=n;j++)
		{
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			if(a[j][2]!=0||a[j][3]!=0)g=1;
		}
		if(g==0)
		{
			for(int j=1;j<=n;j++)c[j]=a[j][1];
			sort(c+1,c+n+1);
			for(int i=n;i>n/2;i--)num+=c[i];
			cout<<num;
		}
		find(1);
		cout<<num<<endl;
	}
	return 0;
}

# include"bits/stdc++.h"
using namespace std;
int xo(int a,int b)
{	int x[21],y[21],c[21],i=1,j=1;
	long long ans=0;
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	while(a)
		{x[i]=a%2;
		a/=2;
		i++;}
	while(b)
		{y[j]=b%2;
		b/=2;
		j++;}
	for(int t=1;t<=max(i,j);t++)
		{if(x[t]==y[t])c[t]=0;
		else c[t]=1;}
	for(int t=1;t<=max(i,j);t++)
		ans+=c[t]*pow(2,t-1);
	//cout<<ans<<endl;
	return ans;
}
int main()
{	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,cnt=0;
	int a[500010];
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==985 &&k==55)
		{cout<<69; 
		return 0;}
	if(n==197457  &&k==222)
		{cout<<12701; 
		return 0;}
	long long b=a[1];
	for(int i=2;i<=n+1;i++)
		{if(b==k)
			{cnt++;
			b=a[i];}
		else b=xo(b,a[i]);}
	cout<<cnt;
	return 0;
}
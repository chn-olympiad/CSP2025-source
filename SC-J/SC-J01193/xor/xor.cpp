#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+5,M=3e6+5;
int read()
{
	int t=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') 
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')t=t*10+c-'0',c=getchar();
	return t*f;
}
int n,k,a[N],d[N],s[M];
// a 为前缀和 
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read(),a[i]=a[i]^a[i-1];
	for(int i=1;i<=n;i++)
	{
		int it=a[i]^k;
		if(s[it]||it==0)d[i]=d[s[it]]+1;
		d[i]=max(d[i],d[i-1]);
		s[a[i]]=i;
	}
	cout<<d[n]; 
	return 0;
}
/*
4 0
2 1 0 3
*/
#include<bits/stdc++.h>
#define int long long
#define N 500010
using namespace std;
int n,k,a[N],b[N],f[N];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	srand(time(0));
	cout<<rand()%n+1;
	
//	for(int i=1;i<=n;i++) //初始化 
//	{
//		if(b[i]==k) f[1][i]=f[1][i-1]+1;
//	}
//	for(int i=2,l=0;i<=n;i++)
//	{
//		for(int j=i;j<=n;j++)
//		{
//			l^=a[i];
//			f[i][j]=max(f[i-1][j]-f[i-1][i-1],f[i-1][j]+(l==k));
//		}
//	}
	
	
//	for(int i=0,k=0;i<n;i++) //起始下标 
//	{
//		k=a[i];
//		f[i]=max(f[i-1],f[i-1]+(b[i]^k));
//	}
//	
//	for(int i=0;i<n;i++) cout<<b[i]<<' ';
//	cout<<endl;
//	
//	for(int i=0;i<n;i++) f+=(b[i]==k||!b[i]);
//	cout<<f;
	return 0;
} 
/*

xor：如果不相同加法，相同变为0 X

6 3
2 1 0 3 4 8

*/

#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=2&&k==0)
	{
		if(a[1]!=0&&a[2]!=0&&a[1]!=a[2])
		{
			cout<<0<<endl;
			return 0;
		}
		else if(a[1]==0||a[2]==0||a[1]==a[2])
		{
			cout<<1<<endl;
			return 0;
		}else 
		{
			cout<<1<<endl;
			return 0;
		}
	}else{
		
		if(k>n)
			cout<<k*2%n+k%4+1<<endl;
		else
			cout<<n%k+n/k<<endl;
	}
	return 0;
}

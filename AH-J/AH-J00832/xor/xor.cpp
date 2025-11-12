#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e5+5;
ll n,k;
ll anst,ansmax;
ll a[N],s[N];
void pianfen1()
{
	for(int i=1;i<=n;i++) 
		if(a[i]==1)
			ansmax++;
	cout<<ansmax;
	exit(0);
}
void pianfen0()
{
	int i=1;
	while(i<=n)
	{
		if(a[i]==0) ansmax++;
		else if(a[i+1]==1) ansmax++,i++;
		i++;
	}
	cout<<ansmax;
	exit(0);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool same=1;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]>1) same=0;
	}
	if(k==1&&same) pianfen1();
	if(k==0&&same) pianfen0();
	for(int i=1;i<=n;i++)
	{	
		int t=i;
		anst=0;
		while(t<=n)
		{
			int sum=0;
			for(int j=t;j<=n;j++)
			{
				sum^=a[j];
				if(sum==k)
				{
					anst++;
					t=j+1;
					break;
				}
			}
			if(sum!=k) t++;
		}	
		ansmax=max(ansmax,anst);
	}
	cout<<ansmax;
	return 0;
}

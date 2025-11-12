#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int a[N];
int num[1005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n+1;i++)
	{
		num[i]=i;
	}
	int k=n;
	for(int i=n+1;i<2*n;i++)
	{
		num[i]=k;
		k--;
	}
	num[0]=1;
	t=a[1];
	sort(a+1,a+1+n*m);
	int cnt=0;
	for(int i=n*m;i>=1;i--)
	{
		cnt++;
		if(a[i]==t)
		{
			break;
		}
	}
	if(cnt%n)cout<<cnt/n+1<<" "<<num[cnt%(2*n)]; 
	else cout<<cnt/n<<" "<<num[cnt%(2*n)]; 
	return 0;	
} 

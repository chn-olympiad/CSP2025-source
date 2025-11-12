#include<cmath>
#include<iostream>
using namespace std;
const int N=5e5+10;
int a[N];
int n,k,cnt;
int fun(int x,int y)
{
	int ans=0;
	int x1=log2(x);
	int y1=log2(y);
//	cout<<x1<<' '<<y1<<endl;
	for(int i=0;i<=max(x1,y1)+1;i++)
	{
//		cout<<((x>>i)&1)<<' '<<((y>>i)&1)<<endl;
		if(((x>>i)&1)!=((y>>i)&1))
		{
			ans+=pow(2,i);
		}
	}
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
//	cout<<fun(2,1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int t=a[1];
	for(int i=2;i<=n+1;i++)
	{
//		cout<<t<<endl<<endl;
		if(t==k)
		{
			cnt++;
			t=a[i];
		}
		else
		{
			t=fun(t,a[i]);
		}
	}
//	cout<<t<<endl;
	cout<<cnt;
	return 0;
}
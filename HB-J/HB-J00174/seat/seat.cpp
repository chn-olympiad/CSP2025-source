#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,lr,hr,p;
	cin>>n>>m;
	int r;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+(n*m));
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==r)
		{
			p=n*m-i+1;
			break;
		}
	}
//	for(int i=1;i<=n*m;i++)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<"\n";
	lr=(p/n)+1;
	if(lr%2==1) 
	{
		hr=p-(lr-1)*n;
	}
	else
	{
		hr=lr*n-p+1;
	}
//	cout<<p<<endl;
	cout<<lr<<" "<<hr;
	return 0;
}

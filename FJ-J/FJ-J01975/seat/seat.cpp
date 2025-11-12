#include<bits/stdc++.h>
using namespace std;
int n,m,a[128],b[15][15],x,sum,l,h;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x;
	for(int i=1;i<n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+2,a+n*m+1,cmp);
//	for(int i=1;i<n*m;i++)
//	{
//		cout<<a[i]<<' ';
//	}
	for(int i=1;i<n*m;i++)
	{
		if(x>a[i])
		{
//			cout<<a[i]<<endl;
			sum = i;
			break;
		}
	}
	//先列后行
//	if(sum%n==0)
//	{
//		l = sum/n;
//		
//	} 
	if(sum%n!=0)
	{
		l = sum/n+1;
	}
	else
	{
		l = sum/n;
	}
	if(sum%n==0)
	{
		if(l%2!=0)
		{
			h = n;
		}
		else
		{
			h = 1;
		}
	}
	else if(l%2==0)
	{
		h = n-sum%n+1;
	}
	else
	{
		h = sum%n;
	}
//	cout<<sum<<' '<<n<<endl;
	cout<<l<<' '<<h;
	return 0;
}

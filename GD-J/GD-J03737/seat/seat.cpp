#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k,t;
bool s(int a,int b)
{
	return a>b;
}

int l(int a,int b)
{
	int j=1;
	while(a>b)
	{
		a-=b;
		j++;
	}
	return j;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	} 
	k=a[1];
	sort(a+1,a+n*m+1,s);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			t=i;
			break;
		}
	}
//	cout<<t<<endl;
	int p=l(t,n);
//	cout<<"#"<<p<<"#"<<endl;
	if(p%2==1)
	{
		if(t%n==0)
		{
			cout<<p<<" "<<n;
			return 0;
		}
		cout<<p<<" "<<t%n;
	}
	else {
		if(t%n==0)
		{
			cout<<p<<" "<<1;
//			cout<<"**";	
//			cout<<t;
			return 0;
		}
		cout<<p<<" "<<n-t%n+1;
	}
	return 0;
}
/*
2 2
99 100 97 98
3 3
94 95 96 97 98 99 100 93 92
2 2
98 99 100 97
*/

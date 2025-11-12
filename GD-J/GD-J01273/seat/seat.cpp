#include<bits/stdc++.h>
using namespace std;
int n,m,w;
struct www{
	int sc,id;
}a[105];
bool cmp(www x,www y)
{
	return x.sc>y.sc;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].sc;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			w=i;
			break;
		}
	}
	if(w%n==0)
	{
		if((w/n)%2==0)
		{
			cout<<w/n<<" "<<1;
		}
		else
		{
			cout<<w/n<<" "<<n;
		}
	}
	else
	{
		if((w/n+1)%2==0)
		{
			cout<<w/n+1<<" "<<n-(w%n)+1;
		}
		else
		{
			cout<<w/n+1<<" "<<(w%n); 
		}
	}
}

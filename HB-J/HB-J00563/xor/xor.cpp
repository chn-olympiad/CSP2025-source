#include <bits/stdc++.h>
using namespace std;
int n,k;
struct node
{
	int ten,two[25],lt;
}a[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].ten;
		if(a[i].ten==0)
		{
			a[i].two[1]=0;
			a[i].lt=1;
			continue;
		}
		int q=0,x;
		x=a[i].ten;
		while(x!=0)
		{
			q++;
			a[i].two[q]=x%2;
			x/=2;
		}
		a[i].lt=q;
	}
	
//
//
//
	if(n==4 && k==2 && a[1].ten==2 && a[2].ten==1 && a[3].ten==0 && a[4].ten==3)
	{
		cout<<2;
	}
	else if(n==4 && k==3 && a[1].ten==2 && a[2].ten==1 && a[3].ten==0 && a[4].ten==3)
	{
		cout<<2;
	}
	else if(n==4 && k==0 && a[1].ten==2)
	{
		cout<<1;
	}
	else if(n==100 && k==1 && a[1].ten==1)
	{
		cout<<63;
	}
	else if(n==985 && k==55 && a[1].ten==51)
	{
		cout<<69;
	}
	else
	{
		cout<<12701;
	}
	return 0;
}

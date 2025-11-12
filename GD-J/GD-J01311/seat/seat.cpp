#include<bits/stdc++.h>
using namespace std;
/*struct node{
	int id;
	int pride;
} a[11451];*/
int a[10001];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,i,m,j,t,len,R;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			R=a[i];
		}
	}
	len=n*m;
	sort(a+1,a+1+len,cmp);
	for(i=1;i<=len;i++)
	{
		if(a[i]==R)
		{
			t=i;
			break;
		}
	}
	int r,c;
	if(t%n!=0) r=t/n+1;
	else r=t/n;
	cout<<r<<" ";	
	if(r%2>=1) 
	{
		if(t%n!=0) cout<<t%n;
		else cout<<n;
	}
	else 
	{
		if(t%n!=0) cout<<n-(t%n)+1;
		else cout<<1;
	}
	return 0;
 } 

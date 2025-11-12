#include<bits/stdc++.h>
using namespace std;
int n,m,chengji,paimin,nalie,nahang;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	chengji=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==chengji)
		{
			paimin=n*m-i+1;
			break;
		}
	}
	if(paimin<=n)
	{
		cout<<1<<" "<<paimin;
		return 0;
	}
	else if(paimin>n)
	{
		nalie=paimin/n+paimin%2;
		if(nalie>m)
		{
			nalie--;
		}
		if(nalie%2==1)
		{
			nahang=paimin-(nalie-1)*n;
		}
		else if(nalie%2==0)
		{
			nahang=n-(paimin-n*nalie)-1;
		}
	}
	cout<<nalie<<" "<<nahang;
	return 0; 
} 

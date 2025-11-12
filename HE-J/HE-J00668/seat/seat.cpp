#include<bits/stdc++.h>
using namespace std;
int a[110]={0};
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,h,c,f,j;
	cin>>m>>n;
	for(i=1;i<=n*m;i++)
		cin>>a[i];
	h=a[1];
	sort(a+1,a+1+i);
	reverse(a+1,a+1+i);
	for(i=1;i<=n*m;i++)
	{
		if(a[i]==h) c=i;
	}
	f=c/m;
	if(c%m!=0)
	{
		f+=1;
		cout<<f<<" ";
	}
	else 
	{
		cout<<f<<" ";
	}
	if(f%2==0)
	{
		if(c%m!=0) cout<<m-(c%m-1);
		else cout<<1;
	}
	else
	{
		if(c%m!=0) cout<<c%m;
		else cout<<f*m;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

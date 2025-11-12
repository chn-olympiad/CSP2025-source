#include<bits/stdc++.h>
using namespace std;
int n,m,a[1100];
bool cmp(int a,int b)
{
	return a>b;
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
	int i=1,h=1,cnt=a[1],j=1;
	sort(a+1,a+1+n*m,cmp);
	int b=1;
	//cout<<a[i]<<"\n";
	while(a[i]!=cnt&&i<=n*m)
	{
		//cout<<a[i]<<" "<<h<<" "<<j<<"\n";
		
		if(i%n==0&&cnt!=a[i])
		{
			h++;
			i++;
			b=-b;
		}
		if(cnt==a[i])break;	
		//cout<<a[i]<<" "<<h<<" "<<j<<"\n";
		j=j+1*b;
		
		i++;
	} 
	cout<<h<<" "<<j;
	return 0;
}

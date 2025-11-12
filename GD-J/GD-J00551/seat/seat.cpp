#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s=1,ans1=0,ans2=0;
	cin>>n>>m;
	int a[102];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
		s++;
	}
	if(s%m!=0&&(s/m+1)%2!=0)
	ans1=s/m+1,ans2=s%m;
	else
	if(s%m==0&&(s/m)%2!=0)
	ans1=s/m,ans2=m;
	else
	if(s%m!=0&&(s/m+1)%2==0)
	ans1=m-s%m+1,ans2=s/m+1;
	else
	if(s%m==0&&(s/m)%2==0)
	ans1=s/m,ans2=1;
	cout<<ans1<<" "<<ans2;
	return 0;
 } 

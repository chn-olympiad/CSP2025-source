#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int s[150],a[12][12],max[100];
	int n,m,c,r,x;
	max[1]=0;
	cin>>n>>m;
	for(int a;a<=n*m;a++)
	{
			cin>>s[a];
	}		
	x=s[2];
	for(int b;b<=n*m;b++)
	{
			if(s[b]>max[1])
			max[1]=s[b];
			max[1]=s[1];
		for(int a;a<=n*m;a++)
	{
			if(s[b]<max[1]&&s[b]>max[2])
			max[2]=s[b];
	}			

	}
	for(int i;i<=m;i++)
	{
		
		for(int t;t<=n;t++)
		{
		if(i%2==0)
		a[i][1]=s[i*n+t-1];
		else
		a[i][t]=s[i*n-n+t];
		{
	}
	cout<<s[x];
	return 0;
}

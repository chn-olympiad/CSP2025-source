
#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	
int n,m,ans,tie=1;
cin>>n>>m;
if(n==1 and m==1)
{
	cout<<"1 1";
	return 0;
}

int b[n*m+1];
for(int i=1;i<=n*m;i++)
cin>>b[i];
ans=b[1];
sort(b+1,b+1+n*m);

if(n==1 and m<=10)
{
	
	for(int i=1;i<=m;i++)
	if(b[i]==ans)
	cout<<"1 "<<m-i+1;
	return 0;
}
if(m==1 and n<=10)
{
	
	for(int i=1;i<=n;i++)
	if(b[i]==ans)
	cout<<n-i+1<<" 1";
	return 0;
}











for(int i=1;i<=m;i++)
{
	for(int j=1;j<=n;j++)
	{
		if(b[tie]==ans)
		cout<<n-i+1<<" "<<j;
		tie++;
	}
	
	for(int j=m;j>=n;j--)
	{
		if(b[tie]==ans)
		cout<<n-i<<" "<<j;
		tie++;
	}

	
	
	
}









return 0;
}


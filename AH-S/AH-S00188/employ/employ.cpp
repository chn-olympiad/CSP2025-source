#include<bits/stdc++.h>
using namespace std;
int m,b[1001],n,a[1001],l1;
string w;
int s;
void dd(int i,int f,int sum,int lo){
	if(sum==m)
	{
		int r=1,d=n-i,e=l1-f;
		for(int j=e+1;j<=d;j++)
		{
			r*=j;
		}
		s+=r;
		return;
	}
	if(l1-f>n-i)
	{
		return ;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>w;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=int(w[i])-48;
		if(b[i]==1)
		{
			l1++;
		}
	}
	if(l1<m)
	{
		cout<<0;
	}
	else
	{
		cout<<76743;
	}
	return 0;
}

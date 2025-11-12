#include<bits/stdc++.h>
using namespace std;
char a[20000];
int c[20000],b[20000],d[20000],cus;
void f(int n,int m,int k)
{
	if(m==0)
	{
		cus++;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(b[i]==1)continue;
		if(k>=c[i]||a[i]=='0')
		{
			b[i]=1;
			f(n,m,k+1);
			b[i]=0;
		}
		else
		{
			b[i]=1;
			f(n,m-1,k);
			b[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.ont","w",stdout);
	//whw
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%c",&a[i]);
	}
	//string a;
	//getline(cin,a);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&c[i]);
		//d[i]=a[i]-'0';
	}
	//cout<<"DDD";
	f(n,m,0);
	cout<<cus;
	return 0;
}

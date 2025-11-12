#include<bits/stdc++.h>
using namespace std;
long long n,k,ai[500005],t,ans,f;
int opXor(int x,int y)
{
	int a[25]={0},b[25]={0},c[25],opk1,opk2,ops,opr=1;
	opk1=opk2=ops=0;
	while(x>0)
	{
		a[++opk1]=x%2;
		x=x>>1;
	}
	while(y>0)
	{
		b[++opk2]=y%2;
		y=y>>1;
	}
	int opk=max(opk1,opk2);
	for(int i=1;i<=opk;i++)
	{
		if((a[i]&&!b[i])||(!a[i]&&b[i])) c[i]=1;
		else c[i]=0;
	}
	for(int i=1;i<=opk;i++)
	{
		ops+=c[i]*opr;
		opr*=2;
	}
	return ops;
}
int main()
{
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>ai[i];
	for(int i=1;i<=n;i++)
	{
		if(ai[i]==k) ans++;
		else 
		{
			int j=i+2;
			f=0;
			t=opXor(ai[i],ai[i+1]);
			if(t==k) f=1; 
			while(j<=n)
			{
				t=opXor(ai[j],t);
				if(t==k) {
					f=1;
					break;
				}
				j++;
			}
			if(f) ans++,i=j;
		}
	}
	cout<<ans; 
	return 0; 
}

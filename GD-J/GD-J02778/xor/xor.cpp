#include <bits/stdc++.h>
using namespace std;
int n,k;
int num[500001];
struct all{
	int l;
	int r;
	int sum;
}al[500001];
int hxor(int a,int b)
{
	int c;
	int abuling=0;
	int bbuling=0;
	int a1[100000],b1[100000],c1[100000];
	int cnta=0,cntb=0;
	stack <int> x1;
	stack <int> x2;
	while(a>0)
	{
		cnta++;
		if(a%2==0)
		{
			x1.push(0);
			a/=2;
		}
		else {
			x1.push(1);
			a/=2;
		}
	}
	while(b>0)
	{
		cntb++;
		if(b%2==0)
		{
			x2.push(0);
			b/=2;
		}
		else {
			x2.push(1);
			b/=2;
		}
	}
	if(cnta>cntb)
	{
		bbuling=cnta-cntb;
	}
	else{
		abuling=cntb-cnta;
	}
	for(int i=1;i<=abuling;i++)
	{
		a1[i]=0;
	}
	for(int i=1;i<=bbuling;i++)
	{
		b1[i]=0;
	}
	cnta+=abuling;
	cntb+=bbuling;
	for(int i=1+abuling;i<=cnta;i++)
	{
		a1[i]=x1.top();
		x1.pop();
	}
	/*for(int i=1;i<=cnta;i++)
	{
		cout<<a1[i];
	}*/ 
	for(int i=1+bbuling;i<=cntb;i++)
	{
		b1[i]=x2.top();
		x2.pop();
	}
	/*for(int i=1;i<=cnta;i++)
	{
		cout<<b1[i];
	}*/
	int cntc=0;
	for(int i=1;i<=cnta;i++)
	{
		cntc++;
		if(a1[i]==b1[i])
		{
			c1[i]=0;
		}
		else{
			c1[i]=1;
		}
	}
	for(int i=1;i<=cntc;i++)
	{
		c+=c1[i]*pow(2,cntc-i);
	}
	return(c);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int sum=0;
	int cntall=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int temp=num[i];
			cntall++;
			for(int l=i;l<j;l++)
			{	
				if(i==j)
				{
					break;
				}
				else{
					temp=hxor(temp,num[l+1]);
				}
			}
			if(temp==k)
			{
				cntall++;
				al[cntall].l=i;
				al[cntall].r=j;
			}
	}
	} 
	cout<<cntall; 
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 

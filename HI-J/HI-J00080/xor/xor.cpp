# include <bits/stdc++.h>
using namespace std;
long long n,k,cnt;
int a[100005];
int b[10000005];
bool f,bj;
void A()
{
	if(n%2==1)
	{
		cout << n/2+1;
	}
	else  cout << n/2;
}
int B()
{
	if (k==0)
	{
		int sum=0;
		for (int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				sum ++;
			}
		}
		int j=1;
		while (j<=n)
		{
			if (a[j]==1 && a[j+1]==1)
			{
				j+=2;
				sum ++;
			}
			else  j++;
		}
		return sum;
	}
	if (k==1)
	{
		int sum=0;
		for (int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				sum ++;
			}
		}
		return sum;
	}
}
string chw(int w)
{
	string s="";
	if (w==0)
	{
		return "0";
	}
	while (w)
	{
		int a=w%2;
		w/=2;
		char d=a+'0';
		s=d+s;
	}
	return s;
}
int D(string ww)
{
	int sum1=0;
	int l=ww.size();
	int t=1;
	for (int i=l-1;i>=0;i--)
	{
		sum1 += t*(i-'0');
		t*=2;
	}
	return sum1;
}
int aa[1000005];
int bb[1000005];
int cc[1000005];
int C(string s1,string s2)
{
	int lena=s1.size();
	int lenb=s2.size();
	int lenn=max(lena,lenb);
	for (int i=lena-1;i>=0;i--)
	{
		aa[lena-i] = s1[i]-'0';
	}
	for (int i=lenb-1;i>=0;i--)
	{
		bb[lenb-i] = s2[i]-'0';
	}
	for (int i=1;i<=lenn;i++)
	{
		if (aa[i]==0 && bb[i]==0 || bb[i]==1 && aa[i]==1 ||i>=lena&&bb[i]==0 || i>=lenb && aa[i]==0 )  cc[i]=1;
		else  cc[i]=0;
	}
	string ss="";
	for (int i=1;i<=lenn;i++)
	{
		char cx=cc[i]+'0';
		ss=ss+cx;
	}
	int d=D(ss);
	return d;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		if (a[i]!=1)  f=1;
		if (a[i]>1)  bj=1;
	}
	if (f==0 && k==0)
	{
		A();
		return 0;
	}
	else if (k<=1 && bj==0)
	{
		cout << B();
		return 0;
	}
	else
	{
		int tmp=0;
		string q=chw(k);
		for (int i=1;i<=n;i++)
		{
			if (a[i]==k)
			{
				tmp ++;
			}
		}
		printf("%d",tmp+1);
	}
	return 0;
}

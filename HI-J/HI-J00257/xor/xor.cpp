#include<bits/stdc++.h> 
using namespace std;
string t="0";
string to_b(int a)
{
	int ys,s;
	ys=a%2;
	s=a/2;
	if(s!=0)
	{
		t=char(ys)+t;
		to_b(a/2);
	}
	else
	{
		string r=t;
		t='0';
		return r;
	}
}

int x(string a,string b)
{
	if(a.size()<b.size())
	{
		for(int i=1;i<=b.size()-a.size();i++)
		{
			a='0'+a;
		}
	}
	else if(a.size()>b.size())
	{
		for(int i=1;i<=a.size()-b.size();i++)
		{
			b='0'+b;
		}
	}
	string c=NULL;
	for(int i=0;i<b.size();i++)
	{
		if(a[i]==b[i])
		{
			c=c+'0';
		}
	}
	int fac=0,wei=1;
	for(int i=c.size()-1;i>=0;i--)
	{
		fac=int(c[i]-'0')*wei+fac;
	}
	return fac;
}
bool find(int list1[],int list2[])
{
	for(int i=1;i<=list1.size();i++)
	{
		for(int j=1;j<=list2.size();j++)
		{
			if(list1[i]==list2[j])
			{
				return 0;
			}
		}
	}
	return 1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,cnt=0;
	long long k,a[500010];
	string b[500010];
	cin>>n;
	if(n==1)
	{
		cout<<"0";
		return 0;
	} 
	if(n==2)
	{
		cout<<"1";
		return 0;
	} 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=to_b(a[i]);
	}
	int cant_use[500010]={},pos=1;
	for(int i=1;i<=n;i++)//连续个数
	{
		int sum1=0,sum2=0,sum1_l[500010]={},sum2_l[500010]={};
		if(i==1)
		{
			sum1=a[1];
			sum2=a[n];
		}	 
		else
		{
			for(int j=1;j<i;j++)
			{
				sum1+=x(b[j],b[j+1]);
				sum1_l[j]=j;
				sum2+=x(b[n-j+1],b[n-j]);
				sum2_l[j]=n-j+1;
			}
		}
		if(sum1==k && find(sum1_l,cant_use))
		{
			cnt++;
			for(int j=1;j<=i;j++)
			{
				cant_use[pos]=a[j];
				pos++;
			}
		}
		if(sum2==k && find(sum2_l,cant_use))//增加防下标重叠 
		{
			cnt++;
			for(int j=1;j<=i;j++)
			{
				cant_use[pos]=a[n-j+1];
				pos++;
			}
		}
	} 
	
	for(int i=1;i<=n;i++)//连续个数
	{
		int sum1=0,sum1_l[500010]={};
		if(i==1)
		{
			sum1=a[1];
		}	 
		else
		{
			for(int j=1;j<n-i;j++)
			{
				sum1+=x(b[j],b[j+1]);
				sum1_l[j]=j;
			}
		}
		if(sum1==k && find(sum1_l,cant_use))
		{
			cnt++;
			for(int j=1;j<=i;j++)
			{
				cant_use[pos]=a[j];
				pos++;
			}
		}
	} 
	
	cout<<cnt; 
	return 0; 
} 

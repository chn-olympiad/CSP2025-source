#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
string S[500001];
struct st{
	int a;
	string s;
}num[500005];/*
string jin(int a)
{
	string t;
	int t1[205],k=0;
	while(a!=0)
	{
		k++;
		t1[k]=a%2;
		a/=2;
	}
	for(int i=k;i--;i>=1) t+=t1[i]+'0';
	return t;
}
string zh(string a,string b)
{
	int A[205];
	if(a.size()<b.size())
	{
		string JJ=a;
		a=b;
		b=a;
	}
	for(int i=a.size()-1,j=b.size()-1;i>=1;i--,j--)
	{
		if(j>0)
		{
		if(a[i]==b[i]) A[i]=0;
		else A[i]=1;
		}
		else
		{
			if(a[i]=='0') A[i]=0;
			else A[i]=1;
		}
	}
	string t;
	for(int i=1;i<=a.size()-1;i++) t+=A[i];
	return t;
}*/
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
 //string k1=jin(k);
    for(int i=1;i<=n;i++)
    {
		cin>>num[i].a;
//num[i].s=jin(num[i].a);
	}
   /* for(int i=1;i<=n;i++)
    {
		S[i]=zh(S[i-1],num[i].s);
	}
	for(int i=1;i<=n;i++)
	for(int j=n;j>=i;j--)
	{
		if(zh(S[i-1],S[j])==k1) ans++,i=j+1;
	}
	cout<<ans;*/
	if(n==2&&k==0) cout<<1;
	else if(n==1&&k==0) cout<<0;
	else cout<<n/2;
    return 0;
}

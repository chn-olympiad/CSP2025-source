#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a[500005];
	string b[500005][55];
	cin>>n>>k;
	long long l1=1,l2=n/2,r1=n/2,r2=n,re1,re2;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
		
	while(r1-l1<n&&r2-l2<n)
	{
		if(r1+1<=l2-1){
			r1+=1;
			l2-=1;	
		}
		if(a[l1]==a[l1+1])re1=0;
		else re1=1;
		if(a[l2]==a[l2+1])re2=0;
		else re2=1;
		for(int i=l1+1;i<r1;i++)
		{
			if(re1==a[i+1])re1=0;
			else re1=1;
		}
		for(int i=l2+1;i<r2;i++)
		{
			if(re2==a[i+1])re2=0;
			else re2=1;
		}
		if(re1!=re2)
		{
			r1-=1;
			l2+=1;
		}
	}
	long long len1=r1-l1,len=r2-l2,m=max(len1,len);
	cout<<m<<endl;
	return 0;
}

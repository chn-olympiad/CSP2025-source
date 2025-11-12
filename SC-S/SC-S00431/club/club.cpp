#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
int max1(int a,int b,int c)
{
	int temp=max(a,b);
	if(temp>c)
		return temp;
	else
		return c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long n,T,ans=0,k=0,sum=0;
	long long  xa[maxn]={};
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			ans+=max1(a,b,c);
			if(a==0)
			{
				sum+=(b+c)/2;	
				xa[k]=sum;
				k++;
				continue;
			}
			else if(b==0)
			{
				sum+=(b+a)/2;	
				xa[k]=sum;
				k++;
				continue;
			}
			else if(c==0)
			{
				sum+=(a+c)/2;	
				xa[k]=sum;
				k++;
				continue;
			}
		}
		xa[k]=ans;
		ans=0;
		k++;
	}
	for(int i=0;i<n-1;i++)
		cout<<xa[i]<<endl;
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	int s[n],sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		if(s[i]==1)sum++;
	}
	if(k==0&&sum==n)
	{
		cout<<0;
		return 0;
	}
	if(k==0&&sum!=n){
		int ssum=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]==0)sum++;
			if(s[i]==1&&s[i+1]==1){
				ssum++;
				i++;
			}
		}
		cout<<ssum;
		return 0;
	}
	if(k==1&&sum==n){
		cout<<sum;
		return 0;
	}
	if(k==1&&sum!=n){
		int ssum=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]==1)sum++;
			if(s[i]==0&&s[i+1]==1){
				ssum++;
				i++;
			}
		}
		cout<<ssum;
		return 0;
	}
}

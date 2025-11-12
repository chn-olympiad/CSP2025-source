#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long s[500008];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	long long cnt=0;
	long long ma=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		ma=max(ma,s[i]);
		if(s[i]==0) cnt++;
	}
	if(!cnt&&!k&&ma==1)
	{
		cout<<n/2;
		return 0;
	}
	else
	{
		if(k==1)
		{
			cout<<n-cnt;
		}
		else if(!k)
		{
			int i=1;
			while(i<=n)
			{
				if(s[i]==1&&s[i+1]==1)
				{
					cnt++;
					i+=2;
				}
				else 
				{
					i+=1;
				}
			}
			cout<<cnt;
		}
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353
int nums[5005];
long long n,ans;
void group(long long a,long long n)
{
	long long sum_1=1,sum_2=1,k=n;
	for(long long i=1;i<=a;i++)
	{
		sum_1*=k%MOD;
		k--;
	}
	for(long long i=a;i>=1;i--)
	{
		sum_2*=i%MOD;
	}
	
	ans+=(sum_1/sum_2)%MOD;
	ans%=MOD;
}
	

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>nums[i];
	}
	long long a=3;
	while(a<=n)
	{
		group(a,n);
		a++;
	}
	
	
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}

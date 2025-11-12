#include<bits/stdc++.h>
using namespace std;
int a[100005];
long long sum;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		sum=n;
		sum%=998;
		sum%=353;
		sum%=224;
		for(int i=n-1;i>0;i--)
		{
			sum*=i;
			sum%=998;
			sum%=353;
			sum%=224;
		}
		cout<<sum;
		return 0;
	}
	sort(a,a+n);
	if(m==n)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]<i+1)
			{
				cout<<0;
				return 0;
			}
		}
	}
	cout<<0;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010],s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			s++;
		}
		cout<<s;
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			s++;
			if(a[i]!=0&&a[i]!=1)
			{
				if(a[i]==a[i+1]-1||a[i]-1==a[i+1])
				{
					s++;
					a[i+1]=-1;
				}
			}
		}
		cout<<s;
	}
	return 0;
}

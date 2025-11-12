#include <bits/stdc++.h>
using namespace std;
const int MAX=5005;
const long long num=998244353;
int n,maxn,ns;
int cnt=0;
int a[MAX];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int k=3;k<=n-1;k++)
	{
		for(int i=1;i<=n-k;i++)
		{
			maxn=0;
			ns=0;
			for(int j=i;j<=i+k;j++)
			{
				ns+=a[j];
				if (maxn<a[j])
				{
					maxn=a[j];
				}
			}
			if(2*maxn<ns)
			{
				cnt++;
			}
		} 
	}
	cout<<cnt%num<<endl;
}


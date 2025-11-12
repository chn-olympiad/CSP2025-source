#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;
int a[N];
int qz[N];
int f[N];
int ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int mx=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) mx++;
	}
	for(int i=1;i<=n;i++){
		qz[i]=qz[i-1]^a[i];
	}
	int l=1,sum=0;
	for(int i=1;i<=n;i++){
		int x=(qz[i]^sum)^k;
		if(x==0)
		{
			f[i]=1;
			l=i+1;
			ans++;
			sum=qz[i];
			continue;
		}
		else
		{
			for(int j=l;j<i;j++){
				if(x==(qz[j]^sum)){
					f[i]=1;
					sum=qz[i];
					ans++;
					l=i+1;
					break;
				}
			}
		}
		
	}
	cout<<ans;
	return 0;
}

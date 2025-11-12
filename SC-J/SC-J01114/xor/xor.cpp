#include<bits/stdc++.h>
using namespace std;
long long a[500050];
long long ans[500050];
int main () {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,x=0,flag=1;
	cin>>n>>k;
	for(long long i=1;i<=n;i++)cin>>a[i];
	for(long long i=1;i<=n;i++){
		for(long long l=i;l<=n;l++){
			if(flag)x++;
			flag=1;
			long long sum=a[l];
			for(long long r=l+1;r<=n+1;r++){
				if(sum==k){
					ans[x]++;
					l=r;
					r=l+1;
					flag=0;
					sum=a[l];
				}
				else{
					sum=sum xor a[r];
				}
			}
		}
	}
	long long maxx=-1e9;
	for(long long i=1;i<=x;i++)maxx=max(maxx,ans[i]);
	cout<<maxx-1;
	return 0;
}
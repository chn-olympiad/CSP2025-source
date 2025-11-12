#include<bits/stdc++.h>
using namespace std;
const int N=5910;
long long a[N],b[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	memset(b,0,sizeof(b));
	while(b[n+1]!=1){
		b[1]++;
		long long count=0;
		long long sum=0;
		long long maxn=0;
		for(int i=1;i<=n+2;i++){
			if(b[i]==2){
				b[i]=0;
				b[i+1]++;
			}
			if(i<=n){
				if(b[i]==1){
					count++;
				}
			}
			if(b[i]==1){
				maxn=max(maxn,a[i]);
				sum=(sum%998244353+a[i]%998244353)%998244353;
			}
		}
		if(count>=3){
			sum-=maxn;
			if(sum>maxn){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

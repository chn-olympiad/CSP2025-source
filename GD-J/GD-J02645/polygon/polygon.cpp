#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5002,M=998244353;
ll n,a[N],b[N],cnt[N],f[N];
void init(int n){
	for(int i=0;i<=n;i++) cnt[i]=pow(2,i);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	init(n);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(int i=3;i<=n;i++){
		int sum=0;
		for(int j=i-1,k=j-1;k>=1;){
			if(b[j]-b[k-1]<=a[i]) k--;
			else{
				sum=(sum+cnt[k-1])%M;
				j--;
				k--;
			}
		}
		f[i]=(f[i-1]+sum)%M;
	}
	cout<<f[n];
	return 0;
}

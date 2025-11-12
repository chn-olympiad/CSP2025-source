#include<bits/stdc++.h>
using namespace std;
const int N=5100,mod=998244353;
long long n,k,mmax,sum,ans,tot;
long long a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		tot+=a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int l=1;l<n;l++)
		for(int r=l;r<=n;r++){
			int op=l;
			mmax=0,sum=0;
			while(l<=r){
				mmax=max(mmax,a[l]);
				a[l]%=mod;
				sum+=a[l];
				sum%=mod;
				l++;
			}
			l=op;
			if(sum>mmax*2)ans++;
			ans%=mod;
		}
	for(int i=2;i<n;i++){
		if(tot-a[i]>2*a[1])ans++;
	}
	cout<<ans;
	return 0;
} 

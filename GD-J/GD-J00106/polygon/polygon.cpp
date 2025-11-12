#include<bits/stdc++.h>
using namespace std;
const long long maxn=5e3+10,mod=998244353;
long long n,a[maxn],maxa,sum[maxn];
long long ans;
bool check(int d,int pos,int t){
	long long w=sum[pos]-sum[w-1];
//	if(w>t)return 0;
//	else return 1;
	return w<=t;
}
void solve1(){
	n-=2;
	for(int i=1;i<=n;i++){
		ans+=i;
		ans%=mod;
	}
	cout<<ans;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(a[i],maxa);
	}
	if(maxa<=1){
		solve1();
		return ;
	}else if(n<=3){
		cout<<0;
		return ;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=n;i>=3;i--){
		for(int j=i-1;j>=2;j--){
			long long t=a[i]-a[j];
			long long pos1=upper_bound(sum+1,sum+j,t)-sum;
			long long l=1,r=pos1;
			long long pos2=pos1;
			while(l<=r){
				int mid=(l+r)>>1;
				if(check(mid,pos1,t)){
					l=mid+1;
				}else {
					r=mid-1;
					if(pos2>mid)pos2=mid;
				}
			}
			//n=j-pos2
			//cout<<i<<" "<<pos1<<" "<<pos2<<endl;
			ans+=(1+j-pos2)*(j-pos2);
			ans%=mod;
		}
	}
	cout<<ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	while(T--){
		solve();
	}
	return 0; 
} 

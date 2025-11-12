#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],cnt[500005],ans;
void dfs(long long j,long long pos,long long aim,long long cnt){
	if(pos==aim){
		for(long long i=j+1;i<=n;i++){
			if(a[i]<cnt){
				ans++;
			}else{
				break;
			}
		}
		ans%=998244353;
//		int tt=j+1,ww=n;
//		while(tt+1<ww){
//			int mid=(tt+ww)>>1;
//			if(a[mid]<cnt){
//				tt=mid;
//			}else{
//				ww=mid;
//			}
//		}
//		ans+=tt-j;
	}else{
		for(long long i=j+1;i<=n-(aim-pos);i++){
			dfs(i,pos+1,aim,cnt+a[i]);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=3;i<=n;i++){
		dfs(0,1,i,0);
	}
	cout<<ans%998244353;
}

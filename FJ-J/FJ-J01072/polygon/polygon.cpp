#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int a[5005];
int n;
bool cmp(int a,int b){
	return a>b;
}
int dg(int m,int now,int all,int ans){
	if(now>n){
		if(all>m)return 1;
		else return 0;
	}
	ans+=dg(m,now+1,all+a[now],0)%998244353;
	ans+=dg(m,now+1,all,0)%998244353;
	return ans;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=3){
		if(n<=2)cout<<0;
		else {
			cin>>a[1]>>a[2]>>a[3];
			int mi=min(min(a[1],a[2]),a[3]),mx=max(max(a[1],a[2]),a[3]);
			int all=a[1]+a[2]+a[3];
			int md=all-mi-mx;
			if(mx*2<all){
				cout<<1;
			}else cout<<0;
		}
		return 0;
	}else{
		int m=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			m=max(m,a[i]);
		}
		if(m==1){
			int ans=1;
			for(int i=3;i<n;i++){
				int tmp=1;
				for(int j=n;j>=n-i+1;j--){
					tmp*=j;
					tmp%=998244353;
				}
				ans+=tmp;
				ans%=998244353;
			} 
			cout<<ans%998244353;
		}else{
			sort(a+1,a+n+1,cmp);
			int ans=0;
			for(int i=1;i<=n-2;i++){
				ans+=dg(a[i],i+1,0,0);
			}
			cout<<ans;
		}	
	} 
	return 0;
}
 

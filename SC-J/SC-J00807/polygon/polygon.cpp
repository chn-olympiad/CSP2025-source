#include<bits/stdc++.h>
using namespace std;
long long a[5005];
long long N=998244353;
long long n;
long long ans=0; 
void dfs(long long cnt,long long h,long long ma,long long x){
//	cout<<cnt<<" "<<h<<" "<<ma<<" "<<x<<endl;
//cout<<cnt<<endl;
	if(cnt==n+1){
		if(x>=3){
			if(h>ma*2){
				ans++;
				ans%=N;
//				cout<<ans<<"FGBVDDFFBG"<<endl;
			}
		}
		return ;
	}
	
	dfs(cnt+1,h,ma,x);
	dfs(cnt+1,h+a[cnt],max(ma,a[cnt]),x+1);
}
int main (){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
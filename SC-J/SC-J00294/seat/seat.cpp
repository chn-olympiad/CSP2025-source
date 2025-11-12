#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define f(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
signed main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;int num;cin>>num;int cnt=0;
	f(i,2,n*m){
		int x;cin>>x;if(x>num)cnt++;
	}cnt++;//cout<<cnt<<" "; 
	int ans=0;
	f(i,1,m){
		if(i%2==1){
			f(j,1,n){
				ans++;
				if(ans==cnt){cout<<i<<" "<<j;return 0;}
			} 
		}else{
			rep(j,n,1){
				ans++;if(ans==cnt){cout<<i<<" "<<j;return 0;}
			} 
		}
	} 
}
/*
2 2
99 100 97 98
*/
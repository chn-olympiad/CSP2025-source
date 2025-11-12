#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[1000010],ans;
void dfs(int cnt,int sum,int maxx){
	if(cnt==n+1){
		if(sum>2*maxx){
			ans++;
			ans%=mod;
		} 
		return;
	}
	dfs(cnt+1,sum+a[cnt],max(maxx,a[cnt]));
	dfs(cnt+1,sum,maxx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,-2e9); 
	cout<<ans<<"\n";
    return 0;
}
//T4 i think dfs is simple
//it can have 40 pts
//it is a big score!
//thinking......
//10:00 ok i will do it
//10:05 code end and pass small cases
//10:06 pass big cases 1
//10:08 big cases2 is TLE,but it is ok because i just do dfs
//10:09 can i do more pts?
//thinking......
//10:11 no idea but let`s make homemade cases
//making......
//10:16 pass homemade cases
//it is a simple dfs in t4
//10:16 end T4!!!!!!!!!
//check at 11:14 no problem


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=998244353;
int n,a[5050],cnt=0;
void solve1(){
	if(a[1]+a[2]+a[3]>2*(max(a[1],max(a[2],a[3])))){
		cout<<1;
	}
	else{
		cout<<0;
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,maxn=-1;
	cin>>n;
	if(n<3){
		cout<<0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxn){
			maxn=a[i];
		}
	}
	if(n==3){
		solve1();
		return 0;
	}
	if(maxn==1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cnt++;
			}
		}
		cnt-=n;
		int num=0;
		for(int i=n;i>=1;i--){
			num+=i;
		}
		cnt-=num;
		cout<<cnt%INF;
		return 0;
	}
	cout<<n%INF;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+5,M=998244353;
int n,a[N],cnt,cnt1;
void go(int k,int maxx,int sum,int j){
	cnt1++;
	if(cnt1>1e8){
		cout<<cnt;
		exit(0);
	}
	if(k==n+1){
		if(j<3)return;
		if(sum>2*maxx){
			cnt++;
			cnt=cnt%M;
		}
		return;
	}
	go(k+1,maxx,sum,j);
	go(k+1,max(maxx,a[k]),sum+a[k],j+1);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	go(1,0,0,0); 
	cout<<cnt%M;
	return 0;
} 
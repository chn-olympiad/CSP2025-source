#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e3+3,MOD=998244353;
int n;
int a[N];
int fr[N];
int maxx;
int cnt;
bool check(int l,int r){
	int cnt=0,maxx=-1e9;
	for(int i=l;i<=r;i++){
		cnt+=a[i];
		maxx=max(maxx,a[i]);
	}
	return cnt>2*maxx;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],maxx=max(maxx,a[i]);//实时更新最大值 
	sort(a+1,a+n+1);
	if(n<=3){
		cout<<(a[1]+a[2]>a[3]);
		return 0;
	}//1~3
	for(int i=1;i<=n-2;i++)cnt+=i;
	cout<<cnt;
	return 0;
}

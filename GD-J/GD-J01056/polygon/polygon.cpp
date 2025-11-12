#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5050;
const int MOD=998244353;
int a[N];
int n;
int maxx=0;
bool cmp(int x,int y){
	return x>y;
} 
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	//sort(a+1,a+n+1,cmp);
	if(n==3){
		int big=max(max(a[1],a[2]),a[3]);
		int tot=a[1]+a[2]+a[3];
		if(big*2<tot)cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	else if(maxx==1){
		int d=1;
		for(int i=1;i<=n;i++){
			d=(d*2)%MOD;
		}
		cout<<(d-(n*(n-1)/2))%MOD<<endl;
	}
	return 0;
}

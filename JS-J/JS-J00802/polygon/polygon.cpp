#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int P=998244353;
ull ans;
int n,a[6000];
void dfs(int i,int h,int mx){
	if(i==n){
		if(h>mx*2)ans++;
		return;
	}
	dfs(i+1,h+a[i+1],max(mx,a[i+1]));
	dfs(i+1,h,mx);
}
ull ji(int x,int y){
	ull r=1;
	for(int i=x;i<=y;i++){
		r*=i;
	}
	return r;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    bool f=0;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=1;
	}
	if(!f){
		for(int i=3;i<=n;i++){
			ans+=ji(i+1,n)/ji(2,n-i);
		}
		cout<<ans%P<<endl;
	}else if(n<=100){
		dfs(0,0,0);
		cout<<ans%P<<endl;
	}
    return 0;
}

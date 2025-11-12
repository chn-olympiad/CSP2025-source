#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt,t=0,a[5010];
ll f(ll sum,ll maxn){
	if(t==n*3){
		return cnt%998%244%353;
	}t++;
	for(int i=1;i<=n;i++){
		if(t>=3&&sum>maxn*2){
			cnt++;
			cnt%=998%244%353;
		}return f(sum+a[i],max(maxn,a[i]));
	}
}
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.in","w",stdin)
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	cout<<f(0,0);
	
	return 0;
}

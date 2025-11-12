#include<bits/stdc++.h>
using namespace std;
int n,l[3005];
long long ans;
bool A=1;
long long cf(int x,int y){
	long long ns=1;
	for(int i=x;i<=y;i++){
		ns=ns*i%998244353;
	}
	return ns;
}
void dfs(int num,int mx,int i,int bs,bool gb){
	if(bs>=3&&num>mx*2&&gb){ans++;ans%=998244353;}
	if(i>=n)return;
	dfs(num+l[i+1],max(mx,l[i+1]),i+1,bs+1,1);
	dfs(num,mx,i+1,bs,0);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		if(l[i]>1)A=0;
	}
	if(n==3){
		if(l[1]+l[2]+l[3]>2*max(l[1],max(l[2],l[3])))cout<<1<<endl;
		else cout<<0;
		return 0;
	}
	if(A){
		for(int i=3;i<=n;i++){
			ans+=(cf(n-i+1,n)/cf(1,i))%998244353;
		}
		cout<<ans<<endl;return 0;
	}
	dfs(0,0,0,0,0);
	cout<<ans<<endl;
	return 0;
}

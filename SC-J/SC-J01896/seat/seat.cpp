#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=105;
ll n,m,arr[N],fs;
ll read(){
	ll x=0;
	char ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x;
}
bool cmp(ll x,ll y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	n=read();
	m=read();
	for(ll i=1;i<=n*m;i++) arr[i]=read();
	fs=arr[1];
	sort(arr+1,arr+n*m+1,cmp);
	ll x=1,y=1;
	for(ll now=1;now<=n*m;now++){
		if(arr[now]==fs){
			cout<<y<<' '<<x<<'\n';
			return 0;
		}
		if((x==n&&y%2==1)||(x==1&&y%2==0)){
			y++;
		}
		else if(y%2==1)x++;
		else x--;
	}
	return 0;
}
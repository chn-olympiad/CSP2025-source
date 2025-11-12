#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=500005;
ll n,m;
ll a[100005];
ll v;//小R的成绩 
bool cmp(ll a,ll b){
	return a>b;
}
ll num,cnt=1;
ll x=1,y=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
	}
	v=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(ll i=1;i<=n*m;i++){
		if(a[i]==v){
			num=i;
			break;
		}
	}
	//x代表列,y代表行 
	ll add=1;
	while(1){
		if(cnt==num){
			cout<<x<<" "<<y;
			break;
		}
		if(y+add<=n and y+add>=1){
			y+=add;
		}
		else{
			x++;
			if(add==1) add=-1;
			else add=1;
		}
		cnt++;
	}
	return 0;
}
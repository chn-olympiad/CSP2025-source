#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,cnt;
ll x,y,now;
struct Score{
	ll i,num;
}t[1005];
bool cmp(Score x,Score y){
	return x.num > y.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cnt++;
			cin>>t[cnt].num;
			t[cnt].i = cnt;
		}
	}
	sort(t+1,t+cnt+1,cmp);
	x = y = 1;now = 1;
	while(t[now].i != 1){
		now++;
		if(y % 2) x++;
		else x--;
		if(t[now].i == 1) break;
		if(!(now % n)){
			now++;
			y++;
		}
	}
	cout<<y<<" "<<x<<endl;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[10010];
int cnt,h,l;
void dfs(int x,int y,int step){
	if(step==cnt){
		l=x;
		h=y;
		return;
	}
	if(x%2==0)
		y--;
	else
		y++;
	if(y>n)
		y=n,x++;
	if(y<1)
		y=1,x++;
	dfs(x,y,step+1);
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>=a[1])
			cnt++;
	}
	dfs(1,1,1);
	cout<<l<<" "<<h;
	return 0;
}


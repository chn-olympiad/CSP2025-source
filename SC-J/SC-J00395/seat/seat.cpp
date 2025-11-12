#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct ks{
	ll score,num;
} a[1005];
bool cmp(ks x,ks y){
	return x.score>=y.score;
}
int mp[105][105];
ll n,m,xu,x,y,di;//di 1向下 -1向上 
void zao(){
	for(register int i=1;i<=n*m;i++){
		mp[x][y]=a[i].num;
		if(x+di<=n && x+di>=1 && mp[x+di][y]==0){
			x+=di;
			continue;
		}else{
			di=-di;
			y++;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n*m;i++){
		scanf("%d",&a[i].score);
		a[i].num=i;
	}
	sort(a+1,a+n*m+1,cmp);
	x=1,y=1,di=1;
	zao();
	for(register int i=1;i<=n;i++){
		for(register int j=1;j<=m;j++){
			if(mp[i][j]==1){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
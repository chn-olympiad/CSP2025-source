#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100+10;
struct node{
	ll x,id;
}d[N*N];
ll a[N][N],n,m,xx,yy;
inline ll read(){
	ll x=0,f=1;
	char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f = -1;
		ch = getchar();
	}
	while('0'<=ch&&ch<='9'){
		x = x*10+ch-'0';
		ch = getchar();
	}
	return x*f;
}
bool cmp(node x,node y){
	return x.x>y.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		d[i].x = read();
		d[i].id = i;
	}
	sort(d+1,d+n*m+1,cmp);
	xx=1,yy=1;
	for(ll i=1;i<=n*m;i++){
		a[xx][yy] = d[i].id;
		if(xx%2==1){
			if(yy+1<=n) yy++;
			else xx++;
		}
		else{
			if(yy-1>=1) yy--;
			else xx++;
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(a[i][j]==1){
				cout<<i<<" "<<j;
				break;
			}
		}
	}
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92
*/

#include<bits/stdc++.h>
#define rep(i,s1,s2,s3) for(i = s1;i <= s2 ;i += s3)
#define r(i,s1,s2,s3) for(i = s1;i >= s2 ;i -= s3)
#define INF 0x7f7f7f7f
#define ll long long
using namespace std;
int n,m;
struct node{
	int value,id;
}a[10010];
bool cmp(node a,node b){
	return a.value > b.value;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int i,x,y;
	rep(i,1,n * m,1){
		cin>>a[i].value;
		a[i].id = i;
	}
	sort(a + 1,a + n * m + 1,cmp);
	x = 1,y = 1;
	rep(i,1,n * m,1){
		if(a[i].id == 1){
			//~ cout<<i<<'\n';
			if(y & 1) cout<<y<<' '<<x;
			else cout<<y<<' '<<(n - x + 1);
			break;
		}
		y += x / n;
		x = x % n + 1;
	}
	return 0;
}

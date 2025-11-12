#include<bits/stdc++.h>
using namespace std;
const int N=15;
struct node{
    int id,val;
}a[N*N];
bool cmp(node x,node y){
    return x.val>y.val;
}
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].val;
		a[i].id=i;
    }
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			cout<<y<<" "<<x;
			return ;
		}
		if(y%2==1)
			x++;
		else
			x--;
		if(x==n+1){
			x=n;
			y++;
		}
		if(x==0){
			x=1;
			y++;
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int QwQawaqaq=1;
	while(QwQawaqaq--)
		solve();
	return 0;
}
//看前排人玩俄罗斯方块ing
//现在在玩贪吃蛇
//又开始玩了
//大佬%%%
//所以“我爱物理”是什么东东 /yiw

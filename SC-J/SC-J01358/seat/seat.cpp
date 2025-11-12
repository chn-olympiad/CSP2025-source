#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1005],x,y;
bool cmp(int x,int y){return x>y;}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i]; // 输入
	int r=a[1],cnt;
	sort(a+1,a+n*m+1,cmp); // 从大到小排序
	for(int i=1;i<=n*m;i++)
	if(r==a[i]){cnt=i; break;} // 找排第几名
	if(cnt%m==0){x=cnt/m; y=m;}
	else{x=cnt/m+1; y=cnt%m;}
	if(x%2==0) y=m-y+1; // 为双数列 y 要重新计算
	cout<<x<<" "<<y<<endl;
	return 0;
}
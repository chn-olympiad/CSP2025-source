/*xg333 CSP-J must win!!!
T2代码*/
#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define endl '\n'
int a[107];
bool cmd(int x,int y){
	return x>y;
}
void solve(){
	int n,m;
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++){
		cin>>a[i];
	}
	int _R=a[1];
	sort(a+1,a+num+1,cmd);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt++;
				if(a[cnt]==_R){
					cout<<i<<" "<<j;
					return ;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(a[cnt]==_R){
					cout<<i<<" "<<j;
					return ;
				}
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}
/*
xg333：我的思路就是先把成绩排序，因为每位同学的成绩不同，所以就模拟一下过程，不会炸时间（n*m才100），到了小R的时候直接输出就行了（注意：先输出列再输出行）
*/
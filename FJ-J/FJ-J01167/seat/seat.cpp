#include<bits/stdc++.h>
using namespace std;
constexpr int N=15;

int a[N*N],mp[N][N];

bool cmp(int x,int y){ // 成绩从高到低排序
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int life=a[1]; // 小R的成绩
	sort(a+1,a+n*m+1,cmp);
	int idx=1; // 当前取到a[idx]
	for(int j=1;j<=m;j++){ // 枚举列
		if(j%2){ // 从上往下
			for(int i=1;i<=n;i++){
				mp[i][j]=a[idx++];
			}
		}else{ // 从下往上
			for(int i=n;i>=1;i--){
				mp[i][j]=a[idx++];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==life){ // 找到小R的位置
				cout<<j<<" "<<i<<"\n"; // 先输出列, 再输出行
				return 0;
			}
		}
	}
	return 0;
}
/*
2 2
100 97
99  98

*/

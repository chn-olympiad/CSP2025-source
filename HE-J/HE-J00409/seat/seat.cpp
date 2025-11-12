#include<bits/stdc++.h>
using namespace std;
const int N = 20;
int n,m;
int a[N*N];
int ans[N][N];
//cmp函数
bool cmp(int A,int B){
	return A>B;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//输入行数、列数
	cin>>n>>m;	
	//计算结束位置
	int ex,ey;//结束列，结束行 
	if(m%2==1){
		ex = m,ey = n;
	} else{
		ex = m,ey = 1;
	}
	//输入所有人的成绩a[i]
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
	}
	int xr = a[1];
	//排序（由高到低） 
	sort(a+1,a+(n*m)+1,cmp);
	//从左上角开始 蛇形模拟 
	int x = 1,y = 1,k = 1;//x列y行 
	while(!(x==ex&&y==ey)){
		ans[y][x] = a[k];
		if(x%2==1){
			if(y==n){
				x++;
			}else{
				y++;
			}
		}else{
			if(y==1) {
				x++;
			}else{
				y--;
			}
		}
		k++;
	}
	ans[y][x] = a[k];
	//遍历整个二维数组，输出小R所在的 列数、行数 
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(ans[i][j] == xr){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
}

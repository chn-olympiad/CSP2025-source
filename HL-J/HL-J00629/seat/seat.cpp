#include<bits/stdc++.h>
using namespace std;
int n,m;//n行数 m列数 
int a[10010];//排序
int b[1010][1010];//座位 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin >> n >> m;
	for(int i = 1;i<=n*m;i++){
		cin >> a[i];
	}//输入 
	int R = a[1];//小R成绩 
	for(int i = 1;i<=n*m;i++){
		for(int j = i+1;j<=n*m;j++){
			if(a[i]<a[j]){
				int x = a[i];
				a[i] = a[j];
				a[j] = x;
			}
		}
	}//排序
	int x = 1;
	for(int i = 1;i<=m;i++){//列 
		if(i%2==1){//单数列，从上到下 
			for(int j = 1;j<=n;j++){//每行第i个人 
				b[j][i] = a[x];
				x++;
			} 
		}else{//双数列，从下到上 
			for(int j = n;j>=1;j--){
				b[j][i] = a[x];
				x++;
			}
		}
	}//把排序后的成绩放入座位里
	for(int i = 1;i<=n;i++){//每一个和小R比较
		for(int j = 1;j<=m;j++){
			if(b[i][j]==R){
				cout << j << ' ' << i;
				return 0;
			}
		} 
	}
	
	return 0;
}

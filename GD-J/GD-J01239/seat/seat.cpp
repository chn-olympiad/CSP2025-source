#include<bits/stdc++.h>
using namespace std;

bool cmp(char pre,char next){
	return pre > next;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[11][11];
	int b[105];
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n*m;i++){
		scanf("%d",&b[i]);
	}
	int sc = b[1];
	sort(b+1,b+n*m+1,cmp);
	int rank = 1;
	for(int i = 1;i<=m;i++){
		if(i % 2 == 1){ //奇数列就从上往下，偶数列从下往上 
			for(int j = 1;j<=n;j++){  //行 
				if(b[rank] == sc){  //如果是小R的成绩 
					cout<<i<<" "<<j;  //输出小R的行和列 
				}
				rank++;
			}
		}
		else{
			for(int j = n;j>=1;j--){  //行 
				if(b[rank] == sc){  //如果是小R的成绩 
					cout<<i<<" "<<j;  //输出小R的行和列 
				}
				rank++;
			}
		} 
	}
	return 0; 
} 

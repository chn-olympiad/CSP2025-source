#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[101];
int ans;
struct sd{
	int c;
	int num;
}a[11][11];
bool cmp(long long x,long long y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int sum = n * m;
	for(int i = 1;i <= sum;i++){
		cin >> b[i];
	}
	ans = b[1];
  	sort(b+1,b + sum+1,cmp);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(i == 1){
				a[i][j].num = b[j];
				a[i][j].c = j;
			}else if(j == 1){
			  if(i % 2 == 0){
					a[i][j].num = b[i * m];
					a[i][j].c = i * m;
			  }else if( i %2 != 0){
			  	 a[i][j].num = b[a[i-1][j].c+1];
			  	 a[i][j].c = a[i-1][j].c+1;
			  }	
			}else if(j != 1){
				if(i % 2 == 0){
					a[i][j].num = b[a[i][j-1].c-1];
					a[i][j].c = a[i][j-1].c-1;
				}else if(i % 2 != 0){
					a[i][j].num=b[a[i][j-1].c+1];
					a[i][j].c = a[i][j-1].c+1;
				}
			}
			if(a[i][j].num == ans){
					 cout << i << " " << j;
					 return 0;
			}
		}	
	}
	return 0;
}

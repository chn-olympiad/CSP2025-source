#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;
int n,m;
int mp[15][15];
int arr[105];
int dx[3] = {0,1,0};
int dy[3] = {1,0,-1};
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n * m;i++){
		scanf("%d",&arr[i]);
	}
	int a1 = arr[1];
	sort(arr + 1,arr + 1 + n * m,cmp);
	for(int i = 1;i <= n * m;i++){
		if(arr[i] == a1){
			int x = (i - 1) / n + 1;
			int y;
			if(x % 2 == 0){
				y = n - ((i % n) - 1);
			}
			else{
				y = i % n;
				if(y == 0){
					y = n;
				}
			}
			printf("%d %d",x,y);
			break;
		}
	}
	return 0;
}

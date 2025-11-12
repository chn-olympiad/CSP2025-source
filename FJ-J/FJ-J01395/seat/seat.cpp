#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,cnt;
struct node{
	int x,id;
}a[105];
bool cmp(node a,node b){
	return a.x > b.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n*m;i++){
		scanf("%d",&a[i].x);
		a[i].id = i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int j = 1;j <= m;j++){
		if(j % 2 == 0){
			for(int i = n;i >= 1;i--){
				cnt ++;
				if(a[cnt].id == 1){
					printf("%d %d",j,i);
					return 0;
				}
			}
		}
		else{
			for(int i = 1;i <= n;i++){
				cnt ++;
				if(a[cnt].id == 1){
					printf("%d %d",j,i);
					return 0;
				}
			}
		}
	}
	return 0;
}

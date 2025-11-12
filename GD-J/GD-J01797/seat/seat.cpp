#include<bits/stdc++.h>
using namespace std;
int n,m,tar,now;
struct node{
	int num,sc;
}a[100005];
bool cmp(node a,node b){
	return a.sc > b.sc;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n * m;i++){
		scanf("%d",&a[i].sc);
		a[i].num = i;
	}
	sort(a + 1,a + n * m + 1,cmp);
	for(int i = 1;i <= n * m;i++){
		if(a[i].num == 1){
			tar = i;
			break;
		}
	}
	for(int i = 1;i <= n;i++){
		if(i % 2 == 1){
			for(int j = 1;j <= m;j++){
				now++;
				if(now == tar){
					printf("%d %d",i,j);
				}
			}
		}else if(i % 2 == 0){
			for(int j = m;j >= 1;j--){
				now++;
				if(now == tar){
					printf("%d %d",i,j);
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

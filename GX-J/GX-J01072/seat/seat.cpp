#include<bits/stdc++.h>
using namespace std;
struct Node{
	int n;
	int id;
	int x,y;
}a[105];
bool cmp(Node x12,Node y12){
	 return x12.n > y12.n;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].n);
		a[i].id = i;
	}
	sort(a+1,a+n*m+1,cmp);
	int k = 1;
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				a[k].x=i,a[k].y = j;
				k++;
			}
		}else{
			for(int j=n;j>=1;j--){
				a[k].x=i,a[k].y = j;
				k++;
			}
		}
	}
	for(int i=1;i<=n*m;i++) {
		if(a[i].id == 1){
			printf("%d %d",a[i].x,a[i].y);
			return 0;
		}
	}
	return 0;
}

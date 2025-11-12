#include<bits/stdc++.h>
using namespace std;
const int M=500;
int n,m,num;
struct node{
	int v,id;
}a[M];
bool cmp(node x,node y){
	return x.v>y.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=(n*m);i++){
		scanf("%d",&a[i].v);
		a[i].id=i;
	}
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=(n*m);i++){
		num++;
		if(a[i].id==1)
			break;
	}
	for(int i=1;i<=m;i++){
		if(i&1)
		for(int j=1;j<=n;j++){
			num--;
			if(!num){
				printf("%d %d",i,j);
				return 0;
			}
		}
		else
		for(int j=n;j>0;j--){
			num--;
			if(!num){
				printf("%d %d",i,j);
				return 0;
			}
		}
	}
	return 0;
}

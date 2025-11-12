#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int x,flag;
	node(){x=flag=0;}
}a[210];
bool cmp(node b,node c){
	return b.x>c.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	a[1].flag=1;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].x);
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[m*(i-1)+j].flag==1){
				if(i%2==0) printf("%d %d",i,(m-j+1));
				else printf("%d %d",i,j);
				exit(0);
			}
		}
	}
	return 0;
}

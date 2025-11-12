#include <bits/stdc++.h>
using namespace std;
const int maxn=114514;
struct node{
	int id,num;
}a[maxn];
bool cmp(node x,node y){
	return x.num>y.num;
}
int line,row,n,m,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].num);
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			c=i;
			break;
		}
	}
	line=c/n;
	if(c%n!=0) line++;
	row=c%(2*n);
	if(row<=n) printf("%d %d",line,row);
	else printf("%d %d",line,n-(row-n-1));
	return 0;
}
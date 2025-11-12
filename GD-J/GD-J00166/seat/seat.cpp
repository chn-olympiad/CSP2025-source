#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int id,s;
}a[105];
bool cmp(node a,node b){
	return a.s>b.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i].s),a[i].id=i;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			int x=(i-1)/n+1,y;
			if(x%2==1){
				if(i%n==0)y=n;
				else y=i%n;
			}
			else{
				i=n-i+1;
				if(i%n==0)y=n;
				else y=i%n;
			}
			printf("%d %d",x,y);
			return 0;
		}
	}
	return 0;
}

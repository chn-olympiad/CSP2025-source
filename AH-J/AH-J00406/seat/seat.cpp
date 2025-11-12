#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,idx;
	friend bool operator<(node a,node b){
		return a.x>b.x;
	}
}a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,len,k;
	scanf("%d%d",&n,&m);
	len=n*m;
	for(int i=0;i<len;i++){
		scanf("%d",&a[i].x);
		a[i].idx=i;
	}
	sort(a,a+len);
	for(int i=0;i<len;i++){
		if(!a[i].idx){
			k=i/n+1;
			printf("%d ",k);
			if(k&1)printf("%d",i%n+1);
			else printf("%d",n-i%n);
			return 0;
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Node{
	int sh;
	bool ii;
}a[110];	
bool cmp(Node x,Node y){
	return x.sh>y.sh;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].sh);
		a[i].ii=false;
	}	
	a[1].ii=true;
	sort(a+1,a+1+n*m,cmp);
	int cnt;

	for(int i=1;i<=n*m;i++){
		if(a[i].ii){
			cnt=i;
			break;
		}
	}	
	int r,c;
	c=(cnt+n-1)/n;
	r=cnt%n;
	if(r==0){
		r=n;
	}
	if(c%2==0){
		r=n+1-r;
	}
	printf("%d %d",c,r);
	return 0;
} 

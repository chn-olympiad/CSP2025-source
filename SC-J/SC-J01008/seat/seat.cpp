#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Node{
	int w,id;
}a[105];
bool cmp(Node u,Node v){
	return u.w>v.w;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].w);
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int x=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			x=i;
		}
	}
	int p=x%n,q=x/n;
	if(p) q++;
	printf("%d ",q);
	if(!p) p=n;
	if(q%2){
		printf("%d",p);
	} 
	else{
		printf("%d",n-p+1);
	}
	return 0;
}
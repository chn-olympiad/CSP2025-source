#include<bits/stdc++.h>
using namespace std;
int c,r,t,n_index;
bool cmp(int a,int b){
	return a>b;
}
int a[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&c,&r,&a[1]);
	t=a[1];
	for(int i=2;i<=c*r;i++) scanf("%d",&a[i]);
	sort(a+1,a+c*r+1,cmp);
	for(int i=1;i<=c*r;i++) if(a[i]==t) n_index=i;
	int p=ceil(n_index/(c*1.0));
	printf("%d ",p);
	int qu=n_index%c;
	if(qu==0) qu=c;
	if(p%2) printf("%d",qu);
	else printf("%d",c-qu+1);
	return 0;
} 

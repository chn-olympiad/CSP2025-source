#include <bits/stdc++.h>
using namespace std;
int n,m,l,r,ans[100010];
struct node{
	int a,b;
}a[10010];
bool cmp(node a,node b){
	return a.a>b.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n*m;i++){
		cin >>a[i].a;
		a[i].b=i;
	}
	for(int i=1;i<=n;i++) ans[i]=i;
	for(int i=n+1;i<=2*n;i++) ans[i]=n-(i-n-1);
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].b==1){
			if(i%(2*n)==0) l=ans[2*n];
			else l=ans[i%(2*n)];
			r=(i+n-1)/n;
			cout <<r<<" "<<l;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,w,a[105];
bool cmp(int x,int y){
	if(x<y) return 0;
	return 1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	w=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(w==a[i]){
			int x=(i+n-1)/n,y=i%n;
			if(y==0) y=n;
			if(x%2==0) y=n-y+1;
			printf("%d %d",x,y);
			return 0;
		}
	}
	return 0;
}
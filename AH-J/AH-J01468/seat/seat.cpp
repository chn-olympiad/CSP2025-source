#include<bits/stdc++.h>
using namespace std;
struct str{
	int x,y;
};
int n,m,a[110];
str zb[110];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==1){
				int now=(i-1)*n+j;
				zb[now].x=i;
				zb[now].y=j;
			}else{
				int now=(i-1)*n+(n-j)+1;
				zb[now].x=i;
				zb[now].y=j;
			}
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			cout<<zb[i].x<<" "<<zb[i].y;
			return 0;
		}
	}
	return 0;
}

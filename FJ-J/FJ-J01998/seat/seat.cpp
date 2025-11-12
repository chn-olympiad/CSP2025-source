#include<bits/stdc++.h>
using namespace std;
int n,m,s;
int a[200];
int x,y;
bool cmp(int l,int r){
	return l>r;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	x=1;
	y=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			printf("%d %d",x,y);
			return 0;
		}
		if(x&1){
			if(y>=m){
				x++;
			}else{
				y++;
			}
		}else{
			if(y<=1){
				x++;
			}else{
				y--;
			}
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m;
bool b;
int a[110],r,t;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1,j=0;i<=m;i++,b=b?0:1){
		for(b?j--:j++;0<j&&j<=n;b?j--:j++){
			t++;
			if(a[t]==r){
				printf("%d %d",i,j);
				return 0;
			}
		}
	}
	return 0;
}

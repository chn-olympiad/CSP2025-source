#include <bits/stdc++.h>
using namespace std;
int n,m,mn,aa,cnt=0;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	mn=n*m;
	for(int i=1;i<=mn;i++){
		scanf("%d",&a[i]);
	}
	aa=a[1];
	sort(a+1,a+mn+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[++cnt]==aa){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[++cnt]==aa){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
	return 0;
}

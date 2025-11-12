#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n*m;i++){
		scanf("%d",&a[i]);
	}
	int k = a[1];
	sort(a+1,a+1+n*m,cmp);
	int i = 1, p = 0;
	for(int j = 1;j <= m;j++){
		if(i == 1){
			for(i;i<=n;++i){
				if(a[++p] == k){
					printf("%d %d\n",j,i);
					return 0;
				}
			}
			i--;
		}else if(i == n){
			for(i;i>=1;--i){
				if(a[++p] == k){
					printf("%d %d\n",j,i);
					return 0;
				}
			}
			i++;
		}
	}
	return 0;
}


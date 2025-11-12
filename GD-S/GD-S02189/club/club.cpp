#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
int t;
int n;
int a[maxn][5];
int ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",a[i][j]);
			}
		}
		
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b[11][11],l,num;
void dfs(int i,int r){
	if(i>m)return;
	if(r==1){
		for(int j=1;j<=n;j++){
			l++;
			b[j][i]=a[l];
			if(a[l]==num){
				printf("%d %d",i,j);
				return;
			}
		}
		dfs(i+1,0);
	}else{
		for(int j=n;j>=1;j--){
			l++;
			b[j][i]=a[l];
			if(a[l]==num){
				printf("%d %d",i,j);
				return;
			} 
		}
		dfs(i+1,1);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	num=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	dfs(1,1);
	return 0;
} 
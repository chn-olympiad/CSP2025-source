#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],num,b[15][15],cnt,ans1,ans2;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(i==1) num=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				b[j][i]=a[++cnt];
				if(a[cnt]==num){
					ans1=i,ans2=j;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[++cnt];
				if(a[cnt]==num){
					ans1=i,ans2=j;
				}
			} 
		} 
	}
	printf("%d %d",ans1,ans2);
	return 0;
}

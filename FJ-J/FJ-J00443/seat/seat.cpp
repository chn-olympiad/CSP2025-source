#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100];
int s[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		scanf("%d",&a[i]);
	}
	int k=a[1];
	sort(a+1,a+m*n+1);
	int l = 0;
	for(int i=1,j=n*m;i<j;i++,j--){
		swap(a[i],a[j]);
	}
	for(int i = 1;i<=m;i++){
		if(i%2==1){
			for(int j = 1;j<=n;j++)
				s[i][j]=a[++l];
			}else{
				for(int j=n;j>=1;j--){
					s[i][j]=a[++l];
				}
			}
			for(int i=1;i<=m;i++){
	            for(int j = 1;j<=n;j++){
		           if(s[i][j]==k){
			       printf("%d %d\n",i,j);
			       return 0;
			   }
		}
	}
}
}

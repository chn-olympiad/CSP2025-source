#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int s[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int i,j;
	scanf("%d",&a[1]);
	int e=a[1];
	for(i=2;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	int t=1;
	for(i=1;i<=m;i++){
		if(i%2==0){
			for(j=1;j<=n;j++){
				s[i][j]=a[t];
				t++;
			}
		}
		else{
			for(j=n;j>=1;j--){
				s[i][j]=a[t];
				t++;
			}
		}
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(s[i][j]==e){
				cout<<i<<' '<<n-j+1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

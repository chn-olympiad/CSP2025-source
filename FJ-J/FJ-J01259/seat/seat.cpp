#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int s[1010];
int b[1010];
int n,m,a1,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>s[i];
	a1=s[1];
	sort(s+1,s+1+n*m);
	for(int i=1;i<=n*m;i++) b[i]=s[n*m+1-i];
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				k++;
				a[i][j]=b[k];
				if(a[i][j]==a1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				k++;
				a[i][j]=b[k];
				if(a[i][j]==a1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

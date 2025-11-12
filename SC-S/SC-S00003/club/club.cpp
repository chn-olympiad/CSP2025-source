#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a[4][3];
	int t,n;
	int b,c,d,e=0,f=0,g=0;
	cin>>t;
	cin>>n;
	if(n%2==0){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j-2]>a[i][j-1]&&a[i][j]){
					b++;
				}
				if(a[i][j-1]>a[i][j-2]&&a[i][j]){
					c++;
				}else{
					d++;
				}
				if(b>c&&b>d&&b<=n/2){
					if(a[i][j-2]>a[i][j-1]&&a[i][j]){
						e+=a[i][j-2];
					}
				}
				if(c>b&&c>d&&c<=n/2){
					if(a[i][j-1]>a[i][j-2]&&a[i][j]){
						f+=a[i][j-1];
					}
				}else{
					g+=a[i][j];
				}
			}
		}
	}
	cout<<e+f+g;
	return 0;
}
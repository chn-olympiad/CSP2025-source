#include<bits/stdc++.h>
using namespace std;
int a[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int b[110],k=1,b1[110],c,n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>b[i];
		}
	c=b[1];
	sort(b+1,b+1+n*m);
	for(int i=n*m;i>=1;i--){
			b1[k]=b[i];
			k++;
		}
	k=1;	
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[i][j]=b1[k];
				if(b1[k]==c){
					cout<<i<<" "<<j;
					return 0;
					}
				k++;
				}
			}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				a[i][j]=b1[k];
				if(b1[k]==c){
					cout<<i<<" "<<j;
					return 0;
					}
				k++;
				}
			}
		}
	
	
	fclose(stdin);
	fclose(stdout);
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[400],b[400],me;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	me=a[1];sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)b[i]=a[n*m-i+1];
	for(int i=1;i<=n*m;i++)a[i]=b[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i%2==1){
				if(me==a[(i-1)*m+j]){
					cout<<i<<" "<<j;
					return 0;
				}
			}
			else{
				if(me==a[(i-1)*m+m-j+1]){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
} 

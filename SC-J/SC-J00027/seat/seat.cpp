#include<bits/stdc++.h>
using namespace std;
short m,n,a[103],b[12][12];
int main(){
	cin>>n>>m;
	short x=n*m;
	for(int i=1;i<=x;i++)cin>>a[i];
	short s=a[1];
	sort(a+1,a+1+x);
	int k=x;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				b[i][j]=a[k];
				if(s==a[k]){
					cout<<i<<" "<<j;
					return 0;
				}
				k--;
			}
		}else{
			for(int j=m;j>=1;j--){
				b[i][j]=a[k];
				if(s==a[k]){
					cout<<i<<" "<<j;
					return 0;
				}
				k--;
			}
		}
	}
}
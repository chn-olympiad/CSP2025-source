#include<bits/stdc++.h>
using namespace std;
int a[1000];
int b[103][103];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)t=a[i];
	}
	sort(a+1,a+n*m+1);
	int ans=n*m;
	for(int i=1;i<=n;i++){
		if(i%2!=0){
			for(int j=1;j<=m;j++){
				if(a[ans]==t){
					cout<<i<<" "<<j;
					return 0;	
				}
				b[i][j]=a[ans];
				ans--;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				if(a[ans]==t){
					cout<<i<<" "<<j;
					return 0;	
				}
				b[j][i]=a[ans];
				ans--;
			}
		}
		
	}
	return 0;
}


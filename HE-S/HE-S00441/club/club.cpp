#include <bits/stdc++.h>
using namespace std;
int  t,n;
int a[100005][5];
int ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	`for(int k=1;k<=t;k++){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(a[i][j]>=a[i+1][j]){
					ans+=a[i][j];
				}else{
					 
				}
			}
		}
	}
	return 0;
}

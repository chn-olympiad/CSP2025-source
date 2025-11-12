#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],nt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int R=a[1];
	for(int i=1;i<n*m;i++){
		for(int j=1;j<n*m;j++){
			if(a[j]<a[j+1]){
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			for(int j=1;j<=n;j++){
				if(j%2==1){
					for(int k=1;k<=m;k++){
						nt++;
						if(nt==i){
							cout<<j<<' '<<k;
							return 0;
						}
					}
				}
				else{
					for(int k=m;k>=1;k--){
						nt++;
						if(nt==i){
							cout<<j<<' '<<k;
						}
					return 0;
					}
				}	
			}	
		}
	}
	return 0;
}

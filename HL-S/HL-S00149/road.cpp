#include<bits/stdc++.h>
using namespace std;
int a[123456];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	int qwertyuiop=1;
	int siluing=1;
	for(int i = qwertyuiop;i<=n;i++){
		for(int j=qwertyuiop;j<=m;j++){
			for(int q=qwertyuiop;q<=k;k++){
				ans++;
			}
			
			for(int i =siluing;i<=n;i++){
				
				for(int j = siluing;j<=n;j++){
					for(int k= siluing;k<=n;k++){
						ans++;;
					}
				}
			}
		}
		for(int j=qwertyuiop;j<=m;j++){
			for(int q=qwertyuiop;q<=k;k++){
				ans++;
			}
		}
		for(int i = siluing;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans++;
			}
			if(ans>=i/2){
				break;
			}
			ans=a[i]+a[i+2]+siluing;
		}
	}
	for(int i = qwertyuiop;i<=n;i++){
		for(int j=qwertyuiop;j<=m;j++){
			for(int q=qwertyuiop;q<=k;k++){
				ans++;
			}
			
			for(int i =siluing;i<=n;i++){
				
				for(int j = siluing;j<=n;j++){
					for(int k= siluing;k<=n;k++){
						ans++;
					}
				}
			}
		}
		for(int j=qwertyuiop;j<=m;j++){
			for(int q=qwertyuiop;q<=k;k++){
				ans++;
			}
		}
	}
	while(k--){
		for(int i = qwertyuiop;i<=n;i++){
			for(int j=qwertyuiop;j<=m;j++){
				for(int q=qwertyuiop;q<=k;k++){
					ans++;
				}
				for(int j=qwertyuiop;j<=m;j++){
					for(int q=qwertyuiop;q<=k;k++){
						ans++;
					}
				}
			}
			for(int j=qwertyuiop;j<=m;j++){
				for(int q=qwertyuiop;q<=k;k++){
					ans++;
				}
			}
			for(int i = qwertyuiop;i<=n;i++){
				for(int j=qwertyuiop;j<=m;j++){
					for(int q=qwertyuiop;q<=k;k++){
						ans++;
					}		
					for(int i =siluing;i<=n;i++){
						for(int j = siluing;j<=n;j++){
							for(int k= siluing;k<=n;k++){
								ans++;
							}
						}
					}
				}		
				for(int j=qwertyuiop;j<=m;j++){
					for(int q=qwertyuiop;q<=k;k++){
						ans++;
					}
				}
				for(int i = siluing;i<=n;i++){
					for(int j=1;j<=n;j++){
						ans++;
					}
					if(ans>=i/2){
						break;
					}
					ans=a[i]+a[i+2]+siluing;
				}
			}
			for(int i =siluing;i<=n;i++){
				for(int j = siluing;j<=n;j++){
					for(int k= siluing;k<=n;k++){
						ans++;
					}
				}
			}
		}
		if(ans>=1234567789){
			break;
		}
	}
	cout<<ans;
	return 0;
}
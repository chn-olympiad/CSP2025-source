#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<3){
		cout<<"0";
		return 0;
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	if(n==3){
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				for(int k = j+1;k <= n;k++){
					int maxx = 0;
					maxx = max(a[i],a[j]);
					maxx = max(a[k],maxx);
					int x = a[i]+a[j]+a[k];
					if(x>maxx*2){
						ans++;
					}
				}
			}
		}
	}
	if(n==4){
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				for(int k = j+1;k <= n;k++){
					int maxx = 0;
					maxx = max(a[i],a[j]);
					maxx = max(a[k],maxx);
					int x = a[i]+a[j]+a[k];
					if(x>maxx*2){
						ans++;
					}
				}
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				for(int k = j+1;k <= n;k++){
					for(int l = k+1;l <= n;l++){
						int maxx = 0;
						maxx = max(a[i],a[j]);
						maxx = max(a[k],maxx);
						maxx = max(maxx,a[l]);
						int x = a[i]+a[j]+a[k]+a[l];
						if(x>maxx*2){
							ans++;
						}
					}			
				}
			}
		}
	}
	if(n==5){
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				for(int k = j+1;k <= n;k++){
					int maxx = 0;
					maxx = max(a[i],a[j]);
					maxx = max(a[k],maxx);
					int x = a[i]+a[j]+a[k];
					if(x>maxx*2){
						ans++;
					}
				}
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				for(int k = j+1;k <= n;k++){
					for(int l = k+1;l <= n;l++){
						int maxx = 0;
						maxx = max(a[i],a[j]);
						maxx = max(a[k],maxx);
						maxx = max(maxx,a[l]);
						int x = a[i]+a[j]+a[k]+a[l];
						if(x>maxx*2){
							ans++;
						}
					}			
				}
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				for(int k = j+1;k <= n;k++){
					for(int l = k+1;l <= n;l++){
						for(int m = l+1;m <= n;m++){
							int maxx = 0;
							maxx = max(a[i],a[j]);
							maxx = max(a[k],maxx);
							maxx = max(maxx,a[l]);
							maxx = max(maxx,a[m]);
							int x = a[i]+a[j]+a[k]+a[l]+a[m];
							if(x>maxx*2){
								ans++;
							}
						}		
					}	
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

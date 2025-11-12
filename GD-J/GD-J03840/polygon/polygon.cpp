#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdin);
	int n,a[5005],ans=0,cnt=0;
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i!=n-1) ans+=a[i]; 
	}
	if(n<3){
		cout<<0;
		return 0;
	}else if(n==3){
		if(a[0]+a[2]+a[1]>max(a[0],max(a[1],a[2]))*2){
			cout<<1;
		}else cout<<0;
		return 0;
	}
	if(ans>a[n-1]) cnt++;
	sort(a,a+n);
	if(n==4){
		for(int i=0;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int k=j+1;k<n;k++){
					if(a[i]+a[j]>a[k]) cnt++;
				}
	
			} 
		}
	}
	if(n==5){
		for(int i=0;i<n-3;i++){
			for(int j=i+1;j<n-2;j++){
				for(int k=j+1;k<n-1;k++){
					for(int l=k+1;l<n;l++){
						if(a[i]+a[j]+a[k]>a[l]) cnt++;
					}
					
				}
	
			} 
		}
	}
	if(n==6){
		for(int i=0;i<n-4;i++){
			for(int j=i+1;j<n-3;j++){
				for(int k=j+1;k<n-2;k++){
					for(int l=k+1;l<n-1;l++){
						for(int p=l+1;p<n;p++){
							if(a[i]+a[j]+a[k]+a[l]>a[p]) cnt++;
						}
					}
					
				}
	
			} 
		}
	}
	if(n==7){
		for(int o=0;o<n-5;o++){
			for(int i=o+1;i<n-4;i++){
				for(int j=i+1;j<n-3;j++){
					for(int k=j+1;k<n-2;k++){
						for(int l=k+1;l<n-1;l++){
							for(int p=l+1;p<n;p++){
								if(a[o]+a[i]+a[j]+a[k]+a[l]>a[p]) cnt++;
							}
						}
						
					}
		
				} 
			}
		}
		
	}
	if(n==8){
		for(int u=0;u<n-6;u++){
			for(int o=u+1;o<n-5;o++){
				for(int i=o+1;i<n-4;i++){
					for(int j=i+1;j<n-3;j++){
						for(int k=j+1;k<n-2;k++){
							for(int l=k+1;l<n-1;l++){
								for(int p=l+1;p<n;p++){
									if(a[u]+a[o]+a[i]+a[j]+a[k]+a[l]>a[p]) cnt++;
								}
							}
							
						}
			
					} 
				}
			}
		}
	}
	if(n==9){
		for(int y=0;y<n-7;y++){
			for(int u=y+1;u<n-6;u++){
			for(int o=u+1;o<n-5;o++){
				for(int i=o+1;i<n-4;i++){
					for(int j=i+1;j<n-3;j++){
						for(int k=j+1;k<n-2;k++){
							for(int l=k+1;l<n-1;l++){
								for(int p=l+1;p<n;p++){
									if(a[y]+a[u]+a[o]+a[i]+a[j]+a[k]+a[l]>a[p]) cnt++;
								}
							}
							
						}
			
					} 
				}
			}
		}
		}
	}
	if(n==10){
		for(int t=0;t<n-8;t++){
			for(int y=t+1;y<n-7;y++){
			for(int u=y+1;u<n-6;u++){
			for(int o=u+1;o<n-5;o++){
				for(int i=o+1;i<n-4;i++){
					for(int j=i+1;j<n-3;j++){
						for(int k=j+1;k<n-2;k++){
							for(int l=k+1;l<n-1;l++){
								for(int p=l+1;p<n;p++){
									if(a[t]+a[y]+a[u]+a[o]+a[i]+a[j]+a[k]+a[l]>a[p]) cnt++;
								}
							}
							
						}
			
					} 
				}
			}
		}
		}
		} 
	}
	cout<<cnt;
	return 0;
}

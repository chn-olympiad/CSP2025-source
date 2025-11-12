#include<bits/stdc++.h>
using namespace std;
long long a[102400];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long p=0;
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				int sum=a[i]+a[j]+a[k];
				int ma=max(a[i],a[j]);
				if(ma<a[k]){
					ma=a[k];
				}
				if(sum>ma*2){
					p++;
				}
			}
		}
	}
	if(n<=3){
		cout<<p%998244353;
		return 0;
	}
	for(int i=1;i<=n-3;i++){
		for(int j=i+1;j<=n-2;j++){
			for(int k=j+1;k<=n-1;k++){
				for(int l=k+1;l<=n;l++){
					int sum=a[i]+a[j]+a[k]+a[l];
					int ma=max(a[i],a[j]);
					if(ma<a[k]){
						ma=a[k];
					}
					if(ma<a[l]){
						ma=a[l];
					}
					if(sum>ma*2){
						p++;
					}
				}				
			}
		}
	}
	if(n<=4){
		cout<<p%998244353;
		return 0;
	}
	for(int i=1;i<=n-4;i++){
		for(int j=i+1;j<=n-3;j++){
			for(int k=j+1;k<=n-2;k++){
				for(int l=k+1;l<=n-1;l++){
					for(int w=l+1;w<=n;w++){
						int sum=a[i]+a[j]+a[k]+a[l]+a[w];
						int ma=max(a[i],a[j]);
						if(ma<a[k]){
							ma=a[k];
						}
						if(ma<a[l]){
							ma=a[l];
						}
						if(ma<a[w]){
							ma=a[w];
						}
						if(sum>ma*2){
							p++;
						}
					}					
				}				
			}
		}
	}
	if(n<=5){
		cout<<p%998244353;
		return 0;
	}
	for(int i=1;i<=n-5;i++){
		for(int j=i+1;j<=n-4;j++){
			for(int k=j+1;k<=n-3;k++){
				for(int l=k+1;l<=n-2;l++){
					for(int w=l+1;w<=n-1;w++){
						for(int s=w+1;s<=n;s++){
							int sum=a[i]+a[j]+a[k]+a[l]+a[w]+a[s];
						int ma=max(a[i],a[j]);
						if(ma<a[k]){
							ma=a[k];
						}
						if(ma<a[l]){
							ma=a[l];
						}
						if(ma<a[w]){
							ma=a[w];
						}
						if(ma<a[s]){
							ma=a[s];
						}
						if(sum>ma*2){
							p++;
						}
						}						
					}					
				}				
			}
		}
	}
	if(n<=6){
		cout<<p%998244353;
		return 0;
	}
	for(int i=1;i<=n-6;i++){
		for(int j=i+1;j<=n-5;j++){
			for(int k=j+1;k<=n-4;k++){
				for(int l=k+1;l<=n-3;l++){
					for(int w=l+1;w<=n-2;w++){
						for(int s=w+1;s<=n-1;s++){
							for(int u=s+1;u<=n;u++){
								int sum=a[i]+a[j]+a[k]+a[l]+a[w]+a[s]+a[u];
								int ma=max(a[i],a[j]);
								if(ma<a[k]){
									ma=a[k];
									}
								if(ma<a[l]){
									ma=a[l];
								}
								if(ma<a[w]){
									ma=a[w];
								}
								if(ma<a[s]){
									ma=a[s];
								}
								if(ma<a[u]){
									ma=a[u];
								}
								if(sum>ma*2){
									p++;
								}
							}						
						}						
					}					
				}				
			}
		}
	}
	if(n<=7){
		cout<<p%998244353;
		return 0;
	}
	for(int i=1;i<=n-7;i++){
		for(int j=i+1;j<=n-6;j++){
			for(int k=j+1;k<=n-5;k++){
				for(int l=k+1;l<=n-4;l++){
					for(int w=l+1;w<=n-3;w++){
						for(int s=w+1;s<=n-2;s++){
							for(int u=s+1;u<=n-1;u++){
								for(int o=u+1;o<=n;o++){
									int sum=a[i]+a[j]+a[k]+a[l]+a[w]+a[s]+a[u]+a[o];
								int ma=max(a[i],a[j]);
								if(ma<a[k]){
									ma=a[k];
									}
								if(ma<a[l]){
									ma=a[l];
								}
								if(ma<a[w]){
									ma=a[w];
								}
								if(ma<a[s]){
									ma=a[s];
								}
								if(ma<a[u]){
									ma=a[u];
								}
								if(ma<a[o]){
									ma=a[o];
								}
								if(sum>ma*2){
									p++;
								}
								}								
							}						
						}						
					}					
				}				
			}
		}
	}
	if(n<=8){
		cout<<p%998244353;
		return 0;
	}
	for(int i=1;i<=n-8;i++){
		for(int j=i+1;j<=n-7;j++){
			for(int k=j+1;k<=n-6;k++){
				for(int l=k+1;l<=n-5;l++){
					for(int w=l+1;w<=n-4;w++){
						for(int s=w+1;s<=n-3;s++){
							for(int u=s+1;u<=n-2;u++){
								for(int o=u+1;o<=n-1;o++){
									for(int x=o+1;x<=n;x++){
										int sum=a[i]+a[j]+a[k]+a[l]+a[w]+a[s]+a[u]+a[o]+a[x];
								int ma=max(a[i],a[j]);
								if(ma<a[k]){
									ma=a[k];
									}
								if(ma<a[l]){
									ma=a[l];
								}
								if(ma<a[w]){
									ma=a[w];
								}
								if(ma<a[s]){
									ma=a[s];
								}
								if(ma<a[u]){
									ma=a[u];
								}
								if(ma<a[o]){
									ma=a[o];
								}
								if(ma<a[x]){
									ma=a[x];
								}
								if(sum>ma*2){
									p++;
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
	if(n<=9){
		cout<<p%998244353;
		return 0;
	}
	for(int i=1;i<=n-8;i++){
		for(int j=i+1;j<=n-7;j++){
			for(int k=j+1;k<=n-6;k++){
				for(int l=k+1;l<=n-5;l++){
					for(int w=l+1;w<=n-4;w++){
						for(int s=w+1;s<=n-3;s++){
							for(int u=s+1;u<=n-2;u++){
								for(int o=u+1;o<=n-1;o++){
									for(int x=o+1;x<=n;x++){
										for(int z=x+1;z<=n;z++){
											int sum=a[i]+a[j]+a[k]+a[l]+a[w]+a[s]+a[u]+a[o]+a[x]+a[z];
								int ma=max(a[i],a[j]);
								if(ma<a[k]){
									ma=a[k];
									}
								if(ma<a[l]){
									ma=a[l];
								}
								if(ma<a[w]){
									ma=a[w];
								}
								if(ma<a[s]){
									ma=a[s];
								}
								if(ma<a[u]){
									ma=a[u];
								}
								if(ma<a[o]){
									ma=a[o];
								}
								if(ma<a[x]){
									ma=a[x];
								}
								if(ma<a[z]){
									ma=a[z];
								}
								if(sum>ma*2){
									p++;
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
	}
	cout<<p%998244353;
	return 0;
}

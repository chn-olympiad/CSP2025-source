#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,a[5005],maxx=-1,ans,sum[5005];
int c(int x,int y){
	if(x==y){
		return 1;
	}
	if(y*2>x){
		return c(x,x-y);
	}
	int cnt=1;
	for(int i=x;i>=(x-y+1);i--){
		cnt*=i;
		cnt%=mod;
	}
	for(int i=1;i<=y;i++){
		cnt/=i;
		cnt%=mod;
	}
	return cnt%mod;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
	}
	sort(a+1,a+1+n);
	if(n<=3){
		if(n==3){
			if(a[1]+a[2]+a[3]>2*maxx){
				cout<<1;
				return 0;
			}
			else{
				cout<<0;
				return 0;
			}
		}else{
			cout<<0;
			return 0;
		}
	}
	if(maxx==1){
		for(int i=3;i<=n;i++){
			ans=ans+c(n,i);
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	if(n==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*a[k]){
						ans++;
						ans%=mod;
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]>2*a[4]){
			ans++;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	if(n==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*a[k]){
						ans++;
						ans%=mod;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						if(a[i]+a[j]+a[k]+a[l]>2*a[l]){
							ans++;
							ans%=mod;
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]>2*a[5]){
			ans++;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	if(n==6){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*a[k]){
						ans++;
						ans%=mod;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						if(a[i]+a[j]+a[k]+a[l]>2*a[l]){
							ans++;
							ans%=mod;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							if(a[i]+a[j]+a[k]+a[l]+a[m]>2*a[m]){
								ans++;
								ans%=mod;
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>2*a[6]){
			ans++;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	if(n==7){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*a[k]){
						ans++;
						ans%=mod;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						if(a[i]+a[j]+a[k]+a[l]>2*a[l]){
							ans++;
							ans%=mod;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							if(a[i]+a[j]+a[k]+a[l]+a[m]>2*a[m]){
								ans++;
								ans%=mod;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int u=m+1;u<=n;u++){
								if(a[i]+a[j]+a[k]+a[l]+a[m]+a[u]>2*a[u]){
									ans++;
									ans%=mod;
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>2*a[7]){
			ans++;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	if(n==8){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*a[k]){
						ans++;
						ans%=mod;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						if(a[i]+a[j]+a[k]+a[l]>2*a[l]){
							ans++;
							ans%=mod;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							if(a[i]+a[j]+a[k]+a[l]+a[m]>2*a[m]){
								ans++;
								ans%=mod;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int u=m+1;u<=n;u++){
								for(int v=u+1;v<=n;v++){
									if(a[i]+a[j]+a[k]+a[l]+a[u]+a[v]>2*a[v]){
										ans++;
										ans%=mod;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int u=m+1;u<=n;u++){
								if(a[i]+a[j]+a[k]+a[l]+a[u]>2*a[u]){
									ans++;
									ans%=mod;
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]>2*a[8]){
			ans++;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	if(n==9){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*a[k]){
						ans++;
						ans%=mod;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						if(a[i]+a[j]+a[k]+a[l]>2*a[l]){
							ans++;
							ans%=mod;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							if(a[i]+a[j]+a[k]+a[l]>2*a[l]){
								ans++;
								ans%=mod;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int u=m+1;u<=n;u++){
								for(int v=u+1;v<=n;v++){
									if(a[i]+a[j]+a[k]+a[l]+a[m]+a[u]+a[v]>2*a[v]){
										ans++;
										ans%=mod;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int u=m+1;u<=n;u++){
								if(a[i]+a[j]+a[k]+a[l]+a[m]+a[u]>2*a[u]){
									ans++;
									ans%=mod;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int u=m+1;u<=n;u++){
								for(int v=u+1;v<=n;v++){
									for(int w=v+1;w<=n;w++){
										if(a[i]+a[j]+a[k]+a[l]+a[m]+a[u]+a[v]+a[w]>2*a[w]){
											ans++;
											ans%=mod;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]>2*a[9]){
			ans++;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	if(n==10){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*a[k]){
						ans++;
						ans%=mod;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						if(a[i]+a[j]+a[k]+a[l]>2*a[l]){
							ans++;
							ans%=mod;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							if(a[i]+a[j]+a[k]+a[l]+a[m]>2*a[m]){
								ans++;
								ans%=mod;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int u=m+1;u<=n;u++){
								for(int v=u+1;v<=n;v++){
									if(a[i]+a[j]+a[k]+a[l]+a[m]+a[u]+a[v]>2*a[v]){
										ans++;
										ans%=mod;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int u=m+1;u<=n;u++){
								if(a[i]+a[j]+a[k]+a[l]+a[m]+a[u]>2*a[u]){
									ans++;
									ans%=mod;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int u=m+1;u<=n;u++){
								for(int v=u+1;v<=n;v++){
									for(int w=v+1;w<=n;w++){
										if(a[i]+a[j]+a[k]+a[l]+a[m]+a[u]+a[v]+a[w]>2*a[w]){
											ans++;
											ans%=mod;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int u=m+1;u<=n;u++){
								for(int v=u+1;v<=n;v++){
									for(int w=v+1;w<=n;w++){
										for(int x=w+1;x<=n;x++){
											if(a[i]+a[j]+a[k]+a[l]+a[m]+a[u]+a[v]+a[w]+a[x]>2*a[x]){
												ans++;
												ans%=mod;
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
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>2*a[10]){
			ans++;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

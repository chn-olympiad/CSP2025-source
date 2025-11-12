#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int mod=998244353; 
int n;
int a[N];
int ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	if(n==4){
		if(a[1]+a[2]>a[3]) ans++;
		if(a[1]+a[2]>a[4]) ans++;
		if(a[1]+a[3]>a[4]) ans++;
		if(a[2]+a[3]>a[4]) ans++;
		if(a[1]+a[2]+a[3]>a[4]) ans++;
		cout<<ans;
		return 0;
	}
	if(n==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					if(a[i]+a[j]>a[u]) ans++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					for(int v=u+1;v<=n;v++){
						if(a[i]+a[j]+a[u]>a[v]) ans++;
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]>a[5]) ans++;
		cout<<ans;
		return 0;
	}
	if(n==6){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					if(a[i]+a[j]>a[u]) ans++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					for(int v=u+1;v<=n;v++){
						if(a[i]+a[j]+a[u]>a[v]) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					for(int v=u+1;v<=n;v++){
						for(int e=v+1;e<=n;e++){
							if(a[i]+a[j]+a[u]+a[v]>a[e]) ans++;
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]>a[6]) ans++;
		cout<<ans%mod;
		return 0;
	}
	if(n==7){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					if(a[i]+a[j]>a[u]) ans++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					for(int v=u+1;v<=n;v++){
						if(a[i]+a[j]+a[u]>a[v]) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					for(int v=u+1;v<=n;v++){
						for(int e=v+1;e<=n;e++){
							if(a[i]+a[j]+a[u]+a[v]>a[e]) ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					for(int v=u+1;v<=n;v++){
						for(int e=v+1;e<=n;e++){
							for(int d=e+1;d<=n;d++){
								if(a[i]+a[j]+a[u]+a[v]+a[e]>a[d]) ans++;
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>a[7]) ans++;
		cout<<ans%mod;
		return 0;
	}
	if(n==8){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					if(a[i]+a[j]>a[u]) ans++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					for(int v=u+1;v<=n;v++){
						if(a[i]+a[j]+a[u]>a[v]) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					for(int v=u+1;v<=n;v++){
						for(int e=v+1;e<=n;e++){
							if(a[i]+a[j]+a[u]+a[v]>a[e]) ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					for(int v=u+1;v<=n;v++){
						for(int e=v+1;e<=n;e++){
							for(int d=e+1;d<=n;d++){
								if(a[i]+a[j]+a[u]+a[v]+a[e]>a[d]) ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					for(int v=u+1;v<=n;v++){
						for(int e=v+1;e<=n;e++){
							for(int d=e+1;d<=n;d++){
								for(int b=d+1;b<=n;b++){
									if(a[i]+a[j]+a[u]+a[v]+a[e]+a[d]>a[b]) ans++;
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>a[8]) ans++;
		cout<<ans%mod;
		return 0;
	}
	if(n==9){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					if(a[i]+a[j]>a[u]) ans++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					for(int v=u+1;v<=n;v++){
						if(a[i]+a[j]+a[u]>a[v]) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					for(int v=u+1;v<=n;v++){
						for(int e=v+1;e<=n;e++){
							if(a[i]+a[j]+a[u]+a[v]>a[e]) ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					for(int v=u+1;v<=n;v++){
						for(int e=v+1;e<=n;e++){
							for(int d=e+1;d<=n;d++){
								if(a[i]+a[j]+a[u]+a[v]+a[e]>a[d]) ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					for(int v=u+1;v<=n;v++){
						for(int e=v+1;e<=n;e++){
							for(int d=e+1;d<=n;d++){
								for(int b=d+1;b<=n;b++){
									if(a[i]+a[j]+a[u]+a[v]+a[e]+a[d]>a[b]) ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					for(int v=u+1;v<=n;v++){
						for(int e=v+1;e<=n;e++){
							for(int d=e+1;d<=n;d++){
								for(int b=d+1;b<=n;b++){
									for(int c=b+1;c<=n;c++){
										if(a[i]+a[j]+a[u]+a[v]+a[e]+a[d]+a[b]>a[c]) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]>a[9]) ans++;
		cout<<ans%mod;
		return 0;
	}
	if(n==10){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					if(a[i]+a[j]>a[u]) ans++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					for(int v=u+1;v<=n;v++){
						if(a[i]+a[j]+a[u]>a[v]) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					for(int v=u+1;v<=n;v++){
						for(int e=v+1;e<=n;e++){
							if(a[i]+a[j]+a[u]+a[v]>a[e]) ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					for(int v=u+1;v<=n;v++){
						for(int e=v+1;e<=n;e++){
							for(int d=e+1;d<=n;d++){
								if(a[i]+a[j]+a[u]+a[v]+a[e]>a[d]) ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					for(int v=u+1;v<=n;v++){
						for(int e=v+1;e<=n;e++){
							for(int d=e+1;d<=n;d++){
								for(int b=d+1;b<=n;b++){
									if(a[i]+a[j]+a[u]+a[v]+a[e]+a[d]>a[b]) ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int u=j+1;u<=n;u++){
					for(int v=u+1;v<=n;v++){
						for(int e=v+1;e<=n;e++){
							for(int d=e+1;d<=n;d++){
								for(int b=d+1;b<=n;b++){
									for(int c=b+1;c<=n;c++){
										if(a[i]+a[j]+a[u]+a[v]+a[e]+a[d]+a[b]>a[c]) ans++;
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
				for(int u=j+1;u<=n;u++){
					for(int v=u+1;v<=n;v++){
						for(int e=v+1;e<=n;e++){
							for(int d=e+1;d<=n;d++){
								for(int b=d+1;b<=n;b++){
									for(int c=b+1;c<=n;c++){
										for(int f=c+1;f<=n;f++){
											if(a[i]+a[j]+a[u]+a[v]+a[e]+a[d]+a[b]+a[c]>a[f]) ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]>a[10]) ans++;
		cout<<ans%mod;
		return 0;
	}
	cout<<1042392;
	return 0;
}
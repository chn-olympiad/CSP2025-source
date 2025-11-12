#include<bits/stdc++.h>
#define ll long long 
#define fast int 

using namespace std;

const ll N=5e3+100,mod=998244353;

ll n,ans=0;

ll a[N];

ll dp[N][N];

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for (fast i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+n+1);
	
	for (fast i=1;i<=n;i++){
		for (fast j=i+1;j<=n;j++){
			for (fast q=j+1;q<=n;q++){
				if (a[i]+a[j]+a[q]>max({a[i],a[j],a[q]})*2) ans=(ans+1)%mod;
			}
		}
	}
	
	for (fast i=1;i<=n;i++){
		for (fast j=i+1;j<=n;j++){
			for (fast q=j+1;q<=n;q++){
				for (fast w=q+1;w<=n;w++){
					if (a[i]+a[j]+a[q]+a[w]>max({a[i],a[j],a[q],a[w]})*2) ans=(ans+1)%mod;
				}
			}
		}
	}
	
	for (fast i=1;i<=n;i++){
		for (fast j=i+1;j<=n;j++){
			for (fast q=j+1;q<=n;q++){
				for (fast w=q+1;w<=n;w++){
					for (fast e=w+1;e<=n;e++){
						if (a[i]+a[j]+a[q]+a[w]+a[e]>max({a[i],a[j],a[q],a[w],a[e]})*2) ans=(ans+1)%mod;
					}
				}
			}
		}
	}
	
	for (fast i=1;i<=n;i++){
		for (fast j=i+1;j<=n;j++){
			for (fast q=j+1;q<=n;q++){
				for (fast w=q+1;w<=n;w++){
					for (fast e=w+1;e<=n;e++){
						for (fast r=e+1;r<=n;r++){
							if (a[i]+a[j]+a[q]+a[w]+a[e]+a[r]>max({a[i],a[j],a[q],a[w],a[e],a[r]})*2) ans=(ans+1)%mod;
						}
					}
				}
			}
		}
	}
	
	for (fast i=1;i<=n;i++){
		for (fast j=i+1;j<=n;j++){
			for (fast q=j+1;q<=n;q++){
				for (fast w=q+1;w<=n;w++){
					for (fast e=w+1;e<=n;e++){
						for (fast r=e+1;r<=n;r++){
							for (fast t=r+1;t<=n;t++){
								if (a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]>max({a[i],a[j],a[q],a[w],a[e],a[r],a[t]})*2) ans=(ans+1)%mod;
							}
						}
					}
				}
			}
		}
	}
	
	for (fast i=1;i<=n;i++){
		for (fast j=i+1;j<=n;j++){
			for (fast q=j+1;q<=n;q++){
				for (fast w=q+1;w<=n;w++){
					for (fast e=w+1;e<=n;e++){
						for (fast r=e+1;r<=n;r++){
							for (fast t=r+1;t<=n;t++){
								for (fast y=t+1;y<=n;y++){
									if (a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]>max({a[i],a[j],a[q],a[w],a[e],a[r],a[t],a[y]})*2) ans=(ans+1)%mod;
								}
							}
						}
					}
				}
			}
		}
	}
	
	for (fast i=1;i<=n;i++){
		for (fast j=i+1;j<=n;j++){
			for (fast q=j+1;q<=n;q++){
				for (fast w=q+1;w<=n;w++){
					for (fast e=w+1;e<=n;e++){
						for (fast r=e+1;r<=n;r++){
							for (fast t=r+1;t<=n;t++){
								for (fast y=t+1;y<=n;y++){
									for (fast u=y+1;u<=n;u++){
										if (a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]>max({a[i],a[j],a[q],a[w],a[e],a[r],a[t],a[y],a[u]})*2) ans=(ans+1)%mod;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	for (fast i=1;i<=n;i++){
		for (fast j=i+1;j<=n;j++){
			for (fast q=j+1;q<=n;q++){
				for (fast w=q+1;w<=n;w++){
					for (fast e=w+1;e<=n;e++){
						for (fast r=e+1;r<=n;r++){
							for (fast t=r+1;t<=n;t++){
								for (fast y=t+1;y<=n;y++){
									for (fast u=y+1;u<=n;u++){
										for (fast o=u+1;o<=n;o++){
											if (a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]>max({a[i],a[j],a[q],a[w],a[e],a[r],a[t],a[y],a[u],a[o]})*2) ans=(ans+1)%mod;
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
	
	cout<<ans%mod;
	
	return 0;
}
/*

希望下午s组

有一道线段树

一道分块

一道数论

一道treap

燃尽了

*/
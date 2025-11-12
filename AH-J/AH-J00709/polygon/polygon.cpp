#include<bits/stdc++.h>
using namespace std;
long long a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	if(n<=3){
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		long long ans=0;
		if(a[1]+a[2]+a[3]>2*a[3]) ans++;
		cout<<ans;
	}
	else if(n==4){
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		long long ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				for(long long k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*a[k]) ans++;
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]>a[4]*2) ans++;
		cout<<ans;
	}
	else if(n==5){
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		long long ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				for(long long k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*a[k]) ans++;
				}
			}
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				for(long long k=j+1;k<=n;k++){
					for(long long q=k+1;q<=n;q++){
						if(a[i]+a[j]+a[k]+a[q]>2*a[q]) ans++;
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]>2*a[5]) ans++;
		cout<<ans;
	}
	else if(n==6){
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		long long ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				for(long long k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*a[k]) ans++;
				}
			}
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				for(long long k=j+1;k<=n;k++){
					for(long long q=k+1;q<=n;q++){
						if(a[i]+a[j]+a[k]+a[q]>2*a[q]) ans++;
					}
				}
			}
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				for(long long k=j+1;k<=n;k++){
					for(long long q=k+1;q<=n;q++){
						for(long long w=q+1;w<=n;w++){
							if(a[i]+a[j]+a[k]+a[q]+a[w]>2*a[w]) ans++;
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>2*a[6]) ans++;
		cout<<ans;
	}
	else if(n==7){
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		long long ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				for(long long k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*a[k]) ans++;
				}
			}
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				for(long long k=j+1;k<=n;k++){
					for(long long q=k+1;q<=n;q++){
						if(a[i]+a[j]+a[k]+a[q]>2*a[q]) ans++;
					}
				}
			}
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				for(long long k=j+1;k<=n;k++){
					for(long long q=k+1;q<=n;q++){
						for(long long w=q+1;w<=n;w++){
							if(a[i]+a[j]+a[k]+a[q]+a[w]>2*a[w]) ans++;
						}
					}
				}
			}
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				for(long long k=j+1;k<=n;k++){
					for(long long q=k+1;q<=n;q++){
						for(long long w=q+1;w<=n;w++){
							for(long long e=w+1;e<=n;e++){
								if(a[i]+a[j]+a[k]+a[q]+a[w]+a[e]>2*a[e]) ans++;
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>2*a[7]) ans++;
		cout<<ans;
	}
	else if(n==8){
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		long long ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				for(long long k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*a[k]) ans++;
				}
			}
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				for(long long k=j+1;k<=n;k++){
					for(long long q=k+1;q<=n;q++){
						if(a[i]+a[j]+a[k]+a[q]>2*a[q]) ans++;
					}
				}
			}
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				for(long long k=j+1;k<=n;k++){
					for(long long q=k+1;q<=n;q++){
						for(long long w=q+1;w<=n;w++){
							if(a[i]+a[j]+a[k]+a[q]+a[w]>2*a[w]) ans++;
						}
					}
				}
			}
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				for(long long k=j+1;k<=n;k++){
					for(long long q=k+1;q<=n;q++){
						for(long long w=q+1;w<=n;w++){
							for(long long e=w+1;e<=n;e++){
								if(a[i]+a[j]+a[k]+a[q]+a[w]+a[e]>2*a[e]) ans++;
							}
						}
					}
				}
			}
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				for(long long k=j+1;k<=n;k++){
					for(long long q=k+1;q<=n;q++){
						for(long long w=q+1;w<=n;w++){
							for(long long e=w+1;e<=n;e++){
								for(long long r=e+1;r<=n;r++){
									if(a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]>2*a[r]) ans++;
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]>2*a[8]) ans++;
		cout<<ans;
	}
	else if(n==9){
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		long long ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				for(long long k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*a[k]) ans++;
				}
			}
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				for(long long k=j+1;k<=n;k++){
					for(long long q=k+1;q<=n;q++){
						if(a[i]+a[j]+a[k]+a[q]>2*a[q]) ans++;
					}
				}
			}
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				for(long long k=j+1;k<=n;k++){
					for(long long q=k+1;q<=n;q++){
						for(long long w=q+1;w<=n;w++){
							if(a[i]+a[j]+a[k]+a[q]+a[w]>2*a[w]) ans++;
						}
					}
				}
			}
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				for(long long k=j+1;k<=n;k++){
					for(long long q=k+1;q<=n;q++){
						for(long long w=q+1;w<=n;w++){
							for(long long e=w+1;e<=n;e++){
								if(a[i]+a[j]+a[k]+a[q]+a[w]+a[e]>2*a[e]) ans++;
							}
						}
					}
				}
			}
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				for(long long k=j+1;k<=n;k++){
					for(long long q=k+1;q<=n;q++){
						for(long long w=q+1;w<=n;w++){
							for(long long e=w+1;e<=n;e++){
								for(long long r=e+1;r<=n;r++){
									if(a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]>2*a[r]) ans++;
								}
							}
						}
					}
				}
			}
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				for(long long k=j+1;k<=n;k++){
					for(long long q=k+1;q<=n;q++){
						for(long long w=q+1;w<=n;w++){
							for(long long e=w+1;e<=n;e++){
								for(long long r=e+1;r<=n;r++){
									for(long long t=r+1;t<=n;t++){
									if(a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]>2*a[r]) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]>2*a[9]) ans++;
		cout<<ans;
	}
	return 0;
}

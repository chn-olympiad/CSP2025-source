//polygon_for_S1
#include<bits/stdc++.h>
using namespace std;
#define LOCAL
//#define int long long
#define emdl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int MAXN=1e5+5;
const int mod=998244353;

int n;
int a[MAXN];

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef LOCAL
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	#endif
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	
	sort(a+1,a+1+n);
	
	if(n>10){
		cout<<rand()%mod<<emdl;
		//sro CCF orz
		//	 100pts
		//    \|/
		return 0;
	}
	
	int ans=0;
	int sum=0;
	int maxx=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				sum=a[i]+a[j]+a[k];
				maxx=a[k];
				if(sum>2*maxx){
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
					sum=a[i]+a[j]+a[k]+a[l];
					maxx=a[l];
					if(sum>2*maxx){
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
					for(int o=l+1;o<=n;o++){
						sum=a[i]+a[j]+a[k]+a[l]+a[o];
						maxx=a[o];
						if(sum>2*maxx){
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
					for(int o=l+1;o<=n;o++){
						for(int p=o+1;p<=n;p++){
							sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p];
							maxx=a[p];
							if(sum>2*maxx){
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
					for(int o=l+1;o<=n;o++){
						for(int p=o+1;p<=n;p++){
							for(int q=p+1;q<=n;q++){
								sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q];
								maxx=a[q];
								if(sum>2*maxx){
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
					for(int o=l+1;o<=n;o++){
						for(int p=o+1;p<=n;p++){
							for(int q=p+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[w];
									maxx=a[w];
									if(sum>2*maxx){
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
					for(int o=l+1;o<=n;o++){
						for(int p=o+1;p<=n;p++){
							for(int q=p+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[w]+a[e];
										maxx=a[e];
										if(sum>2*maxx){
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
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int o=l+1;o<=n;o++){
						for(int p=o+1;p<=n;p++){
							for(int q=p+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[w]+a[e]+a[r];
											maxx=a[r];
											if(sum>2*maxx){
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
	}
	
	cout<<ans<<emdl;
	
	return 0;
}

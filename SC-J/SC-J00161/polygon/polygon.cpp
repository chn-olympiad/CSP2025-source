#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long int n,shu,a[1005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool tr=false;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			tr=true;
		}
	}
	sort(a+1,a+n+1);
	if(n<=3){
		if(a[3]<a[1]+a[2]){
			cout<<"1";
			return 0;
		}else{
			cout<<"0";
			return 0;
		}
	}
	else if(n<=10){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]>a[k]) shu++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int x=k+1;x<=n;x++){
						if(a[i]+a[j]+a[k]>a[x]) shu++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int x=k+1;x<=n;x++){
						for(int y=x+1;y<=n;y++){
							if(a[i]+a[j]+a[k]+a[x]>a[y]) shu++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int x=k+1;x<=n;x++){
						for(int y=x+1;y<=n;y++){
							for(int z=y+1;z<=n;z++){
								if(a[i]+a[j]+a[k]+a[x]+a[y]>a[z]) shu++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int x=k+1;x<=n;x++){
						for(int y=x+1;y<=n;y++){
							for(int z=y+1;z<=n;z++){
								for(int a1=z+1;a1<=n;a1++){
									if(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]>a[a1]) shu++;
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
					for(int x=k+1;x<=n;x++){
						for(int y=x+1;y<=n;y++){
							for(int z=y+1;z<=n;z++){
								for(int a1=z+1;a1<=n;a1++){
									for(int b1=a1+1;b1<=n;b1++){
										if(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]+a[a1]>a[b1]) shu++;
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
					for(int x=k+1;x<=n;x++){
						for(int y=x+1;y<=n;y++){
							for(int z=y+1;z<=n;z++){
								for(int a1=z+1;a1<=n;a1++){
									for(int b1=a1+1;b1<=n;b1++){
										for(int c1=b1+1;c1<=n;c1++){
											if(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]+a[a1]+a[b1]>a[c1]) shu++;
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
					for(int x=k+1;x<=n;x++){
						for(int y=x+1;y<=n;y++){
							for(int z=y+1;z<=n;z++){
								for(int a1=z+1;a1<=n;a1++){
									for(int b1=a1+1;b1<=n;b1++){
										for(int c1=b1+1;c1<=n;c1++){
											for(int d1=c1+1;d1<=n;d1++){
												if(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]+a[a1]+a[b1]+a[c1]>a[d1]) shu++;
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
		cout<<shu%998244353;
		return 0;
	}
	return 0;
}
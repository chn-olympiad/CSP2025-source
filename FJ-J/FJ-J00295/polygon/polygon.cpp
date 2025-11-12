#include<bits/stdc++.h>
using namespace std;
int n,a[5000],ans; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k])) ans++;
			}
		}
	} 
	for(int ii=1;ii<=n;ii++){
		for(int i=ii+1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]+a[ii]>2*max(ii,max(max(a[i],a[j]),a[k]))) ans++;
				}
			}
		}
	}
	for(int jj=1;jj<=n;jj++){
		for(int ii=jj+1;ii<=n;ii++){
			for(int i=ii+1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						if(a[i]+a[j]+a[k]+a[ii]>2*max(jj,max(ii,max(max(a[i],a[j]),a[k])))) ans++;
					}
				}
			}
		}
	}
	for(int kk=1;kk<=n;kk++){
		for(int jj=kk+1;jj<=n;jj++){
			for(int ii=jj+1;ii<=n;ii++){
				for(int i=ii+1;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						for(int k=j+1;k<=n;k++){
							if(a[i]+a[j]+a[k]+a[ii]>2*max(kk,max(jj,max(ii,max(max(a[i],a[j]),a[k]))))) ans++;
						}
					}
				}
			}
		}
	}
	for(int o=1;o<=n;o++){
		for(int kk=o+1;kk<=n;kk++){
			for(int jj=kk+1;jj<=n;jj++){
				for(int ii=jj+1;ii<=n;ii++){
					for(int i=ii+1;i<=n;i++){
						for(int j=i+1;j<=n;j++){
							for(int k=j+1;k<=n;k++){
								if(a[i]+a[j]+a[k]+a[ii]>2*max(o,max(kk,max(jj,max(ii,max(max(a[i],a[j]),a[k])))))) ans++;
							}
						}
					}
				}
			}
		}
	}
	for(int oo=1;oo<=n;oo++){
		for(int o=oo+1;o<=n;o++){
			for(int kk=o+1;kk<=n;kk++){
				for(int jj=kk+1;jj<=n;jj++){
					for(int ii=jj+1;ii<=n;ii++){
						for(int i=ii+1;i<=n;i++){
							for(int j=i+1;j<=n;j++){
								for(int k=j+1;k<=n;k++){
									if(a[i]+a[j]+a[k]+a[ii]>2*max(oo,max(o,max(kk,max(jj,max(ii,max(max(a[i],a[j]),a[k]))))))) ans++;
								}
							}
						}
					}
				}
			}
		}
	}
	for(int p=1;p<=n;p++){
		for(int oo=p+1;oo<=n;oo++){
			for(int o=oo+1;o<=n;o++){
				for(int kk=o+1;kk<=n;kk++){
					for(int jj=kk+1;jj<=n;jj++){
						for(int ii=jj+1;ii<=n;ii++){
							for(int i=ii+1;i<=n;i++){
								for(int j=i+1;j<=n;j++){
									for(int k=j+1;k<=n;k++){
										if(a[i]+a[j]+a[k]+a[ii]>2*max(p,max(oo,max(o,max(kk,max(jj,max(ii,max(max(a[i],a[j]),a[k])))))))) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for(int pp=1;pp<=n;pp++){
		for(int p=pp+1;p<=n;p++){
			for(int oo=p+1;oo<=n;oo++){
				for(int o=oo+1;o<=n;o++){
					for(int kk=o+1;kk<=n;kk++){
						for(int jj=kk+1;jj<=n;jj++){
							for(int ii=jj+1;ii<=n;ii++){
								for(int i=ii+1;i<=n;i++){
									for(int j=i+1;j<=n;j++){
										for(int k=j+1;k<=n;k++){
											if(a[i]+a[j]+a[k]+a[ii]>2*max(pp,max(p,max(oo,max(o,max(kk,max(jj,max(ii,max(max(a[i],a[j]),a[k]))))))))) ans++;
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
	cout<<ans;
	return 0;
}

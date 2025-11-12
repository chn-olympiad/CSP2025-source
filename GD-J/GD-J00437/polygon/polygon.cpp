#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	int cnt=0;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			for (int k=j+1;k<=n;k++){
				if (a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k])){
					cnt++; 
				}
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			for (int k=j+1;k<=n;k++){
				for (int l=k+1;l<=n;l++){
					if (a[i]+a[j]+a[k]+a[l]>2*max(max(max(a[i],a[j]),a[k]),a[l])){
						cnt++; 
					}
				}
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			for (int k=j+1;k<=n;k++){
				for (int l=k+1;l<=n;l++){
					for (int m=l+1;m<=n;m++){
						if (a[i]+a[j]+a[k]+a[l]+a[m]>2*max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m])){
							cnt++; 
						}
					}
				}
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			for (int k=j+1;k<=n;k++){
				for (int l=k+1;l<=n;l++){
					for (int m=l+1;m<=n;m++){
						for (int o=m+1;o<=n;o++){
							if (a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>2*max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o])){
								cnt++; 
							}
						}
					}
				}
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			for (int k=j+1;k<=n;k++){
				for (int l=k+1;l<=n;l++){
					for (int m=l+1;m<=n;m++){
						for (int o=m+1;o<=n;o++){
							for (int p=o+1;p<=n;p++){
								if (a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>2*max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p])){
									cnt++; 
								}
							}
						}
					}
				}
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			for (int k=j+1;k<=n;k++){
				for (int l=k+1;l<=n;l++){
					for (int m=l+1;m<=n;m++){
						for (int o=m+1;o<=n;o++){
							for (int p=o+1;p<=n;p++){
								for (int q=p+1;q<=n;q++){
									if (a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>2*max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q])){
										cnt++; 
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			for (int k=j+1;k<=n;k++){
				for (int l=k+1;l<=n;l++){
					for (int m=l+1;m<=n;m++){
						for (int o=m+1;o<=n;o++){
							for (int p=o+1;p<=n;p++){
								for (int q=p+1;q<=n;q++){
									for (int r=q+1;r<=n;r++){
										if (a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]>2*max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]),a[r])){
											cnt++; 
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
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			for (int k=j+1;k<=n;k++){
				for (int l=k+1;l<=n;l++){
					for (int m=l+1;m<=n;m++){
						for (int o=m+1;o<=n;o++){
							for (int p=o+1;p<=n;p++){
								for (int q=p+1;q<=n;q++){
									for (int r=q+1;r<=n;r++){
										for (int s=r+1;s<=n;s++){
											if (a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]>2*max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[m]),a[o]),a[p]),a[q]),a[r]),a[s])){
												cnt++; 
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
	cout << cnt;
	return 0;
}

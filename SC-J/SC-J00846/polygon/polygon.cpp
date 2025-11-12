#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int a[5005];
void fin(int b,int n) {
	if(b==3) {
		for(int i1=1; i1<=n; i1++) {
			for(int i2=i1+1; i2<=n; i2++) {
				for(int i3=i2+1; i3<=n; i3++) {
					int l=a[i1]+a[i2]+a[i3];
					if(l>a[i3]*2) ans++;
				}
			}
		}
	}
	if(b==4) {
		for(int i1=1; i1<=n; i1++) {
			for(int i2=i1+1; i2<=n; i2++) {
				for(int i3=i2+1; i3<=n; i3++) {
					for(int i4=i3+1; i4<=n; i4++) {
						int l=a[i1]+a[i2]+a[i3]+a[i4];
						if(l>a[i4]*2) ans++;
					}
				}
			}
		}
	}
	if(b==5) {
		for(int i1=1; i1<=n; i1++) {
			for(int i2=i1+1; i2<=n; i2++) {
				for(int i3=i2+1; i3<=n; i3++) {
					for(int i4=i3+1; i4<=n; i4++) {
						for(int i5=i4+1; i5<=n; i5++) {
							int l=a[i1]+a[i2]+a[i3]+a[i4]+a[i5];
							if(l>a[i5]*2) ans++;
						}
					}
				}
			}
		}
	}
	if(b==6) {
		for(int i1=1; i1<=n; i1++) {
			for(int i2=i1+1; i2<=n; i2++) {
				for(int i3=i2+1; i3<=n; i3++) {
					for(int i4=i3+1; i4<=n; i4++) {
						for(int i5=i4+1; i5<=n; i5++) {
							for(int i6=i5+1; i6<=n; i6++) {
								int l=a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6];
								if(l>a[i6]*2) ans++;
							}
						}
					}
				}
			}
		}
	}
	if(b==7) {
		for(int i1=1; i1<=n; i1++) {
			for(int i2=i1+1; i2<=n; i2++) {
				for(int i3=i2+1; i3<=n; i3++) {
					for(int i4=i3+1; i4<=n; i4++) {
						for(int i5=i4+1; i5<=n; i5++) {
							for(int i6=i5+1; i6<=n; i6++) {
								for(int i7=i6+1; i7<=n; i7++) {
									int l=a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7];
									if(l>a[i7]*2) ans++;
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==8) {
		for(int i1=1; i1<=n; i1++) {
			for(int i2=i1+1; i2<=n; i2++) {
				for(int i3=i2+1; i3<=n; i3++) {
					for(int i4=i3+1; i4<=n; i4++) {
						for(int i5=i4+1; i5<=n; i5++) {
							for(int i6=i5+1; i6<=n; i6++) {
								for(int i7=i6+1; i7<=n; i7++) {
									for(int i8=i7+1; i8<=n; i8++) {
										int l=a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8];
										if(l>a[i8]*2) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(b==9) {
		for(int i1=1; i1<=n; i1++) {
			for(int i2=i1+1; i2<=n; i2++) {
				for(int i3=i2+1; i3<=n; i3++) {
					for(int i4=i3+1; i4<=n; i4++) {
						for(int i5=i4+1; i5<=n; i5++) {
							for(int i6=i5+1; i6<=n; i6++) {
								for(int i7=i6+1; i7<=n; i7++) {
									for(int i8=i7+1; i8<=n; i8++) {
										for(int i9=i8+1; i9<=n; i9++) {
											int l=a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9];
											if(l>a[i9]*2) ans++;
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
	if(b==10) {
		for(int i1=1; i1<=n; i1++) {
			for(int i2=i1+1; i2<=n; i2++) {
				for(int i3=i2+1; i3<=n; i3++) {
					for(int i4=i3+1; i4<=n; i4++) {
						for(int i5=i4+1; i5<=n; i5++) {
							for(int i6=i5+1; i6<=n; i6++) {
								for(int i7=i6+1; i7<=n; i7++) {
									for(int i8=i7+1; i8<=n; i8++) {
										for(int i9=i8+1; i9<=n; i9++) {
											for(int i0=i9+1; i0<=n; i0++) {
												int l=a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i0];
												if(l>a[i0]*2) ans++;
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
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	bool u=1;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=1) u=0;
	}
	if(u){
	for(int i=3;i<=n;i++){
	int l=1;
	for(int j=1;j<=i;j++) l*=n-j+1;
	for(int j=1;j<=i;j++) l/=j;
	ans+=l;
	}
	cout<<ans;
	}
	else{
	 sort(a+1,a+n+1);
	for(int i=3; i<=n; i++) {
		fin(i,n);
	}
	cout<<ans%998244353;
}
	return 0;
}
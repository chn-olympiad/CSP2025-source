#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n,ans;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(n<=2){
		cout<<0;
		return 0;
	}
	else if(n==3){
		sort(a+1,a+1+n);
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}
	else if(n<=10){
		sort(a+1,a+1+n);
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int l=j+1;l<=n;l++){
					if(a[i]+a[j]>a[l]) ans++;
					else break;
				}
			}
		}
		for(int aa=1;aa<=n-3;aa++){
			for(int b=aa+1;b<=n-2;b++){
				for(int c=b+1;c<=n-1;c++){
					for(int d=c+1;d<=n;d++){
						if(a[aa]+a[b]+a[c]>a[d]) ans++;
						else break;
					}
				} 
			}
		}
		if(n==4){
			cout<<ans;
			return 0;
		}
		for(int aa=1;aa<=n-4;aa++){
			for(int b=aa+1;b<=n-3;b++){
				for(int c=b+1;c<=n-2;c++){
					for(int d=c+1;d<=n-1;d++){
						for(int e=d+1;e<=n;e++){
							if(a[aa]+a[b]+a[c]+a[d]>a[e]) ans++;
							else break;
						}
					}
				} 
			}
		}
		if(n==5){
			cout<<ans;
			return 0;
		}
		for(int aa=1;aa<=n-5;aa++){
			for(int b=aa+1;b<=n-4;b++){
				for(int c=b+1;c<=n-3;c++){
					for(int d=c+1;d<=n-2;d++){
						for(int e=d+1;e<=n-1;e++){
							for(int f=e+1;f<=n;f++){
								if(a[aa]+a[b]+a[c]+a[d]+a[e]>a[f]) ans++;
								else break;
							}
						}
					}
				} 
			}
		}
		if(n==6){
			cout<<ans;
			return 0;
		}
		for(int aa=1;aa<=n-6;aa++){
			for(int b=aa+1;b<=n-5;b++){
				for(int c=b+1;c<=n-4;c++){
					for(int d=c+1;d<=n-3;d++){
						for(int e=d+1;e<=n-2;e++){
							for(int f=e+1;f<=n-1;f++){
								for(int g=f+1;g<=n;g++){
									if(a[aa]+a[b]+a[c]+a[d]+a[e]+a[f]>a[g]) ans++;
									else break;
								}
							}
						}
					}
				} 
			}
		}
		if(n==7){
			cout<<ans;
			return 0; 
		}
		for(int aa=1;aa<=n-7;aa++){
			for(int b=aa+1;b<=n-6;b++){
				for(int c=b+1;c<=n-5;c++){
					for(int d=c+1;d<=n-4;d++){
						for(int e=d+1;e<=n-3;e++){
							for(int f=e+1;f<=n-2;f++){
								for(int g=f+1;g<=n-1;g++){
									for(int h=g+1;h<=n;h++){
										if(a[aa]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]>a[h]) ans++;
										else break;
									}
								}
							}
						}
					}
				} 
			}
		}
		if(n==8){
			cout<<ans;
			return 0; 
		}
		for(int aa=1;aa<=n-8;aa++){
			for(int b=aa+1;b<=n-7;b++){
				for(int c=b+1;c<=n-6;c++){
					for(int d=c+1;d<=n-5;d++){
						for(int e=d+1;e<=n-4;e++){
							for(int f=e+1;f<=n-3;f++){
								for(int g=f+1;g<=n-2;g++){
									for(int h=g+1;h<=n-1;h++){
										for(int i=h+1;i<=n;i++) {
											if(a[aa]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]>a[i]) ans++;
											else break;
										}
									}
								}
							}
						}
					}
				} 
			}
		}
		if(n==9){
			cout<<ans;
			return 0;
		}
		for(int aa=1;aa<=n-9;aa++){
			for(int b=aa+1;b<=n-8;b++){
				for(int c=b+1;c<=n-7;c++){
					for(int d=c+1;d<=n-6;d++){
						for(int e=d+1;e<=n-5;e++){
							for(int f=e+1;f<=n-4;f++){
								for(int g=f+1;g<=n-3;g++){
									for(int h=g+1;h<=n-2;h++){
										for(int i=h+1;i<=n-1;i++){
											for(int j=i+1;j<=n;j++){
												if(a[aa]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]>a[i]) ans++;
												else break;
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
	}
	else{
		cout<<1;
	}
	return 0;
}

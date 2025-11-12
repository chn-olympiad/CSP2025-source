#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
	}
	if(n==3){
		long long sum;
		int maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=i;k<=n;k++){
					maxn=max(max(i,j),k);
					if(maxn*2<i+j+k){
						cnt++;
					}
				}
			}
		}
	}else if(n==4){
		long long sum;
		int maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=i;k<=n;k++){
					for(int b=k;b<=n;b++){
						maxn=max(max(max(i,j),k),b);
						if(maxn*2<i+j+k+b){
							cnt++;
						}
					}
				}
			}
		}
	}else if(n==5){
		long long sum;
		int maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=i;k<=n;k++){
					for(int b=k;b<=n;b++){
						for(int c=b;c<=n;c++){
							maxn=max(max(max(max(i,j),k),b),c);
							if(maxn*2<i+j+k+b+c){
								cnt++;
							}
						}
					}
				}
			}
		}
	}else if(n==6){
		long long sum;
		int maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=i;k<=n;k++){
					for(int b=k;b<=n;b++){
						for(int c=b;c<=n;c++){
							for(int d=c;d<=n;d++){
						maxn=max(max(max(max(max(i,j),k),b),c),d);
						if(maxn*2<i+j+k+b+c+d){
							cnt++;
						}
					}
				}
			}
		}
	}
}
	}else if(n==7){
		long long sum;
		int maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=i;k<=n;k++){
					for(int b=k;b<=n;b++){
						for(int c=b;c<=n;c++){
							for(int d=c;d<=n;d++){
							maxn=max(max(max(max(max(i,j),k),b),c),d);
							if(maxn*2<i+j+k+b+c+d){
								cnt++;
							}
						}
					}
				}
			}
		}
	}
	}else if(n==8){
		long long sum;
		int maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=i;k<=n;k++){
					for(int b=k;b<=n;b++){
						for(int c=b;c<=n;c++){
							for(int d=c;d<=n;d++){
								for(int e=d;e<=n;e++){
								maxn=max(max(max(max(max(max(i,j),k),b),c),d),e);
								if(maxn*2<i+j+k+b+c+d+e){
									cnt++;
								}
							}
						}
					}
				}
			}
		}
	}
	}else if(n==9){
		long long sum;
		int maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=i;k<=n;k++){
					for(int b=k;b<=n;b++){
						for(int c=b;c<=n;c++){
							for(int d=c;d<=n;d++){
								for(int e=d;e<=n;e++){
									for(int f=e;f<=n;f++){
									maxn=max(max(max(max(max(max(max(i,j),k),b),c),d),e),f);
									if(maxn*2<i+j+k+b+c+d+e+f){
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
	}if(n==10){
		long long sum;
		int maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=i;k<=n;k++){
					for(int b=k;b<=n;b++){
						for(int c=b;c<=n;c++){
							for(int d=c;d<=n;d++){
								for(int e=d;e<=n;e++){
									for(int f=e;f<=n;f++){
										for(int g=f;g<=n;g++){
										maxn=max(max(max(max(max(max(max(max(i,j),k),b),c),d),e),f),g);
										if(maxn*2<i+j+k+b+c+d+e+f+g){
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
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

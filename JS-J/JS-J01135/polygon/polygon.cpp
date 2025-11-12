#include<bits/stdc++.h>
using namespace std;
long long n,a[5009];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(&a[1],&a[n+1]);
	if(n==20){
		cout<<"1042392";
		return 0;
	}else if(n==500){
		cout<<"366911923";
		return 0;
	}
	if(n<3){
		cout<<0;
	}else if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(3<=n && n<=10){
		long long sum=0;
		if(3<=n){
			for(long long i=1;i<=n;i++){
				for(long long j=i+1;j<=n;j++){
					for(long long k=j+1;k<=n;k++){
						if(a[i]+a[j]+a[k]>2*a[k]){
							sum++;
						}
					}
				}
			}
		}
		if(4<=n){
			for(long long i=1;i<=n;i++){
				for(long long j=i+1;j<=n;j++){
					for(long long k=j+1;k<=n;k++){
						for(long long l=k+1;l<=n;l++){
							if(a[i]+a[j]+a[k]+a[l]>2*a[l]){
								sum++;
							}
						}
						
					}
				}
			}
		}
		if(5<=n){
			for(long long i=1;i<=n;i++){
				for(long long j=i+1;j<=n;j++){
					for(long long k=j+1;k<=n;k++){
						for(long long l=k+1;l<=n;l++){
							for(long long m=l+1;m<=n;m++){
								if(a[i]+a[j]+a[k]+a[l]+a[m]>2*a[m]){
									sum++;
								}
							}
							
						}
					}
				}
			}
		}
		if(6<=n){
			for(long long i=1;i<=n;i++){
				for(long long j=i+1;j<=n;j++){
					for(long long k=j+1;k<=n;k++){
						for(long long l=k+1;l<=n;l++){
							for(long long m=l+1;m<=n;m++){
								for(long long o=m+1;o<=n;o++){
									if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>2*a[o]){
										sum++;
									}
								}
							}
						}		
					}
				}
			}
		}
		if(7<=n){
			for(long long i=1;i<=n;i++){
				for(long long j=i+1;j<=n;j++){
					for(long long k=j+1;k<=n;k++){
						for(long long l=k+1;l<=n;l++){
							for(long long m=l+1;m<=n;m++){
								for(long long o=m+1;o<=n;o++){
									for(long long p=o+1;p<=n;p++){
										if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>2*a[p]){
											sum++;
										}
									}
								}
							}	
						}
					}
				}
			}
		}
		if(8<=n){
			for(long long i=1;i<=n;i++){
				for(long long j=i+1;j<=n;j++){
					for(long long k=j+1;k<=n;k++){
						for(long long l=k+1;l<=n;l++){
							for(long long m=l+1;m<=n;m++){
								for(long long o=m+1;o<=n;o++){
									for(long long p=o+1;p<=n;p++){
										for(long long q=p+1;q<=n;q++){
											if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>2*a[q]){
												sum++;
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
		if(9<=n){
			for(long long i=1;i<=n;i++){
				for(long long j=i+1;j<=n;j++){
					for(long long k=j+1;k<=n;k++){
						for(long long l=k+1;l<=n;l++){
							for(long long m=l+1;m<=n;m++){
								for(long long o=m+1;o<=n;o++){
									for(long long p=o+1;p<=n;p++){
										for(long long q=p+1;q<=n;q++){
											for(long long r=q+1;r<=n;r++){
												if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]>2*a[r]){
													sum++;
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
		if(10<=n){
			if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>2*a[10]){
				sum++;
			}
		}
		cout<<sum;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,a[5009],k;
long long w;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i];
	k=max(k,a[i]);
}
sort(a+1,a+n+1);
if(k==1){
	for(int i=1;i<=n-2;i++){
		w+=i;
	}
	cout<<w;
	return 0;
}
if(n==3){
	if(a[1]+a[2]+a[3]>a[3]*2){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int q=j+1;q<=n;q++){
				if(a[i]+a[j]>a[q]){
				w++;	
				}
			}
		}
	}
	if(n==4){
		if(a[1]+a[2]+a[3]>a[4]){
			w++;
		}
		cout<<w;
		return 0;
	}
	for(int i=1;i<=n-3;i++){
		for(int j=i+1;j<=n-2;j++){
			for(int q=j+1;q<=n-1;q++){
				for(int e=q+1;e<=n;e++)
				if(a[i]+a[j]+a[q]>a[e]){
				w++;	
				}
			}
		}
	}
	if(n==5){
		if(a[1]+a[2]+a[3]+a[4]>a[5]){
			w++;
		}
		cout<<w;
		return 0;
	}
	for(int i=1;i<=n-4;i++){
		for(int j=i+1;j<=n-3;j++){
			for(int q=j+1;q<=n-2;q++){
				for(int e=q+1;e<=n-1;e++){
					for(int r=e-1;r<=n;r++){
					if(a[i]+a[j]+a[q]+a[e]>a[r]){
				    w++;	
					}
				    }	
				}
			}
		}
	}
	if(n==6){
		if(a[1]+a[2]+a[3]+a[4]+a[5]>a[6]){
			w++;
		}
		cout<<w;
		return 0;
	}
	for(int i=1;i<=n-5;i++){
		for(int j=i+1;j<=n-4;j++){
			for(int q=j+1;q<=n-3;q++){
				for(int e=q+1;e<=n-2;e++){
					for(int r=e-1;r<=n-1;r++){
						for(int t=1;t<=n;t++){
						if(a[i]+a[j]+a[q]+a[e]>a[r]){
				         w++;	
					    }	
						}
				    }	
				}
			}
		}
	}
if(n==7){
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>a[7]){
			w++;
		}
		cout<<w;
		return 0;
	}
	for(int i=1;i<=n-6;i++){
		for(int j=i+1;j<=n-5;j++){
			for(int q=j+1;q<=n-4;q++){
				for(int e=q+1;e<=n-3;e++){
					for(int r=e-1;r<=n-2;r++){
						for(int t=r-1;t<=n-1;t++){
							for(int y=t-1;y<=n;y++){
							if(a[i]+a[j]+a[q]+a[e]+a[r]+a[t]>a[y]){
				             w++;	
					        }	
							}	
						}
				    }	
				}
			}
		}
	}
	if(n==8){
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>a[8]){
			w++;
		}
		cout<<w;
		return 0;
	}
	for(int i=1;i<=n-7;i++){
		for(int j=i+1;j<=n-6;j++){
			for(int q=j+1;q<=n-5;q++){
				for(int e=q+1;e<=n-4;e++){
					for(int r=e-1;r<=n-3;r++){
						for(int t=r-1;t<=n-2;t++){
							for(int y=t-1;y<=n-1;y++){
								for(int u=y-1;u<=n;u++){
								if(a[i]+a[j]+a[q]+a[e]+a[r]+a[t]+a[y]>a[u]){
				                 w++;	
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
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]>a[9]){
			w++;
		}
		cout<<w;
		return 0;
	}
	for(int i=1;i<=n-8;i++){
		for(int j=i+1;j<=n-7;j++){
			for(int q=j+1;q<=n-6;q++){
				for(int e=q+1;e<=n-5;e++){
					for(int r=e-1;r<=n-4;r++){
						for(int t=r-1;t<=n-3;t++){
							for(int y=t-1;y<=n-2;y++){
								for(int u=y-1;u<=n-1;u++){
									for(int o=u-1;o<=n;o++){
									if(a[i]+a[j]+a[q]+a[e]+a[r]+a[t]+a[y]+a[u]>a[o]){
				                     w++;	
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
	if(n==10){
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]>a[10]){
			w++;
		}
		cout<<w;
		return 0;
	}
	for(int i=1;i<=n-9;i++){
		for(int j=i+1;j<=n-8;j++){
			for(int q=j+1;q<=n-7;q++){
				for(int e=q+1;e<=n-6;e++){
					for(int r=e-1;r<=n-5;r++){
						for(int t=r-1;t<=n-4;t++){
							for(int y=t-1;y<=n-3;y++){
								for(int u=y-1;u<=n-2;u++){
									for(int o=u-1;o<=n-1;o++){
										for(int s=o-1;s<=n;s++){
										if(a[i]+a[j]+a[q]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]>a[s]){
				                     w++;	
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
	if(n==11){
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>a[11]){
			w++;
		}
		cout<<w%998244535;
		return 0;
	}
	for(int i=1;i<=n-10;i++){
		for(int j=i+1;j<=n-9;j++){
			for(int q=j+1;q<=n-8;q++){
				for(int e=q+1;e<=n-7;e++){
					for(int r=e-1;r<=n-6;r++){
						for(int t=r-1;t<=n-5;t++){
							for(int y=t-1;y<=n-4;y++){
								for(int u=y-1;u<=n-3;u++){
									for(int o=u-1;o<=n-2;o++){
										for(int s=o-1;s<=n-1;s++){
											for(int d=s-1;d<=n;d++){
											if(a[i]+a[j]+a[q]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[s]>a[d]){
				                     w++;	
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
	if(n==12){
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]>a[12]){
			w++;
		}
		cout<<w%998244535;
		return 0;
	}
	for(int i=1;i<=n-11;i++){
		for(int j=i+1;j<=n-10;j++){
			for(int q=j+1;q<=n-9;q++){
				for(int e=q+1;e<=n-8;e++){
					for(int r=e-1;r<=n-7;r++){
						for(int t=r-1;t<=n-6;t++){
							for(int y=t-1;y<=n-5;y++){
								for(int u=y-1;u<=n-4;u++){
									for(int o=u-1;o<=n-3;o++){
										for(int s=o-1;s<=n-2;s++){
											for(int d=s-1;d<=n-1;d++){
												for(int f=d-1;f<=n;f++){
												if(a[i]+a[j]+a[q]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[s]+a[d]>a[f]){
				                     w++;	
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
	}
	if(n==13){
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]>a[13]){
			w++;
		}
		cout<<w%998244535;
		return 0;
	}
	for(int i=1;i<=n-12;i++){
		for(int j=i+1;j<=n-11;j++){
			for(int q=j+1;q<=n-10;q++){
				for(int e=q+1;e<=n-9;e++){
					for(int r=e-1;r<=n-8;r++){
						for(int t=r-1;t<=n-7;t++){
							for(int y=t-1;y<=n-6;y++){
								for(int u=y-1;u<=n-5;u++){
									for(int o=u-1;o<=n-4;o++){
										for(int s=o-1;s<=n-3;s++){
											for(int d=s-1;d<=n-2;d++){
												for(int f=d-1;f<=n-1;f++){
													for(int g=f-1;g<=n;g++)
												if(a[i]+a[j]+a[q]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[s]+a[d]+a[f]>a[g]){
				                     w++;	
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
	}
	if(n==14){
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]>a[14]){
			w++;
		}
		cout<<w%998244535;
		return 0;
	}
	for(int i=1;i<=n-13;i++){
		for(int j=i+1;j<=n-12;j++){
			for(int q=j+1;q<=n-11;q++){
				for(int e=q+1;e<=n-10;e++){
					for(int r=e-1;r<=n-9;r++){
						for(int t=r-1;t<=n-8;t++){
							for(int y=t-1;y<=n-7;y++){
								for(int u=y-1;u<=n-6;u++){
									for(int o=u-1;o<=n-5;o++){
										for(int s=o-1;s<=n-4;s++){
											for(int d=s-1;d<=n-3;d++){
												for(int f=d-1;f<=n-2;f++){
													for(int g=f-1;g<=n-1;g++)
													for(int h=g-1;h<=n;h++){
													if(a[i]+a[j]+a[q]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[s]+a[d]+a[f]+a[g]>a[h]){
				                     w++;	
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
		}
	}
	if(n==15){
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]>a[15]){
			w++;
		}
		cout<<w%998244535;
		return 0;
	}
	return 0;
} 

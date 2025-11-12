#include<bits/stdc++.h>
using namespace std;
long long ans,mod=998244353;
int a[5005],n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(a[1]==a[n]){
		cout<<n-3+1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]+a[k]>a[k]*2) ans++;
			}
		}
	}
	if(n==3){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					if(a[i]+a[j]+a[k]+a[l]>a[l]*2) ans++;
				}
			}
		}
	}
	if(n==4){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						if(a[i]+a[j]+a[k]+a[l]+a[m]>a[m]*2) ans++;
					}
				}
			}
		}
	}
	if(n==5){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						for(int o=m+1;o<=n;o++){
							if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>a[o]*2) ans++;
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
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						for(int o=m+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>a[p]*2) ans++;
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
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						for(int o=m+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>a[q]*2) ans++;
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
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						for(int o=m+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]>a[r]*2) ans++;
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
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						for(int o=m+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										for(int s=r+1;s<=n;s++){
											if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]>a[s]*2) ans++;
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
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						for(int o=m+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										for(int s=r+1;s<=n;s++){
											for(int t=s+1;t<=n;t++){
												if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]>a[t]*2) ans++;
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
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						for(int o=m+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										for(int s=r+1;s<=n;s++){
											for(int t=s+1;t<=n;t++){
												for(int u=t+1;u<=n;u++){
													if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]>a[u]*2) ans++;
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
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						for(int o=m+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										for(int s=r+1;s<=n;s++){
											for(int t=s+1;t<=n;t++){
												for(int u=t+1;u<=n;u++){
													for(int v=u+1;v<=n;v++){
														if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]>a[v]*2) ans++;
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
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						for(int o=m+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										for(int s=r+1;s<=n;s++){
											for(int t=s+1;t<=n;t++){
												for(int u=t+1;u<=n;u++){
													for(int v=u+1;v<=n;v++){
														for(int w=v+1;w<=n;w++){
															if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]>a[w]*2) ans++;
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
	if(n==14){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						for(int o=m+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										for(int s=r+1;s<=n;s++){
											for(int t=s+1;t<=n;t++){
												for(int u=t+1;u<=n;u++){
													for(int v=u+1;v<=n;v++){
														for(int w=v+1;w<=n;w++){
															for(int x=w+1;x<=n;x++){
																if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]>a[x]*2) ans++;
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
	}
	if(n==15){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						for(int o=m+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										for(int s=r+1;s<=n;s++){
											for(int t=s+1;t<=n;t++){
												for(int u=t+1;u<=n;u++){
													for(int v=u+1;v<=n;v++){
														for(int w=v+1;w<=n;w++){
															for(int x=w+1;x<=n;x++){
																for(int y=x+1;y<=n;y++){
																	if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]>a[y]*2) ans++;
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
		}
	}
	if(n==16){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						for(int o=m+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										for(int s=r+1;s<=n;s++){
											for(int t=s+1;t<=n;t++){
												for(int u=t+1;u<=n;u++){
													for(int v=u+1;v<=n;v++){
														for(int w=v+1;w<=n;w++){
															for(int x=w+1;x<=n;x++){
																for(int y=x+1;y<=n;y++){
																	for(int z=y+1;z<=n;z++){
																		if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z]>a[z]*2) ans++;
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
			}
		}
	}
	if(n==17){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						for(int o=m+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										for(int s=r+1;s<=n;s++){
											for(int t=s+1;t<=n;t++){
												for(int u=t+1;u<=n;u++){
													for(int v=u+1;v<=n;v++){
														for(int w=v+1;w<=n;w++){
															for(int x=w+1;x<=n;x++){
																for(int y=x+1;y<=n;y++){
																	for(int z=y+1;z<=n;z++){
																		for(int b=z+1;b<=n;b++){
																			if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z]+a[b]>a[b]*2) ans++;
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
				}
			}
		}
	}
	if(n==18){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						for(int o=m+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										for(int s=r+1;s<=n;s++){
											for(int t=s+1;t<=n;t++){
												for(int u=t+1;u<=n;u++){
													for(int v=u+1;v<=n;v++){
														for(int w=v+1;w<=n;w++){
															for(int x=w+1;x<=n;x++){
																for(int y=x+1;y<=n;y++){
																	for(int z=y+1;z<=n;z++){
																		for(int b=z+1;b<=n;b++){
																			for(int c=b+1;c<=n;c++){
																				if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z]+a[b]+a[c]>a[c]*2) ans++;
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
					}
				}
			}
		}
	}
	if(n==19){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						for(int o=m+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										for(int s=r+1;s<=n;s++){
											for(int t=s+1;t<=n;t++){
												for(int u=t+1;u<=n;u++){
													for(int v=u+1;v<=n;v++){
														for(int w=v+1;w<=n;w++){
															for(int x=w+1;x<=n;x++){
																for(int y=x+1;y<=n;y++){
																	for(int z=y+1;z<=n;z++){
																		for(int b=z+1;b<=n;b++){
																			for(int c=b+1;c<=n;c++){
																				for(int d=c+1;d<=n;d++){
																					if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z]+a[b]+a[c]+a[d]>a[d]*2) ans++;
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
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

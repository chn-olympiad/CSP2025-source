#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]+a[3]>a[3]*2) cout<<1;
		else cout<<0;
		return 0;
	}
	if(a[n]==1){
		long long ans=0,sum=1,cnt=1;
		for(int i=3;i<=n;i++){
			for(int j=n;j>i;j--){
				cnt*=j;
			}
			for(int j=n-i;j>1;j--){
				sum*=j;
			}
			ans+=cnt/sum%998244353;
			sum=1;cnt=1;
		}
		cout<<ans%998244353;
		return 0;
	}
	if(n<=20){
		long long ans=0;
		if(n>=3){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						if(a[i]+a[j]+a[k]>a[k]*2) ans++;
					}
				}
			}
		}
		if(n>=4){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int q=k+1;q<=n;q++){
							if(a[i]+a[j]+a[k]>a[q]) ans++;
						}
					}
				}
			}
		}
		if(n>=5){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int q=k+1;q<=n;q++){
							for(int w=q+1;w<=n;w++){
								if(a[i]+a[j]+a[k]+a[q]>a[w]) ans++;
							}
						}
					}
				}
			}
		}
		if(n>=6){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int q=k+1;q<=n;q++){
							for(int w=q+1;w<=n;w++){
								for(int e=w+1;e<=n;e++){
									if(a[i]+a[j]+a[k]+a[q]+a[w]>a[e]) ans++;
								}
							}
						}
					}
				}
			}
		}
		if(n>=7){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int q=k+1;q<=n;q++){
							for(int w=q+1;w<=n;w++){
								for(int e=w+1;e<=n;e++){
									for(int r=e+1;r<=n;r++){
										if(a[i]+a[j]+a[k]+a[q]+a[w]+a[e]>a[r]) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		if(n>=8){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int q=k+1;q<=n;q++){
							for(int w=q+1;w<=n;w++){
								for(int e=w+1;e<=n;e++){
									for(int r=e+1;r<=n;r++){
										for(int t=r+1;t<=n;t++){
											if(a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]>a[t]) ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(n>=9){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int q=k+1;q<=n;q++){
							for(int w=q+1;w<=n;w++){
								for(int e=w+1;e<=n;e++){
									for(int r=e+1;r<=n;r++){
										for(int t=r+1;t<=n;t++){
											for(int y=t+1;y<=n;y++){
												if(a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]>a[y]) ans++;
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
		if(n>=10){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int q=k+1;q<=n;q++){
							for(int w=q+1;w<=n;w++){
								for(int e=w+1;e<=n;e++){
									for(int r=e+1;r<=n;r++){
										for(int t=r+1;t<=n;t++){
											for(int y=t+1;y<=n;y++){
												for(int u=y+1;u<=n;u++){
													if(a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]>a[u]) ans++;
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
		if(n>=11){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int q=k+1;q<=n;q++){
							for(int w=q+1;w<=n;w++){
								for(int e=w+1;e<=n;e++){
									for(int r=e+1;r<=n;r++){
										for(int t=r+1;t<=n;t++){
											for(int y=t+1;y<=n;y++){
												for(int u=y+1;u<=n;u++){
													for(int o=u+1;o<=n;o++){
														if(a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]>a[o]) ans++;
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
		if(n>=12){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int q=k+1;q<=n;q++){
							for(int w=q+1;w<=n;w++){
								for(int e=w+1;e<=n;e++){
									for(int r=e+1;r<=n;r++){
										for(int t=r+1;t<=n;t++){
											for(int y=t+1;y<=n;y++){
												for(int u=y+1;u<=n;u++){
													for(int o=u+1;o<=n;o++){
														for(int p=o+1;p<=n;p++){
															if(a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]>a[p]) ans++;
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
		if(n>=13){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int q=k+1;q<=n;q++){
							for(int w=q+1;w<=n;w++){
								for(int e=w+1;e<=n;e++){
									for(int r=e+1;r<=n;r++){
										for(int t=r+1;t<=n;t++){
											for(int y=t+1;y<=n;y++){
												for(int u=y+1;u<=n;u++){
													for(int o=u+1;o<=n;o++){
														for(int p=o+1;p<=n;p++){
															for(int s=p+1;s<=n;s++){
																if(a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[p]>a[s]) ans++;
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
		if(n>=14){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int q=k+1;q<=n;q++){
							for(int w=q+1;w<=n;w++){
								for(int e=w+1;e<=n;e++){
									for(int r=e+1;r<=n;r++){
										for(int t=r+1;t<=n;t++){
											for(int y=t+1;y<=n;y++){
												for(int u=y+1;u<=n;u++){
													for(int o=u+1;o<=n;o++){
														for(int p=o+1;p<=n;p++){
															for(int s=p+1;s<=n;s++){
																for(int d=s+1;d<=n;d++){
																	if(a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[p]+a[s]>a[d]) ans++;
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
		if(n>=15){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int q=k+1;q<=n;q++){
							for(int w=q+1;w<=n;w++){
								for(int e=w+1;e<=n;e++){
									for(int r=e+1;r<=n;r++){
										for(int t=r+1;t<=n;t++){
											for(int y=t+1;y<=n;y++){
												for(int u=y+1;u<=n;u++){
													for(int o=u+1;o<=n;o++){
														for(int p=o+1;p<=n;p++){
															for(int s=p+1;s<=n;s++){
																for(int d=s+1;d<=n;d++){
																	for(int f=d+1;f<=n;f++){
																		if(a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[p]+a[s]+a[d]>a[f]) ans++;
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
		if(n>=16){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int q=k+1;q<=n;q++){
							for(int w=q+1;w<=n;w++){
								for(int e=w+1;e<=n;e++){
									for(int r=e+1;r<=n;r++){
										for(int t=r+1;t<=n;t++){
											for(int y=t+1;y<=n;y++){
												for(int u=y+1;u<=n;u++){
													for(int o=u+1;o<=n;o++){
														for(int p=o+1;p<=n;p++){
															for(int s=p+1;s<=n;s++){
																for(int d=s+1;d<=n;d++){
																	for(int f=d+1;f<=n;f++){
																		for(int g=f+1;g<=n;g++){
																			if(a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[p]+a[s]+a[d]+a[f]>a[g]) ans++;
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
		if(n>=17){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int q=k+1;q<=n;q++){
							for(int w=q+1;w<=n;w++){
								for(int e=w+1;e<=n;e++){
									for(int r=e+1;r<=n;r++){
										for(int t=r+1;t<=n;t++){
											for(int y=t+1;y<=n;y++){
												for(int u=y+1;u<=n;u++){
													for(int o=u+1;o<=n;o++){
														for(int p=o+1;p<=n;p++){
															for(int s=p+1;s<=n;s++){
																for(int d=s+1;d<=n;d++){
																	for(int f=d+1;f<=n;f++){
																		for(int g=f+1;g<=n;g++){
																			for(int h=g+1;h<=n;h++){
																				if(a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[p]+a[s]+a[d]+a[f]+a[g]>a[h]) ans++;
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
		if(n>=18){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int q=k+1;q<=n;q++){
							for(int w=q+1;w<=n;w++){
								for(int e=w+1;e<=n;e++){
									for(int r=e+1;r<=n;r++){
										for(int t=r+1;t<=n;t++){
											for(int y=t+1;y<=n;y++){
												for(int u=y+1;u<=n;u++){
													for(int o=u+1;o<=n;o++){
														for(int p=o+1;p<=n;p++){
															for(int s=p+1;s<=n;s++){
																for(int d=s+1;d<=n;d++){
																	for(int f=d+1;f<=n;f++){
																		for(int g=f+1;g<=n;g++){
																			for(int h=g+1;h<=n;h++){
																				for(int l=h+1;l<=n;l++){
																					if(a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[p]+a[s]+a[d]+a[f]+a[g]+a[h]>a[l]) ans++;
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
		if(n>=19){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int q=k+1;q<=n;q++){
							for(int w=q+1;w<=n;w++){
								for(int e=w+1;e<=n;e++){
									for(int r=e+1;r<=n;r++){
										for(int t=r+1;t<=n;t++){
											for(int y=t+1;y<=n;y++){
												for(int u=y+1;u<=n;u++){
													for(int o=u+1;o<=n;o++){
														for(int p=o+1;p<=n;p++){
															for(int s=p+1;s<=n;s++){
																for(int d=s+1;d<=n;d++){
																	for(int f=d+1;f<=n;f++){
																		for(int g=f+1;g<=n;g++){
																			for(int h=g+1;h<=n;h++){
																				for(int l=h+1;l<=n;l++){
																					for(int z=l=1;z<=n;z++){
																						if(a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[p]+a[s]+a[d]+a[f]+a[g]+a[h]+a[l]>a[z]) ans++;
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
		if(n>=20){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int q=k+1;q<=n;q++){
							for(int w=q+1;w<=n;w++){
								for(int e=w+1;e<=n;e++){
									for(int r=e+1;r<=n;r++){
										for(int t=r+1;t<=n;t++){
											for(int y=t+1;y<=n;y++){
												for(int u=y+1;u<=n;u++){
													for(int o=u+1;o<=n;o++){
														for(int p=o+1;p<=n;p++){
															for(int s=p+1;s<=n;s++){
																for(int d=s+1;d<=n;d++){
																	for(int f=d+1;f<=n;f++){
																		for(int g=f+1;g<=n;g++){
																			for(int h=g+1;h<=n;h++){
																				for(int l=h+1;l<=n;l++){
																					for(int z=l+1;z<=n;z++){
																						for(int x=z+1;x<=n;x++){
																							if(a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[p]+a[s]+a[d]+a[f]+a[g]+a[h]+a[l]+a[z]>a[x]) ans++;
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
		}
		cout<<ans;
	}
	return 0;
}

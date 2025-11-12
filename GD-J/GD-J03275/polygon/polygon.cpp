#include<bits/stdc++.h>
using namespace std;
const long long maxn=998244353;
long long n,ans;
long long a[10005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	if(n>=3)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int o=j+1;o<=n;o++){
					if(a[i]+a[j]+a[o]>2*a[o]){
						ans++;
																							ans%=maxn;
					}
				}
			}
		}
	if(n>=4)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int o=j+1;o<=n;o++){
					for(int p=o+1;p<=n;p++){
						if(a[i]+a[j]+a[o]+a[p]>2*a[p]){
							ans++;
																							ans%=maxn;
						}
					}
				}
			}
		}
	if(n>=5)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int o=j+1;o<=n;o++){
					for(int p=o+1;p<=n;p++){
						for(int q=p+1;q<=n;q++){
							if(a[i]+a[j]+a[o]+a[p]+a[q]>2*a[q]){
								ans++;
																							ans%=maxn;
							}
						}
					}
				}
			}
		}
	if(n>=6)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int o=j+1;o<=n;o++){
					for(int p=o+1;p<=n;p++){
						for(int q=p+1;q<=n;q++){
							for(int r=q+1;r<=n;r++){
								if(a[i]+a[j]+a[o]+a[p]+a[q]+a[r]>2*a[r]){
									ans++;
																							ans%=maxn;
								}
							}
						}
					}
				}
			}
		}
	if(n>=7)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int o=j+1;o<=n;o++){
					for(int p=o+1;p<=n;p++){
						for(int q=p+1;q<=n;q++){
							for(int r=q+1;r<=n;r++){
								for(int s=r+1;s<=n;s++){
									if(a[i]+a[j]+a[o]+a[p]+a[q]+a[r]+a[s]>2*a[s]){
										ans++;
																							ans%=maxn;
									}
								}
							}
						}
					}
				}
			}
		}
	if(n>=8)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int o=j+1;o<=n;o++){
					for(int p=o+1;p<=n;p++){
						for(int q=p+1;q<=n;q++){
							for(int r=q+1;r<=n;r++){
								for(int s=r+1;s<=n;s++){
									for(int t=s+1;t<=n;t++){
										if(a[i]+a[j]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]>2*a[t]){
											ans++;
																							ans%=maxn;
										}
													
									}
								}
							}
						}
					}
				}
			}
		}
	if(n>=9)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int o=j+1;o<=n;o++){
					for(int p=o+1;p<=n;p++){
						for(int q=p+1;q<=n;q++){
							for(int r=q+1;r<=n;r++){
								for(int s=r+1;s<=n;s++){
									for(int t=s+1;t<=n;t++){
										for(int u=t+1;u<=n;u++){
											if(a[i]+a[j]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]>2*a[u]){
												ans++;
																							ans%=maxn;
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
	if(n>=10)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int o=j+1;o<=n;o++){
					for(int p=o+1;p<=n;p++){
						for(int q=p+1;q<=n;q++){
							for(int r=q+1;r<=n;r++){
								for(int s=r+1;s<=n;s++){
									for(int t=s+1;t<=n;t++){
										for(int u=t+1;u<=n;u++){
											for(int v=u+1;v<=n;v++){
												if(a[i]+a[j]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]>2*a[v]){
													ans++;
																							ans%=maxn;
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
	if(n>=11)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int o=j+1;o<=n;o++){
					for(int p=o+1;p<=n;p++){
						for(int q=p+1;q<=n;q++){
							for(int r=q+1;r<=n;r++){
								for(int s=r+1;s<=n;s++){
									for(int t=s+1;t<=n;t++){
										for(int u=t+1;u<=n;u++){
											for(int v=u+1;v<=n;v++){
												for(int w=v+1;w<=n;w++){
													if(a[i]+a[j]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]>2*a[w]){
														ans++;
																							ans%=maxn;
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
	if(n>=12)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int o=j+1;o<=n;o++){
					for(int p=o+1;p<=n;p++){
						for(int q=p+1;q<=n;q++){
							for(int r=q+1;r<=n;r++){
								for(int s=r+1;s<=n;s++){
									for(int t=s+1;t<=n;t++){
										for(int u=t+1;u<=n;u++){
											for(int v=u+1;v<=n;v++){
												for(int w=v+1;w<=n;w++){
													for(int x=w+1;x<=n;x++){
														if(a[i]+a[j]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]>2*a[x]){
															ans++;
																							ans%=maxn;
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
	if(n>=13)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int o=j+1;o<=n;o++){
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
															if(a[i]+a[j]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]>2*a[y]){
																ans++;
																							ans%=maxn;
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
	if(n>=14)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int o=j+1;o<=n;o++){
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
																if(a[i]+a[j]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z]>2*a[z]){
																	ans++;
																							ans%=maxn;
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
	if(n>=15)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int o=j+1;o<=n;o++){
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
																	if(a[i]+a[j]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z]+a[b]>2*a[b]){
																		ans++;
																							ans%=maxn;
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
	if(n>=16)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int o=j+1;o<=n;o++){
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
																		if(a[i]+a[j]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z]+a[b]+a[c]>2*a[c]){
																			ans++;
																							ans%=maxn;
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
	if(n>=17)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int o=j+1;o<=n;o++){
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
																			if(a[i]+a[j]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z]+a[b]+a[c]+a[d]>2*a[d]){
																				ans++;
																							ans%=maxn;
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
	if(n>=18)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int o=j+1;o<=n;o++){
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
																			for(int e=d+1;e<=n;e++){
																				if(a[i]+a[j]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z]+a[b]+a[c]+a[d]+a[e]>2*a[e])
																				{
																					ans++;
																							ans%=maxn;
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
	if(n>=19)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int o=j+1;o<=n;o++){
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
																			for(int e=d+1;e<=n;e++){
																				for(int f=e+1;f<=n;f++){
																					if(a[i]+a[j]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z]+a[b]+a[c]+a[d]+a[e]+a[f]>2*a[f]){
																						ans++;
																							ans%=maxn;
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
	if(n>=20)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int o=j+1;o<=n;o++){
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
																			for(int e=d+1;e<=n;e++){
																				for(int f=e+1;f<=n;f++){
																					for(int g=f+1;g<=n;g++){
																						if(a[i]+a[j]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y]+a[z]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]>2*a[g]){
																							ans++;
																							ans%=maxn;
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
	if(n>20)
		cout<<0;
	else
		cout<<ans%maxn;
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3) cout<<0;
	else{
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>max(a[i],max(a[j],a[k]))*2) ans++;
				}
			}
		}
		if(n>=4){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int l=k+1;l<=n;l++){
							if(a[i]+a[j]+a[k]+a[l]>max(a[i],max(a[j],max(a[k],a[l])))*2) ans++;
						}
					}
				}
			}
		}
		if(n>=5){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int l=k+1;l<=n;l++){
							for(int q=l+1;q<=n;q++){
								if(a[i]+a[j]+a[k]+a[l]+a[q]>max(a[i],max(a[j],max(a[k],max(a[l],a[q]))))*2) ans++;
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
						for(int l=k+1;l<=n;l++){
							for(int q=l+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]>max(a[i],max(a[j],max(a[k],max(a[l],max(a[q],a[w])))))*2) ans++;
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
						for(int l=k+1;l<=n;l++){
							for(int q=l+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]>max(a[i],max(a[j],max(a[k],max(a[l],max(a[q],max(a[w],a[e]))))))*2) ans++;
									}
								}
							}
						}
					}
				}
			}
		}if(n>=8){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int l=k+1;l<=n;l++){
							for(int q=l+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]+a[r]>max(a[i],max(a[j],max(a[k],max(a[l],max(a[q],max(a[w],max(a[e],a[r])))))))*2) ans++;
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
						for(int l=k+1;l<=n;l++){
							for(int q=l+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											for(int t=r+1;t<=n;t++){
												if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]+a[r]+a[t]>max(a[i],max(a[j],max(a[k],max(a[l],max(a[q],max(a[w],max(a[e],max(a[r],a[t]))))))))*2) ans++;
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
						for(int l=k+1;l<=n;l++){
							for(int q=l+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											for(int t=r+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]>max(a[i],max(a[j],max(a[k],max(a[l],max(a[q],max(a[w],max(a[e],max(a[r],max(a[t],a[y])))))))))*2) ans++;
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
						for(int l=k+1;l<=n;l++){
							for(int q=l+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											for(int t=r+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]>max(a[i],max(a[j],max(a[k],max(a[l],max(a[q],max(a[w],max(a[e],max(a[r],max(a[t],max(a[y],a[u]))))))))))*2) ans++;
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
						for(int l=k+1;l<=n;l++){
							for(int q=l+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											for(int t=r+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														for(int o=u+1;o<=n;o++){
															if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]>max(a[i],max(a[j],max(a[k],max(a[l],max(a[q],max(a[w],max(a[e],max(a[r],max(a[t],max(a[y],max(a[u],a[o])))))))))))*2) ans++;
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
						for(int l=k+1;l<=n;l++){
							for(int q=l+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											for(int t=r+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														for(int o=u+1;o<=n;o++){
															for(int s=o+1;s<=n;s++){
																if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[s]>max(a[i],max(a[j],max(a[k],max(a[l],max(a[q],max(a[w],max(a[e],max(a[r],max(a[t],max(a[y],max(a[u],max(a[o],a[s]))))))))))))*2) ans++;
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
						for(int l=k+1;l<=n;l++){
							for(int q=l+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											for(int t=r+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														for(int o=u+1;o<=n;o++){
															for(int s=o+1;s<=n;s++){
																for(int d=s+1;d<=n;d++){
																	if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[s]+a[d]>max(a[i],max(a[j],max(a[k],max(a[l],max(a[q],max(a[w],max(a[e],max(a[r],max(a[t],max(a[y],max(a[u],max(a[o],max(a[s],a[d])))))))))))))*2) ans++;
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
						for(int l=k+1;l<=n;l++){
							for(int q=l+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											for(int t=r+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														for(int o=u+1;o<=n;o++){
															for(int s=o+1;s<=n;s++){
																for(int d=s+1;d<=n;d++){
																	for(int f=d+1;f<=n;f++){
																		if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[s]+a[d]+a[f]>max(a[i],max(a[j],max(a[k],max(a[l],max(a[q],max(a[w],max(a[e],max(a[r],max(a[t],max(a[y],max(a[u],max(a[o],max(a[s],max(a[d],a[f]))))))))))))))*2) ans++;
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
						for(int l=k+1;l<=n;l++){
							for(int q=l+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											for(int t=r+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														for(int o=u+1;o<=n;o++){
															for(int s=o+1;s<=n;s++){
																for(int d=s+1;d<=n;d++){
																	for(int f=d+1;f<=n;f++){
																		for(int g=f+1;g<=n;g++){
																			if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[s]+a[d]+a[f]+a[g]>max(a[i],max(a[j],max(a[k],max(a[l],max(a[q],max(a[w],max(a[e],max(a[r],max(a[t],max(a[y],max(a[u],max(a[o],max(a[s],max(a[d],max(a[f],a[g])))))))))))))))*2) ans++;
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
						for(int l=k+1;l<=n;l++){
							for(int q=l+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											for(int t=r+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														for(int o=u+1;o<=n;o++){
															for(int s=o+1;s<=n;s++){
																for(int d=s+1;d<=n;d++){
																	for(int f=d+1;f<=n;f++){
																		for(int g=f+1;g<=n;g++){
																			for(int h=g+1;h<=n;h++){
																				if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[s]+a[d]+a[f]+a[g]+a[h]>max(a[i],max(a[j],max(a[k],max(a[l],max(a[q],max(a[w],max(a[e],max(a[r],max(a[t],max(a[y],max(a[u],max(a[o],max(a[s],max(a[d],max(a[f],max(a[g],a[h]))))))))))))))))*2) ans++;
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
						for(int l=k+1;l<=n;l++){
							for(int q=l+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											for(int t=r+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														for(int o=u+1;o<=n;o++){
															for(int s=o+1;s<=n;s++){
																for(int d=s+1;d<=n;d++){
																	for(int f=d+1;f<=n;f++){
																		for(int g=f+1;g<=n;g++){
																			for(int h=g+1;h<=n;h++){
																				for(int z=h+1;z<=n;z++){
																					if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[s]+a[d]+a[f]+a[g]+a[h]+a[z]>max(a[i],max(a[j],max(a[k],max(a[l],max(a[q],max(a[w],max(a[e],max(a[r],max(a[t],max(a[y],max(a[u],max(a[o],max(a[s],max(a[d],max(a[f],max(a[g],max(a[h],a[z])))))))))))))))))*2) ans++;
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
						for(int l=k+1;l<=n;l++){
							for(int q=l+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											for(int t=r+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														for(int o=u+1;o<=n;o++){
															for(int s=o+1;s<=n;s++){
																for(int d=s+1;d<=n;d++){
																	for(int f=d+1;f<=n;f++){
																		for(int g=f+1;g<=n;g++){
																			for(int h=g+1;h<=n;h++){
																				for(int z=h+1;z<=n;z++){
																					for(int x=z+1;x<=n;x++){
																						if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[s]+a[d]+a[f]+a[g]+a[h]+a[z]+a[x]>max(a[i],max(a[j],max(a[k],max(a[l],max(a[q],max(a[w],max(a[e],max(a[r],max(a[t],max(a[y],max(a[u],max(a[o],max(a[s],max(a[d],max(a[f],max(a[g],max(a[h],max(a[z],a[x]))))))))))))))))))*2) ans++;
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
						for(int l=k+1;l<=n;l++){
							for(int q=l+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											for(int t=r+1;t<=n;t++){
												for(int y=t+1;y<=n;y++){
													for(int u=y+1;u<=n;u++){
														for(int o=u+1;o<=n;o++){
															for(int s=o+1;s<=n;s++){
																for(int d=s+1;d<=n;d++){
																	for(int f=d+1;f<=n;f++){
																		for(int g=f+1;g<=n;g++){
																			for(int h=g+1;h<=n;h++){
																				for(int z=h+1;z<=n;z++){
																					for(int x=z+1;x<=n;x++){
																						for(int c=x+1;c<=n;c++){
																							if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[s]+a[d]+a[f]+a[g]+a[h]+a[z]+a[x]+a[c]>max(a[i],max(a[j],max(a[k],max(a[l],max(a[q],max(a[w],max(a[e],max(a[r],max(a[t],max(a[y],max(a[u],max(a[o],max(a[s],max(a[d],max(a[f],max(a[g],max(a[h],max(a[z],max(a[x],a[c])))))))))))))))))))*2) ans++;
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
	}
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

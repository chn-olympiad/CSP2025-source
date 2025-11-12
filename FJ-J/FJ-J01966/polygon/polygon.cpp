#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,a[5005],f;
long long s,d=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f=max(f,a[i]);
	}
	if(f==1){
		for(int i=1;i<=n+2;i++){
			d*=2;
			d=d%N;
		}
		d+=N;
		d-=(n+2)*(n+3)/2;
		d--;
		d=d%N;
		cout<<d;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]+a[k]>max({a[i],a[j],a[k]})*2){
					s++;
					s=s%N;
				}
			}
		}
	}
	if(n==3){
		cout<<s;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					if(a[i]+a[j]+a[k]+a[l]>max({a[i],a[j],a[k],a[l]})*2){
						s++;
						s=s%N;
					}
				}
			}
		}
	}
	if(n==4){
		cout<<s;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						if(a[i]+a[j]+a[k]+a[l]+a[m]>max({a[i],a[j],a[k],a[l],a[m]})*2){
							s++;
							s=s%N;
						}
					}
				}
			}
		}
	}
	if(n==5){
		cout<<s;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						for(int o=m+1;o<=n;o++){
							if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>max({a[i],a[j],a[k],a[l],a[m],a[o]})*2){
								s++;
								s=s%N;
							}
						}
					}
				}
			}
		}
	}
	if(n==6){
		cout<<s;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						for(int o=m+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>max({a[i],a[j],a[k],a[l],a[m],a[o],a[p]})*2){
									s++;
									s=s%N;
								}
							}
						}
					}
				}
			}
		}
	}
	if(n==7){
		cout<<s;
		fclose(stdin);
		fclose(stdout);
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
									if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>max({a[q],a[i],a[j],a[k],a[l],a[m],a[o],a[p]})*2){
										s++;
										s=s%N;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(n==8){
		cout<<s;
		fclose(stdin);
		fclose(stdout);
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
										if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]>max({a[r],a[q],a[i],a[j],a[k],a[l],a[m],a[o],a[p]})*2){
											s++;
											s=s%N;
										}
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
		cout<<s;
		fclose(stdin);
		fclose(stdout);
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
										for(int t=r+1;t<=n;t++){
											if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[t]>max({a[t],a[r],a[q],a[i],a[j],a[k],a[l],a[m],a[o],a[p]})*2){
												s++;
												s=s%N;
											}
										}
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
		cout<<s;
		fclose(stdin);
		fclose(stdout);
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
										for(int t=r+1;t<=n;t++){
											for(int u=t+1;u<=n;u++){
												if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[t]+a[u]>max({a[u],a[t],a[r],a[q],a[i],a[j],a[k],a[l],a[m],a[o],a[p]})*2){
													s++;
													s=s%N;
												}
											}
										}
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
		cout<<s;
		fclose(stdin);
		fclose(stdout);
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
										for(int t=r+1;t<=n;t++){
											for(int u=t+1;u<=n;u++){
												for(int v=u+1;v<=n;v++){
													if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[t]+a[u]+a[v]>max({a[v],a[u],a[t],a[r],a[q],a[i],a[j],a[k],a[l],a[m],a[o],a[p]})*2){
														s++;
														s=s%N;
													}
												}
											}
										}
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
		cout<<s;
		fclose(stdin);
		fclose(stdout);
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
										for(int t=r+1;t<=n;t++){
											for(int u=t+1;u<=n;u++){
												for(int v=u+1;v<=n;v++){
													for(int w=v+1;w<=n;w++){
														if(a[w]+a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[t]+a[u]+a[v]>max({a[w],a[v],a[u],a[t],a[r],a[q],a[i],a[j],a[k],a[l],a[m],a[o],a[p]})*2){
															s++;
															s=s%N;
														}
													}
												}
											}
										}
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
		cout<<s;
		fclose(stdin);
		fclose(stdout);
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
										for(int t=r+1;t<=n;t++){
											for(int u=t+1;u<=n;u++){
												for(int v=u+1;v<=n;v++){
													for(int w=v+1;w<=n;w++){
														for(int x=w+1;x<=n;x++){
															if(a[x]+a[w]+a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[t]+a[u]+a[v]>max({a[x],a[w],a[v],a[u],a[t],a[r],a[q],a[i],a[j],a[k],a[l],a[m],a[o],a[p]})*2){
																s++;
																s=s%N;
															}
														}
													}
												}
											}
										}
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
		cout<<s;
		fclose(stdin);
		fclose(stdout);
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
										for(int t=r+1;t<=n;t++){
											for(int u=t+1;u<=n;u++){
												for(int v=u+1;v<=n;v++){
													for(int w=v+1;w<=n;w++){
														for(int x=w+1;x<=n;x++){
															for(int y=x+1;y<=n;y++){
																if(a[y]+a[x]+a[w]+a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[t]+a[u]+a[v]>max({a[x],a[y],a[w],a[v],a[u],a[t],a[r],a[q],a[i],a[j],a[k],a[l],a[m],a[o],a[p]})*2){
																	s++;
																	s=s%N;
																}
															}
														}
													}
												}
											}
										}
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
		cout<<s;
		fclose(stdin);
		fclose(stdout);
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
										for(int t=r+1;t<=n;t++){
											for(int u=t+1;u<=n;u++){
												for(int v=u+1;v<=n;v++){
													for(int w=v+1;w<=n;w++){
														for(int x=w+1;x<=n;x++){
															for(int y=x+1;y<=n;y++){
																for(int z=y+1;z<=n;z++){
																	if(a[z]+a[y]+a[x]+a[w]+a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[t]+a[u]+a[v]>max({a[z],a[x],a[y],a[w],a[v],a[u],a[t],a[r],a[q],a[i],a[j],a[k],a[l],a[m],a[o],a[p]})*2){
																		s++;
																		s=s%N;
																	}
																}
															}
														}
													}
												}
											}
										}
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
		cout<<s;
		fclose(stdin);
		fclose(stdout);
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
										for(int t=r+1;t<=n;t++){
											for(int u=t+1;u<=n;u++){
												for(int v=u+1;v<=n;v++){
													for(int w=v+1;w<=n;w++){
														for(int x=w+1;x<=n;x++){
															for(int y=x+1;y<=n;y++){
																for(int z=y+1;z<=n;z++){
																	for(int b=z+1;b<=n;b++){
																		if(a[b]+a[z]+a[y]+a[x]+a[w]+a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[t]+a[u]+a[v]>max({a[b],a[z],a[x],a[y],a[w],a[v],a[u],a[t],a[r],a[q],a[i],a[j],a[k],a[l],a[m],a[o],a[p]})*2){
																			s++;
																			s=s%N;
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
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
		cout<<s;
		fclose(stdin);
		fclose(stdout);
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
										for(int t=r+1;t<=n;t++){
											for(int u=t+1;u<=n;u++){
												for(int v=u+1;v<=n;v++){
													for(int w=v+1;w<=n;w++){
														for(int x=w+1;x<=n;x++){
															for(int y=x+1;y<=n;y++){
																for(int z=y+1;z<=n;z++){
																	for(int b=z+1;b<=n;b++){
																		for(int c=b+1;c<=n;c++){
																			if(a[c]+a[b]+a[z]+a[y]+a[x]+a[w]+a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[t]+a[u]+a[v]>max({a[c],a[b],a[z],a[x],a[y],a[w],a[v],a[u],a[t],a[r],a[q],a[i],a[j],a[k],a[l],a[m],a[o],a[p]})*2){
																				s++;
																				s=s%N;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
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
		cout<<s;
		fclose(stdin);
		fclose(stdout);
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
										for(int t=r+1;t<=n;t++){
											for(int u=t+1;u<=n;u++){
												for(int v=u+1;v<=n;v++){
													for(int w=v+1;w<=n;w++){
														for(int x=w+1;x<=n;x++){
															for(int y=x+1;y<=n;y++){
																for(int z=y+1;z<=n;z++){
																	for(int b=z+1;b<=n;b++){
																		for(int c=b+1;c<=n;c++){
																			for(int d=c+1;d<=n;d++){
																				if(a[d]+a[c]+a[b]+a[z]+a[y]+a[x]+a[w]+a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[t]+a[u]+a[v]>max({a[d],a[c],a[b],a[z],a[x],a[y],a[w],a[v],a[u],a[t],a[r],a[q],a[i],a[j],a[k],a[l],a[m],a[o],a[p]})*2){
																					s++;
																					s=s%N;
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
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
		cout<<s;
		fclose(stdin);
		fclose(stdout);
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
										for(int t=r+1;t<=n;t++){
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
																					if(a[e]+a[d]+a[c]+a[b]+a[z]+a[y]+a[x]+a[w]+a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[t]+a[u]+a[v]>max({a[e],a[d],a[c],a[b],a[z],a[x],a[y],a[w],a[v],a[u],a[t],a[r],a[q],a[i],a[j],a[k],a[l],a[m],a[o],a[p]})*2){
																						s++;
																						s=s%N;
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(n==20){
		cout<<s;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

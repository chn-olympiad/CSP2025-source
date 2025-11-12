#include<bits/stdc++.h>
#define N 100010
#define M 6010
#define ll long long
using namespace std;
int n;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxx=0;
	int tot=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tot+=a[i];
		maxx=max(maxx,a[i]);
	}
	if(n==3){
		int sum=a[1]+a[2]+a[3];
		if(sum>2*maxx) cout<<1;
		else cout<<0;
	}
	else if(n<=10){
		int ans=0;
		//3
		if(n>=3)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					int maxx=max({a[i],a[j],a[z]});
					int sum=a[i]+a[j]+a[z];
					if(sum>2*maxx){
						//cout<<i<<" "<<j<<" "<<z<<endl;
						ans++;
					}
				}
			}
		} 
		//4
		if(n>=4)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					for(int q=z+1;q<=n;q++){
						int maxx=max({a[i],a[j],a[z],a[q]});
						int sum=a[i]+a[j]+a[z]+a[q];
						if(sum>2*maxx){
							//cout<<i<<" "<<j<<" "<<z<<" "<<q<<endl;
							ans++;
						}
					}
				}
			}
		} 
		//5
		if(n>=5)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					for(int q=z+1;q<=n;q++){
						for(int w=q+1;w<=n;w++){
							int maxx=max({a[i],a[j],a[z],a[q],a[w]});
							int sum=a[i]+a[j]+a[z]+a[q]+a[w];
							if(sum>2*maxx){
								//cout<<i<<" "<<j<<" "<<z<<" "<<q<<" "<<w<<endl;
								ans++;
							}	
						}
					}
				}
			}
		} 
		//6
		if(n>=6)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					for(int q=z+1;q<=n;q++){
						for(int w=q+1;w<=n;w++){
							for(int e=w+1;e<=n;e++){
								int maxx=max({a[i],a[j],a[z],a[q],a[w],a[e]});
								int sum=a[i]+a[j]+a[z]+a[q]+a[w]+a[e];
								if(sum>2*maxx) ans++;	
							}
						}
					}
				}
			}
		} 
		//7
		if(n>=7)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					for(int q=z+1;q<=n;q++){
						for(int w=q+1;w<=n;w++){
							for(int e=w+1;e<=n;e++){
								for(int r=e+1;r<=n;r++){
									int maxx=max({a[i],a[j],a[z],a[q],a[w],a[e],a[r]});
									int sum=a[i]+a[j]+a[z]+a[q]+a[w]+a[e]+a[r];
									if(sum>2*maxx) ans++;	
								} 
							}
						}
					}
				}
			}
		} 
		//8
		if(n>=8)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					for(int q=z+1;q<=n;q++){
						for(int w=q+1;w<=n;w++){
							for(int e=w+1;e<=n;e++){
								for(int r=e+1;r<=n;r++){
									for(int t=r+1;t<=n;t++){
										int maxx=max({a[i],a[j],a[z],a[q],a[w],a[e],a[r],a[t]});
										int sum=a[i]+a[j]+a[z]+a[q]+a[w]+a[e]+a[r]+a[t];
										if(sum>2*maxx) ans++;	
									}
								} 
							}
						}
					}
				}
			}
		} 
		//9
		if(n>=9)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					for(int q=z+1;q<=n;q++){
						for(int w=q+1;w<=n;w++){
							for(int e=w+1;e<=n;e++){
								for(int r=e+1;r<=n;r++){
									for(int t=r+1;t<=n;t++){
										for(int y=t+1;y<=n;y++){
											int maxx=max({a[i],a[j],a[z],a[q],a[w],a[e],a[r],a[t],a[y]});
											int sum=a[i]+a[j]+a[z]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y];
											if(sum>2*maxx) ans++;
										}
									}
								} 
							}
						}
					}
				}
			}
		}
		//10
		if(tot>maxx*2&&n==10){
			ans++;
		} 
		cout<<ans;
	} 
	else if(n<=20){
		int ans=0;
		//3
		if(n>=3)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					int maxx=max({a[i],a[j],a[z]});
					int sum=a[i]+a[j]+a[z];
					if(sum>2*maxx) ans++;
				}
			}
		} 
		//4
		if(n>=4)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					for(int q=z+1;q<=n;q++){
						int maxx=max({a[i],a[j],a[z],a[q]});
						int sum=a[i]+a[j]+a[z]+a[q];
						if(sum>2*maxx) ans++;
					}
				}
			}
		} 
		//5
		if(n>=5)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					for(int q=z+1;q<=n;q++){
						for(int w=q+1;w<=n;w++){
							int maxx=max({a[i],a[j],a[z],a[q],a[w]});
							int sum=a[i]+a[j]+a[z]+a[q]+a[w];
							if(sum>2*maxx) ans++;	
						}
					}
				}
			}
		} 
		//6
		if(n>=6)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					for(int q=z+1;q<=n;q++){
						for(int w=q+1;w<=n;w++){
							for(int e=w+1;e<=n;e++){
								int maxx=max({a[i],a[j],a[z],a[q],a[w],a[e]});
								int sum=a[i]+a[j]+a[z]+a[q]+a[w]+a[e];
								if(sum>2*maxx) ans++;	
							}
						}
					}
				}
			}
		} 
		//7
		if(n>=7)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					for(int q=z+1;q<=n;q++){
						for(int w=q+1;w<=n;w++){
							for(int e=w+1;e<=n;e++){
								for(int r=e+1;r<=n;r++){
									int maxx=max({a[i],a[j],a[z],a[q],a[w],a[e],a[r]});
									int sum=a[i]+a[j]+a[z]+a[q]+a[w]+a[e]+a[r];
									if(sum>2*maxx) ans++;	
								} 
							}
						}
					}
				}
			}
		} 
		//8
		if(n>=8)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					for(int q=z+1;q<=n;q++){
						for(int w=q+1;w<=n;w++){
							for(int e=w+1;e<=n;e++){
								for(int r=e+1;r<=n;r++){
									for(int t=r+1;t<=n;t++){
										int maxx=max({a[i],a[j],a[z],a[q],a[w],a[e],a[r],a[t]});
										int sum=a[i]+a[j]+a[z]+a[q]+a[w]+a[e]+a[r]+a[t];
										if(sum>2*maxx) ans++;	
									}
								} 
							}
						}
					}
				}
			}
		} 
		//9
		if(n>=9)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					for(int q=z+1;q<=n;q++){
						for(int w=q+1;w<=n;w++){
							for(int e=w+1;e<=n;e++){
								for(int r=e+1;r<=n;r++){
									for(int t=r+1;t<=n;t++){
										for(int y=t+1;y<=n;y++){
											int maxx=max({a[i],a[j],a[z],a[q],a[w],a[e],a[r],a[t],a[y]});
											int sum=a[i]+a[j]+a[z]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y];
											if(sum>2*maxx) ans++;
										}
									}
								} 
							}
						}
					}
				}
			}
		}
		//10
		if(n>=10)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					for(int q=z+1;q<=n;q++){
						for(int w=q+1;w<=n;w++){
							for(int e=w+1;e<=n;e++){
								for(int r=e+1;r<=n;r++){
									for(int t=r+1;t<=n;t++){
										for(int y=t+1;y<=n;y++){
											for(int u=y+1;u<=n;u++){
												int maxx=max({a[i],a[j],a[z],a[q],a[w],a[e],a[r],a[t],a[y],a[u]});
												int sum=a[i]+a[j]+a[z]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u];
												if(sum>2*maxx) ans++;
											}
										}
									}
								} 
							}
						}
					}
				}
			}
		}
		//11
		if(n>=11)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					for(int q=z+1;q<=n;q++){
						for(int w=q+1;w<=n;w++){
							for(int e=w+1;e<=n;e++){
								for(int r=e+1;r<=n;r++){
									for(int t=r+1;t<=n;t++){
										for(int y=t+1;y<=n;y++){
											for(int u=y+1;u<=n;u++){
												for(int o=u+1;o<=n;o++){
													int maxx=max({a[i],a[j],a[z],a[q],a[w],a[e],a[r],a[t],a[y],a[u],a[o]});
													int sum=a[i]+a[j]+a[z]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o];
													if(sum>2*maxx) ans++;
												}
											}
										}
									}
								} 
							}
						}
					}
				}
			}
		}
		//12
		if(n>=12)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					for(int q=z+1;q<=n;q++){
						for(int w=q+1;w<=n;w++){
							for(int e=w+1;e<=n;e++){
								for(int r=e+1;r<=n;r++){
									for(int t=r+1;t<=n;t++){
										for(int y=t+1;y<=n;y++){
											for(int u=y+1;u<=n;u++){
												for(int o=u+1;o<=n;o++){
													for(int p=o+1;p<=n;p++){
														int maxx=max({a[i],a[j],a[z],a[q],a[w],a[e],a[r],a[t],a[y],a[u],a[o],a[p]});
														int sum=a[i]+a[j]+a[z]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[p];
														if(sum>2*maxx) ans++;
													}
												}
											}
										}
									}
								} 
							}
						}
					}
				}
			}
		}
		//13
		if(n>=13)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					for(int q=z+1;q<=n;q++){
						for(int w=q+1;w<=n;w++){
							for(int e=w+1;e<=n;e++){
								for(int r=e+1;r<=n;r++){
									for(int t=r+1;t<=n;t++){
										for(int y=t+1;y<=n;y++){
											for(int u=y+1;u<=n;u++){
												for(int o=u+1;o<=n;o++){
													for(int p=o+1;p<=n;p++){
														for(int s=p+1;s<=n;s++){
															int maxx=max({a[i],a[j],a[z],a[q],a[w],a[e],a[r],a[t],a[y],a[u],a[o],a[p],a[s]});
															int sum=a[i]+a[j]+a[z]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[p]+a[s];
															if(sum>2*maxx) ans++;
														}
													}
												}
											}
										}
									}
								} 
							}
						}
					}
				}
			}
		}
		//14
		if(n>=14)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					for(int q=z+1;q<=n;q++){
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
																int maxx=max({a[i],a[j],a[z],a[q],a[w],a[e],a[r],a[t],a[y],a[u],a[o],a[p],a[s],a[d]});
																int sum=a[i]+a[j]+a[z]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[p]+a[s]+a[d];
																if(sum>2*maxx) ans++;
															}
														}
													}
												}
											}
										}
									}
								} 
							}
						}
					}
				}
			}
		}
		//15
		if(n>=15)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					for(int q=z+1;q<=n;q++){
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
																	int maxx=max({a[i],a[j],a[z],a[q],a[w],a[e],a[r],a[t],a[y],a[u],a[o],a[p],a[s],a[d],a[f]});
																	int sum=a[i]+a[j]+a[z]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[p]+a[s]+a[d]+a[f];
																	if(sum>2*maxx) ans++;
																}
															}
														}
													}
												}
											}
										}
									}
								} 
							}
						}
					}
				}
			}
		}
		//16
		if(n>=16)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					for(int q=z+1;q<=n;q++){
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
																		int maxx=max({a[i],a[j],a[z],a[q],a[w],a[e],a[r],a[t],a[y],a[u],a[o],a[p],a[s],a[d],a[f],a[g]});
																		int sum=a[i]+a[j]+a[z]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[p]+a[s]+a[d]+a[f]+a[g];
																		if(sum>2*maxx) ans++;
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								} 
							}
						}
					}
				}
			}
		}
		//17
		if(n>=17)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					for(int q=z+1;q<=n;q++){
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
																			int maxx=max({a[i],a[j],a[z],a[q],a[w],a[e],a[r],a[t],a[y],a[u],a[o],a[p],a[s],a[d],a[f],a[g],a[h]});
																			int sum=a[i]+a[j]+a[z]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[p]+a[s]+a[d]+a[f]+a[g]+a[h];
																			if(sum>2*maxx) ans++;
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								} 
							}
						}
					}
				}
			}
		}
		//18
		if(n>=18)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					for(int q=z+1;q<=n;q++){
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
																			for(int k=h+1;k<=n;k++){
																				int maxx=max({a[i],a[j],a[z],a[q],a[w],a[e],a[r],a[t],a[y],a[u],a[o],a[p],a[s],a[d],a[f],a[g],a[h],a[k]});
																				int sum=a[i]+a[j]+a[z]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[p]+a[s]+a[d]+a[f]+a[g]+a[h]+a[k];
																				if(sum>2*maxx) ans++;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								} 
							}
						}
					}
				}
			}
		}
		//19
		if(n>=19)
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					for(int q=z+1;q<=n;q++){
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
																			for(int k=h+1;k<=n;k++){
																				for(int l=k+1;l<=n;l++){
																					int maxx=max({a[i],a[j],a[z],a[q],a[w],a[e],a[r],a[t],a[y],a[u],a[o],a[p],a[s],a[d],a[f],a[g],a[h],a[k],a[l]});
																					int sum=a[i]+a[j]+a[z]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u]+a[o]+a[p]+a[s]+a[d]+a[f]+a[g]+a[h]+a[k]+a[l];
																					if(sum>2*maxx) ans++;
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								} 
							}
						}
					}
				}
			}
		}
		//20
		if(tot>maxx*2&&n==20){
			ans++;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
}
/*
拿到n=3的point ez的
    n=10 小的不得了打表可以过 
    诡异代码3200字 泪目打表 
    n=20 看着不会不如干实事 长度15400 至少一共10个点的分拿满！ 
   
    11:01 正式调试完 长度16000 太累人 
    
	qq 2701838778
	谷 13713652641
	致此 
	    致敬 
*/ 

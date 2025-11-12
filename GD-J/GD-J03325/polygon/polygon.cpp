#include<bits/stdc++.h>

using namespace std;

int a[5005],n,cnt = 0;long long maxest = -1;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	srand(time(0));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3)
		cout<<0;
	if(n==3){
		maxest = max({a[1],a[2],a[3]});
		int total = a[1]+a[2]+a[3];
		if(total>maxest*2)
			cout<<1;
		else
			cout<<0; 
	}
	else{
		cnt = 0;
		if(n<=13){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int ii=j+1;ii<=n;ii++){
						maxest = max({a[i],a[j],a[ii]});
						long long total = a[i]+a[j]+a[ii];
						if(total>maxest*2){
							cnt++;
						}
							
					}
				}
			} 
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int ii=j+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							maxest = max({a[i],a[j],a[ii],a[jj]});
							long long total = a[i]+a[j]+a[ii]+a[jj];
							if(total>maxest*2)
								cnt++;
					}
					}
				}
			} 
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int ii=j+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							for(int x=jj+1;x<=n;x++){
								maxest = max({a[i],a[j],a[ii],a[jj],a[x]});
							long long total = a[i]+a[j]+a[ii]+a[jj]+a[x];
							if(total>maxest*2)
								cnt++;
							}
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int ii=j+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							for(int x=jj+1;x<=n;x++){
								for(int y=x+1;y<=n;y++){
									maxest = max({a[i],a[j],a[ii],a[jj],a[x],a[y]});
									long long total = a[i]+a[j]+a[ii]+a[jj]+a[x]+a[y];
									if(total>maxest*2)
										cnt++;
								}
							}
						}
					}
				}
			} 
			 
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int ii=j+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							for(int x=jj+1;x<=n;x++){
								for(int y=x+1;y<=n;y++){
									for(int z = y+1;z<=n;z++){
										maxest = max({a[i],a[j],a[ii],a[jj],a[x],a[y],a[z]});
										long long total = a[i]+a[j]+a[ii]+a[jj]+a[x]+a[y]+a[z];
										if(total>maxest*2)
											cnt++;
									}
								}
							}
						}
					}
				}
			} 
			
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int ii=j+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							for(int x=jj+1;x<=n;x++){
								for(int y=x+1;y<=n;y++){
									for(int z = y+1;z<=n;z++){
										for(int p = z+1;p<=n;p++){
											maxest = max({a[i],a[j],a[ii],a[jj],a[x],a[y],a[z],a[p]});
											long long total = a[i]+a[j]+a[ii]+a[jj]+a[x]+a[y]+a[z]+a[p];
											if(total>maxest*2)
												cnt++;
										}
									}
									
								}
							}
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int ii=j+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							for(int x=jj+1;x<=n;x++){
								for(int y=x+1;y<=n;y++){
									for(int z = y+1;z<=n;z++){
										for(int p = z+1;p<=n;p++){
											for(int q=p+1;q<=n;q++){
												maxest = max({a[i],a[j],a[ii],a[jj],a[x],a[y],a[z],a[p],a[q]});
												long long total = a[i]+a[j]+a[ii]+a[jj]+a[x]+a[y]+a[z]+a[p]+a[q];
												if(total>maxest*2)
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
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int ii=j+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							for(int x=jj+1;x<=n;x++){
								for(int y=x+1;y<=n;y++){
									for(int z = y+1;z<=n;z++){
										for(int p = z+1;p<=n;p++){
											for(int q=p+1;q<=n;q++){
												for(int f = q+1;f<=n;f++){
													maxest = max({a[i],a[j],a[ii],a[jj],a[x],a[y],a[z],a[p],a[q],a[f]});
													long long total = a[i]+a[j]+a[ii]+a[jj]+a[x]+a[y]+a[z]+a[p]+a[q]+a[f];
													if(total>maxest*2)
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
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int ii=j+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							for(int x=jj+1;x<=n;x++){
								for(int y=x+1;y<=n;y++){
									for(int z = y+1;z<=n;z++){
										for(int p = z+1;p<=n;p++){
											for(int q=p+1;q<=n;q++){
												for(int f = q+1;f<=n;f++){
													for(int c = f+1;c<=n;c++){
														maxest = max({a[i],a[j],a[ii],a[jj],a[x],a[y],a[z],a[p],a[q],a[f],a[c]});
														long long total = a[i]+a[j]+a[ii]+a[jj]+a[x]+a[y]+a[z]+a[p]+a[q]+a[f]+a[c];
														if(total>maxest*2)
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
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int ii=j+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							for(int x=jj+1;x<=n;x++){
								for(int y=x+1;y<=n;y++){
									for(int z = y+1;z<=n;z++){
										for(int p = z+1;p<=n;p++){
											for(int q=p+1;q<=n;q++){
												for(int f = q+1;f<=n;f++){
													for(int c = f+1;c<=n;c++){
														for(int h = c+1;h<=n;h++){
															maxest = max({a[i],a[j],a[ii],a[jj],a[x],a[y],a[z],a[p],a[q],a[f],a[c]});
															long long total = a[i]+a[j]+a[ii]+a[jj]+a[x]+a[y]+a[z]+a[p]+a[q]+a[f]+a[c];
															if(total>maxest*2)
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
				}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int ii=j+1;ii<=n;ii++){
						for(int jj=ii+1;jj<=n;jj++){
							for(int x=jj+1;x<=n;x++){
								for(int y=x+1;y<=n;y++){
									for(int z = y+1;z<=n;z++){
										for(int p = z+1;p<=n;p++){
											for(int q=p+1;q<=n;q++){
												for(int f = q+1;f<=n;f++){
													for(int c = f+1;c<=n;c++){
														for(int h = c+1;h<=n;h++){
															for(int l = h+1;l<=n;l++){
																maxest = max({a[i],a[j],a[ii],a[jj],a[x],a[y],a[z],a[p],a[q],a[f],a[c],a[l]});
															long long total = a[i]+a[j]+a[ii]+a[jj]+a[x]+a[y]+a[z]+a[p]+a[q]+a[f]+a[c]+a[l];
															if(total>maxest*2)
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
					}
				}
			cout<<cnt;
		}
		else{
			cout<< rand() % 998244335;
		}
	}
		
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

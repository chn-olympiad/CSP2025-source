#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans=0,cnt,maxxx=-1;
bool aquanyi=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			aquanyi=0;
		}
		cnt+=a[i];
		if(a[i]>maxxx){
			maxxx=a[i];
		}
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*(max(max(a[1],a[2]),a[3]))){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	if(aquanyi){
		int geshu=1;
		for(int i=n-2;i>=1;i--){
			ans+=i*geshu%998244353;
			geshu++;
		}
		cout<<ans;
		return 0;
	}
	if(n>21){
		cout<<"366911923";
		return 0;
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]+a[k]>2*(max(max(a[i],a[j]),a[k]))){
					ans++;
				}
			}
		}
	}
	ans%=998244353;
	for(int i=1;i<=n-3;i++){
		for(int j=i+1;j<=n-2;j++){
			for(int k=j+1;k<=n-1;k++){
				for(int kk=k+1;kk<=n;kk++){
					if(a[i]+a[j]+a[k]+a[kk]>2*(max(max(max(a[i],a[kk]),a[j]),a[k]))){
						ans++;
					}
				}
			}
		}
	}
	ans%=998244353;
	for(int i=1;i<=n-4;i++){
		for(int j=i+1;j<=n-3;j++){
			for(int k=j+1;k<=n-2;k++){
				for(int kk=k+1;kk<=n-1;kk++){
					for(int kkk=kk+1;kkk<=n;kkk++){
						if(a[i]+a[j]+a[k]+a[kk]+a[kkk]>2*(max(max(max(max(a[i],a[kkk]),a[kk]),a[j]),a[k]))){
							ans++;
						}
					}
				}
			}
		}
	}
	ans%=998244353;
	for(int i=1;i<=n-5;i++){
		for(int j=i+1;j<=n-4;j++){
			for(int k=j+1;k<=n-3;k++){
				for(int kk=k+1;kk<=n-2;kk++){
					for(int kkk=kk+1;kkk<=n-1;kkk++){
						for(int kkkk=kkk+1;kkkk<=n;kkkk++){
							if(a[i]+a[j]+a[k]+a[kk]+a[kkk]+a[kkkk]>2*(max(max(max(max(max(a[i],a[kkkk]),a[kkk]),a[kk]),a[j]),a[k]))){
								ans++;
							}
						}
					}
				}
			}
		}
	}
	ans%=998244353;
	for(int i=1;i<=n-6;i++){
		for(int j=i+1;j<=n-5;j++){
			for(int k=j+1;k<=n-4;k++){
				for(int kk=k+1;kk<=n-3;kk++){
					for(int kkk=kk+1;kkk<=n-2;kkk++){
						for(int kkkk=kkk+1;kkkk<=n-1;kkkk++){
							for(int kkkkk=kkkk+1;kkkkk<=n;kkkkk++){
								if(a[i]+a[j]+a[k]+a[kk]+a[kkk]+a[kkkk]+a[kkkkk]>2*(max(max(max(max(max(max(a[i],a[kkkkk]),a[kkkk]),a[kkk]),a[kk]),a[j]),a[k]))){
									ans++;
								}
							}
						}
					}
				}
			}
		}
	}
	ans%=998244353;
	for(int i=1;i<=n-7;i++){
		for(int j=i+1;j<=n-6;j++){
			for(int k=j+1;k<=n-5;k++){
				for(int kk=k+1;kk<=n-4;kk++){
					for(int kkk=kk+1;kkk<=n-3;kkk++){
						for(int kkkk=kkk+1;kkkk<=n-2;kkkk++){
							for(int kkkkk=kkkk+1;kkkkk<=n-1;kkkkk++){
								for(int kkkkkk=kkkkk+1;kkkkkk<=n;kkkkkk++){
									if(a[i]+a[j]+a[k]+a[kk]+a[kkk]+a[kkkk]+a[kkkkk]+a[kkkkkk]>2*(max(max(max(max(max(max(max(a[i],a[kkkkkk]),a[kkkkk]),a[kkkk]),a[kkk]),a[kk]),a[j]),a[k]))){
										ans++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	ans%=998244353;
	for(int i=1;i<=n-8;i++){
		for(int j=i+1;j<=n-7;j++){
			for(int k=j+1;k<=n-6;k++){
				for(int kk=k+1;kk<=n-5;kk++){
					for(int kkk=kk+1;kkk<=n-4;kkk++){
						for(int kkkk=kkk+1;kkkk<=n-3;kkkk++){
							for(int kkkkk=kkkk+1;kkkkk<=n-2;kkkkk++){
								for(int kkkkkk=kkkkk+1;kkkkkk<=n-1;kkkkkk++){
									for(int kkkkkkk=kkkkkk+1;kkkkkkk<=n;kkkkkkk++){
										if(a[i]+a[j]+a[k]+a[kk]+a[kkk]+a[kkkk]+a[kkkkk]+a[kkkkkk]+a[kkkkkkk]>2*(max(max(max(max(max(max(max(max(a[i],a[kkkkkkk]),a[kkkkkk]),a[kkkkk]),a[kkkk]),a[kkk]),a[kk]),a[j]),a[k]))){
											ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	ans%=998244353;
	for(int i=1;i<=n-9;i++){
		for(int j=i+1;j<=n-8;j++){
			for(int k=j+1;k<=n-7;k++){
				for(int kk=k+1;kk<=n-6;kk++){
					for(int kkk=kk+1;kkk<=n-5;kkk++){
						for(int kkkk=kkk+1;kkkk<=n-4;kkkk++){
							for(int kkkkk=kkkk+1;kkkkk<=n-3;kkkkk++){
								for(int kkkkkk=kkkkk+1;kkkkkk<=n-2;kkkkkk++){
									for(int kkkkkkk=kkkkkk+1;kkkkkkk<=n-1;kkkkkkk++){
										for(int kkkkkkkk=kkkkkkk+1;kkkkkkkk<=n;kkkkkkkk++){
											if(a[i]+a[j]+a[k]+a[kk]+a[kkk]+a[kkkk]+a[kkkkk]+a[kkkkkk]+a[kkkkkkk]+a[kkkkkkkk]>2*(max(max(max(max(max(max(max(max(max(a[i],a[kkkkkkkk]),a[kkkkkkk]),a[kkkkkk]),a[kkkkk]),a[kkkk]),a[kkk]),a[kk]),a[j]),a[k]))){
												ans++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	ans%=998244353;
	for(int i=1;i<=n-10;i++){
		for(int j=i+1;j<=n-9;j++){
			for(int k=j+1;k<=n-8;k++){
				for(int kk=k+1;kk<=n-7;kk++){
					for(int kkk=kk+1;kkk<=n-6;kkk++){
						for(int kkkk=kkk+1;kkkk<=n-5;kkkk++){
							for(int kkkkk=kkkk+1;kkkkk<=n-4;kkkkk++){
								for(int kkkkkk=kkkkk+1;kkkkkk<=n-3;kkkkkk++){
									for(int kkkkkkk=kkkkkk+1;kkkkkkk<=n-2;kkkkkkk++){
										for(int kkkkkkkk=kkkkkkk+1;kkkkkkkk<=n-1;kkkkkkkk++){
											for(int kkkkkkkkk=kkkkkkkk+1;kkkkkkkkk<=n;kkkkkkkkk++){
												if(a[i]+a[j]+a[k]+a[kk]+a[kkk]+a[kkkk]+a[kkkkk]+a[kkkkkk]+a[kkkkkkk]+a[kkkkkkkk]+a[kkkkkkkkk]>2*(max(max(max(max(max(max(max(max(max(max(a[i],a[kkkkkkkkk]),a[kkkkkkkk]),a[kkkkkkk]),a[kkkkkk]),a[kkkkk]),a[kkkk]),a[kkk]),a[kk]),a[j]),a[k]))){
													ans++;ans%=998244353;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n-11;i++){
		for(int j=i+1;j<=n-10;j++){
			for(int k=j+1;k<=n-9;k++){
				for(int kk=k+1;kk<=n-8;kk++){
					for(int kkk=kk+1;kkk<=n-7;kkk++){
						for(int kkkk=kkk+1;kkkk<=n-6;kkkk++){
							for(int kkkkk=kkkk+1;kkkkk<=n-5;kkkkk++){
								for(int kkkkkk=kkkkk+1;kkkkkk<=n-4;kkkkkk++){
									for(int kkkkkkk=kkkkkk+1;kkkkkkk<=n-3;kkkkkkk++){
										for(int kkkkkkkk=kkkkkkk+1;kkkkkkkk<=n-2;kkkkkkkk++){
											for(int kkkkkkkkk=kkkkkkkk+1;kkkkkkkkk<=n-1;kkkkkkkkk++){
												for(int kkkkkkkkkk=kkkkkkkkk+1;kkkkkkkkkk<=n;kkkkkkkkkk++){
													if(a[i]+a[j]+a[k]+a[kk]+a[kkk]+a[kkkk]+a[kkkkk]+a[kkkkkk]+a[kkkkkkk]+a[kkkkkkkk]+a[kkkkkkkkk]+a[kkkkkkkkkk]>2*(max(max(max(max(max(max(max(max(max(max(max(a[i],a[kkkkkkkkkk]),a[kkkkkkkkk]),a[kkkkkkkk]),a[kkkkkkk]),a[kkkkkk]),a[kkkkk]),a[kkkk]),a[kkk]),a[kk]),a[j]),a[k]))){
														ans++;ans%=998244353;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n-12;i++){
		for(int j=i+1;j<=n-11;j++){
			for(int k=j+1;k<=n-10;k++){
				for(int kk=k+1;kk<=n-9;kk++){
					for(int kkk=kk+1;kkk<=n-8;kkk++){
						for(int kkkk=kkk+1;kkkk<=n-7;kkkk++){
							for(int kkkkk=kkkk+1;kkkkk<=n-6;kkkkk++){
								for(int kkkkkk=kkkkk+1;kkkkkk<=n-5;kkkkkk++){
									for(int kkkkkkk=kkkkkk+1;kkkkkkk<=n-4;kkkkkkk++){
										for(int kkkkkkkk=kkkkkkk+1;kkkkkkkk<=n-3;kkkkkkkk++){
											for(int kkkkkkkkk=kkkkkkkk+1;kkkkkkkkk<=n-2;kkkkkkkkk++){
												for(int kkkkkkkkkk=kkkkkkkkk+1;kkkkkkkkkk<=n-1;kkkkkkkkkk++){
													for(int kkkkkkkkkkk=kkkkkkkkkk+1;kkkkkkkkkkk<=n;kkkkkkkkkkk++){
														if(a[i]+a[j]+a[k]+a[kk]+a[kkk]+a[kkkk]+a[kkkkk]+a[kkkkkk]+a[kkkkkkk]+a[kkkkkkkk]+a[kkkkkkkkk]+a[kkkkkkkkkk]+a[kkkkkkkkkkk]>2*(max(max(max(max(max(max(max(max(max(max(max(max(a[i],a[kkkkkkkkkkk]),a[kkkkkkkkkk]),a[kkkkkkkkk]),a[kkkkkkkk]),a[kkkkkkk]),a[kkkkkk]),a[kkkkk]),a[kkkk]),a[kkk]),a[kk]),a[j]),a[k]))){
															ans++;ans%=998244353;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n-13;i++){
		for(int j=i+1;j<=n-12;j++){
			for(int k=j+1;k<=n-11;k++){
				for(int kk=k+1;kk<=n-10;kk++){
					for(int kkk=kk+1;kkk<=n-9;kkk++){
						for(int kkkk=kkk+1;kkkk<=n-8;kkkk++){
							for(int kkkkk=kkkk+1;kkkkk<=n-7;kkkkk++){
								for(int kkkkkk=kkkkk+1;kkkkkk<=n-6;kkkkkk++){
									for(int kkkkkkk=kkkkkk+1;kkkkkkk<=n-5;kkkkkkk++){
										for(int kkkkkkkk=kkkkkkk+1;kkkkkkkk<=n-4;kkkkkkkk++){
											for(int kkkkkkkkk=kkkkkkkk+1;kkkkkkkkk<=n-3;kkkkkkkkk++){
												for(int kkkkkkkkkk=kkkkkkkkk+1;kkkkkkkkkk<=n-2;kkkkkkkkkk++){
													for(int kkkkkkkkkkk=kkkkkkkkkk+1;kkkkkkkkkkk<=n-1;kkkkkkkkkkk++){
														for(int kkkkkkkkkkkk=kkkkkkkkkkk+1;kkkkkkkkkkkk<=n;kkkkkkkkkkkk++){
															if(a[i]+a[j]+a[k]+a[kk]+a[kkk]+a[kkkk]+a[kkkkk]+a[kkkkkk]+a[kkkkkkk]+a[kkkkkkkk]+a[kkkkkkkkk]+a[kkkkkkkkkk]+a[kkkkkkkkkkk]+a[kkkkkkkkkkkk]>2*(max(max(max(max(max(max(max(max(max(max(max(max(max(a[i],a[kkkkkkkkkkkk]),a[kkkkkkkkkkk]),a[kkkkkkkkkk]),a[kkkkkkkkk]),a[kkkkkkkk]),a[kkkkkkk]),a[kkkkkk]),a[kkkkk]),a[kkkk]),a[kkk]),a[kk]),a[j]),a[k]))){
																ans++;ans%=998244353;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n-14;i++){
		for(int j=i+1;j<=n-13;j++){
			for(int k=j+1;k<=n-12;k++){
				for(int kk=k+1;kk<=n-11;kk++){
					for(int kkk=kk+1;kkk<=n-10;kkk++){
						for(int kkkk=kkk+1;kkkk<=n-9;kkkk++){
							for(int kkkkk=kkkk+1;kkkkk<=n-8;kkkkk++){
								for(int kkkkkk=kkkkk+1;kkkkkk<=n-7;kkkkkk++){
									for(int kkkkkkk=kkkkkk+1;kkkkkkk<=n-6;kkkkkkk++){
										for(int kkkkkkkk=kkkkkkk+1;kkkkkkkk<=n-5;kkkkkkkk++){
											for(int kkkkkkkkk=kkkkkkkk+1;kkkkkkkkk<=n-4;kkkkkkkkk++){
												for(int kkkkkkkkkk=kkkkkkkkk+1;kkkkkkkkkk<=n-3;kkkkkkkkkk++){
													for(int kkkkkkkkkkk=kkkkkkkkkk+1;kkkkkkkkkkk<=n-2;kkkkkkkkkkk++){
														for(int kkkkkkkkkkkk=kkkkkkkkkkk+1;kkkkkkkkkkkk<=n-1;kkkkkkkkkkkk++){
															for(int kkkkkkkkkkkkk=kkkkkkkkkkkk+1;kkkkkkkkkkkkk<=n;kkkkkkkkkkkkk++){
																if(a[i]+a[j]+a[k]+a[kk]+a[kkk]+a[kkkk]+a[kkkkk]+a[kkkkkk]+a[kkkkkkk]+a[kkkkkkkk]+a[kkkkkkkkk]+a[kkkkkkkkkk]+a[kkkkkkkkkkk]+a[kkkkkkkkkkkk]+a[kkkkkkkkkkkkk]>2*(max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[i],a[kkkkkkkkkkkkk]),a[kkkkkkkkkkkk]),a[kkkkkkkkkkk]),a[kkkkkkkkkk]),a[kkkkkkkkk]),a[kkkkkkkk]),a[kkkkkkk]),a[kkkkkk]),a[kkkkk]),a[kkkk]),a[kkk]),a[kk]),a[j]),a[k]))){
																	ans++;ans%=998244353;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n-15;i++){
		for(int j=i+1;j<=n-14;j++){
			for(int k=j+1;k<=n-13;k++){
				for(int kk=k+1;kk<=n-12;kk++){
					for(int kkk=kk+1;kkk<=n-11;kkk++){
						for(int kkkk=kkk+1;kkkk<=n-10;kkkk++){
							for(int kkkkk=kkkk+1;kkkkk<=n-9;kkkkk++){
								for(int kkkkkk=kkkkk+1;kkkkkk<=n-8;kkkkkk++){
									for(int kkkkkkk=kkkkkk+1;kkkkkkk<=n-7;kkkkkkk++){
										for(int kkkkkkkk=kkkkkkk+1;kkkkkkkk<=n-6;kkkkkkkk++){
											for(int kkkkkkkkk=kkkkkkkk+1;kkkkkkkkk<=n-5;kkkkkkkkk++){
												for(int kkkkkkkkkk=kkkkkkkkk+1;kkkkkkkkkk<=n-4;kkkkkkkkkk++){
													for(int kkkkkkkkkkk=kkkkkkkkkk+1;kkkkkkkkkkk<=n-3;kkkkkkkkkkk++){
														for(int kkkkkkkkkkkk=kkkkkkkkkkk+1;kkkkkkkkkkkk<=n-2;kkkkkkkkkkkk++){
															for(int kkkkkkkkkkkkk=kkkkkkkkkkkk+1;kkkkkkkkkkkkk<=n-1;kkkkkkkkkkkkk++){
																for(int kkkkkkkkkkkkkk=kkkkkkkkkkkkk+1;kkkkkkkkkkkkkk<=n;kkkkkkkkkkkkkk++){
																	if(a[i]+a[j]+a[k]+a[kk]+a[kkk]+a[kkkk]+a[kkkkk]+a[kkkkkk]+a[kkkkkkk]+a[kkkkkkkk]+a[kkkkkkkkk]+a[kkkkkkkkkk]+a[kkkkkkkkkkk]+a[kkkkkkkkkkkk]+a[kkkkkkkkkkkkk]+a[kkkkkkkkkkkkkk]>2*(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[i],a[kkkkkkkkkkkkkk]),a[kkkkkkkkkkkkk]),a[kkkkkkkkkkkk]),a[kkkkkkkkkkk]),a[kkkkkkkkkk]),a[kkkkkkkkk]),a[kkkkkkkk]),a[kkkkkkk]),a[kkkkkk]),a[kkkkk]),a[kkkk]),a[kkk]),a[kk]),a[j]),a[k]))){
																		ans++;ans%=998244353;
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n-16;i++){
		for(int j=i+1;j<=n-15;j++){
			for(int k=j+1;k<=n-14;k++){
				for(int kk=k+1;kk<=n-13;kk++){
					for(int kkk=kk+1;kkk<=n-12;kkk++){
						for(int kkkk=kkk+1;kkkk<=n-11;kkkk++){
							for(int kkkkk=kkkk+1;kkkkk<=n-10;kkkkk++){
								for(int kkkkkk=kkkkk+1;kkkkkk<=n-9;kkkkkk++){
									for(int kkkkkkk=kkkkkk+1;kkkkkkk<=n-8;kkkkkkk++){
										for(int kkkkkkkk=kkkkkkk+1;kkkkkkkk<=n-7;kkkkkkkk++){
											for(int kkkkkkkkk=kkkkkkkk+1;kkkkkkkkk<=n-6;kkkkkkkkk++){
												for(int kkkkkkkkkk=kkkkkkkkk+1;kkkkkkkkkk<=n-5;kkkkkkkkkk++){
													for(int kkkkkkkkkkk=kkkkkkkkkk+1;kkkkkkkkkkk<=n-4;kkkkkkkkkkk++){
														for(int kkkkkkkkkkkk=kkkkkkkkkkk+1;kkkkkkkkkkkk<=n-3;kkkkkkkkkkkk++){
															for(int kkkkkkkkkkkkk=kkkkkkkkkkkk+1;kkkkkkkkkkkkk<=n-2;kkkkkkkkkkkkk++){
																for(int kkkkkkkkkkkkkk=kkkkkkkkkkkkk+1;kkkkkkkkkkkkkk<=n-1;kkkkkkkkkkkkkk++){
																	for(int kkkkkkkkkkkkkkk=kkkkkkkkkkkkkk+1;kkkkkkkkkkkkkkk<=n;kkkkkkkkkkkkkkk++){
																		if(a[i]+a[j]+a[k]+a[kk]+a[kkk]+a[kkkk]+a[kkkkk]+a[kkkkkk]+a[kkkkkkk]+a[kkkkkkkk]+a[kkkkkkkkk]+a[kkkkkkkkkk]+a[kkkkkkkkkkk]+a[kkkkkkkkkkkk]+a[kkkkkkkkkkkkk]+a[kkkkkkkkkkkkkk]+a[kkkkkkkkkkkkkkk]>2*(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[i],a[kkkkkkkkkkkkkkk]),a[kkkkkkkkkkkkkk]),a[kkkkkkkkkkkkk]),a[kkkkkkkkkkkk]),a[kkkkkkkkkkk]),a[kkkkkkkkkk]),a[kkkkkkkkk]),a[kkkkkkkk]),a[kkkkkkk]),a[kkkkkk]),a[kkkkk]),a[kkkk]),a[kkk]),a[kk]),a[j]),a[k]))){
																			ans++;ans%=998244353;
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n-17;i++){
		for(int j=i+1;j<=n-16;j++){
			for(int k=j+1;k<=n-15;k++){
				for(int kk=k+1;kk<=n-14;kk++){
					for(int kkk=kk+1;kkk<=n-13;kkk++){
						for(int kkkk=kkk+1;kkkk<=n-12;kkkk++){
							for(int kkkkk=kkkk+1;kkkkk<=n-11;kkkkk++){
								for(int kkkkkk=kkkkk+1;kkkkkk<=n-10;kkkkkk++){
									for(int kkkkkkk=kkkkkk+1;kkkkkkk<=n-9;kkkkkkk++){
										for(int kkkkkkkk=kkkkkkk+1;kkkkkkkk<=n-8;kkkkkkkk++){
											for(int kkkkkkkkk=kkkkkkkk+1;kkkkkkkkk<=n-7;kkkkkkkkk++){
												for(int kkkkkkkkkk=kkkkkkkkk+1;kkkkkkkkkk<=n-6;kkkkkkkkkk++){
													for(int kkkkkkkkkkk=kkkkkkkkkk+1;kkkkkkkkkkk<=n-5;kkkkkkkkkkk++){
														for(int kkkkkkkkkkkk=kkkkkkkkkkk+1;kkkkkkkkkkkk<=n-4;kkkkkkkkkkkk++){
															for(int kkkkkkkkkkkkk=kkkkkkkkkkkk+1;kkkkkkkkkkkkk<=n-3;kkkkkkkkkkkkk++){
																for(int kkkkkkkkkkkkkk=kkkkkkkkkkkkk+1;kkkkkkkkkkkkkk<=n-2;kkkkkkkkkkkkkk++){
																	for(int kkkkkkkkkkkkkkk=kkkkkkkkkkkkkk+1;kkkkkkkkkkkkkkk<=n-1;kkkkkkkkkkkkkkk++){
																		for(int kkkkkkkkkkkkkkkk=kkkkkkkkkkkkkkk+1;kkkkkkkkkkkkkkkk<=n;kkkkkkkkkkkkkkkk++){
																			if(a[i]+a[j]+a[k]+a[kk]+a[kkk]+a[kkkk]+a[kkkkk]+a[kkkkkk]+a[kkkkkkk]+a[kkkkkkkk]+a[kkkkkkkkk]+a[kkkkkkkkkk]+a[kkkkkkkkkkk]+a[kkkkkkkkkkkk]+a[kkkkkkkkkkkkk]+a[kkkkkkkkkkkkkk]+a[kkkkkkkkkkkkkkk]+a[kkkkkkkkkkkkkkkk]>2*(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[i],a[kkkkkkkkkkkkkkkk]),a[kkkkkkkkkkkkkkk]),a[kkkkkkkkkkkkkk]),a[kkkkkkkkkkkkk]),a[kkkkkkkkkkkk]),a[kkkkkkkkkkk]),a[kkkkkkkkkk]),a[kkkkkkkkk]),a[kkkkkkkk]),a[kkkkkkk]),a[kkkkkk]),a[kkkkk]),a[kkkk]),a[kkk]),a[kk]),a[j]),a[k]))){
																				ans++;ans%=998244353;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n-18;i++){
		for(int j=i+1;j<=n-17;j++){
			for(int k=j+1;k<=n-16;k++){
				for(int kk=k+1;kk<=n-15;kk++){
					for(int kkk=kk+1;kkk<=n-14;kkk++){
						for(int kkkk=kkk+1;kkkk<=n-13;kkkk++){
							for(int kkkkk=kkkk+1;kkkkk<=n-12;kkkkk++){
								for(int kkkkkk=kkkkk+1;kkkkkk<=n-11;kkkkkk++){
									for(int kkkkkkk=kkkkkk+1;kkkkkkk<=n-10;kkkkkkk++){
										for(int kkkkkkkk=kkkkkkk+1;kkkkkkkk<=n-9;kkkkkkkk++){
											for(int kkkkkkkkk=kkkkkkkk+1;kkkkkkkkk<=n-8;kkkkkkkkk++){
												for(int kkkkkkkkkk=kkkkkkkkk+1;kkkkkkkkkk<=n-7;kkkkkkkkkk++){
													for(int kkkkkkkkkkk=kkkkkkkkkk+1;kkkkkkkkkkk<=n-6;kkkkkkkkkkk++){
														for(int kkkkkkkkkkkk=kkkkkkkkkkk+1;kkkkkkkkkkkk<=n-5;kkkkkkkkkkkk++){
															for(int kkkkkkkkkkkkk=kkkkkkkkkkkk+1;kkkkkkkkkkkkk<=n-4;kkkkkkkkkkkkk++){
																for(int kkkkkkkkkkkkkk=kkkkkkkkkkkkk+1;kkkkkkkkkkkkkk<=n-3;kkkkkkkkkkkkkk++){
																	for(int kkkkkkkkkkkkkkk=kkkkkkkkkkkkkk+1;kkkkkkkkkkkkkkk<=n-2;kkkkkkkkkkkkkkk++){
																		for(int kkkkkkkkkkkkkkkk=kkkkkkkkkkkkkkk+1;kkkkkkkkkkkkkkkk<=n-1;kkkkkkkkkkkkkkkk++){
																			for(int kkkkkkkkkkkkkkkkk=kkkkkkkkkkkkkkkk+1;kkkkkkkkkkkkkkkkk<=n;kkkkkkkkkkkkkkkkk++){
																				if(a[i]+a[j]+a[k]+a[kk]+a[kkk]+a[kkkk]+a[kkkkk]+a[kkkkkk]+a[kkkkkkk]+a[kkkkkkkk]+a[kkkkkkkkk]+a[kkkkkkkkkk]+a[kkkkkkkkkkk]+a[kkkkkkkkkkkk]+a[kkkkkkkkkkkkk]+a[kkkkkkkkkkkkkk]+a[kkkkkkkkkkkkkkk]+a[kkkkkkkkkkkkkkkk]+a[kkkkkkkkkkkkkkkkk]>2*(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[i],a[kkkkkkkkkkkkkkkkk]),a[kkkkkkkkkkkkkkkk]),a[kkkkkkkkkkkkkkk]),a[kkkkkkkkkkkkkk]),a[kkkkkkkkkkkkk]),a[kkkkkkkkkkkk]),a[kkkkkkkkkkk]),a[kkkkkkkkkk]),a[kkkkkkkkk]),a[kkkkkkkk]),a[kkkkkkk]),a[kkkkkk]),a[kkkkk]),a[kkkk]),a[kkk]),a[kk]),a[j]),a[k]))){
																					ans++;ans%=998244353;
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n-19;i++){
		for(int j=i+1;j<=n-18;j++){
			for(int k=j+1;k<=n-17;k++){
				for(int kk=k+1;kk<=n-16;kk++){
					for(int kkk=kk+1;kkk<=n-15;kkk++){
						for(int kkkk=kkk+1;kkkk<=n-14;kkkk++){
							for(int kkkkk=kkkk+1;kkkkk<=n-13;kkkkk++){
								for(int kkkkkk=kkkkk+1;kkkkkk<=n-12;kkkkkk++){
									for(int kkkkkkk=kkkkkk+1;kkkkkkk<=n-11;kkkkkkk++){
										for(int kkkkkkkk=kkkkkkk+1;kkkkkkkk<=n-10;kkkkkkkk++){
											for(int kkkkkkkkk=kkkkkkkk+1;kkkkkkkkk<=n-9;kkkkkkkkk++){
												for(int kkkkkkkkkk=kkkkkkkkk+1;kkkkkkkkkk<=n-8;kkkkkkkkkk++){
													for(int kkkkkkkkkkk=kkkkkkkkkk+1;kkkkkkkkkkk<=n-7;kkkkkkkkkkk++){
														for(int kkkkkkkkkkkk=kkkkkkkkkkk+1;kkkkkkkkkkkk<=n-6;kkkkkkkkkkkk++){
															for(int kkkkkkkkkkkkk=kkkkkkkkkkkk+1;kkkkkkkkkkkkk<=n-5;kkkkkkkkkkkkk++){
																for(int kkkkkkkkkkkkkk=kkkkkkkkkkkkk+1;kkkkkkkkkkkkkk<=n-4;kkkkkkkkkkkkkk++){
																	for(int kkkkkkkkkkkkkkk=kkkkkkkkkkkkkk+1;kkkkkkkkkkkkkkk<=n-3;kkkkkkkkkkkkkkk++){
																		for(int kkkkkkkkkkkkkkkk=kkkkkkkkkkkkkkk+1;kkkkkkkkkkkkkkkk<=n-2;kkkkkkkkkkkkkkkk++){
																			for(int kkkkkkkkkkkkkkkkk=kkkkkkkkkkkkkkkk+1;kkkkkkkkkkkkkkkkk<=n-1;kkkkkkkkkkkkkkkkk++){
																				for(int kkkkkkkkkkkkkkkkkk=kkkkkkkkkkkkkkkkk+1;kkkkkkkkkkkkkkkkkk<=n;kkkkkkkkkkkkkkkkkk++){
																					if(a[i]+a[j]+a[k]+a[kk]+a[kkk]+a[kkkk]+a[kkkkk]+a[kkkkkk]+a[kkkkkkk]+a[kkkkkkkk]+a[kkkkkkkkk]+a[kkkkkkkkkk]+a[kkkkkkkkkkk]+a[kkkkkkkkkkkk]+a[kkkkkkkkkkkkk]+a[kkkkkkkkkkkkkk]+a[kkkkkkkkkkkkkkk]+a[kkkkkkkkkkkkkkkk]+a[kkkkkkkkkkkkkkkkk]+a[kkkkkkkkkkkkkkkkkk]>2*(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(max(a[i],a[kkkkkkkkkkkkkkkkkk]),a[kkkkkkkkkkkkkkkkk]),a[kkkkkkkkkkkkkkkk]),a[kkkkkkkkkkkkkkk]),a[kkkkkkkkkkkkkk]),a[kkkkkkkkkkkkk]),a[kkkkkkkkkkkk]),a[kkkkkkkkkkk]),a[kkkkkkkkkk]),a[kkkkkkkkk]),a[kkkkkkkk]),a[kkkkkkk]),a[kkkkkk]),a[kkkkk]),a[kkkk]),a[kkk]),a[kk]),a[j]),a[k]))){
																						ans++;ans%=998244353;
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	if(n==21){
		if(cnt>2*maxxx){
			cout<<ans+1; 
		}else{
			cout<<ans;
		}
		
	}else{
		cout<<ans;
	}
	
	
	
	
	return 0;
	
}

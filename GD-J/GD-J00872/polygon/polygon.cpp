#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
const int mod=998244353;
int a[maxn];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<3) cout<<0;
	else if(n==3){
		int maxx=max(max(a[1],a[2]),a[3]);
		if(maxx*2<a[1]+a[2]+a[3]) cout<<1;
		else cout<<0;
	}
	else if(n==4){
		int ans=0;
		for(int a1=0;a1<=1;a1++){
			for(int a2=0;a2<=1;a2++){
				for(int a3=0;a3<=1;a3++){
					for(int a4=0;a4<=1;a4++){
						int sum=0,cnt=0,maxx=INT_MIN;
						if(a1) sum+=a[1],cnt++,maxx=max(maxx,a[1]);
						if(a2) sum+=a[2],cnt++,maxx=max(maxx,a[2]);
						if(a3) sum+=a[3],cnt++,maxx=max(maxx,a[3]);
						if(a4) sum+=a[4],cnt++,maxx=max(maxx,a[4]);
						if(cnt>=3&&sum>2*maxx) ans++;
						ans%=mod;
					}
				}
			}
		}
		cout<<ans%mod;
	}
	else if(n==5){
		int ans=0;
		for(int a1=0;a1<=1;a1++){
			for(int a2=0;a2<=1;a2++){
				for(int a3=0;a3<=1;a3++){
					for(int a4=0;a4<=1;a4++){
						for(int a5=0;a5<=1;a5++){
							int sum=0,cnt=0,maxx=INT_MIN;
							if(a1) sum+=a[1],cnt++,maxx=max(maxx,a[1]);
							if(a2) sum+=a[2],cnt++,maxx=max(maxx,a[2]);
							if(a3) sum+=a[3],cnt++,maxx=max(maxx,a[3]);
							if(a4) sum+=a[4],cnt++,maxx=max(maxx,a[4]);
							if(a5) sum+=a[5],cnt++,maxx=max(maxx,a[5]);
							if(cnt>=3&&sum>2*maxx) ans++;
							ans%=mod;
						}
					}
				}
			}
		}
		cout<<ans%mod;
	}
	else if(n==6){
		int ans=0;
		for(int a1=0;a1<=1;a1++){
			for(int a2=0;a2<=1;a2++){
				for(int a3=0;a3<=1;a3++){
					for(int a4=0;a4<=1;a4++){
						for(int a5=0;a5<=1;a5++){
							for(int a6=0;a6<=1;a6++){
								int sum=0,cnt=0,maxx=INT_MIN;
								if(a1) sum+=a[1],cnt++,maxx=max(maxx,a[1]);
								if(a2) sum+=a[2],cnt++,maxx=max(maxx,a[2]);
								if(a3) sum+=a[3],cnt++,maxx=max(maxx,a[3]);
								if(a4) sum+=a[4],cnt++,maxx=max(maxx,a[4]);
								if(a5) sum+=a[5],cnt++,maxx=max(maxx,a[5]);
								if(a6) sum+=a[6],cnt++,maxx=max(maxx,a[6]);
								if(cnt>=3&&sum>2*maxx) ans++;
								ans%=mod;
							}
						}
					}
				}
			}
		}
		cout<<ans%mod;
	}
	else if(n==7){
		int ans=0;
		for(int a1=0;a1<=1;a1++){
			for(int a2=0;a2<=1;a2++){
				for(int a3=0;a3<=1;a3++){
					for(int a4=0;a4<=1;a4++){
						for(int a5=0;a5<=1;a5++){
							for(int a6=0;a6<=1;a6++){
								for(int a7=0;a7<=1;a7++){
									int sum=0,cnt=0,maxx=INT_MIN;
									if(a1) sum+=a[1],cnt++,maxx=max(maxx,a[1]);
									if(a2) sum+=a[2],cnt++,maxx=max(maxx,a[2]);
									if(a3) sum+=a[3],cnt++,maxx=max(maxx,a[3]);
									if(a4) sum+=a[4],cnt++,maxx=max(maxx,a[4]);
									if(a5) sum+=a[5],cnt++,maxx=max(maxx,a[5]);
									if(a6) sum+=a[6],cnt++,maxx=max(maxx,a[6]);
									if(a7) sum+=a[7],cnt++,maxx=max(maxx,a[7]);
									if(cnt>=3&&sum>2*maxx) ans++;
									ans%=mod;
								}
							}
						}
					}
				}
			}
		}
		cout<<ans%mod;
	}
	else if(n==8){
		int ans=0;
		for(int a1=0;a1<=1;a1++){
			for(int a2=0;a2<=1;a2++){
				for(int a3=0;a3<=1;a3++){
					for(int a4=0;a4<=1;a4++){
						for(int a5=0;a5<=1;a5++){
							for(int a6=0;a6<=1;a6++){
								for(int a7=0;a7<=1;a7++){
									for(int a8=0;a8<=1;a8++){
										int sum=0,cnt=0,maxx=INT_MIN;
										if(a1) sum+=a[1],cnt++,maxx=max(maxx,a[1]);
										if(a2) sum+=a[2],cnt++,maxx=max(maxx,a[2]);
										if(a3) sum+=a[3],cnt++,maxx=max(maxx,a[3]);
										if(a4) sum+=a[4],cnt++,maxx=max(maxx,a[4]);
										if(a5) sum+=a[5],cnt++,maxx=max(maxx,a[5]);
										if(a6) sum+=a[6],cnt++,maxx=max(maxx,a[6]);
										if(a7) sum+=a[7],cnt++,maxx=max(maxx,a[7]);
										if(a8) sum+=a[8],cnt++,maxx=max(maxx,a[8]);
										if(cnt>=3&&sum>2*maxx) ans++;
										ans%=mod;
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans%mod;
	}
	else if(n==9){
		int ans=0;
		for(int a1=0;a1<=1;a1++){
			for(int a2=0;a2<=1;a2++){
				for(int a3=0;a3<=1;a3++){
					for(int a4=0;a4<=1;a4++){
						for(int a5=0;a5<=1;a5++){
							for(int a6=0;a6<=1;a6++){
								for(int a7=0;a7<=1;a7++){
									for(int a8=0;a8<=1;a8++){
										for(int a9=0;a9<=1;a9++){
											int sum=0,cnt=0,maxx=INT_MIN;
											if(a1) sum+=a[1],cnt++,maxx=max(maxx,a[1]);
											if(a2) sum+=a[2],cnt++,maxx=max(maxx,a[2]);
											if(a3) sum+=a[3],cnt++,maxx=max(maxx,a[3]);
											if(a4) sum+=a[4],cnt++,maxx=max(maxx,a[4]);
											if(a5) sum+=a[5],cnt++,maxx=max(maxx,a[5]);
											if(a6) sum+=a[6],cnt++,maxx=max(maxx,a[6]);
											if(a7) sum+=a[7],cnt++,maxx=max(maxx,a[7]);
											if(a8) sum+=a[8],cnt++,maxx=max(maxx,a[8]);
											if(a9) sum+=a[9],cnt++,maxx=max(maxx,a[9]);
											if(cnt>=3&&sum>2*maxx) ans++;
											ans%=mod;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans%mod;
	}
	else if(n==10){
		int ans=0;
		for(int a1=0;a1<=1;a1++){
			for(int a2=0;a2<=1;a2++){
				for(int a3=0;a3<=1;a3++){
					for(int a4=0;a4<=1;a4++){
						for(int a5=0;a5<=1;a5++){
							for(int a6=0;a6<=1;a6++){
								for(int a7=0;a7<=1;a7++){
									for(int a8=0;a8<=1;a8++){
										for(int a9=0;a9<=1;a9++){
											for(int a10=0;a10<=1;a10++){
												int sum=0,cnt=0,maxx=INT_MIN;
												if(a1) sum+=a[1],cnt++,maxx=max(maxx,a[1]);
												if(a2) sum+=a[2],cnt++,maxx=max(maxx,a[2]);
												if(a3) sum+=a[3],cnt++,maxx=max(maxx,a[3]);
												if(a4) sum+=a[4],cnt++,maxx=max(maxx,a[4]);
												if(a5) sum+=a[5],cnt++,maxx=max(maxx,a[5]);
												if(a6) sum+=a[6],cnt++,maxx=max(maxx,a[6]);
												if(a7) sum+=a[7],cnt++,maxx=max(maxx,a[7]);
												if(a8) sum+=a[8],cnt++,maxx=max(maxx,a[8]);
												if(a9) sum+=a[9],cnt++,maxx=max(maxx,a[9]);
												if(a10) sum+=a[10],cnt++,maxx=max(maxx,a[10]);
												if(cnt>=3&&sum>2*maxx) ans++;
												ans%=mod;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans%mod;
	}
	else if(n==11){
		int ans=0;
		for(int a1=0;a1<=1;a1++){
			for(int a2=0;a2<=1;a2++){
				for(int a3=0;a3<=1;a3++){
					for(int a4=0;a4<=1;a4++){
						for(int a5=0;a5<=1;a5++){
							for(int a6=0;a6<=1;a6++){
								for(int a7=0;a7<=1;a7++){
									for(int a8=0;a8<=1;a8++){
										for(int a9=0;a9<=1;a9++){
											for(int a10=0;a10<=1;a10++){
												for(int a11=0;a11<=1;a11++){
													int sum=0,cnt=0,maxx=INT_MIN;
													if(a1) sum+=a[1],cnt++,maxx=max(maxx,a[1]);
													if(a2) sum+=a[2],cnt++,maxx=max(maxx,a[2]);
													if(a3) sum+=a[3],cnt++,maxx=max(maxx,a[3]);
													if(a4) sum+=a[4],cnt++,maxx=max(maxx,a[4]);
													if(a5) sum+=a[5],cnt++,maxx=max(maxx,a[5]);
													if(a6) sum+=a[6],cnt++,maxx=max(maxx,a[6]);
													if(a7) sum+=a[7],cnt++,maxx=max(maxx,a[7]);
													if(a8) sum+=a[8],cnt++,maxx=max(maxx,a[8]);
													if(a9) sum+=a[9],cnt++,maxx=max(maxx,a[9]);
													if(a10) sum+=a[10],cnt++,maxx=max(maxx,a[10]);
													if(a11) sum+=a[11],cnt++,maxx=max(maxx,a[11]);
													if(cnt>=3&&sum>2*maxx) ans++;
													ans%=mod;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans%mod;
	}
	else if(n==12){
		int ans=0;
		for(int a1=0;a1<=1;a1++){
			for(int a2=0;a2<=1;a2++){
				for(int a3=0;a3<=1;a3++){
					for(int a4=0;a4<=1;a4++){
						for(int a5=0;a5<=1;a5++){
							for(int a6=0;a6<=1;a6++){
								for(int a7=0;a7<=1;a7++){
									for(int a8=0;a8<=1;a8++){
										for(int a9=0;a9<=1;a9++){
											for(int a10=0;a10<=1;a10++){
												for(int a11=0;a11<=1;a11++){
													for(int a12=0;a12<=1;a12++){
														int sum=0,cnt=0,maxx=INT_MIN;
														if(a1) sum+=a[1],cnt++,maxx=max(maxx,a[1]);
														if(a2) sum+=a[2],cnt++,maxx=max(maxx,a[2]);
														if(a3) sum+=a[3],cnt++,maxx=max(maxx,a[3]);
														if(a4) sum+=a[4],cnt++,maxx=max(maxx,a[4]);
														if(a5) sum+=a[5],cnt++,maxx=max(maxx,a[5]);
														if(a6) sum+=a[6],cnt++,maxx=max(maxx,a[6]);
														if(a7) sum+=a[7],cnt++,maxx=max(maxx,a[7]);
														if(a8) sum+=a[8],cnt++,maxx=max(maxx,a[8]);
														if(a9) sum+=a[9],cnt++,maxx=max(maxx,a[9]);
														if(a10) sum+=a[10],cnt++,maxx=max(maxx,a[10]);
														if(a11) sum+=a[11],cnt++,maxx=max(maxx,a[11]);
														if(a12) sum+=a[12],cnt++,maxx=max(maxx,a[12]);
														if(cnt>=3&&sum>2*maxx) ans++;
														ans%=mod;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans%mod;
	}
	else if(n==13){
		int ans=0;
		for(int a1=0;a1<=1;a1++){
			for(int a2=0;a2<=1;a2++){
				for(int a3=0;a3<=1;a3++){
					for(int a4=0;a4<=1;a4++){
						for(int a5=0;a5<=1;a5++){
							for(int a6=0;a6<=1;a6++){
								for(int a7=0;a7<=1;a7++){
									for(int a8=0;a8<=1;a8++){
										for(int a9=0;a9<=1;a9++){
											for(int a10=0;a10<=1;a10++){
												for(int a11=0;a11<=1;a11++){
													for(int a12=0;a12<=1;a12++){
														for(int a13=0;a13<=1;a13++){
															int sum=0,cnt=0,maxx=INT_MIN;
															if(a1) sum+=a[1],cnt++,maxx=max(maxx,a[1]);
															if(a2) sum+=a[2],cnt++,maxx=max(maxx,a[2]);
															if(a3) sum+=a[3],cnt++,maxx=max(maxx,a[3]);
															if(a4) sum+=a[4],cnt++,maxx=max(maxx,a[4]);
															if(a5) sum+=a[5],cnt++,maxx=max(maxx,a[5]);
															if(a6) sum+=a[6],cnt++,maxx=max(maxx,a[6]);
															if(a7) sum+=a[7],cnt++,maxx=max(maxx,a[7]);
															if(a8) sum+=a[8],cnt++,maxx=max(maxx,a[8]);
															if(a9) sum+=a[9],cnt++,maxx=max(maxx,a[9]);
															if(a10) sum+=a[10],cnt++,maxx=max(maxx,a[10]);
															if(a11) sum+=a[11],cnt++,maxx=max(maxx,a[11]);
															if(a12) sum+=a[12],cnt++,maxx=max(maxx,a[12]);
															if(a13) sum+=a[13],cnt++,maxx=max(maxx,a[13]);
															if(cnt>=3&&sum>2*maxx) ans++;
															ans%=mod;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans%mod;
	}
	else if(n==14){
		int ans=0;
		for(int a1=0;a1<=1;a1++){
			for(int a2=0;a2<=1;a2++){
				for(int a3=0;a3<=1;a3++){
					for(int a4=0;a4<=1;a4++){
						for(int a5=0;a5<=1;a5++){
							for(int a6=0;a6<=1;a6++){
								for(int a7=0;a7<=1;a7++){
									for(int a8=0;a8<=1;a8++){
										for(int a9=0;a9<=1;a9++){
											for(int a10=0;a10<=1;a10++){
												for(int a11=0;a11<=1;a11++){
													for(int a12=0;a12<=1;a12++){
														for(int a13=0;a13<=1;a13++){
															for(int a14=0;a14<=1;a14++){
																int sum=0,cnt=0,maxx=INT_MIN;
																if(a1) sum+=a[1],cnt++,maxx=max(maxx,a[1]);
																if(a2) sum+=a[2],cnt++,maxx=max(maxx,a[2]);
																if(a3) sum+=a[3],cnt++,maxx=max(maxx,a[3]);
																if(a4) sum+=a[4],cnt++,maxx=max(maxx,a[4]);
																if(a5) sum+=a[5],cnt++,maxx=max(maxx,a[5]);
																if(a6) sum+=a[6],cnt++,maxx=max(maxx,a[6]);
																if(a7) sum+=a[7],cnt++,maxx=max(maxx,a[7]);
																if(a8) sum+=a[8],cnt++,maxx=max(maxx,a[8]);
																if(a9) sum+=a[9],cnt++,maxx=max(maxx,a[9]);
																if(a10) sum+=a[10],cnt++,maxx=max(maxx,a[10]);
																if(a11) sum+=a[11],cnt++,maxx=max(maxx,a[11]);
																if(a12) sum+=a[12],cnt++,maxx=max(maxx,a[12]);
																if(a13) sum+=a[13],cnt++,maxx=max(maxx,a[13]);
																if(a14) sum+=a[14],cnt++,maxx=max(maxx,a[14]);
																if(cnt>=3&&sum>2*maxx) ans++;
																ans%=mod;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans%mod;
	}
	else if(n==15){
		int ans=0;
		for(int a1=0;a1<=1;a1++){
			for(int a2=0;a2<=1;a2++){
				for(int a3=0;a3<=1;a3++){
					for(int a4=0;a4<=1;a4++){
						for(int a5=0;a5<=1;a5++){
							for(int a6=0;a6<=1;a6++){
								for(int a7=0;a7<=1;a7++){
									for(int a8=0;a8<=1;a8++){
										for(int a9=0;a9<=1;a9++){
											for(int a10=0;a10<=1;a10++){
												for(int a11=0;a11<=1;a11++){
													for(int a12=0;a12<=1;a12++){
														for(int a13=0;a13<=1;a13++){
															for(int a14=0;a14<=1;a14++){
																for(int a15=0;a15<=1;a15++){
																	int sum=0,cnt=0,maxx=INT_MIN;
																	if(a1) sum+=a[1],cnt++,maxx=max(maxx,a[1]);
																	if(a2) sum+=a[2],cnt++,maxx=max(maxx,a[2]);
																	if(a3) sum+=a[3],cnt++,maxx=max(maxx,a[3]);
																	if(a4) sum+=a[4],cnt++,maxx=max(maxx,a[4]);
																	if(a5) sum+=a[5],cnt++,maxx=max(maxx,a[5]);
																	if(a6) sum+=a[6],cnt++,maxx=max(maxx,a[6]);
																	if(a7) sum+=a[7],cnt++,maxx=max(maxx,a[7]);
																	if(a8) sum+=a[8],cnt++,maxx=max(maxx,a[8]);
																	if(a9) sum+=a[9],cnt++,maxx=max(maxx,a[9]);
																	if(a10) sum+=a[10],cnt++,maxx=max(maxx,a[10]);
																	if(a11) sum+=a[11],cnt++,maxx=max(maxx,a[11]);
																	if(a12) sum+=a[12],cnt++,maxx=max(maxx,a[12]);
																	if(a13) sum+=a[13],cnt++,maxx=max(maxx,a[13]);
																	if(a14) sum+=a[14],cnt++,maxx=max(maxx,a[14]);
																	if(a15) sum+=a[15],cnt++,maxx=max(maxx,a[15]);
																	if(cnt>=3&&sum>2*maxx) ans++;
																	ans%=mod;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans%mod;
	}
	else if(n==16){
		int ans=0;
		for(int a1=0;a1<=1;a1++){
			for(int a2=0;a2<=1;a2++){
				for(int a3=0;a3<=1;a3++){
					for(int a4=0;a4<=1;a4++){
						for(int a5=0;a5<=1;a5++){
							for(int a6=0;a6<=1;a6++){
								for(int a7=0;a7<=1;a7++){
									for(int a8=0;a8<=1;a8++){
										for(int a9=0;a9<=1;a9++){
											for(int a10=0;a10<=1;a10++){
												for(int a11=0;a11<=1;a11++){
													for(int a12=0;a12<=1;a12++){
														for(int a13=0;a13<=1;a13++){
															for(int a14=0;a14<=1;a14++){
																for(int a15=0;a15<=1;a15++){
																	for(int a16=0;a16<=1;a16++){
																		int sum=0,cnt=0,maxx=INT_MIN;
																		if(a1) sum+=a[1],cnt++,maxx=max(maxx,a[1]);
																		if(a2) sum+=a[2],cnt++,maxx=max(maxx,a[2]);
																		if(a3) sum+=a[3],cnt++,maxx=max(maxx,a[3]);
																		if(a4) sum+=a[4],cnt++,maxx=max(maxx,a[4]);
																		if(a5) sum+=a[5],cnt++,maxx=max(maxx,a[5]);
																		if(a6) sum+=a[6],cnt++,maxx=max(maxx,a[6]);
																		if(a7) sum+=a[7],cnt++,maxx=max(maxx,a[7]);
																		if(a8) sum+=a[8],cnt++,maxx=max(maxx,a[8]);
																		if(a9) sum+=a[9],cnt++,maxx=max(maxx,a[9]);
																		if(a10) sum+=a[10],cnt++,maxx=max(maxx,a[10]);
																		if(a11) sum+=a[11],cnt++,maxx=max(maxx,a[11]);
																		if(a12) sum+=a[12],cnt++,maxx=max(maxx,a[12]);
																		if(a13) sum+=a[13],cnt++,maxx=max(maxx,a[13]);
																		if(a14) sum+=a[14],cnt++,maxx=max(maxx,a[14]);
																		if(a15) sum+=a[15],cnt++,maxx=max(maxx,a[15]);
																		if(a16) sum+=a[16],cnt++,maxx=max(maxx,a[16]);
																		if(cnt>=3&&sum>2*maxx) ans++;
																		ans%=mod;
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans%mod;
	}
	else if(n==17){
		int ans=0;
		for(int a1=0;a1<=1;a1++){
			for(int a2=0;a2<=1;a2++){
				for(int a3=0;a3<=1;a3++){
					for(int a4=0;a4<=1;a4++){
						for(int a5=0;a5<=1;a5++){
							for(int a6=0;a6<=1;a6++){
								for(int a7=0;a7<=1;a7++){
									for(int a8=0;a8<=1;a8++){
										for(int a9=0;a9<=1;a9++){
											for(int a10=0;a10<=1;a10++){
												for(int a11=0;a11<=1;a11++){
													for(int a12=0;a12<=1;a12++){
														for(int a13=0;a13<=1;a13++){
															for(int a14=0;a14<=1;a14++){
																for(int a15=0;a15<=1;a15++){
																	for(int a16=0;a16<=1;a16++){
																		for(int a17=0;a17<=1;a17++){
																			int sum=0,cnt=0,maxx=INT_MIN;
																			if(a1) sum+=a[1],cnt++,maxx=max(maxx,a[1]);
																			if(a2) sum+=a[2],cnt++,maxx=max(maxx,a[2]);
																			if(a3) sum+=a[3],cnt++,maxx=max(maxx,a[3]);
																			if(a4) sum+=a[4],cnt++,maxx=max(maxx,a[4]);
																			if(a5) sum+=a[5],cnt++,maxx=max(maxx,a[5]);
																			if(a6) sum+=a[6],cnt++,maxx=max(maxx,a[6]);
																			if(a7) sum+=a[7],cnt++,maxx=max(maxx,a[7]);
																			if(a8) sum+=a[8],cnt++,maxx=max(maxx,a[8]);
																			if(a9) sum+=a[9],cnt++,maxx=max(maxx,a[9]);
																			if(a10) sum+=a[10],cnt++,maxx=max(maxx,a[10]);
																			if(a11) sum+=a[11],cnt++,maxx=max(maxx,a[11]);
																			if(a12) sum+=a[12],cnt++,maxx=max(maxx,a[12]);
																			if(a13) sum+=a[13],cnt++,maxx=max(maxx,a[13]);
																			if(a14) sum+=a[14],cnt++,maxx=max(maxx,a[14]);
																			if(a15) sum+=a[15],cnt++,maxx=max(maxx,a[15]);
																			if(a16) sum+=a[16],cnt++,maxx=max(maxx,a[16]);
																			if(a17) sum+=a[17],cnt++,maxx=max(maxx,a[17]);
																			if(cnt>=3&&sum>2*maxx) ans++;
																			ans%=mod;
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans%mod;
	}
	else if(n==18){
		int ans=0;
		for(int a1=0;a1<=1;a1++){
			for(int a2=0;a2<=1;a2++){
				for(int a3=0;a3<=1;a3++){
					for(int a4=0;a4<=1;a4++){
						for(int a5=0;a5<=1;a5++){
							for(int a6=0;a6<=1;a6++){
								for(int a7=0;a7<=1;a7++){
									for(int a8=0;a8<=1;a8++){
										for(int a9=0;a9<=1;a9++){
											for(int a10=0;a10<=1;a10++){
												for(int a11=0;a11<=1;a11++){
													for(int a12=0;a12<=1;a12++){
														for(int a13=0;a13<=1;a13++){
															for(int a14=0;a14<=1;a14++){
																for(int a15=0;a15<=1;a15++){
																	for(int a16=0;a16<=1;a16++){
																		for(int a17=0;a17<=1;a17++){
																			for(int a18=0;a18<=1;a18++){
																				int sum=0,cnt=0,maxx=INT_MIN;
																				if(a1) sum+=a[1],cnt++,maxx=max(maxx,a[1]);
																				if(a2) sum+=a[2],cnt++,maxx=max(maxx,a[2]);
																				if(a3) sum+=a[3],cnt++,maxx=max(maxx,a[3]);
																				if(a4) sum+=a[4],cnt++,maxx=max(maxx,a[4]);
																				if(a5) sum+=a[5],cnt++,maxx=max(maxx,a[5]);
																				if(a6) sum+=a[6],cnt++,maxx=max(maxx,a[6]);
																				if(a7) sum+=a[7],cnt++,maxx=max(maxx,a[7]);
																				if(a8) sum+=a[8],cnt++,maxx=max(maxx,a[8]);
																				if(a9) sum+=a[9],cnt++,maxx=max(maxx,a[9]);
																				if(a10) sum+=a[10],cnt++,maxx=max(maxx,a[10]);
																				if(a11) sum+=a[11],cnt++,maxx=max(maxx,a[11]);
																				if(a12) sum+=a[12],cnt++,maxx=max(maxx,a[12]);
																				if(a13) sum+=a[13],cnt++,maxx=max(maxx,a[13]);
																				if(a14) sum+=a[14],cnt++,maxx=max(maxx,a[14]);
																				if(a15) sum+=a[15],cnt++,maxx=max(maxx,a[15]);
																				if(a16) sum+=a[16],cnt++,maxx=max(maxx,a[16]);
																				if(a17) sum+=a[17],cnt++,maxx=max(maxx,a[17]);
																				if(a18) sum+=a[18],cnt++,maxx=max(maxx,a[18]);
																				if(cnt>=3&&sum>2*maxx) ans++;
																				ans%=mod;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans%mod;
	}
	else if(n==19){
		int ans=0;
		for(int a1=0;a1<=1;a1++){
			for(int a2=0;a2<=1;a2++){
				for(int a3=0;a3<=1;a3++){
					for(int a4=0;a4<=1;a4++){
						for(int a5=0;a5<=1;a5++){
							for(int a6=0;a6<=1;a6++){
								for(int a7=0;a7<=1;a7++){
									for(int a8=0;a8<=1;a8++){
										for(int a9=0;a9<=1;a9++){
											for(int a10=0;a10<=1;a10++){
												for(int a11=0;a11<=1;a11++){
													for(int a12=0;a12<=1;a12++){
														for(int a13=0;a13<=1;a13++){
															for(int a14=0;a14<=1;a14++){
																for(int a15=0;a15<=1;a15++){
																	for(int a16=0;a16<=1;a16++){
																		for(int a17=0;a17<=1;a17++){
																			for(int a18=0;a18<=1;a18++){
																				for(int a19=0;a19<=1;a19++){
																					int sum=0,cnt=0,maxx=INT_MIN;
																					if(a1) sum+=a[1],cnt++,maxx=max(maxx,a[1]);
																					if(a2) sum+=a[2],cnt++,maxx=max(maxx,a[2]);
																					if(a3) sum+=a[3],cnt++,maxx=max(maxx,a[3]);
																					if(a4) sum+=a[4],cnt++,maxx=max(maxx,a[4]);
																					if(a5) sum+=a[5],cnt++,maxx=max(maxx,a[5]);
																					if(a6) sum+=a[6],cnt++,maxx=max(maxx,a[6]);
																					if(a7) sum+=a[7],cnt++,maxx=max(maxx,a[7]);
																					if(a8) sum+=a[8],cnt++,maxx=max(maxx,a[8]);
																					if(a9) sum+=a[9],cnt++,maxx=max(maxx,a[9]);
																					if(a10) sum+=a[10],cnt++,maxx=max(maxx,a[10]);
																					if(a11) sum+=a[11],cnt++,maxx=max(maxx,a[11]);
																					if(a12) sum+=a[12],cnt++,maxx=max(maxx,a[12]);
																					if(a13) sum+=a[13],cnt++,maxx=max(maxx,a[13]);
																					if(a14) sum+=a[14],cnt++,maxx=max(maxx,a[14]);
																					if(a15) sum+=a[15],cnt++,maxx=max(maxx,a[15]);
																					if(a16) sum+=a[16],cnt++,maxx=max(maxx,a[16]);
																					if(a17) sum+=a[17],cnt++,maxx=max(maxx,a[17]);
																					if(a18) sum+=a[18],cnt++,maxx=max(maxx,a[18]);
																					if(a19) sum+=a[19],cnt++,maxx=max(maxx,a[19]);
																					if(cnt>=3&&sum>2*maxx) ans++;
																					ans%=mod;
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans%mod;
	}
	else if(n==20){
		int ans=0;
		for(int a1=0;a1<=1;a1++){
			for(int a2=0;a2<=1;a2++){
				for(int a3=0;a3<=1;a3++){
					for(int a4=0;a4<=1;a4++){
						for(int a5=0;a5<=1;a5++){
							for(int a6=0;a6<=1;a6++){
								for(int a7=0;a7<=1;a7++){
									for(int a8=0;a8<=1;a8++){
										for(int a9=0;a9<=1;a9++){
											for(int a10=0;a10<=1;a10++){
												for(int a11=0;a11<=1;a11++){
													for(int a12=0;a12<=1;a12++){
														for(int a13=0;a13<=1;a13++){
															for(int a14=0;a14<=1;a14++){
																for(int a15=0;a15<=1;a15++){
																	for(int a16=0;a16<=1;a16++){
																		for(int a17=0;a17<=1;a17++){
																			for(int a18=0;a18<=1;a18++){
																				for(int a19=0;a19<=1;a19++){
																					for(int a20=0;a20<=1;a20++){
																						int sum=0,cnt=0,maxx=INT_MIN;
																						if(a1) sum+=a[1],cnt++,maxx=max(maxx,a[1]);
																						if(a2) sum+=a[2],cnt++,maxx=max(maxx,a[2]);
																						if(a3) sum+=a[3],cnt++,maxx=max(maxx,a[3]);
																						if(a4) sum+=a[4],cnt++,maxx=max(maxx,a[4]);
																						if(a5) sum+=a[5],cnt++,maxx=max(maxx,a[5]);
																						if(a6) sum+=a[6],cnt++,maxx=max(maxx,a[6]);
																						if(a7) sum+=a[7],cnt++,maxx=max(maxx,a[7]);
																						if(a8) sum+=a[8],cnt++,maxx=max(maxx,a[8]);
																						if(a9) sum+=a[9],cnt++,maxx=max(maxx,a[9]);
																						if(a10) sum+=a[10],cnt++,maxx=max(maxx,a[10]);
																						if(a11) sum+=a[11],cnt++,maxx=max(maxx,a[11]);
																						if(a12) sum+=a[12],cnt++,maxx=max(maxx,a[12]);
																						if(a13) sum+=a[13],cnt++,maxx=max(maxx,a[13]);
																						if(a14) sum+=a[14],cnt++,maxx=max(maxx,a[14]);
																						if(a15) sum+=a[15],cnt++,maxx=max(maxx,a[15]);
																						if(a16) sum+=a[16],cnt++,maxx=max(maxx,a[16]);
																						if(a17) sum+=a[17],cnt++,maxx=max(maxx,a[17]);
																						if(a18) sum+=a[18],cnt++,maxx=max(maxx,a[18]);
																						if(a19) sum+=a[19],cnt++,maxx=max(maxx,a[19]);
																						if(a20) sum+=a[20],cnt++,maxx=max(maxx,a[20]);
																						if(cnt>=3&&sum>2*maxx) ans++;
																						ans%=mod;
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans%mod;
	}
	return 0;
}

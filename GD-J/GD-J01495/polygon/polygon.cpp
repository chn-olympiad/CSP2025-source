#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	long long cnt=0;
	for(int k=1;k<=n;k++)cin>>a[k];
	int k=1;
		for(int len=3;len<=n;len++){
			if(len==3){
				for(int k1=k;k1<=n;k1++){
					for(int k2=k1+1;k2<=n;k2++){
						for(int k3=k2+1;k3<=n;k3++){
							if(k1!=k2&&k2!=k3&&k3!=k1){
								int ma=0;
								int c=a[k1]+a[k2]+a[k3];
								ma=max(ma,max(a[k1],max(a[k2],a[k3])));
								if(c>ma*2){
									cnt=(cnt+1)%998244353;
								}
							}
						}
					}
				}
			}else if(len==4){
				for(int k1=k;k1<=n;k1++){
					for(int k2=k1+1;k2<=n;k2++){
						for(int k3=k2+1;k3<=n;k3++){
							for(int k4=k3+1;k4<=n;k4++){
								if(k1!=k2&&k2!=k3&&k3!=k1&&k4!=k3&&k4!=k2&&k4!=k1){
									int ma=0;
									int c=a[k1]+a[k2]+a[k3]+a[k4];
									ma=max(ma,max(a[k1],max(a[k2],max(a[k3],a[k4]))));
									if(c>ma*2){
									cnt=(cnt+1)%998244353;
								}
							    }
							}
						}
					}
				}
			}else if(len==5){
				for(int k1=k;k1<=n;k1++){
					for(int k2=k1+1;k2<=n;k2++){
						for(int k3=k2+1;k3<=n;k3++){
							for(int k4=k3+1;k4<=n;k4++){
								for(int k5=k4+1;k5<=n;k5++){
									if(k1!=k2&&k2!=k3&&k3!=k1&&k4!=k3&&k4!=k2&&k4!=k1&&k5!=k1&&k5!=k2&&k5!=k3&&k5!=k4){
										int ma=0;
										int c=a[k1]+a[k2]+a[k3]+a[k4]+a[k5];
										ma=max(ma,max(a[k1],max(a[k2],max(a[k3],max(a[k4],a[k5])))));
										if(c>ma*2){
									cnt=(cnt+1)%998244353;
								}
								    }
								}
							}
						}
					}
				}
			}else if(len==6){
				for(int k1=k;k1<=n;k1++){
					for(int k2=k1+1;k2<=n;k2++){
						for(int k3=k2+1;k3<=n;k3++){
							for(int k4=k3+1;k4<=n;k4++){
								for(int k5=k4+1;k5<=n;k5++){
									for(int k6=k5+1;k6<=n;k6++){
										if(k1!=k2&&k2!=k3&&k3!=k1&&k4!=k3&&k4!=k2&&k4!=k1&&k5!=k1&&k5!=k2&&k5!=k3&&k5!=k4&&k6!=k1&&k6!=k2&&k6!=k3&&k6!=k4&&k6!=k5){
											int ma=0;
											int c=a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6];
											ma=max(ma,max(a[k1],max(a[k2],max(a[k3],max(a[k4],max(a[k5],a[k6]))))));
											if(c>ma*2)cnt=(cnt+1)%998244353;
									    }
									}
								}
							}
						}
					}
				}
			}else if(len==7){
				for(int k1=k;k1<=n;k1++){
					for(int k2=k1+1;k2<=n;k2++){
						for(int k3=k2+1;k3<=n;k3++){
							for(int k4=k3+1;k4<=n;k4++){
								for(int k5=k4+1;k5<=n;k5++){
									for(int k6=k5+1;k6<=n;k6++){
										for(int k7=k6+1;k7<=n;k7++){
											if(k1!=k2&&k2!=k3&&k3!=k1&&k4!=k3&&k4!=k2&&k4!=k1&&k5!=k1&&k5!=k2&&k5!=k3&&k5!=k4&&k6!=k1&&k6!=k2&&k6!=k3&&k6!=k4&&k6!=k5&&k7!=k6&&k7!=k5&&k7!=k4&&k7!=k3&&k7!=k2&&k7!=k1){
												int ma=0;
												int c=a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7];
												ma=max(ma,max(a[k1],max(a[k2],max(a[k3],max(a[k4],max(a[k5],max(a[k6],a[k7])))))));
												if(c>ma*2)cnt=(cnt+1)%998244353;
										    }
										}
									}
								}
							}
						}
					}
				}
			}else if(len==8){
				for(int k1=k;k1<=n;k1++){
					for(int k2=k1+1;k2<=n;k2++){
						for(int k3=k2+1;k3<=n;k3++){
							for(int k4=k3+1;k4<=n;k4++){
								for(int k5=k4+1;k5<=n;k5++){
									for(int k6=k5+1;k6<=n;k6++){
										for(int k7=k6+1;k7<=n;k7++){
											for(int k8=k7+1;k8<=n;k8++){
												if(k1!=k2&&k2!=k3&&k3!=k1&&k4!=k3&&k4!=k2&&k4!=k1&&k5!=k1&&k5!=k2&&k5!=k3&&k5!=k4&&k6!=k1&&k6!=k2&&k6!=k3&&k6!=k4&&k6!=k5&&k7!=k6&&k7!=k5&&k7!=k4&&k7!=k3&&k7!=k2&&k7!=k1&&k8!=k1&&k8!=k2&&k8!=k3&&k8!=k4&&k8!=k5&&k8!=k6&&k8!=k7){
													int ma=0;
													int c=a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8];
													ma=max(ma,max(a[k1],max(a[k2],max(a[k3],max(a[k4],max(a[k5],max(a[k6],max(a[k7],a[k8]))))))));
													if(c>ma*2)cnt=(cnt+1)%998244353;
											    }
											}
										}
									}
								}
							}
						}
					}
				}
			}else if(len==9){
				for(int k1=k;k1<=n;k1++){
					for(int k2=k1+1;k2<=n;k2++){
						for(int k3=k2+1;k3<=n;k3++){
							for(int k4=k3+1;k4<=n;k4++){
								for(int k5=k4+1;k5<=n;k5++){
									for(int k6=k5+1;k6<=n;k6++){
										for(int k7=k6+1;k7<=n;k7++){
											for(int k8=k7+1;k8<=n;k8++){
												for(int k9=k8+1;k9<=n;k9++){
													if(k1!=k2&&k2!=k3&&k3!=k1&&k4!=k3&&k4!=k2&&k4!=k1&&k5!=k1&&k5!=k2&&k5!=k3&&k5!=k4&&k6!=k1&&k6!=k2&&k6!=k3&&k6!=k4&&k6!=k5&&k7!=k6&&k7!=k5&&k7!=k4&&k7!=k3&&k7!=k2&&k7!=k1&&k8!=k1&&k8!=k2&&k8!=k3&&k8!=k4&&k8!=k5&&k8!=k6&&k8!=k7&&k9!=k1&&k9!=k2&&k9!=k3&&k9!=k4&&k9!=k5&&k9!=k6&&k9!=k7&&k9!=k8){
														int ma=0;
														int c=a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8]+a[k9];
														ma=max(ma,max(a[k1],max(a[k2],max(a[k3],max(a[k4],max(a[k5],max(a[k6],max(a[k7],max(a[k8],a[k9])))))))));
														if(c>ma*2)cnt=(cnt+1)%998244353;
												    }
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}else if(len==10){
				for(int k1=k;k1<=n;k1++){
					for(int k2=k1+1;k2<=n;k2++){
						for(int k3=k2+1;k3<=n;k3++){
							for(int k4=k3+1;k4<=n;k4++){
								for(int k5=k4+1;k5<=n;k5++){
									for(int k6=k5+1;k6<=n;k6++){
										for(int k7=k6+1;k7<=n;k7++){
											for(int k8=k7+1;k8<=n;k8++){
												for(int k9=k8+1;k9<=n;k9++){
													for(int k10=k9+1;k10<=n;k10++){
														if(k1!=k2&&k2!=k3&&k3!=k1&&k4!=k3&&k4!=k2&&k4!=k1&&k5!=k1&&k5!=k2&&k5!=k3&&k5!=k4&&k6!=k1&&k6!=k2&&k6!=k3&&k6!=k4&&k6!=k5&&k7!=k6&&k7!=k5&&k7!=k4&&k7!=k3&&k7!=k2&&k7!=k1&&k8!=k1&&k8!=k2&&k8!=k3&&k8!=k4&&k8!=k5&&k8!=k6&&k8!=k7&&k9!=k1&&k9!=k2&&k9!=k3&&k9!=k4&&k9!=k5&&k9!=k6&&k9!=k7&&k9!=k8&&k10!=k1&&k10!=k2&&k10!=k3&&k10!=k4&&k10!=k5&&k10!=k6&&k10!=k7&&k10!=k8&&k10!=k9){
															int ma=0;
															int c=a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8]+a[k9]+a[k10];
															ma=max(ma,max(a[k1],max(a[k2],max(a[k3],max(a[k4],max(a[k5],max(a[k6],max(a[k7],max(a[k8],max(a[k9],a[k10]))))))))));
															if(c>ma*2)cnt=(cnt+1)%998244353;
													    }
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}else if(len==11){
				for(int k1=k;k1<=n;k1++){
					for(int k2=k1+1;k2<=n;k2++){
						for(int k3=k2+1;k3<=n;k3++){
							for(int k4=k3+1;k4<=n;k4++){
								for(int k5=k4+1;k5<=n;k5++){
									for(int k6=k5+1;k6<=n;k6++){
										for(int k7=k6+1;k7<=n;k7++){
											for(int k8=k7+1;k8<=n;k8++){
												for(int k9=k8+1;k9<=n;k9++){
													for(int k10=k9+1;k10<=n;k10++){
														for(int k11=k10+1;k11<=n;k11++){
															if(k1!=k2&&k2!=k3&&k3!=k1&&k4!=k3&&k4!=k2&&k4!=k1&&k5!=k1&&k5!=k2&&k5!=k3&&k5!=k4&&k6!=k1&&k6!=k2&&k6!=k3&&k6!=k4&&k6!=k5&&k7!=k6&&k7!=k5&&k7!=k4&&k7!=k3&&k7!=k2&&k7!=k1&&k8!=k1&&k8!=k2&&k8!=k3&&k8!=k4&&k8!=k5&&k8!=k6&&k8!=k7&&k9!=k1&&k9!=k2&&k9!=k3&&k9!=k4&&k9!=k5&&k9!=k6&&k9!=k7&&k9!=k8&&k10!=k1&&k10!=k2&&k10!=k3&&k10!=k4&&k10!=k5&&k10!=k6&&k10!=k7&&k10!=k8&&k10!=k9&&k11!=k1&&k11!=k2&&k11!=k3&&k11!=k4&&k11!=k5&&k11!=k6&&k11!=k7&&k11!=k8&&k11!=k9&&k11!=k10){
																int ma=0;
																int c=a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8]+a[k9]+a[k10]+a[k11];
																ma=max(ma,max(a[k1],max(a[k2],max(a[k3],max(a[k4],max(a[k5],max(a[k6],max(a[k7],max(a[k8],max(a[k9],max(a[k10],a[k11])))))))))));
																if(c>ma*2)cnt=(cnt+1)%998244353;
														    }
														}
													}
												}
											}
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
	return 0;
}

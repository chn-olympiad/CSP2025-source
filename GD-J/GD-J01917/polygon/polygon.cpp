#include<bits/stdc++.h>
using namespace std;
long long n,a[5001];
long long ans;
long long maxn=-1;
long long Max(long long x,long long y){
	if(x>y) return x;
	return y;
}
long long C(long long n,long long m){
	if(n<m) return 0;
	if(m==0||n==m) return 1;
	if(m==1) return n;
	return (C(n-1,m)+C(n-1,m-1))%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=Max(maxn,a[i]);
	}
	if(maxn==1){
		for(int i=3;i<=n;i++){
			ans=(ans+C(n,i))%998244353;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int ii=3;ii<=n;ii++){
		if(ii==3){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						if(a[i]+a[j]>a[k]) ans=(ans+1)%998244353;
						else break;
					}
				}
			}
		}
		if(ii==4){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int o=k+1;o<=n;o++){
							if(a[i]+a[j]+a[k]>a[o]) ans=(ans+1)%998244353;
							else break;
						}
					}
				}
			}
		}
		if(ii==5){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int o=k+1;o<=n;o++){
							for(int i1=o+1;i1<=n;i1++){
								if(a[i]+a[j]+a[k]+a[o]>a[i1]) ans=(ans+1)%998244353;
								else break;
							}
						}
					}
				}
			}
		}
		if(ii==6){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int o=k+1;o<=n;o++){
							for(int i1=o+1;i1<=n;i1++){
								for(int i2=i1+1;i2<=n;i2++){
									if(a[i]+a[j]+a[k]+a[o]+a[i1]>a[i2]) ans=(ans+1)%998244353;
									else break;
								}
							}
						}
					}
				}
			}
		}
		if(ii==7){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int o=k+1;o<=n;o++){
							for(int i1=o+1;i1<=n;i1++){
								for(int i2=i1+1;i2<=n;i2++){
									for(int i3=i2+1;i3<=n;i3++){
										if(a[i]+a[j]+a[k]+a[o]+a[i1]+a[i2]>a[i3]) ans=(ans+1)%998244353;
										else break;
									}
								}
							}
						}
					}
				}
			}
		}
		if(ii==8){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int o=k+1;o<=n;o++){
							for(int i1=o+1;i1<=n;i1++){
								for(int i2=i1+1;i2<=n;i2++){
									for(int i3=i2+1;i3<=n;i3++){
										for(int i4=i3+1;i4<=n;i4++){
											if(a[i]+a[j]+a[k]+a[o]+a[i1]+a[i2]+a[i3]>a[i4]) ans=(ans+1)%998244353;
											else break;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(ii==9){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int o=k+1;o<=n;o++){
							for(int i1=o+1;i1<=n;i1++){
								for(int i2=i1+1;i2<=n;i2++){
									for(int i3=i2+1;i3<=n;i3++){
										for(int i4=i3+1;i4<=n;i4++){
											for(int i5=i4+1;i5<=n;i5++){
												if(a[i]+a[j]+a[k]+a[o]+a[i1]+a[i2]+a[i3]+a[i4]>a[i5]) ans=(ans+1)%998244353;
												else break;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(ii==10){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int o=k+1;o<=n;o++){
							for(int i1=o+1;i1<=n;i1++){
								for(int i2=i1+1;i2<=n;i2++){
									for(int i3=i2+1;i3<=n;i3++){
										for(int i4=i3+1;i4<=n;i4++){
											for(int i5=i4+1;i5<=n;i5++){
												for(int i6=i5+1;i6<=n;i6++){
													if(a[i]+a[j]+a[k]+a[o]+a[i1]+a[i2]+a[i3]+a[i4]+a[i5]>a[i6]) ans=(ans+1)%998244353;
													else break;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(ii==11){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int o=k+1;o<=n;o++){
							for(int i1=o+1;i1<=n;i1++){
								for(int i2=i1+1;i2<=n;i2++){
									for(int i3=i2+1;i3<=n;i3++){
										for(int i4=i3+1;i4<=n;i4++){
											for(int i5=i4+1;i5<=n;i5++){
												for(int i6=i5+1;i6<=n;i6++){
													for(int i7=i6+1;i7<=n;i7++){
														if(a[i]+a[j]+a[k]+a[o]+a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]>a[i7]) ans=(ans+1)%998244353;
														else break;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(ii==12){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int o=k+1;o<=n;o++){
							for(int i1=o+1;i1<=n;i1++){
								for(int i2=i1+1;i2<=n;i2++){
									for(int i3=i2+1;i3<=n;i3++){
										for(int i4=i3+1;i4<=n;i4++){
											for(int i5=i4+1;i5<=n;i5++){
												for(int i6=i5+1;i6<=n;i6++){
													for(int i7=i6+1;i7<=n;i7++){
														for(int i8=i7+1;i8<=n;i8++){
															if(a[i]+a[j]+a[k]+a[o]+a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]>a[i8]) ans=(ans+1)%998244353;
															else break;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(ii==13){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int o=k+1;o<=n;o++){
							for(int i1=o+1;i1<=n;i1++){
								for(int i2=i1+1;i2<=n;i2++){
									for(int i3=i2+1;i3<=n;i3++){
										for(int i4=i3+1;i4<=n;i4++){
											for(int i5=i4+1;i5<=n;i5++){
												for(int i6=i5+1;i6<=n;i6++){
													for(int i7=i6+1;i7<=n;i7++){
														for(int i8=i7+1;i8<=n;i8++){
															for(int i9=i8+1;i9<=n;i9++){
																if(a[i]+a[j]+a[k]+a[o]+a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]>a[i9]) ans=(ans+1)%998244353;
																else break;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(ii==14){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int o=k+1;o<=n;o++){
							for(int i1=o+1;i1<=n;i1++){
								for(int i2=i1+1;i2<=n;i2++){
									for(int i3=i2+1;i3<=n;i3++){
										for(int i4=i3+1;i4<=n;i4++){
											for(int i5=i4+1;i5<=n;i5++){
												for(int i6=i5+1;i6<=n;i6++){
													for(int i7=i6+1;i7<=n;i7++){
														for(int i8=i7+1;i8<=n;i8++){
															for(int i9=i8+1;i9<=n;i9++){
																for(int i10=i9+1;i10<=n;i10++){
																	if(a[i]+a[j]+a[k]+a[o]+a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]>a[i10]) ans=(ans+1)%998244353;
																	else break;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(ii==15){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int o=k+1;o<=n;o++){
							for(int i1=o+1;i1<=n;i1++){
								for(int i2=i1+1;i2<=n;i2++){
									for(int i3=i2+1;i3<=n;i3++){
										for(int i4=i3+1;i4<=n;i4++){
											for(int i5=i4+1;i5<=n;i5++){
												for(int i6=i5+1;i6<=n;i6++){
													for(int i7=i6+1;i7<=n;i7++){
														for(int i8=i7+1;i8<=n;i8++){
															for(int i9=i8+1;i9<=n;i9++){
																for(int i10=i9+1;i10<=n;i10++){
																	for(int i11=i10+1;i11<=n;i11++){
																		if(a[i]+a[j]+a[k]+a[o]+a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]>a[i11]) ans=(ans+1)%998244353;
																		else break;
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(ii==16){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int o=k+1;o<=n;o++){
							for(int i1=o+1;i1<=n;i1++){
								for(int i2=i1+1;i2<=n;i2++){
									for(int i3=i2+1;i3<=n;i3++){
										for(int i4=i3+1;i4<=n;i4++){
											for(int i5=i4+1;i5<=n;i5++){
												for(int i6=i5+1;i6<=n;i6++){
													for(int i7=i6+1;i7<=n;i7++){
														for(int i8=i7+1;i8<=n;i8++){
															for(int i9=i8+1;i9<=n;i9++){
																for(int i10=i9+1;i10<=n;i10++){
																	for(int i11=i10+1;i11<=n;i11++){
																		for(int i12=i11+1;i12<=n;i12++){
																			if(a[i]+a[j]+a[k]+a[o]+a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]>a[i12]) ans=(ans+1)%998244353;
																			else break;
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(ii==17){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int o=k+1;o<=n;o++){
							for(int i1=o+1;i1<=n;i1++){
								for(int i2=i1+1;i2<=n;i2++){
									for(int i3=i2+1;i3<=n;i3++){
										for(int i4=i3+1;i4<=n;i4++){
											for(int i5=i4+1;i5<=n;i5++){
												for(int i6=i5+1;i6<=n;i6++){
													for(int i7=i6+1;i7<=n;i7++){
														for(int i8=i7+1;i8<=n;i8++){
															for(int i9=i8+1;i9<=n;i9++){
																for(int i10=i9+1;i10<=n;i10++){
																	for(int i11=i10+1;i11<=n;i11++){
																		for(int i12=i11+1;i12<=n;i12++){
																			for(int i13=i12+1;i13<=n;i13++){
																				if(a[i]+a[j]+a[k]+a[o]+a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]>a[i13]) ans=(ans+1)%998244353;
																				else break;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(ii==18){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int o=k+1;o<=n;o++){
							for(int i1=o+1;i1<=n;i1++){
								for(int i2=i1+1;i2<=n;i2++){
									for(int i3=i2+1;i3<=n;i3++){
										for(int i4=i3+1;i4<=n;i4++){
											for(int i5=i4+1;i5<=n;i5++){
												for(int i6=i5+1;i6<=n;i6++){
													for(int i7=i6+1;i7<=n;i7++){
														for(int i8=i7+1;i8<=n;i8++){
															for(int i9=i8+1;i9<=n;i9++){
																for(int i10=i9+1;i10<=n;i10++){
																	for(int i11=i10+1;i11<=n;i11++){
																		for(int i12=i11+1;i12<=n;i12++){
																			for(int i13=i12+1;i13<=n;i13++){
																				for(int i14=i13+1;i14<=n;i14++){
																					if(a[i]+a[j]+a[k]+a[o]+a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]+a[i13]>a[i14]) ans=(ans+1)%998244353;
																					else break;
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(ii==19){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int o=k+1;o<=n;o++){
							for(int i1=o+1;i1<=n;i1++){
								for(int i2=i1+1;i2<=n;i2++){
									for(int i3=i2+1;i3<=n;i3++){
										for(int i4=i3+1;i4<=n;i4++){
											for(int i5=i4+1;i5<=n;i5++){
												for(int i6=i5+1;i6<=n;i6++){
													for(int i7=i6+1;i7<=n;i7++){
														for(int i8=i7+1;i8<=n;i8++){
															for(int i9=i8+1;i9<=n;i9++){
																for(int i10=i9+1;i10<=n;i10++){
																	for(int i11=i10+1;i11<=n;i11++){
																		for(int i12=i11+1;i12<=n;i12++){
																			for(int i13=i12+1;i13<=n;i13++){
																				for(int i14=i13+1;i14<=n;i14++){
																					for(int i15=i14+1;i15<=n;i15++){
																						if(a[i]+a[j]+a[k]+a[o]+a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]+a[i13]+a[i14]>a[i15]) ans=(ans+1)%998244353;
																						else break;
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(ii==20){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int o=k+1;o<=n;o++){
							for(int i1=o+1;i1<=n;i1++){
								for(int i2=i1+1;i2<=n;i2++){
									for(int i3=i2+1;i3<=n;i3++){
										for(int i4=i3+1;i4<=n;i4++){
											for(int i5=i4+1;i5<=n;i5++){
												for(int i6=i5+1;i6<=n;i6++){
													for(int i7=i6+1;i7<=n;i7++){
														for(int i8=i7+1;i8<=n;i8++){
															for(int i9=i8+1;i9<=n;i9++){
																for(int i10=i9+1;i10<=n;i10++){
																	for(int i11=i10+1;i11<=n;i11++){
																		for(int i12=i11+1;i12<=n;i12++){
																			for(int i13=i12+1;i13<=n;i13++){
																				for(int i14=i13+1;i14<=n;i14++){
																					for(int i15=i14+1;i15<=n;i15++){
																						for(int i16=i15+1;i16<=n;i16++){
																							if(a[i]+a[j]+a[k]+a[o]+a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]+a[i10]+a[i11]+a[i12]+a[i13]+a[i14]+a[i15]>a[i16]) ans=(ans+1)%998244353;
																							else break;
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}//你觉得三角形好看吗，觉得好看就给我满分！ 
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const long long eps=998244353;
int n,a[5005],vis[5005],cnt,ans,maxx,num,lo;
long long te,lin,l1,l2;
inline void c(int c1,int c2){
	if(c1>c2/2){
		c1=c2-c1;
	}
	l1=1;
	l2=1;
	lo=0;
	for(int i=1;i<=c1;i++){
		l2*=i;
		if(l2>eps){
			l2/=eps;
			lo++;
		}
		
	}
	for(int i=c2-c1+1;i<=c2;i++){
		l1*=i;
		if(l1>eps&&lo>0){
			l1/=eps;
			lo--;
		}
	}
	lin=(l1/l2)%eps;
	return;
}
inline void add(int k){
	cnt=0;
	maxx=-1;
	num=0;
	for(int i=1;i<=k;i++){
		if(vis[i]==1){
			cnt++;
			maxx=max(maxx,a[i]);
			num+=a[i];
		}
	}
	if(cnt>=3&&num>2*maxx){
		ans++;
	}
	return;
}
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans=0;
	if(n==1){
		for(int i1=0;i1<=1;i1++){
			vis[1]=i1;
			add(1);
		}
		cout<<ans;
	}
	else if(n==2){
		for(int i1=0;i1<=1;i1++){
			vis[1]=i1;
			for(int i2=0;i2<=1;i2++){
				vis[2]=i2;
				add(2);
			}
		}
		cout<<ans;
	}
	else if(n==3){
		for(int i1=0;i1<=1;i1++){
			vis[1]=i1;
			for(int i2=0;i2<=1;i2++){
				vis[2]=i2;
				for(int i3=0;i3<=1;i3++){
					vis[3]=i3;
					add(3);
				}
			}
		}
		cout<<ans;
	}
	else if(n==4){
		for(int i1=0;i1<=1;i1++){
			vis[1]=i1;
			for(int i2=0;i2<=1;i2++){
				vis[2]=i2;
				for(int i3=0;i3<=1;i3++){
					vis[3]=i3;
					for(int i4=0;i4<=1;i4++){
						vis[4]=i4;
						add(4);
					}
				}
			}
		}
		cout<<ans;
	}
	else if(n==5){
		for(int i1=0;i1<=1;i1++){
			vis[1]=i1;
			for(int i2=0;i2<=1;i2++){
				vis[2]=i2;
				for(int i3=0;i3<=1;i3++){
					vis[3]=i3;
					for(int i4=0;i4<=1;i4++){
						vis[4]=i4;
						for(int i5=0;i5<=1;i5++){
							vis[5]=i5;
							add(5);
						}
					}
				}
			}
		}
		cout<<ans;
	}
	else if(n==6){
		for(int i1=0;i1<=1;i1++){
			vis[1]=i1;
			for(int i2=0;i2<=1;i2++){
				vis[2]=i2;
				for(int i3=0;i3<=1;i3++){
					vis[3]=i3;
					for(int i4=0;i4<=1;i4++){
						vis[4]=i4;
						for(int i5=0;i5<=1;i5++){
							vis[5]=i5;
							for(int i6=0;i6<=1;i6++){
								vis[6]=i6;
								add(6);
							}
						}
					}
				}
			}
		}
		cout<<ans;
	}
	else if(n==7){
		for(int i1=0;i1<=1;i1++){
			vis[1]=i1;
			for(int i2=0;i2<=1;i2++){
				vis[2]=i2;
				for(int i3=0;i3<=1;i3++){
					vis[3]=i3;
					for(int i4=0;i4<=1;i4++){
						vis[4]=i4;
						for(int i5=0;i5<=1;i5++){
							vis[5]=i5;
							for(int i6=0;i6<=1;i6++){
								vis[6]=i6;
								for(int i7=0;i7<=1;i7++){
									vis[7]=i7;
									add(7);
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
	}
	else if(n==8){
		for(int i1=0;i1<=1;i1++){
			vis[1]=i1;
			for(int i2=0;i2<=1;i2++){
				vis[2]=i2;
				for(int i3=0;i3<=1;i3++){
					vis[3]=i3;
					for(int i4=0;i4<=1;i4++){
						vis[4]=i4;
						for(int i5=0;i5<=1;i5++){
							vis[5]=i5;
							for(int i6=0;i6<=1;i6++){
								vis[6]=i6;
								for(int i7=0;i7<=1;i7++){
									vis[7]=i7;
									for(int i8=0;i8<=1;i8++){
										vis[8]=i8;
										add(8);
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
	else if(n==9){
		for(int i1=0;i1<=1;i1++){
			vis[1]=i1;
			for(int i2=0;i2<=1;i2++){
				vis[2]=i2;
				for(int i3=0;i3<=1;i3++){
					vis[3]=i3;
					for(int i4=0;i4<=1;i4++){
						vis[4]=i4;
						for(int i5=0;i5<=1;i5++){
							vis[5]=i5;
							for(int i6=0;i6<=1;i6++){
								vis[6]=i6;
								for(int i7=0;i7<=1;i7++){
									vis[7]=i7;
									for(int i8=0;i8<=1;i8++){
										vis[8]=i8;
										for(int i9=0;i9<=1;i9++){
											vis[9]=i9;
											add(9);
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
	else if(n==10){
		for(int i1=0;i1<=1;i1++){
			vis[1]=i1;
			for(int i2=0;i2<=1;i2++){
				vis[2]=i2;
				for(int i3=0;i3<=1;i3++){
					vis[3]=i3;
					for(int i4=0;i4<=1;i4++){
						vis[4]=i4;
						for(int i5=0;i5<=1;i5++){
							vis[5]=i5;
							for(int i6=0;i6<=1;i6++){
								vis[6]=i6;
								for(int i7=0;i7<=1;i7++){
									vis[7]=i7;
									for(int i8=0;i8<=1;i8++){
										vis[8]=i8;
										for(int i9=0;i9<=1;i9++){
											vis[9]=i9;
											for(int i10=0;i10<=1;i10++){
												vis[10]=i10;
												add(10);
											}
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
	else if(n==11){
		for(int i1=0;i1<=1;i1++){
			vis[1]=i1;
			for(int i2=0;i2<=1;i2++){
				vis[2]=i2;
				for(int i3=0;i3<=1;i3++){
					vis[3]=i3;
					for(int i4=0;i4<=1;i4++){
						vis[4]=i4;
						for(int i5=0;i5<=1;i5++){
							vis[5]=i5;
							for(int i6=0;i6<=1;i6++){
								vis[6]=i6;
								for(int i7=0;i7<=1;i7++){
									vis[7]=i7;
									for(int i8=0;i8<=1;i8++){
										vis[8]=i8;
										for(int i9=0;i9<=1;i9++){
											vis[9]=i9;
											for(int i10=0;i10<=1;i10++){
												vis[10]=i10;
												for(int i11=0;i11<=1;i11++){
													vis[11]=i11;
													add(11);
												}
											}
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
	else if(n==12){
		for(int i1=0;i1<=1;i1++){
			vis[1]=i1;
			for(int i2=0;i2<=1;i2++){
				vis[2]=i2;
				for(int i3=0;i3<=1;i3++){
					vis[3]=i3;
					for(int i4=0;i4<=1;i4++){
						vis[4]=i4;
						for(int i5=0;i5<=1;i5++){
							vis[5]=i5;
							for(int i6=0;i6<=1;i6++){
								vis[6]=i6;
								for(int i7=0;i7<=1;i7++){
									vis[7]=i7;
									for(int i8=0;i8<=1;i8++){
										vis[8]=i8;
										for(int i9=0;i9<=1;i9++){
											vis[9]=i9;
											for(int i10=0;i10<=1;i10++){
												vis[10]=i10;
												for(int i11=0;i11<=1;i11++){
													vis[11]=i11;
													for(int i12=0;i12<=1;i12++){
														vis[12]=i12;
														add(12);
													}
												}
											}
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
	else if(n==13){
		for(int i1=0;i1<=1;i1++){
			vis[1]=i1;
			for(int i2=0;i2<=1;i2++){
				vis[2]=i2;
				for(int i3=0;i3<=1;i3++){
					vis[3]=i3;
					for(int i4=0;i4<=1;i4++){
						vis[4]=i4;
						for(int i5=0;i5<=1;i5++){
							vis[5]=i5;
							for(int i6=0;i6<=1;i6++){
								vis[6]=i6;
								for(int i7=0;i7<=1;i7++){
									vis[7]=i7;
									for(int i8=0;i8<=1;i8++){
										vis[8]=i8;
										for(int i9=0;i9<=1;i9++){
											vis[9]=i9;
											for(int i10=0;i10<=1;i10++){
												vis[10]=i10;
												for(int i11=0;i11<=1;i11++){
													vis[11]=i11;
													for(int i12=0;i12<=1;i12++){
														vis[12]=i12;
														for(int i13=0;i13<=1;i13++){
															vis[13]=i13;
															add(13);
														}
													}
												}
											}
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
	else if(n==14){
		for(int i1=0;i1<=1;i1++){
			vis[1]=i1;
			for(int i2=0;i2<=1;i2++){
				vis[2]=i2;
				for(int i3=0;i3<=1;i3++){
					vis[3]=i3;
					for(int i4=0;i4<=1;i4++){
						vis[4]=i4;
						for(int i5=0;i5<=1;i5++){
							vis[5]=i5;
							for(int i6=0;i6<=1;i6++){
								vis[6]=i6;
								for(int i7=0;i7<=1;i7++){
									vis[7]=i7;
									for(int i8=0;i8<=1;i8++){
										vis[8]=i8;
										for(int i9=0;i9<=1;i9++){
											vis[9]=i9;
											for(int i10=0;i10<=1;i10++){
												vis[10]=i10;
												for(int i11=0;i11<=1;i11++){
													vis[11]=i11;
													for(int i12=0;i12<=1;i12++){
														vis[12]=i12;
														for(int i13=0;i13<=1;i13++){
															vis[13]=i13;
															for(int i14=0;i14<=1;i14++){
																vis[14]=i14;
																add(14);
															}
														}
													}
												}
											}
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
	else if(n==15){
		for(int i1=0;i1<=1;i1++){
			vis[1]=i1;
			for(int i2=0;i2<=1;i2++){
				vis[2]=i2;
				for(int i3=0;i3<=1;i3++){
					vis[3]=i3;
					for(int i4=0;i4<=1;i4++){
						vis[4]=i4;
						for(int i5=0;i5<=1;i5++){
							vis[5]=i5;
							for(int i6=0;i6<=1;i6++){
								vis[6]=i6;
								for(int i7=0;i7<=1;i7++){
									vis[7]=i7;
									for(int i8=0;i8<=1;i8++){
										vis[8]=i8;
										for(int i9=0;i9<=1;i9++){
											vis[9]=i9;
											for(int i10=0;i10<=1;i10++){
												vis[10]=i10;
												for(int i11=0;i11<=1;i11++){
													vis[11]=i11;
													for(int i12=0;i12<=1;i12++){
														vis[12]=i12;
														for(int i13=0;i13<=1;i13++){
															vis[13]=i13;
															for(int i14=0;i14<=1;i14++){
																vis[14]=i14;
																for(int i15=0;i15<=1;i15++){
																	vis[15]=i15;
																	add(15);
																}
															}
														}
													}
												}
											}
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
	else if(n==16){
		for(int i1=0;i1<=1;i1++){
			vis[1]=i1;
			for(int i2=0;i2<=1;i2++){
				vis[2]=i2;
				for(int i3=0;i3<=1;i3++){
					vis[3]=i3;
					for(int i4=0;i4<=1;i4++){
						vis[4]=i4;
						for(int i5=0;i5<=1;i5++){
							vis[5]=i5;
							for(int i6=0;i6<=1;i6++){
								vis[6]=i6;
								for(int i7=0;i7<=1;i7++){
									vis[7]=i7;
									for(int i8=0;i8<=1;i8++){
										vis[8]=i8;
										for(int i9=0;i9<=1;i9++){
											vis[9]=i9;
											for(int i10=0;i10<=1;i10++){
												vis[10]=i10;
												for(int i11=0;i11<=1;i11++){
													vis[11]=i11;
													for(int i12=0;i12<=1;i12++){
														vis[12]=i12;
														for(int i13=0;i13<=1;i13++){
															vis[13]=i13;
															for(int i14=0;i14<=1;i14++){
																vis[14]=i14;
																for(int i15=0;i15<=1;i15++){
																	vis[15]=i15;
																	for(int i16=0;i16<=1;i16++){
																		vis[16]=i16;
																		add(16);
																	}
																}
															}
														}
													}
												}
											}
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
	else if(n==17){
		for(int i1=0;i1<=1;i1++){
			vis[1]=i1;
			for(int i2=0;i2<=1;i2++){
				vis[2]=i2;
				for(int i3=0;i3<=1;i3++){
					vis[3]=i3;
					for(int i4=0;i4<=1;i4++){
						vis[4]=i4;
						for(int i5=0;i5<=1;i5++){
							vis[5]=i5;
							for(int i6=0;i6<=1;i6++){
								vis[6]=i6;
								for(int i7=0;i7<=1;i7++){
									vis[7]=i7;
									for(int i8=0;i8<=1;i8++){
										vis[8]=i8;
										for(int i9=0;i9<=1;i9++){
											vis[9]=i9;
											for(int i10=0;i10<=1;i10++){
												vis[10]=i10;
												for(int i11=0;i11<=1;i11++){
													vis[11]=i11;
													for(int i12=0;i12<=1;i12++){
														vis[12]=i12;
														for(int i13=0;i13<=1;i13++){
															vis[13]=i13;
															for(int i14=0;i14<=1;i14++){
																vis[14]=i14;
																for(int i15=0;i15<=1;i15++){
																	vis[15]=i15;
																	for(int i16=0;i16<=1;i16++){
																		vis[16]=i16;
																		for(int i17=0;i17<=1;i17++){
																			vis[17]=i17;
																			add(17);
																		}
																	}
																}
															}
														}
													}
												}
											}
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
	else if(n==18){
		for(int i1=0;i1<=1;i1++){
			vis[1]=i1;
			for(int i2=0;i2<=1;i2++){
				vis[2]=i2;
				for(int i3=0;i3<=1;i3++){
					vis[3]=i3;
					for(int i4=0;i4<=1;i4++){
						vis[4]=i4;
						for(int i5=0;i5<=1;i5++){
							vis[5]=i5;
							for(int i6=0;i6<=1;i6++){
								vis[6]=i6;
								for(int i7=0;i7<=1;i7++){
									vis[7]=i7;
									for(int i8=0;i8<=1;i8++){
										vis[8]=i8;
										for(int i9=0;i9<=1;i9++){
											vis[9]=i9;
											for(int i10=0;i10<=1;i10++){
												vis[10]=i10;
												for(int i11=0;i11<=1;i11++){
													vis[11]=i11;
													for(int i12=0;i12<=1;i12++){
														vis[12]=i12;
														for(int i13=0;i13<=1;i13++){
															vis[13]=i13;
															for(int i14=0;i14<=1;i14++){
																vis[14]=i14;
																for(int i15=0;i15<=1;i15++){
																	vis[15]=i15;
																	for(int i16=0;i16<=1;i16++){
																		vis[16]=i16;
																		for(int i17=0;i17<=1;i17++){
																			vis[17]=i17;
																			for(int i18=0;i18<=1;i18++){
																				vis[18]=i18;
																				add(18);
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
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
	else if(n==19){
		for(int i1=0;i1<=1;i1++){
			vis[1]=i1;
			for(int i2=0;i2<=1;i2++){
				vis[2]=i2;
				for(int i3=0;i3<=1;i3++){
					vis[3]=i3;
					for(int i4=0;i4<=1;i4++){
						vis[4]=i4;
						for(int i5=0;i5<=1;i5++){
							vis[5]=i5;
							for(int i6=0;i6<=1;i6++){
								vis[6]=i6;
								for(int i7=0;i7<=1;i7++){
									vis[7]=i7;
									for(int i8=0;i8<=1;i8++){
										vis[8]=i8;
										for(int i9=0;i9<=1;i9++){
											vis[9]=i9;
											for(int i10=0;i10<=1;i10++){
												vis[10]=i10;
												for(int i11=0;i11<=1;i11++){
													vis[11]=i11;
													for(int i12=0;i12<=1;i12++){
														vis[12]=i12;
														for(int i13=0;i13<=1;i13++){
															vis[13]=i13;
															for(int i14=0;i14<=1;i14++){
																vis[14]=i14;
																for(int i15=0;i15<=1;i15++){
																	vis[15]=i15;
																	for(int i16=0;i16<=1;i16++){
																		vis[16]=i16;
																		for(int i17=0;i17<=1;i17++){
																			vis[17]=i17;
																			for(int i18=0;i18<=1;i18++){
																				vis[18]=i18;
																				for(int i19=0;i19<=1;i19++){
																					vis[19]=i19;
																					add(19); 
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
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
	else if(n==20){
		for(int i1=0;i1<=1;i1++){
			vis[1]=i1;
			for(int i2=0;i2<=1;i2++){
				vis[2]=i2;
				for(int i3=0;i3<=1;i3++){
					vis[3]=i3;
					for(int i4=0;i4<=1;i4++){
						vis[4]=i4;
						for(int i5=0;i5<=1;i5++){
							vis[5]=i5;
							for(int i6=0;i6<=1;i6++){
								vis[6]=i6;
								for(int i7=0;i7<=1;i7++){
									vis[7]=i7;
									for(int i8=0;i8<=1;i8++){
										vis[8]=i8;
										for(int i9=0;i9<=1;i9++){
											vis[9]=i9;
											for(int i10=0;i10<=1;i10++){
												vis[10]=i10;
												for(int i11=0;i11<=1;i11++){
													vis[11]=i11;
													for(int i12=0;i12<=1;i12++){
														vis[12]=i12;
														for(int i13=0;i13<=1;i13++){
															vis[13]=i13;
															for(int i14=0;i14<=1;i14++){
																vis[14]=i14;
																for(int i15=0;i15<=1;i15++){
																	vis[15]=i15;
																	for(int i16=0;i16<=1;i16++){
																		vis[16]=i16;
																		for(int i17=0;i17<=1;i17++){
																			vis[17]=i17;
																			for(int i18=0;i18<=1;i18++){
																				vis[18]=i18;
																				for(int i19=0;i19<=1;i19++){
																					vis[19]=i19;
																					for(int i20=0;i20<=1;i20++){
																						vis[20]=i20;
																						add(20);
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
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
	else{
		te=0;
		for(int i=3;i<=n;i++){
			c(i,n);
			te+=lin;
			te%=eps;
		}
		cout<<te;
	}
	return 0;
}
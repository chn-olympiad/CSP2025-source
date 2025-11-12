#include<bits/stdc++.h>
using namespace std;
int a[30];
bool polygon(int b){
	int x=0,y=0;
	for(int i=1;i<=b;i++){
		if(a[i]>x) x=a[i];
		y+=a[i];
	}
	x*=2;
	if(y>x) return true;
	return false;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,s=0;
	cin>>n;
	int mg[n+10];
	for(int i=1;i<=n;i++) cin>>mg[i];
	for(int i1=1;i1<=n-2;i1++){
		for(int i2=i1+1;i2<=n-1;i2++){
			for(int i3=i2+1;i3<=n;i3++){
				a[1]=mg[i1];
				a[2]=mg[i2];
				a[3]=mg[i3];
				if(polygon(3)) s++;
			}
		}
	}
	s%=998244353;
	if(n>=4){
		for(int i1=1;i1<=n-3;i1++){
			for(int i2=i1+1;i2<=n-2;i2++){
				for(int i3=i2+1;i3<=n-1;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						a[1]=mg[i1];
						a[2]=mg[i2];
						a[3]=mg[i3];
						a[4]=mg[i4];
						if(polygon(4)) s++;
					}
				}
			}
		}
	}
	s%=998244353;
	if(n>=5){
		for(int i1=1;i1<=n-4;i1++){
			for(int i2=i1+1;i2<=n-3;i2++){
				for(int i3=i2+1;i3<=n-2;i3++){
					for(int i4=i3+1;i4<=n-1;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							a[1]=mg[i1];
							a[2]=mg[i2];
							a[3]=mg[i3];
							a[4]=mg[i4];
							a[5]=mg[i5];
							if(polygon(5)) s++;
						}
					}
				}
			}
		}
	}
	s%=998244353;
	if(n>=6){
		for(int i1=1;i1<=n-5;i1++){
			for(int i2=i1+1;i2<=n-4;i2++){
				for(int i3=i2+1;i3<=n-3;i3++){
					for(int i4=i3+1;i4<=n-2;i4++){
						for(int i5=i4+1;i5<=n-1;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								a[1]=mg[i1];
								a[2]=mg[i2];
								a[3]=mg[i3];
								a[4]=mg[i4];
								a[5]=mg[i5];
								a[6]=mg[i6];
								if(polygon(6)) s++;
							}
						}
					}
				}
			}
		}
	}
	s%=998244353;
	if(n>=7){
		for(int i1=1;i1<=n-6;i1++){
			for(int i2=i1+1;i2<=n-5;i2++){
				for(int i3=i2+1;i3<=n-4;i3++){
					for(int i4=i3+1;i4<=n-3;i4++){
						for(int i5=i4+1;i5<=n-2;i5++){
							for(int i6=i5+1;i6<=n-1;i6++){
								for(int i7=i6+1;i7<=n;i7++){
									a[1]=mg[i1];
									a[2]=mg[i2];
									a[3]=mg[i3];
									a[4]=mg[i4];
									a[5]=mg[i5];
									a[6]=mg[i6];
									a[7]=mg[i7];
									if(polygon(7)) s++;
								}
							}
						}
					}
				}
			}
		}
	}
	s%=998244353;
	if(n>=8){
		for(int i1=1;i1<=n-7;i1++){
			for(int i2=i1+1;i2<=n-6;i2++){
				for(int i3=i2+1;i3<=n-5;i3++){
					for(int i4=i3+1;i4<=n-4;i4++){
						for(int i5=i4+1;i5<=n-3;i5++){
							for(int i6=i5+1;i6<=n-2;i6++){
								for(int i7=i6+1;i7<=n-1;i7++){
									for(int i8=i7+1;i8<=n;i8++){
										a[1]=mg[i1];
										a[2]=mg[i2];
										a[3]=mg[i3];
										a[4]=mg[i4];
										a[5]=mg[i5];
										a[6]=mg[i6];
										a[7]=mg[i7];
										a[8]=mg[i8];
										if(polygon(8)) s++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	s%=998244353;
	if(n>=9){
		for(int i1=1;i1<=n-8;i1++){
			for(int i2=i1+1;i2<=n-7;i2++){
				for(int i3=i2+1;i3<=n-6;i3++){
					for(int i4=i3+1;i4<=n-5;i4++){
						for(int i5=i4+1;i5<=n-4;i5++){
							for(int i6=i5+1;i6<=n-3;i6++){
								for(int i7=i6+1;i7<=n-2;i7++){
									for(int i8=i7+1;i8<=n-1;i8++){
										for(int i9=i8+1;i9<=n;i9++){
											a[1]=mg[i1];
											a[2]=mg[i2];
											a[3]=mg[i3];
											a[4]=mg[i4];
											a[5]=mg[i5];
											a[6]=mg[i6];
											a[7]=mg[i7];
											a[8]=mg[i8];
											a[9]=mg[i9];
											if(polygon(9)) s++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	s%=998244353;
	if(n>=10){
		for(int i1=1;i1<=n-9;i1++){
			for(int i2=i1+1;i2<=n-8;i2++){
				for(int i3=i2+1;i3<=n-7;i3++){
					for(int i4=i3+1;i4<=n-6;i4++){
						for(int i5=i4+1;i5<=n-5;i5++){
							for(int i6=i5+1;i6<=n-4;i6++){
								for(int i7=i6+1;i7<=n-3;i7++){
									for(int i8=i7+1;i8<=n-2;i8++){
										for(int i9=i8+1;i9<=n-1;i9++){
											for(int i10=i9+1;i10<=n;i10++){
												a[1]=mg[i1];
												a[2]=mg[i2];
												a[3]=mg[i3];
												a[4]=mg[i4];
												a[5]=mg[i5];
												a[6]=mg[i6];
												a[7]=mg[i7];
												a[8]=mg[i8];
												a[9]=mg[i9];
												a[10]=mg[i10];
												if(polygon(10)) s++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	s%=998244353;
	if(n>=11){
		for(int i1=1;i1<=n-10;i1++){
			for(int i2=i1+1;i2<=n-9;i2++){
				for(int i3=i2+1;i3<=n-8;i3++){
					for(int i4=i3+1;i4<=n-7;i4++){
						for(int i5=i4+1;i5<=n-6;i5++){
							for(int i6=i5+1;i6<=n-5;i6++){
								for(int i7=i6+1;i7<=n-4;i7++){
									for(int i8=i7+1;i8<=n-3;i8++){
										for(int i9=i8+1;i9<=n-2;i9++){
											for(int i10=i9+1;i10<=n-1;i10++){
												for(int i11=i10+1;i11<=n;i11++){
													a[1]=mg[i1];
													a[2]=mg[i2];
													a[3]=mg[i3];
													a[4]=mg[i4];
													a[5]=mg[i5];
													a[6]=mg[i6];
													a[7]=mg[i7];
													a[8]=mg[i8];
													a[9]=mg[i9];
													a[10]=mg[i10];
													a[11]=mg[i11];
													if(polygon(11)) s++;	
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	s%=998244353;
	if(n>=12){
		for(int i1=1;i1<=n-11;i1++){
			for(int i2=i1+1;i2<=n-10;i2++){
				for(int i3=i2+1;i3<=n-9;i3++){
					for(int i4=i3+1;i4<=n-8;i4++){
						for(int i5=i4+1;i5<=n-7;i5++){
							for(int i6=i5+1;i6<=n-6;i6++){
								for(int i7=i6+1;i7<=n-5;i7++){
									for(int i8=i7+1;i8<=n-4;i8++){
										for(int i9=i8+1;i9<=n-3;i9++){
											for(int i10=i9+1;i10<=n-2;i10++){
												for(int i11=i10+1;i11<=n-1;i11++){
													for(int i12=i11+1;i12<=n;i12++){
														a[1]=mg[i1];
														a[2]=mg[i2];
														a[3]=mg[i3];
														a[4]=mg[i4];
														a[5]=mg[i5];
														a[6]=mg[i6];
														a[7]=mg[i7];
														a[8]=mg[i8];
														a[9]=mg[i9];
														a[10]=mg[i10];
														a[11]=mg[i11];
														a[12]=mg[i12];
														if(polygon(12)) s++;	
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	s%=998244353;
	if(n>=13){
		for(int i1=1;i1<=n-12;i1++){
			for(int i2=i1+1;i2<=n-11;i2++){
				for(int i3=i2+1;i3<=n-10;i3++){
					for(int i4=i3+1;i4<=n-9;i4++){
						for(int i5=i4+1;i5<=n-8;i5++){
							for(int i6=i5+1;i6<=n-7;i6++){
								for(int i7=i6+1;i7<=n-6;i7++){
									for(int i8=i7+1;i8<=n-5;i8++){
										for(int i9=i8+1;i9<=n-4;i9++){
											for(int i10=i9+1;i10<=n-3;i10++){
												for(int i11=i10+1;i11<=n-2;i11++){
													for(int i12=i11+1;i12<=n-1;i12++){
														for(int i13=i12+1;i13<=n;i13++){
															a[1]=mg[i1];
															a[2]=mg[i2];
															a[3]=mg[i3];
															a[4]=mg[i4];
															a[5]=mg[i5];
															a[6]=mg[i6];
															a[7]=mg[i7];
															a[8]=mg[i8];
															a[9]=mg[i9];
															a[10]=mg[i10];
															a[11]=mg[i11];
															a[12]=mg[i12];
															a[13]=mg[i13];
															if(polygon(13)) s++;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	s%=998244353;
	if(n>=14){
		for(int i1=1;i1<=n-13;i1++){
			for(int i2=i1+1;i2<=n-12;i2++){
				for(int i3=i2+1;i3<=n-11;i3++){
					for(int i4=i3+1;i4<=n-10;i4++){
						for(int i5=i4+1;i5<=n-9;i5++){
							for(int i6=i5+1;i6<=n-8;i6++){
								for(int i7=i6+1;i7<=n-7;i7++){
									for(int i8=i7+1;i8<=n-6;i8++){
										for(int i9=i8+1;i9<=n-5;i9++){
											for(int i10=i9+1;i10<=n-4;i10++){
												for(int i11=i10+1;i11<=n-3;i11++){
													for(int i12=i11+1;i12<=n-2;i12++){
														for(int i13=i12+1;i13<=n-1;i13++){
															for(int i14=i13+1;i14<=n-1;i14++){
																a[1]=mg[i1];
																a[2]=mg[i2];
																a[3]=mg[i3];
																a[4]=mg[i4];
																a[5]=mg[i5];
																a[6]=mg[i6];
																a[7]=mg[i7];
																a[8]=mg[i8];
																a[9]=mg[i9];
																a[10]=mg[i10];
																a[11]=mg[i11];
																a[12]=mg[i12];
																a[13]=mg[i13];
																a[14]=mg[i14];
																if(polygon(14)) s++;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	s%=998244353;
	if(n>=15){
		for(int i1=1;i1<=n-14;i1++){
			for(int i2=i1+1;i2<=n-13;i2++){
				for(int i3=i2+1;i3<=n-12;i3++){
					for(int i4=i3+1;i4<=n-11;i4++){
						for(int i5=i4+1;i5<=n-10;i5++){
							for(int i6=i5+1;i6<=n-9;i6++){
								for(int i7=i6+1;i7<=n-8;i7++){
									for(int i8=i7+1;i8<=n-7;i8++){
										for(int i9=i8+1;i9<=n-6;i9++){
											for(int i10=i9+1;i10<=n-5;i10++){
												for(int i11=i10+1;i11<=n-4;i11++){
													for(int i12=i11+1;i12<=n-3;i12++){
														for(int i13=i12+1;i13<=n-2;i13++){
															for(int i14=i13+1;i14<=n-1;i14++){
																for(int i15=i14+1;i15<=n;i15++){
																	a[1]=mg[i1];
																	a[2]=mg[i2];
																	a[3]=mg[i3];
																	a[4]=mg[i4];
																	a[5]=mg[i5];
																	a[6]=mg[i6];
																	a[7]=mg[i7];
																	a[8]=mg[i8];
																	a[9]=mg[i9];
																	a[10]=mg[i10];
																	a[11]=mg[i11];
																	a[12]=mg[i12];
																	a[13]=mg[i13];
																	a[14]=mg[i14];
																	a[15]=mg[i15];
																	if(polygon(15)) s++;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	s%=998244353;
	if(n>=16){
		for(int i1=1;i1<=n-15;i1++){
			for(int i2=i1+1;i2<=n-14;i2++){
				for(int i3=i2+1;i3<=n-13;i3++){
					for(int i4=i3+1;i4<=n-12;i4++){
						for(int i5=i4+1;i5<=n-11;i5++){
							for(int i6=i5+1;i6<=n-10;i6++){
								for(int i7=i6+1;i7<=n-9;i7++){
									for(int i8=i7+1;i8<=n-8;i8++){
										for(int i9=i8+1;i9<=n-7;i9++){
											for(int i10=i9+1;i10<=n-6;i10++){
												for(int i11=i10+1;i11<=n-5;i11++){
													for(int i12=i11+1;i12<=n-4;i12++){
														for(int i13=i12+1;i13<=n-3;i13++){
															for(int i14=i13+1;i14<=n-2;i14++){
																for(int i15=i14+1;i15<=n-1;i15++){
																	for(int i16=i15+1;i16<=n;i16++){
																		a[1]=mg[i1];
																		a[2]=mg[i2];
																		a[3]=mg[i3];
																		a[4]=mg[i4];
																		a[5]=mg[i5];
																		a[6]=mg[i6];
																		a[7]=mg[i7];
																		a[8]=mg[i8];
																		a[9]=mg[i9];
																		a[10]=mg[i10];
																		a[11]=mg[i11];
																		a[12]=mg[i12];
																		a[13]=mg[i13];
																		a[14]=mg[i14];
																		a[15]=mg[i15];
																		a[16]=mg[i16];
																		if(polygon(16)) s++;
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	s%=998244353;
	if(n>=17){
		for(int i1=1;i1<=n-16;i1++){
			for(int i2=i1+1;i2<=n-15;i2++){
				for(int i3=i2+1;i3<=n-14;i3++){
					for(int i4=i3+1;i4<=n-13;i4++){
						for(int i5=i4+1;i5<=n-12;i5++){
							for(int i6=i5+1;i6<=n-11;i6++){
								for(int i7=i6+1;i7<=n-10;i7++){
									for(int i8=i7+1;i8<=n-9;i8++){
										for(int i9=i8+1;i9<=n-8;i9++){
											for(int i10=i9+1;i10<=n-7;i10++){
												for(int i11=i10+1;i11<=n-6;i11++){
													for(int i12=i11+1;i12<=n-5;i12++){
														for(int i13=i12+1;i13<=n-4;i13++){
															for(int i14=i13+1;i14<=n-3;i14++){
																for(int i15=i14+1;i15<=n-2;i15++){
																	for(int i16=i15+1;i16<=n-1;i16++){
																		for(int i17=i16+1;i17<=n;i17++){
																			a[1]=mg[i1];
																			a[2]=mg[i2];
																			a[3]=mg[i3];
																			a[4]=mg[i4];
																			a[5]=mg[i5];
																			a[6]=mg[i6];
																			a[7]=mg[i7];
																			a[8]=mg[i8];
																			a[9]=mg[i9];
																			a[10]=mg[i10];
																			a[11]=mg[i11];
																			a[12]=mg[i12];
																			a[13]=mg[i13];
																			a[14]=mg[i14];
																			a[15]=mg[i15];
																			a[16]=mg[i16];
																			a[17]=mg[i17];
																			if(polygon(17)) s++;
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	s%=998244353;
	if(n>=18){
		for(int i1=1;i1<=n-17;i1++){
			for(int i2=i1+1;i2<=n-16;i2++){
				for(int i3=i2+1;i3<=n-15;i3++){
					for(int i4=i3+1;i4<=n-14;i4++){
						for(int i5=i4+1;i5<=n-13;i5++){
							for(int i6=i5+1;i6<=n-12;i6++){
								for(int i7=i6+1;i7<=n-11;i7++){
									for(int i8=i7+1;i8<=n-10;i8++){
										for(int i9=i8+1;i9<=n-9;i9++){
											for(int i10=i9+1;i10<=n-8;i10++){
												for(int i11=i10+1;i11<=n-7;i11++){
													for(int i12=i11+1;i12<=n-6;i12++){
														for(int i13=i12+1;i13<=n-5;i13++){
															for(int i14=i13+1;i14<=n-4;i14++){
																for(int i15=i14+1;i15<=n-3;i15++){
																	for(int i16=i15+1;i16<=n-2;i16++){
																		for(int i17=i16+1;i17<=n-1;i17++){
																			for(int i18=i17+1;i18<=n;i18++){
																				a[1]=mg[i1];
																				a[2]=mg[i2];
																				a[3]=mg[i3];
																				a[4]=mg[i4];
																				a[5]=mg[i5];
																				a[6]=mg[i6];
																				a[7]=mg[i7];
																				a[8]=mg[i8];
																				a[9]=mg[i9];
																				a[10]=mg[i10];
																				a[11]=mg[i11];
																				a[12]=mg[i12];
																				a[13]=mg[i13];
																				a[14]=mg[i14];
																				a[15]=mg[i15];
																				a[16]=mg[i16];
																				a[17]=mg[i17];
																				a[18]=mg[i18];
																				if(polygon(18)) s++;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	s%=998244353;
	if(n>=19){
		for(int i1=1;i1<=n-18;i1++){
			for(int i2=i1+1;i2<=n-17;i2++){
				for(int i3=i2+1;i3<=n-16;i3++){
					for(int i4=i3+1;i4<=n-15;i4++){
						for(int i5=i4+1;i5<=n-14;i5++){
							for(int i6=i5+1;i6<=n-13;i6++){
								for(int i7=i6+1;i7<=n-12;i7++){
									for(int i8=i7+1;i8<=n-11;i8++){
										for(int i9=i8+1;i9<=n-10;i9++){
											for(int i10=i9+1;i10<=n-9;i10++){
												for(int i11=i10+1;i11<=n-8;i11++){
													for(int i12=i11+1;i12<=n-7;i12++){
														for(int i13=i12+1;i13<=n-6;i13++){
															for(int i14=i13+1;i14<=n-5;i14++){
																for(int i15=i14+1;i15<=n-4;i15++){
																	for(int i16=i15+1;i16<=n-3;i16++){
																		for(int i17=i16+1;i17<=n-2;i17++){
																			for(int i18=i17+1;i18<=n-1;i18++){
																				for(int i19=i18+1;i19<=n;i19++){
																					a[1]=mg[i1];
																					a[2]=mg[i2];
																					a[3]=mg[i3];
																					a[4]=mg[i4];
																					a[5]=mg[i5];
																					a[6]=mg[i6];
																					a[7]=mg[i7];
																					a[8]=mg[i8];
																					a[9]=mg[i9];
																					a[10]=mg[i10];
																					a[11]=mg[i11];
																					a[12]=mg[i12];
																					a[13]=mg[i13];
																					a[14]=mg[i14];
																					a[15]=mg[i15];
																					a[16]=mg[i16];
																					a[17]=mg[i17];
																					a[18]=mg[i18];
																					a[19]=mg[i19];
																					if(polygon(19)) s++;
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	s%=998244353;
	if(n>=20){
		for(int i1=1;i1<=n-19;i1++){
			for(int i2=i1+1;i2<=n-18;i2++){
				for(int i3=i2+1;i3<=n-17;i3++){
					for(int i4=i3+1;i4<=n-16;i4++){
						for(int i5=i4+1;i5<=n-15;i5++){
							for(int i6=i5+1;i6<=n-14;i6++){
								for(int i7=i6+1;i7<=n-13;i7++){
									for(int i8=i7+1;i8<=n-12;i8++){
										for(int i9=i8+1;i9<=n-11;i9++){
											for(int i10=i9+1;i10<=n-10;i10++){
												for(int i11=i10+1;i11<=n-9;i11++){
													for(int i12=i11+1;i12<=n-8;i12++){
														for(int i13=i12+1;i13<=n-7;i13++){
															for(int i14=i13+1;i14<=n-6;i14++){
																for(int i15=i14+1;i15<=n-5;i15++){
																	for(int i16=i15+1;i16<=n-4;i16++){
																		for(int i17=i16+1;i17<=n-3;i17++){
																			for(int i18=i17+1;i18<=n-2;i18++){
																				for(int i19=i18+1;i19<=n-1;i19++){
																					for(int i20=i19+1;i20<=n;i20++){
																						a[1]=mg[i1];
																						a[2]=mg[i2];
																						a[3]=mg[i3];
																						a[4]=mg[i4];
																						a[5]=mg[i5];
																						a[6]=mg[i6];
																						a[7]=mg[i7];
																						a[8]=mg[i8];
																						a[9]=mg[i9];
																						a[10]=mg[i10];
																						a[11]=mg[i11];
																						a[12]=mg[i12];
																						a[13]=mg[i13];
																						a[14]=mg[i14];
																						a[15]=mg[i15];
																						a[16]=mg[i16];
																						a[17]=mg[i17];
																						a[18]=mg[i18];
																						a[19]=mg[i19];
																						a[20]=mg[i20];
																						if(polygon(20)) s++;
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	s%=998244353;
	cout<<s;
	return 0;
}

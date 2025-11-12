#include<bits/stdc++.h>
using namespace std;

int n;
int a[5100];
int he,maxa;
int H;
bool bja[5100];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n ;
	for (int i=1;i<=n;i++){
		cin >> a[i] ;
	}
	for (int o=1;o<=n;o++){
		if (o==3){
			for (int i=1;i<=n-2;i++){
				for (int j=i+1;j<=n-1;j++){
					for (int h=j+1;h<=n;h++){
						he=a[i]+a[j]+a[h];
	//					maxa=max(max(max(maxa,a[i]),a[j]),a[h]);
						maxa=max(a[i],a[j]);
						maxa=max(maxa,a[h]);
						if (he>maxa*2){
							H++;
							
							//cout << a[i] << " " << a[j] << " " << a[h] << endl ;
						}
					}
				}
			}
		}
		if (o==4){
			for (int i=1;i<=n-3;i++){
				for (int j=i+1;j<=n-2;j++){
					for (int h=j+1;h<=n-1;h++){
						for (int p=h+1;p<=n;p++){
							he=a[i]+a[j]+a[h]+a[p];
		//					maxa=max(max(max(maxa,a[i]),a[j]),a[h]);
							maxa=max(a[i],a[j]);
							maxa=max(maxa,a[h]);
							maxa=max(maxa,a[p]);
							if (he>maxa*2){
								H++;
								
								//cout << a[i] << " " << a[j] << " " << a[h] << endl ;
							}
						}
					}
				}
			}
		}
		if (o==5){
			for (int i=1;i<=n-4;i++){
				for (int j=i+1;j<=n-3;j++){
					for (int h=j+1;h<=n-2;h++){
						for (int p=h+1;p<=n-1;p++){
							for (int g=p+1;g<=n;g++){
								he=a[i]+a[j]+a[h]+a[p]+a[g];
			//					maxa=max(max(max(maxa,a[i]),a[j]),a[h]);
								maxa=max(a[i],a[j]);
								maxa=max(maxa,a[h]);
								maxa=max(maxa,a[p]);
								maxa=max(maxa,a[g]);
								if (he>maxa*2){
									H++;
									
									//cout << a[i] << " " << a[j] << " " << a[h] << endl ;
								}
							}
						}
					}
				}
			}
		}
		if (o==6){
			for (int i=1;i<=n-5;i++){
				for (int j=i+1;j<=n-4;j++){
					for (int h=j+1;h<=n-3;h++){
						for (int p=h+1;p<=n-2;p++){
							for (int g=p+1;g<=n-1;g++){
								for (int f=g+1;f<=n;f++){
									he=a[i]+a[j]+a[h]+a[p]+a[g]+a[f];
				//					maxa=max(max(max(maxa,a[i]),a[j]),a[h]);
									maxa=max(a[i],a[j]);
									maxa=max(maxa,a[h]);
									maxa=max(maxa,a[p]);
									maxa=max(maxa,a[g]);
									maxa=max(maxa,a[f]);
									if (he>maxa*2){
										H++;
										
										//cout << a[i] << " " << a[j] << " " << a[h] << endl ;
									}
								}
							}
						}
					}
				}
			}
		}
		if (o==7){
			for (int i=1;i<=n-6;i++){
				for (int j=i+1;j<=n-5;j++){
					for (int h=j+1;h<=n-4;h++){
						for (int p=h+1;p<=n-3;p++){
							for (int g=p+1;g<=n-2;g++){
								for (int f=g+1;f<=n-1;f++){
									for (int d=f+1;d<=n;d++){
										he=a[i]+a[j]+a[h]+a[p]+a[g]+a[f]+a[d];
					//					maxa=max(max(max(maxa,a[i]),a[j]),a[h]);
										maxa=max(a[i],a[j]);
										maxa=max(maxa,a[h]);
										maxa=max(maxa,a[p]);
										maxa=max(maxa,a[g]);
										maxa=max(maxa,a[f]);
										maxa=max(maxa,a[d]);
										if (he>maxa*2){
											H++;
											
											//cout << a[i] << " " << a[j] << " " << a[h] << endl ;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (o==8){
			for (int i=1;i<=n-7;i++){
				for (int j=i+1;j<=n-6;j++){
					for (int h=j+1;h<=n-5;h++){
						for (int p=h+1;p<=n-4;p++){
							for (int g=p+1;g<=n-3;g++){
								for (int f=g+1;f<=n-2;f++){
									for (int d=f+1;d<=n-1;d++){
										for (int m=d+1;m<=n;m++){
											he=a[i]+a[j]+a[h]+a[p]+a[g]+a[f]+a[d]+a[m];
						//					maxa=max(max(max(maxa,a[i]),a[j]),a[h]);
											maxa=max(a[i],a[j]);
											maxa=max(maxa,a[h]);
											maxa=max(maxa,a[p]);
											maxa=max(maxa,a[g]);
											maxa=max(maxa,a[f]);
											maxa=max(maxa,a[d]);
											maxa=max(maxa,a[m]);
											if (he>maxa*2){
												H++;
												
												//cout << a[i] << " " << a[j] << " " << a[h] << endl ;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (o==9){
			for (int i=1;i<=n-8;i++){
				for (int j=i+1;j<=n-7;j++){
					for (int h=j+1;h<=n-6;h++){
						for (int p=h+1;p<=n-5;p++){
							for (int g=p+1;g<=n-4;g++){
								for (int f=g+1;f<=n-3;f++){
									for (int d=f+1;d<=n-2;d++){
										for (int m=d+1;m<=n-1;m++){
											for (int b=m+1;b<=n;b++){
												he=a[i]+a[j]+a[h]+a[p]+a[g]+a[f]+a[d]+a[m]+a[b];
							//					maxa=max(max(max(maxa,a[i]),a[j]),a[h]);
												maxa=max(a[i],a[j]);
												maxa=max(maxa,a[h]);
												maxa=max(maxa,a[p]);
												maxa=max(maxa,a[g]);
												maxa=max(maxa,a[f]);
												maxa=max(maxa,a[d]);
												maxa=max(maxa,a[m]);
												maxa=max(maxa,a[b]);
												if (he>maxa*2){
													H++;
													
													//cout << a[i] << " " << a[j] << " " << a[h] << endl ;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (o==10){
			for (int i=1;i<=n-9;i++){
				for (int j=i+1;j<=n-8;j++){
					for (int h=j+1;h<=n-7;h++){
						for (int p=h+1;p<=n-6;p++){
							for (int g=p+1;g<=n-5;g++){
								for (int f=g+1;f<=n-4;f++){
									for (int d=f+1;d<=n-3;d++){
										for (int m=d+1;m<=n-2;m++){
											for (int b=m+1;b<=n-1;b++){
												for (int v=b+1;v<=n;v++){
													he=a[i]+a[j]+a[h]+a[p]+a[g]+a[f]+a[d]+a[m]+a[b]+a[v];
								//					maxa=max(max(max(maxa,a[i]),a[j]),a[h]);
													maxa=max(a[i],a[j]);
													maxa=max(maxa,a[h]);
													maxa=max(maxa,a[p]);
													maxa=max(maxa,a[g]);
													maxa=max(maxa,a[f]);
													maxa=max(maxa,a[d]);
													maxa=max(maxa,a[m]);
													maxa=max(maxa,a[b]);
													maxa=max(maxa,a[v]);
													if (he>maxa*2){
														H++;
														
														//cout << a[i] << " " << a[j] << " " << a[h] << endl ;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (o==11){
			for(int i=1;i<=n-10;i++){
				for (int j=i+1;j<=n-9;j++){
					for (int h=j+1;h<=n-8;h++){
						for (int p=h+1;p<=n-7;p++){
							for (int g=p+1;g<=n-6;g++){
								for (int f=g+1;f<=n-5;f++){
									for (int d=f+1;d<=n-4;d++){
										for (int m=d+1;m<=n-3;m++){
											for (int b=m+1;b<=n-2;b++){
												for (int v=b+1;v<=n-1;v++){
													for (int x=v+1;x<=n;x++){
														he=a[i]+a[j]+a[h]+a[p]+a[g]+a[f]+a[d]+a[m]+a[b]+a[v]+a[x];
									//					maxa=max(max(max(maxa,a[i]),a[j]),a[h]);
														maxa=max(a[i],a[j]);
														maxa=max(maxa,a[h]);
														maxa=max(maxa,a[p]);
														maxa=max(maxa,a[g]);
														maxa=max(maxa,a[f]);
														maxa=max(maxa,a[d]);
														maxa=max(maxa,a[m]);
														maxa=max(maxa,a[b]);
														maxa=max(maxa,a[v]);
														maxa=max(maxa,a[x]);
														if (he>maxa*2){
															H++;
															
															//cout << a[i] << " " << a[j] << " " << a[h] << endl ;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (o==12){
			for(int i=1;i<=n-11;i++){
				for (int j=i+1;j<=n-10;j++){
					for (int h=j+1;h<=n-9;h++){
						for (int p=h+1;p<=n-8;p++){
							for (int g=p+1;g<=n-7;g++){
								for (int f=g+1;f<=n-6;f++){
									for (int d=f+1;d<=n-5;d++){
										for (int m=d+1;m<=n-4;m++){
											for (int b=m+1;b<=n-3;b++){
												for (int v=b+1;v<=n-2;v++){
													for (int x=v+1;x<=n-1;x++){
														for (int z=x+1;z<=n;z++){
															he=a[i]+a[j]+a[h]+a[p]+a[g]+a[f]+a[d]+a[m]+a[b]+a[v]+a[x]+a[z];
										//					maxa=max(max(max(maxa,a[i]),a[j]),a[h]);
															maxa=max(a[i],a[j]);
															maxa=max(maxa,a[h]);
															maxa=max(maxa,a[p]);
															maxa=max(maxa,a[g]);
															maxa=max(maxa,a[f]);
															maxa=max(maxa,a[d]);
															maxa=max(maxa,a[m]);
															maxa=max(maxa,a[b]);
															maxa=max(maxa,a[v]);
															maxa=max(maxa,a[x]);
															maxa=max(maxa,a[z]);
															if (he>maxa*2){
																H++;
																
																//cout << a[i] << " " << a[j] << " " << a[h] << endl ;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (o==13){
			for(int i=1;i<=n-12;i++){
				for (int j=i+1;j<=n-11;j++){
					for (int h=j+1;h<=n-10;h++){
						for (int p=h+1;p<=n-9;p++){
							for (int g=p+1;g<=n-8;g++){
								for (int f=g+1;f<=n-7;f++){
									for (int d=f+1;d<=n-6;d++){
										for (int m=d+1;m<=n-5;m++){
											for (int b=m+1;b<=n-4;b++){
												for (int v=b+1;v<=n-3;v++){
													for (int x=v+1;x<=n-2;x++){
														for (int z=x+1;z<=n-1;z++){
															for (int q=z+1;q<=n;q++){
																he=a[i]+a[j]+a[h]+a[p]+a[g]+a[f]+a[d]+a[m]+a[b]+a[v]+a[x]+a[z]+a[q];
											//					maxa=max(max(max(maxa,a[i]),a[j]),a[h]);
																maxa=max(a[i],a[j]);
																maxa=max(maxa,a[h]);
																maxa=max(maxa,a[p]);
																maxa=max(maxa,a[g]);
																maxa=max(maxa,a[f]);
																maxa=max(maxa,a[d]);
																maxa=max(maxa,a[m]);
																maxa=max(maxa,a[b]);
																maxa=max(maxa,a[v]);
																maxa=max(maxa,a[x]);
																maxa=max(maxa,a[z]);
																maxa=max(maxa,a[q]);
																if (he>maxa*2){
																	H++;
																	
																	//cout << a[i] << " " << a[j] << " " << a[h] << endl ;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (o==14){
			for(int i=1;i<=n-13;i++){
				for (int j=i+1;j<=n-12;j++){
					for (int h=j+1;h<=n-11;h++){
						for (int p=h+1;p<=n-10;p++){
							for (int g=p+1;g<=n-9;g++){
								for (int f=g+1;f<=n-8;f++){
									for (int d=f+1;d<=n-7;d++){
										for (int m=d+1;m<=n-6;m++){
											for (int b=m+1;b<=n-5;b++){
												for (int v=b+1;v<=n-4;v++){
													for (int x=v+1;x<=n-3;x++){
														for (int z=x+1;z<=n-2;z++){
															for (int q=z+1;q<=n-1;q++){
																for (int w=q+1;w<=n;w++){
																	he=a[i]+a[j]+a[h]+a[p]+a[g]+a[f]+a[d]+a[m]+a[b]+a[v]+a[x]+a[z]+a[q]+a[w];
												//					maxa=max(max(max(maxa,a[i]),a[j]),a[h]);
																	maxa=max(a[i],a[j]);
																	maxa=max(maxa,a[h]);
																	maxa=max(maxa,a[p]);
																	maxa=max(maxa,a[g]);
																	maxa=max(maxa,a[f]);
																	maxa=max(maxa,a[d]);
																	maxa=max(maxa,a[m]);
																	maxa=max(maxa,a[b]);
																	maxa=max(maxa,a[v]);
																	maxa=max(maxa,a[x]);
																	maxa=max(maxa,a[z]);
																	maxa=max(maxa,a[q]);
																	maxa=max(maxa,a[w]);
																	if (he>maxa*2){
																		H++;
																		
																		//cout << a[i] << " " << a[j] << " " << a[h] << endl ;
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (o==15){
			for(int i=1;i<=n-14;i++){
				for (int j=i+1;j<=n-13;j++){
					for (int h=j+1;h<=n-12;h++){
						for (int p=h+1;p<=n-11;p++){
							for (int g=p+1;g<=n-10;g++){
								for (int f=g+1;f<=n-9;f++){
									for (int d=f+1;d<=n-8;d++){
										for (int m=d+1;m<=n-7;m++){
											for (int b=m+1;b<=n-6;b++){
												for (int v=b+1;v<=n-5;v++){
													for (int x=v+1;x<=n-4;x++){
														for (int z=x+1;z<=n-3;z++){
															for (int q=z+1;q<=n-2;q++){
																for (int w=q+1;w<=n-1;w++){
																	for (int ii=w+1;ii<=n;ii++){
																		he=a[i]+a[j]+a[h]+a[p]+a[g]+a[f]+a[d]+a[m]+a[b]+a[v]+a[x]+a[z]+a[q]+a[w]+a[ii];
													//					maxa=max(max(max(maxa,a[i]),a[j]),a[h]);
																		maxa=max(a[i],a[j]);
																		maxa=max(maxa,a[h]);
																		maxa=max(maxa,a[p]);
																		maxa=max(maxa,a[g]);
																		maxa=max(maxa,a[f]);
																		maxa=max(maxa,a[d]);
																		maxa=max(maxa,a[m]);
																		maxa=max(maxa,a[b]);
																		maxa=max(maxa,a[v]);
																		maxa=max(maxa,a[x]);
																		maxa=max(maxa,a[z]);
																		maxa=max(maxa,a[q]);
																		maxa=max(maxa,a[w]);
																		maxa=max(maxa,a[ii]);
																		if (he>maxa*2){
																			H++;
																			
																			//cout << a[i] << " " << a[j] << " " << a[h] << endl ;
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (o==16){
			for(int i=1;i<=n-15;i++){
				for (int j=i+1;j<=n-14;j++){
					for (int h=j+1;h<=n-13;h++){
						for (int p=h+1;p<=n-12;p++){
							for (int g=p+1;g<=n-11;g++){
								for (int f=g+1;f<=n-10;f++){
									for (int d=f+1;d<=n-9;d++){
										for (int m=d+1;m<=n-8;m++){
											for (int b=m+1;b<=n-7;b++){
												for (int v=b+1;v<=n-6;v++){
													for (int x=v+1;x<=n-5;x++){
														for (int z=x+1;z<=n-4;z++){
															for (int q=z+1;q<=n-3;q++){
																for (int w=q+1;w<=n-2;w++){
																	for (int ii=w+1;ii<=n-1;ii++){
																		for (int pp=ii+1;pp<=n;pp++){
																			he=a[i]+a[j]+a[h]+a[p]+a[g]+a[f]+a[d]+a[m]+a[b]+a[v]+a[x]+a[z]+a[q]+a[w]+a[ii]+a[pp];
														//					maxa=max(max(max(maxa,a[i]),a[j]),a[h]);
																			maxa=max(a[i],a[j]);
																			maxa=max(maxa,a[h]);
																			maxa=max(maxa,a[p]);
																			maxa=max(maxa,a[g]);
																			maxa=max(maxa,a[f]);
																			maxa=max(maxa,a[d]);
																			maxa=max(maxa,a[m]);
																			maxa=max(maxa,a[b]);
																			maxa=max(maxa,a[v]);
																			maxa=max(maxa,a[x]);
																			maxa=max(maxa,a[z]);
																			maxa=max(maxa,a[q]);
																			maxa=max(maxa,a[w]);
																			maxa=max(maxa,a[ii]);
																			maxa=max(maxa,a[pp]);
																			if (he>maxa*2){
																				H++;
																				
																				//cout << a[i] << " " << a[j] << " " << a[h] << endl ;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (o==17){
			for(int i=1;i<=n-16;i++){
				for (int j=i+1;j<=n-15;j++){
					for (int h=j+1;h<=n-14;h++){
						for (int p=h+1;p<=n-13;p++){
							for (int g=p+1;g<=n-12;g++){
								for (int f=g+1;f<=n-11;f++){
									for (int d=f+1;d<=n-10;d++){
										for (int m=d+1;m<=n-9;m++){
											for (int b=m+1;b<=n-8;b++){
												for (int v=b+1;v<=n-7;v++){
													for (int x=v+1;x<=n-6;x++){
														for (int z=x+1;z<=n-5;z++){
															for (int q=z+1;q<=n-4;q++){
																for (int w=q+1;w<=n-3;w++){
																	for (int ii=w+1;ii<=n-2;ii++){
																		for (int pp=ii+1;pp<=n-1;pp++){
																			for (int kk=pp+1;kk<=n;kk++){
																				he=a[i]+a[j]+a[h]+a[p]+a[g]+a[f]+a[d]+a[m]+a[b]+a[v]+a[x]+a[z]+a[q]+a[w]+a[ii]+a[pp]+a[kk];
															//					maxa=max(max(max(maxa,a[i]),a[j]),a[h]);
																				maxa=max(a[i],a[j]);
																				maxa=max(maxa,a[h]);
																				maxa=max(maxa,a[p]);
																				maxa=max(maxa,a[g]);
																				maxa=max(maxa,a[f]);
																				maxa=max(maxa,a[d]);
																				maxa=max(maxa,a[m]);
																				maxa=max(maxa,a[b]);
																				maxa=max(maxa,a[v]);
																				maxa=max(maxa,a[x]);
																				maxa=max(maxa,a[z]);
																				maxa=max(maxa,a[q]);
																				maxa=max(maxa,a[w]);
																				maxa=max(maxa,a[ii]);
																				maxa=max(maxa,a[pp]);
																				maxa=max(maxa,a[kk]);
																				if (he>maxa*2){
																					H++;
																					
																					//cout << a[i] << " " << a[j] << " " << a[h] << endl ;
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (o==18){
			for(int i=1;i<=n-17;i++){
				for (int j=i+1;j<=n-16;j++){
					for (int h=j+1;h<=n-15;h++){
						for (int p=h+1;p<=n-14;p++){
							for (int g=p+1;g<=n-13;g++){
								for (int f=g+1;f<=n-12;f++){
									for (int d=f+1;d<=n-11;d++){
										for (int m=d+1;m<=n-10;m++){
											for (int b=m+1;b<=n-9;b++){
												for (int v=b+1;v<=n-8;v++){
													for (int x=v+1;x<=n-7;x++){
														for (int z=x+1;z<=n-6;z++){
															for (int q=z+1;q<=n-5;q++){
																for (int w=q+1;w<=n-4;w++){
																	for (int ii=w+1;ii<=n-3;ii++){
																		for (int pp=ii+1;pp<=n-2;pp++){
																			for (int kk=pp+1;kk<=n-1;kk++){
																				for (int jj=kk+1;jj<=n;jj++){
																					he=a[i]+a[j]+a[h]+a[p]+a[g]+a[f]+a[d]+a[m]+a[b]+a[v]+a[x]+a[z]+a[q]+a[w]+a[ii]+a[pp]+a[kk]+a[jj];
																//					maxa=max(max(max(maxa,a[i]),a[j]),a[h]);
																					maxa=max(a[i],a[j]);
																					maxa=max(maxa,a[h]);
																					maxa=max(maxa,a[p]);
																					maxa=max(maxa,a[g]);
																					maxa=max(maxa,a[f]);
																					maxa=max(maxa,a[d]);
																					maxa=max(maxa,a[m]);
																					maxa=max(maxa,a[b]);
																					maxa=max(maxa,a[v]);
																					maxa=max(maxa,a[x]);
																					maxa=max(maxa,a[z]);
																					maxa=max(maxa,a[q]);
																					maxa=max(maxa,a[w]);
																					maxa=max(maxa,a[ii]);
																					maxa=max(maxa,a[pp]);
																					maxa=max(maxa,a[kk]);
																					maxa=max(maxa,a[jj]);
																					if (he>maxa*2){
																						H++;
																						
																						//cout << a[i] << " " << a[j] << " " << a[h] << endl ;
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (o==19){
			for(int i=1;i<=n-18;i++){
				for (int j=i+1;j<=n-17;j++){
					for (int h=j+1;h<=n-16;h++){
						for (int p=h+1;p<=n-15;p++){
							for (int g=p+1;g<=n-14;g++){
								for (int f=g+1;f<=n-13;f++){
									for (int d=f+1;d<=n-12;d++){
										for (int m=d+1;m<=n-11;m++){
											for (int b=m+1;b<=n-10;b++){
												for (int v=b+1;v<=n-9;v++){
													for (int x=v+1;x<=n-8;x++){
														for (int z=x+1;z<=n-7;z++){
															for (int q=z+1;q<=n-6;q++){
																for (int w=q+1;w<=n-5;w++){
																	for (int ii=w+1;ii<=n-4;ii++){
																		for (int pp=ii+1;pp<=n-3;pp++){
																			for (int kk=pp+1;kk<=n-2;kk++){
																				for (int jj=kk+1;jj<=n-1;jj++){
																					for (int hh=jj+1;hh<=n;hh++){
																						he=a[i]+a[j]+a[h]+a[p]+a[g]+a[f]+a[d]+a[m]+a[b]+a[v]+a[x]+a[z]+a[q]+a[w]+a[ii]+a[pp]+a[kk]+a[jj]+a[hh];
																	//					maxa=max(max(max(maxa,a[i]),a[j]),a[h]);
																						maxa=max(a[i],a[j]);
																						maxa=max(maxa,a[h]);
																						maxa=max(maxa,a[p]);
																						maxa=max(maxa,a[g]);
																						maxa=max(maxa,a[f]);
																						maxa=max(maxa,a[d]);
																						maxa=max(maxa,a[m]);
																						maxa=max(maxa,a[b]);
																						maxa=max(maxa,a[v]);
																						maxa=max(maxa,a[x]);
																						maxa=max(maxa,a[z]);
																						maxa=max(maxa,a[q]);
																						maxa=max(maxa,a[w]);
																						maxa=max(maxa,a[ii]);
																						maxa=max(maxa,a[pp]);
																						maxa=max(maxa,a[kk]);
																						maxa=max(maxa,a[jj]);
																						maxa=max(maxa,a[hh]);
																						if (he>maxa*2){
																							H++;
																							
																							//cout << a[i] << " " << a[j] << " " << a[h] << endl ;
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (o==20){
			for(int i=1;i<=n-19;i++){
				for (int j=i+1;j<=n-18;j++){
					for (int h=j+1;h<=n-17;h++){
						for (int p=h+1;p<=n-16;p++){
							for (int g=p+1;g<=n-15;g++){
								for (int f=g+1;f<=n-14;f++){
									for (int d=f+1;d<=n-13;d++){
										for (int m=d+1;m<=n-12;m++){
											for (int b=m+1;b<=n-11;b++){
												for (int v=b+1;v<=n-10;v++){
													for (int x=v+1;x<=n-9;x++){
														for (int z=x+1;z<=n-8;z++){
															for (int q=z+1;q<=n-7;q++){
																for (int w=q+1;w<=n-6;w++){
																	for (int ii=w+1;ii<=n-5;ii++){
																		for (int pp=ii+1;pp<=n-4;pp++){
																			for (int kk=pp+1;kk<=n-3;kk++){
																				for (int jj=kk+1;jj<=n-2;jj++){
																					for (int hh=jj+1;hh<=n-1;hh++){
																						for (int yy=hh+1;yy<=n;yy++){
																							he=a[i]+a[j]+a[h]+a[p]+a[g]+a[f]+a[d]+a[m]+a[b]+a[v]+a[x]+a[z]+a[q]+a[w]+a[ii]+a[pp]+a[kk]+a[jj]+a[hh]+a[yy];
																		//					maxa=max(max(max(maxa,a[i]),a[j]),a[h]);
																							maxa=max(a[i],a[j]);
																							maxa=max(maxa,a[h]);
																							maxa=max(maxa,a[p]);
																							maxa=max(maxa,a[g]);
																							maxa=max(maxa,a[f]);
																							maxa=max(maxa,a[d]);
																							maxa=max(maxa,a[m]);
																							maxa=max(maxa,a[b]);
																							maxa=max(maxa,a[v]);
																							maxa=max(maxa,a[x]);
																							maxa=max(maxa,a[z]);
																							maxa=max(maxa,a[q]);
																							maxa=max(maxa,a[w]);
																							maxa=max(maxa,a[ii]);
																							maxa=max(maxa,a[pp]);
																							maxa=max(maxa,a[kk]);
																							maxa=max(maxa,a[jj]);
																							maxa=max(maxa,a[hh]);
																							maxa=max(maxa,a[yy]);
																							if (he>maxa*2){
																								H++;
																								
																								//cout << a[i] << " " << a[j] << " " << a[h] << endl ;
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	cout << H%998244353 ;
	
	
	return 0;
}
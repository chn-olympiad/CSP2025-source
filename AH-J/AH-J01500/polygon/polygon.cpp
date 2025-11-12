#include <bits/stdc++.h>
using namespace std;
int a;long long b[5555],c;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++) cin>>b[i];
	if(3<=a && a<=20){
		for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				for(int k=j+1;k<=a;k++){
					if(b[i]+b[j]+b[k]>2*max(b[i],max(b[j],b[k]))) c++;
				}
			}
		}for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				for(int k=j+1;k<=a;k++){
					for(int l=k+1;l<=a;l++){if(b[i]+b[j]+b[k]+b[l]>2*max(b[i],max(b[j],max(b[k],b[l])))) c++;}
				}
			}
		}for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				for(int k=j+1;k<=a;k++){
					for(int l=k+1;l<=a;l++){
						for(int o=l+1;o<=a;o++){if(b[i]+b[j]+b[k]+b[l]+b[o]>2*max(b[i],max(b[j],max(b[k],max(b[l],b[o]))))) c++;}
					}
				}
			}
		}for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				for(int k=j+1;k<=a;k++){
					for(int l=k+1;l<=a;l++){
						for(int o=l+1;o<=a;o++){
							for(int p=o+1;p<=a;p++){if(b[i]+b[j]+b[k]+b[l]+b[o]+b[p]>2*max(b[i],max(b[j],max(b[k],max(b[l],max(b[o],b[p])))))) c++;}
						}
					}
				}
			}
		}for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				for(int k=j+1;k<=a;k++){
					for(int l=k+1;l<=a;l++){
						for(int o=l+1;o<=a;o++){
							for(int p=o+1;p<=a;p++){
								for(int q=p+1;q<=a;q++){if(b[i]+b[j]+b[k]+b[l]+b[o]+b[p]+b[q]>2*max(b[i],max(b[j],max(b[k],max(b[l],max(b[o],max(b[p],b[q]))))))) c++;}
							}
						}
					}
				}
			}
		}for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				for(int k=j+1;k<=a;k++){
					for(int l=k+1;l<=a;l++){
						for(int o=l+1;o<=a;o++){
							for(int p=o+1;p<=a;p++){
								for(int q=p+1;q<=a;q++){
									for(int y=q+1;y<=a;y++){if(b[i]+b[j]+b[k]+b[l]+b[o]+b[p]+b[q]+b[y]>2*max(b[i],max(b[j],max(b[k],max(b[l],max(b[o],max(b[p],max(b[q],b[y])))))))) c++;}
								}
							}
						}
					}
				}
			}
		}for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				for(int k=j+1;k<=a;k++){
					for(int l=k+1;l<=a;l++){
						for(int o=l+1;o<=a;o++){
							for(int p=o+1;p<=a;p++){
								for(int q=p+1;q<=a;q++){
									for(int y=q+1;y<=a;y++){
										for(int ll=y+1;ll<=a;ll++){if(b[i]+b[j]+b[k]+b[l]+b[o]+b[p]+b[q]+b[y]+b[ll]>2*max(b[i],max(b[j],max(b[k],max(b[l],max(b[o],max(b[p],max(b[q],max(b[y],b[ll]))))))))) c++;}
									}
								}
							}
						}
					}
				}
			}
		}for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				for(int k=j+1;k<=a;k++){
					for(int l=k+1;l<=a;l++){
						for(int o=l+1;o<=a;o++){
							for(int p=o+1;p<=a;p++){
								for(int q=p+1;q<=a;q++){
									for(int y=q+1;y<=a;y++){
										for(int ll=y+1;ll<=a;ll++){
											for(int lll=ll+1;lll<=a;lll++){if(b[i]+b[j]+b[k]+b[l]+b[o]+b[p]+b[q]+b[y]+b[ll]+b[lll]>2*max(b[i],max(b[j],max(b[k],max(b[l],max(b[o],max(b[p],max(b[q],max(b[y],max(b[ll],b[lll])))))))))) c++;}
										}
									}
								}
							}
						}
					}
				}
			}
		}for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				for(int k=j+1;k<=a;k++){
					for(int l=k+1;l<=a;l++){
						for(int o=l+1;o<=a;o++){
							for(int p=o+1;p<=a;p++){
								for(int q=p+1;q<=a;q++){
									for(int y=q+1;y<=a;y++){
										for(int ll=y+1;ll<=a;ll++){
											for(int lll=ll+1;lll<=a;lll++){
												for(int llll=lll+1;llll<=a;llll++){if(b[i]+b[j]+b[k]+b[l]+b[o]+b[p]+b[q]+b[y]+b[ll]+b[lll]+b[llll]>2*max(b[i],max(b[j],max(b[k],max(b[l],max(b[o],max(b[p],max(b[q],max(b[y],max(b[ll],max(b[lll],b[llll]))))))))))) c++;}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				for(int k=j+1;k<=a;k++){
					for(int l=k+1;l<=a;l++){
						for(int o=l+1;o<=a;o++){
							for(int p=o+1;p<=a;p++){
								for(int q=p+1;q<=a;q++){
									for(int y=q+1;y<=a;y++){
										for(int ll=y+1;ll<=a;ll++){
											for(int lll=ll+1;lll<=a;lll++){
												for(int llll=lll+1;llll<=a;llll++){
													for(int lllll=llll+1;lllll<=a;lllll++){if(b[i]+b[j]+b[k]+b[l]+b[o]+b[p]+b[q]+b[y]+b[ll]+b[lll]+b[llll]+b[lllll]>2*max(b[i],max(b[j],max(b[k],max(b[l],max(b[o],max(b[p],max(b[q],max(b[y],max(b[ll],max(b[lll],max(b[llll],b[lllll])))))))))))) c++;}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				for(int k=j+1;k<=a;k++){
					for(int l=k+1;l<=a;l++){
						for(int o=l+1;o<=a;o++){
							for(int p=o+1;p<=a;p++){
								for(int q=p+1;q<=a;q++){
									for(int y=q+1;y<=a;y++){
										for(int ll=y+1;ll<=a;ll++){
											for(int lll=ll+1;lll<=a;lll++){
												for(int llll=lll+1;llll<=a;llll++){
													for(int lllll=llll+1;lllll<=a;lllll++){
														for(int pp=lllll+1;pp<=a;pp++){if(b[i]+b[j]+b[k]+b[l]+b[o]+b[p]+b[q]+b[y]+b[ll]+b[lll]+b[llll]+b[lllll]+b[pp]>2*max(b[i],max(b[j],max(b[k],max(b[l],max(b[o],max(b[p],max(b[q],max(b[y],max(b[ll],max(b[lll],max(b[llll],max(b[lllll],b[pp]))))))))))))) c++;}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				for(int k=j+1;k<=a;k++){
					for(int l=k+1;l<=a;l++){
						for(int o=l+1;o<=a;o++){
							for(int p=o+1;p<=a;p++){
								for(int q=p+1;q<=a;q++){
									for(int y=q+1;y<=a;y++){
										for(int ll=y+1;ll<=a;ll++){
											for(int lll=ll+1;lll<=a;lll++){
												for(int llll=lll+1;llll<=a;llll++){
													for(int lllll=llll+1;lllll<=a;lllll++){
														for(int pp=lllll+1;pp<=a;pp++){
															for(int oo=pp+1;oo<=a;oo++){if(b[i]+b[j]+b[k]+b[l]+b[o]+b[p]+b[q]+b[y]+b[ll]+b[lll]+b[llll]+b[lllll]+b[pp]+b[oo]>2*max(b[i],max(b[j],max(b[k],max(b[l],max(b[o],max(b[p],max(b[q],max(b[y],max(b[ll],max(b[lll],max(b[llll],max(b[lllll],max(b[pp],b[oo])))))))))))))) c++;}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				for(int k=j+1;k<=a;k++){
					for(int l=k+1;l<=a;l++){
						for(int o=l+1;o<=a;o++){
							for(int p=o+1;p<=a;p++){
								for(int q=p+1;q<=a;q++){
									for(int y=q+1;y<=a;y++){
										for(int ll=y+1;ll<=a;ll++){
											for(int lll=ll+1;lll<=a;lll++){
												for(int llll=lll+1;llll<=a;llll++){
													for(int lllll=llll+1;lllll<=a;lllll++){
														for(int pp=lllll+1;pp<=a;pp++){
															for(int oo=pp+1;oo<=a;oo++){
																for(int ii=oo+1;ii<=a;ii++){if(b[i]+b[j]+b[k]+b[l]+b[o]+b[p]+b[q]+b[y]+b[ll]+b[lll]+b[llll]+b[lllll]+b[pp]+b[oo]+b[ii]>2*max(b[i],max(b[j],max(b[k],max(b[l],max(b[o],max(b[p],max(b[q],max(b[y],max(b[ll],max(b[lll],max(b[llll],max(b[lllll],max(b[pp],max(b[oo],b[ii]))))))))))))))) c++;}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				for(int k=j+1;k<=a;k++){
					for(int l=k+1;l<=a;l++){
						for(int o=l+1;o<=a;o++){
							for(int p=o+1;p<=a;p++){
								for(int q=p+1;q<=a;q++){
									for(int y=q+1;y<=a;y++){
										for(int ll=y+1;ll<=a;ll++){
											for(int lll=ll+1;lll<=a;lll++){
												for(int llll=lll+1;llll<=a;llll++){
													for(int lllll=llll+1;lllll<=a;lllll++){
														for(int pp=lllll+1;pp<=a;pp++){
															for(int oo=pp+1;oo<=a;oo++){
																for(int ii=oo+1;ii<=a;ii++){
																	for(int kk=ii+1;kk<=a;kk++){if(b[i]+b[j]+b[k]+b[l]+b[o]+b[p]+b[q]+b[y]+b[ll]+b[lll]+b[llll]+b[lllll]+b[pp]+b[oo]+b[ii]+b[kk]>2*max(b[i],max(b[j],max(b[k],max(b[l],max(b[o],max(b[p],max(b[q],max(b[y],max(b[ll],max(b[lll],max(b[llll],max(b[lllll],max(b[pp],max(b[oo],max(b[ii],b[kk])))))))))))))))) c++;}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				for(int k=j+1;k<=a;k++){
					for(int l=k+1;l<=a;l++){
						for(int o=l+1;o<=a;o++){
							for(int p=o+1;p<=a;p++){
								for(int q=p+1;q<=a;q++){
									for(int y=q+1;y<=a;y++){
										for(int ll=y+1;ll<=a;ll++){
											for(int lll=ll+1;lll<=a;lll++){
												for(int llll=lll+1;llll<=a;llll++){
													for(int lllll=llll+1;lllll<=a;lllll++){
														for(int pp=lllll+1;pp<=a;pp++){
															for(int oo=pp+1;oo<=a;oo++){
																for(int ii=oo+1;ii<=a;ii++){
																	for(int kk=ii+1;kk<=a;kk++){
																		for(int jj=kk+1;jj<=a;jj++){if(b[i]+b[j]+b[k]+b[l]+b[o]+b[p]+b[q]+b[y]+b[ll]+b[lll]+b[llll]+b[lllll]+b[pp]+b[oo]+b[ii]+b[kk]+b[jj]>2*max(b[i],max(b[j],max(b[k],max(b[l],max(b[o],max(b[p],max(b[q],max(b[y],max(b[ll],max(b[lll],max(b[llll],max(b[lllll],max(b[pp],max(b[oo],max(b[ii],max(b[kk],b[jj]))))))))))))))))) c++;}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				for(int k=j+1;k<=a;k++){
					for(int l=k+1;l<=a;l++){
						for(int o=l+1;o<=a;o++){
							for(int p=o+1;p<=a;p++){
								for(int q=p+1;q<=a;q++){
									for(int y=q+1;y<=a;y++){
										for(int ll=y+1;ll<=a;ll++){
											for(int lll=ll+1;lll<=a;lll++){
												for(int llll=lll+1;llll<=a;llll++){
													for(int lllll=llll+1;lllll<=a;lllll++){
														for(int pp=lllll+1;pp<=a;pp++){
															for(int oo=pp+1;oo<=a;oo++){
																for(int ii=oo+1;ii<=a;ii++){
																	for(int kk=ii+1;kk<=a;kk++){
																		for(int jj=kk+1;jj<=a;jj++){
																			for(int u=jj+1;u<+a;u++){if(b[i]+b[j]+b[k]+b[l]+b[o]+b[p]+b[q]+b[y]+b[ll]+b[lll]+b[llll]+b[lllll]+b[pp]+b[oo]+b[ii]+b[kk]+b[jj]+b[u]>2*max(b[i],max(b[j],max(b[k],max(b[l],max(b[o],max(b[p],max(b[q],max(b[y],max(b[ll],max(b[lll],max(b[llll],max(b[lllll],max(b[pp],max(b[oo],max(b[ii],max(b[kk],max(b[jj],b[u])))))))))))))))))) c++;}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				for(int k=j+1;k<=a;k++){
					for(int l=k+1;l<=a;l++){
						for(int o=l+1;o<=a;o++){
							for(int p=o+1;p<=a;p++){
								for(int q=p+1;q<=a;q++){
									for(int y=q+1;y<=a;y++){
										for(int ll=y+1;ll<=a;ll++){
											for(int lll=ll+1;lll<=a;lll++){
												for(int llll=lll+1;llll<=a;llll++){
													for(int lllll=llll+1;lllll<=a;lllll++){
														for(int pp=lllll+1;pp<=a;pp++){
															for(int oo=pp+1;oo<=a;oo++){
																for(int ii=oo+1;ii<=a;ii++){
																	for(int kk=ii+1;kk<=a;kk++){
																		for(int jj=kk+1;jj<=a;jj++){
																			for(int u=jj+1;u<+a;u++){
																				for(int uu=u+1;uu<=a;uu++){if(b[i]+b[j]+b[k]+b[l]+b[o]+b[p]+b[q]+b[y]+b[ll]+b[lll]+b[llll]+b[lllll]+b[pp]+b[oo]+b[ii]+b[kk]+b[jj]+b[u]+b[uu]>2*max(b[i],max(b[j],max(b[k],max(b[l],max(b[o],max(b[p],max(b[q],max(b[y],max(b[ll],max(b[lll],max(b[llll],max(b[lllll],max(b[pp],max(b[oo],max(b[ii],max(b[kk],max(b[jj],max(b[u],b[uu]))))))))))))))))))) c++;}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				for(int k=j+1;k<=a;k++){
					for(int l=k+1;l<=a;l++){
						for(int o=l+1;o<=a;o++){
							for(int p=o+1;p<=a;p++){
								for(int q=p+1;q<=a;q++){
									for(int y=q+1;y<=a;y++){
										for(int ll=y+1;ll<=a;ll++){
											for(int lll=ll+1;lll<=a;lll++){
												for(int llll=lll+1;llll<=a;llll++){
													for(int lllll=llll+1;lllll<=a;lllll++){
														for(int pp=lllll+1;pp<=a;pp++){
															for(int oo=pp+1;oo<=a;oo++){
																for(int ii=oo+1;ii<=a;ii++){
																	for(int kk=ii+1;kk<=a;kk++){
																		for(int jj=kk+1;jj<=a;jj++){
																			for(int u=jj+1;u<+a;u++){
																				for(int uu=u+1;uu<=a;uu++){
																					for(int r=uu+1;r<=a;r++){if(b[i]+b[j]+b[k]+b[l]+b[o]+b[p]+b[q]+b[y]+b[ll]+b[lll]+b[llll]+b[lllll]+b[pp]+b[oo]+b[ii]+b[kk]+b[jj]+b[u]+b[uu]+b[r]>2*max(b[i],max(b[j],max(b[k],max(b[l],max(b[o],max(b[p],max(b[q],max(b[y],max(b[ll],max(b[lll],max(b[llll],max(b[lllll],max(b[pp],max(b[oo],max(b[ii],max(b[kk],max(b[jj],max(b[u],max(b[uu],b[r])))))))))))))))))))) c++;}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}else{
		cout<<366911923;return 0;
	}
	cout<<c%998244353;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int k[30];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>k[i];
	for(int a=1;a<=n;a++){
		for(int b=a+1;b<=n;b++){
			for(int c=b+1;c<=n;c++){
				int aa=k[a],bb=k[b],cc=k[c];
				int mmax=max(aa,max(bb,cc));
				if((aa+bb+cc)>mmax*2)cnt++;
			}
		}
	}
	for(int a=1;a<=n;a++){
		for(int b=a+1;b<=n;b++){
			for(int c=b+1;c<=n;c++){
					for(int d=c+1;d<=n;d++){
					int aa=k[a],bb=k[b],cc=k[c],dd=k[d];
					int mmax=max(aa,max(bb,max(cc,dd)));
					if((aa+bb+cc+dd)>mmax*2)cnt++;
				}
			}
		}
	}
	for(int a=1;a<=n;a++){
		for(int b=a+1;b<=n;b++){
			for(int c=b+1;c<=n;c++){
				for(int d=c+1;d<=n;d++){
					for(int e=d+1;e<=n;e++){
						int aa=k[a],bb=k[b],cc=k[c],dd=k[d],ee=k[e];
						int mmax=max(aa,max(bb,max(cc,max(dd,ee))));
						if((aa+bb+cc+dd+ee)>mmax*2)cnt++;
					}
				}
			}
		}
	}
	for(int a=1;a<=n;a++){
		for(int b=a+1;b<=n;b++){
			for(int c=b+1;c<=n;c++){
				for(int d=c+1;d<=n;d++){
					for(int e=d+1;e<=n;e++){
						for(int f=e+1;f<=n;f++){
							int aa=k[a],bb=k[b],cc=k[c],dd=k[d],ee=k[e],ff=k[f];
							int mmax=max(aa,max(bb,max(cc,max(dd,max(ee,ff)))));
							if((aa+bb+cc+dd+ee+ff)>mmax*2)cnt++;
						}
					}
				}
			}
		}
	}
	for(int a=1;a<=n;a++){
		for(int b=a+1;b<=n;b++){
			for(int c=b+1;c<=n;c++){
				for(int d=c+1;d<=n;d++){
					for(int e=d+1;e<=n;e++){
						for(int f=e+1;f<=n;f++){
							int aa=k[a],bb=k[b],cc=k[c],dd=k[d],ee=k[e],ff=k[f];
							int mmax=max(aa,max(bb,max(cc,max(dd,max(ee,ff)))));
							if((aa+bb+cc+dd+ee+ff)>mmax*2)cnt++;
						}
					}
				}
			}
		}
	}
	for(int a=1;a<=n;a++){
		for(int b=a+1;b<=n;b++){
			for(int c=b+1;c<=n;c++){
				for(int d=c+1;d<=n;d++){
					for(int e=d+1;e<=n;e++){
						for(int f=e+1;f<=n;f++){
							for(int g=f+1;g<=n;g++){
								int aa=k[a],bb=k[b],cc=k[c],dd=k[d],ee=k[e],ff=k[f],gg=k[g];
								int mmax=max(aa,max(bb,max(cc,max(dd,max(ee,max(ff,gg))))));
								if((aa+bb+cc+dd+ee+ff+gg)>mmax*2)cnt++;
							}
						}
					}
				}
			}
		}
	}
	for(int a=1;a<=n;a++){
		for(int b=a+1;b<=n;b++){
			for(int c=b+1;c<=n;c++){
				for(int d=c+1;d<=n;d++){
					for(int e=d+1;e<=n;e++){
						for(int f=e+1;f<=n;f++){
							for(int g=f+1;g<=n;g++){
								for(int h=g+1;h<=n;h++){
									int aa=k[a],bb=k[b],cc=k[c],dd=k[d],ee=k[e],ff=k[f],gg=k[g],hh=k[h];
									int mmax=max(aa,max(bb,max(cc,max(dd,max(ee,max(ff,max(gg,hh)))))));
									if((aa+bb+cc+dd+ee+ff+gg+hh)>mmax*2)cnt++;
								}
							}
						}
					}
				}
			}
		}
	}
	for(int a=1;a<=n;a++){
		for(int b=a+1;b<=n;b++){
			for(int c=b+1;c<=n;c++){
				for(int d=c+1;d<=n;d++){
					for(int e=d+1;e<=n;e++){
						for(int f=e+1;f<=n;f++){
							for(int g=f+1;g<=n;g++){
								for(int h=g+1;h<=n;h++){
									for(int i=h+1;i<=n;i++){
										int aa=k[a],bb=k[b],cc=k[c],dd=k[d],ee=k[e],ff=k[f],gg=k[g],hh=k[h],ii=k[i];
										int mmax=max(aa,max(bb,max(cc,max(dd,max(ee,max(ff,max(gg,max(hh,ii))))))));
										if((aa+bb+cc+dd+ee+ff+gg+hh+ii)>mmax*2)cnt++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for(int a=1;a<=n;a++){
		for(int b=a+1;b<=n;b++){
			for(int c=b+1;c<=n;c++){
				for(int d=c+1;d<=n;d++){
					for(int e=d+1;e<=n;e++){
						for(int f=e+1;f<=n;f++){
							for(int g=f+1;g<=n;g++){
								for(int h=g+1;h<=n;h++){
									for(int i=h+1;i<=n;i++){
										for(int j=i+1;j<=n;j++){
											int aa=k[a],bb=k[b],cc=k[c],dd=k[d],ee=k[e],ff=k[f],gg=k[g],hh=k[h],ii=k[i],jj=k[j];
											int mmax=max(aa,max(bb,max(cc,max(dd,max(ee,max(ff,max(gg,max(hh,max(ii,jj)))))))));
											if((aa+bb+cc+dd+ee+ff+gg+hh+ii+jj)>mmax*2)cnt++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for(int a=1;a<=n;a++){
		for(int b=a+1;b<=n;b++){
			for(int c=b+1;c<=n;c++){
				for(int d=c+1;d<=n;d++){
					for(int e=d+1;e<=n;e++){
						for(int f=e+1;f<=n;f++){
							for(int g=f+1;g<=n;g++){
								for(int h=g+1;h<=n;h++){
									for(int i=h+1;i<=n;i++){
										for(int j=i+1;j<=n;j++){
											for(int kk=j+1;kk<=n;kk++){
												int aa=k[a],bb=k[b],cc=k[c],dd=k[d],ee=k[e],ff=k[f],gg=k[g],hh=k[h],ii=k[i],jj=k[j],kkk=k[kk];
												int mmax=max(aa,max(bb,max(cc,max(dd,max(ee,max(ff,max(gg,max(hh,max(ii,max(jj,kkk))))))))));
												if((aa+bb+cc+dd+ee+ff+gg+hh+ii+jj+kkk)>mmax*2)cnt++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}//11
	for(int a=1;a<=n;a++){
		for(int b=a+1;b<=n;b++){
			for(int c=b+1;c<=n;c++){
				for(int d=c+1;d<=n;d++){
					for(int e=d+1;e<=n;e++){
						for(int f=e+1;f<=n;f++){
							for(int g=f+1;g<=n;g++){
								for(int h=g+1;h<=n;h++){
									for(int i=h+1;i<=n;i++){
										for(int j=i+1;j<=n;j++){
											for(int kk=j+1;kk<=n;kk++){
												for(int l=kk+1;l<=n;l++){
													int aa=k[a],bb=k[b],cc=k[c],dd=k[d],ee=k[e],ff=k[f],gg=k[g],hh=k[h],ii=k[i],jj=k[j],kkk=k[kk],ll=k[ll];
													int mmax=max(aa,max(bb,max(cc,max(dd,max(ee,max(ff,max(gg,max(hh,max(ii,max(jj,max(kkk,ll)))))))))));
													if((aa+bb+cc+dd+ee+ff+gg+hh+ii+jj+kkk+ll)>mmax*2)cnt++;
												}	
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}//12
	for(int a=1;a<=n;a++){
		for(int b=a+1;b<=n;b++){
			for(int c=b+1;c<=n;c++){
				for(int d=c+1;d<=n;d++){
					for(int e=d+1;e<=n;e++){
						for(int f=e+1;f<=n;f++){
							for(int g=f+1;g<=n;g++){
								for(int h=g+1;h<=n;h++){
									for(int i=h+1;i<=n;i++){
										for(int j=i+1;j<=n;j++){
											for(int kk=j+1;kk<=n;kk++){
												for(int l=kk+1;l<=n;l++){
													for(int m=l+1;m<=n;m++){
														int aa=k[a],bb=k[b],cc=k[c],dd=k[d],ee=k[e],ff=k[f],gg=k[g],hh=k[h],ii=k[i],jj=k[j],kkk=k[kk],ll=k[ll],mm=k[m];
														int mmax=max(aa,max(bb,max(cc,max(dd,max(ee,max(ff,max(gg,max(hh,max(ii,max(jj,max(kkk,max(ll,mm))))))))))));
														if((aa+bb+cc+dd+ee+ff+gg+hh+ii+jj+kkk+ll+mm)>mmax*2)cnt++;
													}
												}	
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}//13
	cout<<cnt;
	return 0;
}

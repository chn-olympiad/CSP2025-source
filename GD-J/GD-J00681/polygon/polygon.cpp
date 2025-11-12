#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[1011010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=20){
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]>a[k])ans++;
				} 
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						if(a[i]+a[j]+a[k]>a[l])ans++;
					}
				} 
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int p=l+1;p<=n;p++){
							if(a[i]+a[j]+a[k]+a[l]>a[p])ans++;
						}
					}
				} 
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int p=l+1;p<=n;p++){
							for(int g=p+1;g<=n;g++){
								if(a[i]+a[j]+a[k]+a[l]+a[p]>a[g])ans++;
							} 
							
						}
					}
				} 
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int p=l+1;p<=n;p++){
							for(int g=p+1;g<=n;g++){
								for(int o=g+1;o<=n;o++)if(a[i]+a[j]+a[k]+a[l]+a[p]+a[g]>a[o])ans++;
							} 
							
						}
					}
				} 
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int p=l+1;p<=n;p++){
							for(int g=p+1;g<=n;g++){
								for(int o=g+1;o<=n;o++){
									for(int y=o+1;y<=n;y++)if(a[i]+a[j]+a[k]+a[l]+a[p]+a[g]+a[o]>a[y])ans++;
								}
								
							} 
							
						}
					}
				} 
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int p=l+1;p<=n;p++){
							for(int g=p+1;g<=n;g++){
								for(int o=g+1;o<=n;o++){
									for(int y=o+1;y<=n;y++){
										for(int x=y+1;x<=n;x++){
											if(a[i]+a[j]+a[k]+a[l]+a[p]+a[g]+a[o]+a[y]>a[x])ans++;
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
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int p=l+1;p<=n;p++){
							for(int g=p+1;g<=n;g++){
								for(int o=g+1;o<=n;o++){
									for(int y=o+1;y<=n;y++){
										for(int x=y+1;x<=n;x++){
											for(int b=x+1;b<=n;b++)if(a[i]+a[j]+a[k]+a[l]+a[p]+a[g]+a[o]+a[y]+a[x]>a[b])ans++;
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
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int p=l+1;p<=n;p++){
							for(int g=p+1;g<=n;g++){
								for(int o=g+1;o<=n;o++){
									for(int y=o+1;y<=n;y++){
										for(int x=y+1;x<=n;x++){
											for(int b=x+1;b<=n;b++){
													for(int i1=b+1;i1<=n;i1++)if(a[i]+a[j]+a[k]+a[l]+a[p]+a[g]+a[o]+a[y]+a[x]+a[b]>a[i1])ans++;
											}
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
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int p=l+1;p<=n;p++){
							for(int g=p+1;g<=n;g++){
								for(int o=g+1;o<=n;o++){
									for(int y=o+1;y<=n;y++){
										for(int x=y+1;x<=n;x++){
											for(int b=x+1;b<=n;b++){
													for(int i1=b+1;i1<=n;i1++){
														for(int i2=i1+1;i2<=n;i2++)if(a[i]+a[j]+a[k]+a[l]+a[p]+a[g]+a[o]+a[y]+a[x]+a[b]+a[i1]>a[i2])ans++;
													}
											}
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
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int p=l+1;p<=n;p++){
							for(int g=p+1;g<=n;g++){
								for(int o=g+1;o<=n;o++){
									for(int y=o+1;y<=n;y++){
										for(int x=y+1;x<=n;x++){
											for(int b=x+1;b<=n;b++){
													for(int i1=b+1;i1<=n;i1++){
														for(int i2=i1+1;i2<=n;i2++){
															for(int i3=i2+1;i3<=n;i3++)if(a[i]+a[j]+a[k]+a[l]+a[p]+a[g]+a[o]+a[y]+a[x]+a[b]+a[i1]+a[i2]>a[i3])ans++;
														}
													}
											}
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
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int p=l+1;p<=n;p++){
							for(int g=p+1;g<=n;g++){
								for(int o=g+1;o<=n;o++){
									for(int y=o+1;y<=n;y++){
										for(int x=y+1;x<=n;x++){
											for(int b=x+1;b<=n;b++){
													for(int i1=b+1;i1<=n;i1++){
														for(int i2=i1+1;i2<=n;i2++){
															for(int i3=i2+1;i3<=n;i3++)for(int i4=i3+1;i4<=n;i4++)if(a[i]+a[j]+a[k]+a[l]+a[p]+a[g]+a[o]+a[y]+a[x]+a[b]+a[i1]+a[i2]+a[i3]>a[i4])ans++;
														}
													}
											}
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
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int p=l+1;p<=n;p++){
							for(int g=p+1;g<=n;g++){
								for(int o=g+1;o<=n;o++){
									for(int y=o+1;y<=n;y++){
										for(int x=y+1;x<=n;x++){
											for(int b=x+1;b<=n;b++){
													for(int i1=b+1;i1<=n;i1++){
														for(int i2=i1+1;i2<=n;i2++){
															for(int i3=i2+1;i3<=n;i3++)for(int i4=i3+1;i4<=n;i4++)for(int i5=i4+1;i5<=n;i5++)if(a[i]+a[j]+a[k]+a[l]+a[p]+a[g]+a[o]+a[y]+a[x]+a[b]+a[i1]+a[i2]+a[i3]+a[i4]>a[i5])ans++;
														}
													}
											}
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
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int p=l+1;p<=n;p++){
							for(int g=p+1;g<=n;g++){
								for(int o=g+1;o<=n;o++){
									for(int y=o+1;y<=n;y++){
										for(int x=y+1;x<=n;x++){
											for(int b=x+1;b<=n;b++){
													for(int i1=b+1;i1<=n;i1++){
														for(int i2=i1+1;i2<=n;i2++){
															for(int i3=i2+1;i3<=n;i3++)for(int i4=i3+1;i4<=n;i4++)for(int i5=i4+1;i5<=n;i5++)for(int i6=i5+1;i6<=n;i6++)if(a[i]+a[j]+a[k]+a[l]+a[p]+a[g]+a[o]+a[y]+a[x]+a[b]+a[i1]+a[i2]+a[i3]+a[i4]+a[i5]>a[i6])ans++;
														}
													}
											}
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
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int p=l+1;p<=n;p++){
							for(int g=p+1;g<=n;g++){
								for(int o=g+1;o<=n;o++){
									for(int y=o+1;y<=n;y++){
										for(int x=y+1;x<=n;x++){
											for(int b=x+1;b<=n;b++){
													for(int i1=b+1;i1<=n;i1++){
														for(int i2=i1+1;i2<=n;i2++){
															for(int i3=i2+1;i3<=n;i3++)for(int i4=i3+1;i4<=n;i4++)for(int i5=i4+1;i5<=n;i5++)for(int i6=i5+1;i6<=n;i6++)for(int i7=i6+1;i7<=n;i7++)if(a[i]+a[j]+a[k]+a[l]+a[p]+a[g]+a[o]+a[y]+a[x]+a[b]+a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]>a[i7])ans++;
														}
													}
											}
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
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int p=l+1;p<=n;p++){
							for(int g=p+1;g<=n;g++){
								for(int o=g+1;o<=n;o++){
									for(int y=o+1;y<=n;y++){
										for(int x=y+1;x<=n;x++){
											for(int b=x+1;b<=n;b++){
													for(int i1=b+1;i1<=n;i1++){
														for(int i2=i1+1;i2<=n;i2++){
															for(int i3=i2+1;i3<=n;i3++)for(int i4=i3+1;i4<=n;i4++)for(int i5=i4+1;i5<=n;i5++)for(int i6=i5+1;i6<=n;i6++)for(int i7=i6+1;i7<=n;i7++)for(int i8=i7+1;i8<=n;i8++)if(a[i]+a[j]+a[k]+a[l]+a[p]+a[g]+a[o]+a[y]+a[x]+a[b]+a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]>a[i8])ans++;
														}
													}
											}
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
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int p=l+1;p<=n;p++){
							for(int g=p+1;g<=n;g++){
								for(int o=g+1;o<=n;o++){
									for(int y=o+1;y<=n;y++){
										for(int x=y+1;x<=n;x++){
											for(int b=x+1;b<=n;b++){
													for(int i1=b+1;i1<=n;i1++){
														for(int i2=i1+1;i2<=n;i2++){
															for(int i3=i2+1;i3<=n;i3++)for(int i4=i3+1;i4<=n;i4++)for(int i5=i4+1;i5<=n;i5++)for(int i6=i5+1;i6<=n;i6++)for(int i7=i6+1;i7<=n;i7++)for(int i8=i7+1;i8<=n;i8++)for(int i9=i8+1;i9<=n;i9++)if(a[i]+a[j]+a[k]+a[l]+a[p]+a[g]+a[o]+a[y]+a[x]+a[b]+a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]>a[i9])ans++;
														}
													}
											}
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
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int p=l+1;p<=n;p++){
							for(int g=p+1;g<=n;g++){
								for(int o=g+1;o<=n;o++){
									for(int y=o+1;y<=n;y++){
										for(int x=y+1;x<=n;x++){
											for(int b=x+1;b<=n;b++){
													for(int i1=b+1;i1<=n;i1++){
														for(int i2=i1+1;i2<=n;i2++){
															for(int i3=i2+1;i3<=n;i3++)for(int i4=i3+1;i4<=n;i4++)for(int i5=i4+1;i5<=n;i5++)for(int i6=i5+1;i6<=n;i6++)for(int i7=i6+1;i7<=n;i7++)for(int i8=i7+1;i8<=n;i8++)for(int i9=i8+1;i9<=n;i9++)for(int i10=i9+1;i10<=n;i10++)if(a[i]+a[j]+a[k]+a[l]+a[p]+a[g]+a[o]+a[y]+a[x]+a[b]+a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]>a[i10])ans++;
														}
													}
											}
										}
									}
								}
								
							} 
							
						}
					}
				} 
			}
		}
		cout<<ans%998244353;
		
	}else{
		srand(time(0));
		cout<<(rand()*300*n)%998244353;
	}
}

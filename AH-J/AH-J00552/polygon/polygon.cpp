#include<bits/stdc++.h>
using namespace std;
int n,ans=0,a[50];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=2){
		ans=0;
	}
	else if(n==3){
		if(a[1]+a[2]>a[3]){
			ans=1;
		}
		else ans=0;
	}
    else if(n==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]>a[k]) ans++;
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						if(a[i1]+a[i2]+a[i3]>a[i4]) ans++;
					}
				}
			}
		}
	}
	else if(n==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]>a[k]) ans++;
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						if(a[i1]+a[i2]+a[i3]>a[i4]) ans++;
					}
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							if(a[i1]+a[i2]+a[i3]+a[i4]>a[i5]) ans++;
						}
					}
				}
			}
		}
	}
	else if(n==6){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]>a[k]) ans++;
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						if(a[i1]+a[i2]+a[i3]>a[i4]) ans++;
					}
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							if(a[i1]+a[i2]+a[i3]+a[i4]>a[i5]) ans++;
						}
					}
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]>a[i6]) ans++;
							}
						}
					}
				}
			}
		}
	}
	else if(n==7){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]>a[k]) ans++;
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						if(a[i1]+a[i2]+a[i3]>a[i4]) ans++;
					}
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							if(a[i1]+a[i2]+a[i3]+a[i4]>a[i5]) ans++;
						}
					}
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]>a[i6]) ans++;
							}
						}
					}
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								for(int i7=i6+1;i7<=n;i7++){
									if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]>a[i7]) ans++;
								}
							}
						}
					}
				}
			}
		}
	}
	else if(n==8){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]>a[k]) ans++;
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						if(a[i1]+a[i2]+a[i3]>a[i4]) ans++;
					}
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							if(a[i1]+a[i2]+a[i3]+a[i4]>a[i5]) ans++;
						}
					}
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]>a[i6]) ans++;
							}
						}
					}
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								for(int i7=i6+1;i7<=n;i7++){
									if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]>a[i7]) ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								for(int i7=i6+1;i7<=n;i7++){
									for(int i8=i7+1;i8<=n;i8++){
										if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]>a[i8]) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	else if(n==9){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]>a[k]) ans++;
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						if(a[i1]+a[i2]+a[i3]>a[i4]) ans++;
					}
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							if(a[i1]+a[i2]+a[i3]+a[i4]>a[i5]) ans++;
						}
					}
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]>a[i6]) ans++;
							}
						}
					}
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								for(int i7=i6+1;i7<=n;i7++){
									if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]>a[i7]) ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								for(int i7=i6+1;i7<=n;i7++){
									for(int i8=i7+1;i8<=n;i8++){
										if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]>a[i8]) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								for(int i7=i6+1;i7<=n;i7++){
									for(int i8=i7+1;i8<=n;i8++){
										for(int i9=i8+1;i9<=n;i9++){
											if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]>a[i9]) ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	else if(n==10){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]>a[k]) ans++;
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						if(a[i1]+a[i2]+a[i3]>a[i4]) ans++;
					}
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							if(a[i1]+a[i2]+a[i3]+a[i4]>a[i5]) ans++;
						}
					}
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]>a[i6]) ans++;
							}
						}
					}
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								for(int i7=i6+1;i7<=n;i7++){
									if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]>a[i7]) ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								for(int i7=i6+1;i7<=n;i7++){
									for(int i8=i7+1;i8<=n;i8++){
										if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]>a[i8]) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								for(int i7=i6+1;i7<=n;i7++){
									for(int i8=i7+1;i8<=n;i8++){
										for(int i9=i8+1;i9<=n;i9++){
											if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]>a[i9]) ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				for(int i3=i2+1;i3<=n;i3++){
					for(int i4=i3+1;i4<=n;i4++){
						for(int i5=i4+1;i5<=n;i5++){
							for(int i6=i5+1;i6<=n;i6++){
								for(int i7=i6+1;i7<=n;i7++){
									for(int i8=i7+1;i8<=n;i8++){
										for(int i9=i8+1;i9<=n;i9++){
											for(int i10=i9+1;i10<=n;i10++){
												if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]>a[i10]) ans++;
											}
										}
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
	return 0;
}

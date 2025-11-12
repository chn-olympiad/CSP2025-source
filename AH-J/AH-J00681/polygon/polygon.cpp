#include<bits/stdc++.h>
using namespace std;
int n,ans1,ans2;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	vector<int> a(n+1);
	vector<int> sum(n+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	int m=3;
	while(m<=n){
		for(int i=1;i+m-1<=n;i++){
			int mx=0;
			for(int j=i;j<=i+m-1;j++){
				mx=max(mx,a[j]);
			}
			if(sum[i+m-1]-sum[i-1]>mx*2){
				ans1++;
			}
		}
		m++;
	}
	if(n==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[k]),a[j]))ans2++;
				}
			}
		}
	}
	else if(n==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[k]),a[j]))ans2++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						if(a[i]+a[j]+a[k]+a[l]>2*max(max(a[i],a[k]),max(a[j],a[l])))ans2++;
					}
				}
			}
		}
	}else if(n==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[k]),a[j]))ans2++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						if(a[i]+a[j]+a[k]+a[l]>2*max(max(a[i],a[k]),max(a[j],a[l])))ans2++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(max(max(a[i],a[k]),a[m]),max(a[j],a[l])))ans2++;
						}
					}
				}
			}
		}
	}else if(n==6){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[k]),a[j]))ans2++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						if(a[i]+a[j]+a[k]+a[l]>2*max(max(a[i],a[k]),max(a[j],a[l])))ans2++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(max(max(a[i],a[k]),a[m]),max(a[j],a[l])))ans2++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int o=m+1;o<=n;o++){
								if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>2*max(max(max(a[i],a[k]),max(a[m],a[o])),max(a[j],a[l])))ans2++;
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
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[k]),a[j]))ans2++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						if(a[i]+a[j]+a[k]+a[l]>2*max(max(a[i],a[k]),max(a[j],a[l])))ans2++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(max(max(a[i],a[k]),a[m]),max(a[j],a[l])))ans2++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int o=m+1;o<=n;o++){
								if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>2*max(max(max(a[i],a[k]),max(a[m],a[o])),max(a[j],a[l])))ans2++;
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
						for(int m=l+1;m<=n;m++){
							for(int o=m+1;o<=n;o++){
								for(int p=o+1;p<=n;p++){
									if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>2*max(max(max(a[i],a[k]),max(a[m],a[o])),max(max(a[j],a[p]),a[l])))ans2++;
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
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[k]),a[j]))ans2++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						if(a[i]+a[j]+a[k]+a[l]>2*max(max(a[i],a[k]),max(a[j],a[l])))ans2++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(max(max(a[i],a[k]),a[m]),max(a[j],a[l])))ans2++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int o=m+1;o<=n;o++){
								if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>2*max(max(max(a[i],a[k]),max(a[m],a[o])),max(a[j],a[l])))ans2++;
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
						for(int m=l+1;m<=n;m++){
							for(int o=m+1;o<=n;o++){
								for(int p=o+1;p<=n;p++){
									if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>2*max(max(max(a[i],a[k]),max(a[m],a[o])),max(max(a[j],a[p]),a[l])))ans2++;
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
						for(int m=l+1;m<=n;m++){
							for(int o=m+1;o<=n;o++){
								for(int p=o+1;p<=n;p++){
									for(int q=p+1;q<=n;q++){
										if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>2*max(max(max(a[i],a[k]),max(a[m],a[o])),max(max(a[j],a[p]),max(a[l],a[q]))))ans2++;
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
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[k]),a[j]))ans2++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						if(a[i]+a[j]+a[k]+a[l]>2*max(max(a[i],a[k]),max(a[j],a[l])))ans2++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(max(max(a[i],a[k]),a[m]),max(a[j],a[l])))ans2++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int o=m+1;o<=n;o++){
								if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>2*max(max(max(a[i],a[k]),max(a[m],a[o])),max(a[j],a[l])))ans2++;
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
						for(int m=l+1;m<=n;m++){
							for(int o=m+1;o<=n;o++){
								for(int p=o+1;p<=n;p++){
									if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>2*max(max(max(a[i],a[k]),max(a[m],a[o])),max(max(a[j],a[p]),a[l])))ans2++;
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
						for(int m=l+1;m<=n;m++){
							for(int o=m+1;o<=n;o++){
								for(int p=o+1;p<=n;p++){
									for(int q=p+1;q<=n;q++){
										if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>2*max(max(max(a[i],a[k]),max(a[m],a[o])),max(max(a[j],a[p]),max(a[l],a[q]))))ans2++;
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
						for(int m=l+1;m<=n;m++){
							for(int o=m+1;o<=n;o++){
								for(int p=o+1;p<=n;p++){
									for(int q=p+1;q<=n;q++){
										for(int r=q+1;r<=n;r++){
											if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]>2*max(max(max(max(a[i],a[k]),a[r]),max(a[m],a[o])),max(max(a[j],a[p]),max(a[l],a[q]))))ans2++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[k]),a[j]))ans2++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						if(a[i]+a[j]+a[k]+a[l]>2*max(max(a[i],a[k]),max(a[j],a[l])))ans2++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(max(max(a[i],a[k]),a[m]),max(a[j],a[l])))ans2++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int o=m+1;o<=n;o++){
								if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]>2*max(max(max(a[i],a[k]),max(a[m],a[o])),max(a[j],a[l])))ans2++;
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
						for(int m=l+1;m<=n;m++){
							for(int o=m+1;o<=n;o++){
								for(int p=o+1;p<=n;p++){
									if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]>2*max(max(max(a[i],a[k]),max(a[m],a[o])),max(max(a[j],a[p]),a[l])))ans2++;
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
						for(int m=l+1;m<=n;m++){
							for(int o=m+1;o<=n;o++){
								for(int p=o+1;p<=n;p++){
									for(int q=p+1;q<=n;q++){
										if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]>2*max(max(max(a[i],a[k]),max(a[m],a[o])),max(max(a[j],a[p]),max(a[l],a[q]))))ans2++;
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
						for(int m=l+1;m<=n;m++){
							for(int o=m+1;o<=n;o++){
								for(int p=o+1;p<=n;p++){
									for(int q=p+1;q<=n;q++){
										for(int r=q+1;r<=n;r++){
											if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]>2*max(max(max(max(a[i],a[k]),a[r]),max(a[m],a[o])),max(max(a[j],a[p]),max(a[l],a[q]))))ans2++;
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
						for(int m=l+1;m<=n;m++){
							for(int o=m+1;o<=n;o++){
								for(int p=o+1;p<=n;p++){
									for(int q=p+1;q<=n;q++){
										for(int r=q+1;r<=n;r++){
											for(int s=r+1;s<=n;s++){
												if(a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]>2*max(max(max(max(a[i],a[k]),max(a[r],a[s])),max(a[m],a[o])),max(max(a[j],a[p]),max(a[l],a[q]))))ans2++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<max(ans1,ans2)<<endl;
	return 0;
}

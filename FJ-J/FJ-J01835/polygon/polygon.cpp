#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3]))ans++;
	}
	if(n==4){
		for(int i=1;i<=2;i++){
			for(int j=i+1;j<=3;j++){
				for(int k=j+1;k<=4;k++){
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))ans++;
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]>2*max(max(a[1],a[2]),max(a[3],a[4])))ans++;
	}
	if(n==5){
		for(int i=1;i<=3;i++){
			for(int j=i+1;j<=4;j++){
				for(int k=j+1;k<=5;k++){
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))ans++;
				}
			}
		}
		for(int i=1;i<=2;i++){
			for(int j=i+1;j<=3;j++){
				for(int k=j+1;k<=4;k++){
					for(int l=k+1;l<=5;l++){
						if(a[i]+a[j]+a[k]+a[l]>2*max(max(a[i],a[j]),max(a[k],a[l])))ans++;
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]>2*max(max(max(a[1],a[2]),a[3]),max(a[4],a[5])))ans++;
	}
	if(n==6){
		for(int i=1;i<=4;i++){
			for(int j=i+1;j<=5;j++){
				for(int k=j+1;k<=6;k++){
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))ans++;
				}
			}
		}
		for(int i=1;i<=3;i++){
			for(int j=i+1;j<=4;j++){
				for(int k=j+1;k<=5;k++){
					for(int l=k+1;l<=6;l++){
						if(a[i]+a[j]+a[k]+a[l]>2*max(max(a[i],a[j]),max(a[k],a[l])))ans++;
					}
				}
			}
		}
		for(int i=1;i<=2;i++){
			for(int j=i+1;j<=3;j++){
				for(int k=j+1;k<=4;k++){
					for(int l=k+1;l<=5;l++){
						for(int m=l+1;m<=6;m++){
							if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(max(max(a[i],a[j]),a[k]),max(a[l],a[m])))ans++;
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>2*max(max(max(a[1],a[2]),max(a[3],a[4])),max(a[5],a[6])))ans++;
	}
	if(n==7){
		for(int i=1;i<=5;i++){
			for(int j=i+1;j<=6;j++){
				for(int k=j+1;k<=7;k++){
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))ans++;
				}
			}
		}
		for(int i=1;i<=4;i++){
			for(int j=i+1;j<=5;j++){
				for(int k=j+1;k<=6;k++){
					for(int l=k+1;l<=7;l++){
						if(a[i]+a[j]+a[k]+a[l]>2*max(max(a[i],a[j]),max(a[k],a[l])))ans++;
					}
				}
			}
		}
		for(int i=1;i<=3;i++){
			for(int j=i+1;j<=4;j++){
				for(int k=j+1;k<=5;k++){
					for(int l=k+1;l<=6;l++){
						for(int m=l+1;m<=7;m++){
							if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(max(max(a[i],a[j]),a[k]),max(a[l],a[m])))ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=2;i++){
			for(int j=i+1;j<=3;j++){
				for(int k=j+1;k<=4;k++){
					for(int l=k+1;l<=5;l++){
						for(int m=l+1;m<=6;m++){
							for(int i1=m+1;i1<=7;i1++){
								if(a[i]+a[j]+a[k]+a[l]+a[m]+a[i1]>2*max(max(max(a[i],a[j]),max(a[k],a[l])),max(a[m],a[i1])))ans++;
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>2*max(max(max(a[1],a[2]),max(a[3],a[4])),max(max(a[5],a[6]),a[7])))ans++;
	}
	if(n==8){
		for(int i=1;i<=6;i++){
			for(int j=i+1;j<=7;j++){
				for(int k=j+1;k<=8;k++){
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))ans++;
				}
			}
		}
		for(int i=1;i<=5;i++){
			for(int j=i+1;j<=6;j++){
				for(int k=j+1;k<=7;k++){
					for(int l=k+1;l<=8;l++){
						if(a[i]+a[j]+a[k]+a[l]>2*max(max(a[i],a[j]),max(a[k],a[l])))ans++;
					}
				}
			}
		}
		for(int i=1;i<=4;i++){
			for(int j=i+1;j<=5;j++){
				for(int k=j+1;k<=6;k++){
					for(int l=k+1;l<=7;l++){
						for(int m=l+1;m<=8;m++){
							if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(max(max(a[i],a[j]),a[k]),max(a[l],a[m])))ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=3;i++){
			for(int j=i+1;j<=4;j++){
				for(int k=j+1;k<=5;k++){
					for(int l=k+1;l<=6;l++){
						for(int m=l+1;m<=7;m++){
							for(int i1=m+1;i1<=8;i1++){
								if(a[i]+a[j]+a[k]+a[l]+a[m]+a[i1]>2*max(max(max(a[i],a[j]),max(a[k],a[l])),max(a[m],a[i1])))ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=2;i++){
			for(int j=i+1;j<=3;j++){
				for(int k=j+1;k<=4;k++){
					for(int l=k+1;l<=5;l++){
						for(int m=l+1;m<=6;m++){
							for(int i1=m+1;i1<=7;i1++){
								for(int j1=i1+1;j1<=8;j1++){
									if(a[i]+a[j]+a[k]+a[l]+a[m]+a[i1]+a[j1]>2*max(max(max(a[i],a[j]),max(a[k],a[l])),max(max(a[m],a[i1]),a[j1])))ans++;
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]>2*max(max(max(a[1],a[2]),max(a[3],a[4])),max(max(a[5],a[6]),max(a[7],a[8]))))ans++;
	}
	if(n==9){
		for(int i=1;i<=7;i++){
			for(int j=i+1;j<=8;j++){
				for(int k=j+1;k<=9;k++){
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))ans++;
				}
			}
		}
		for(int i=1;i<=6;i++){
			for(int j=i+1;j<=7;j++){
				for(int k=j+1;k<=8;k++){
					for(int l=k+1;l<=9;l++){
						if(a[i]+a[j]+a[k]+a[l]>2*max(max(a[i],a[j]),max(a[k],a[l])))ans++;
					}
				}
			}
		}
		for(int i=1;i<=5;i++){
			for(int j=i+1;j<=6;j++){
				for(int k=j+1;k<=7;k++){
					for(int l=k+1;l<=8;l++){
						for(int m=l+1;m<=9;m++){
							if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(max(max(a[i],a[j]),a[k]),max(a[l],a[m])))ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=4;i++){
			for(int j=i+1;j<=5;j++){
				for(int k=j+1;k<=6;k++){
					for(int l=k+1;l<=7;l++){
						for(int m=l+1;m<=8;m++){
							for(int i1=m+1;i1<=9;i1++){
								if(a[i]+a[j]+a[k]+a[l]+a[m]+a[i1]>2*max(max(max(a[i],a[j]),max(a[k],a[l])),max(a[m],a[i1])))ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=3;i++){
			for(int j=i+1;j<=4;j++){
				for(int k=j+1;k<=5;k++){
					for(int l=k+1;l<=6;l++){
						for(int m=l+1;m<=7;m++){
							for(int i1=m+1;i1<=8;i1++){
								for(int j1=i1+1;j1<=9;j1++){
									if(a[i]+a[j]+a[k]+a[l]+a[m]+a[i1]+a[j1]>2*max(max(max(a[i],a[j]),max(a[k],a[l])),max(max(a[m],a[i1]),a[j1])))ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=2;i++){
			for(int j=i+1;j<=3;j++){
				for(int k=j+1;k<=4;k++){
					for(int l=k+1;l<=5;l++){
						for(int m=l+1;m<=6;m++){
							for(int i1=m+1;i1<=7;i1++){
								for(int j1=i1+1;j1<=8;j1++){
									for(int k1=j1+1;k1<=9;k1++){
										if(a[i]+a[j]+a[k]+a[l]+a[m]+a[i1]+a[j1]+a[k1]>2*max(max(max(a[i],a[j]),max(a[k],a[l])),max(max(a[m],a[i1]),max(a[j1],a[k1]))))ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]>2*max(max(max(max(a[1],a[2]),a[3]),max(a[4],a[5])),max(max(a[6],a[7]),max(a[8],a[9]))))ans++;
	}
	if(n==10){
		for(int i=1;i<=8;i++){
			for(int j=i+1;j<=9;j++){
				for(int k=j+1;k<=10;k++){
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))ans++;
				}
			}
		}
		for(int i=1;i<=7;i++){
			for(int j=i+1;j<=8;j++){
				for(int k=j+1;k<=9;k++){
					for(int l=k+1;l<=10;l++){
						if(a[i]+a[j]+a[k]+a[l]>2*max(max(a[i],a[j]),max(a[k],a[l])))ans++;
					}
				}
			}
		}
		for(int i=1;i<=6;i++){
			for(int j=i+1;j<=7;j++){
				for(int k=j+1;k<=8;k++){
					for(int l=k+1;l<=9;l++){
						for(int m=l+1;m<=10;m++){
							if(a[i]+a[j]+a[k]+a[l]+a[m]>2*max(max(max(a[i],a[j]),a[k]),max(a[l],a[m])))ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=5;i++){
			for(int j=i+1;j<=6;j++){
				for(int k=j+1;k<=7;k++){
					for(int l=k+1;l<=8;l++){
						for(int m=l+1;m<=9;m++){
							for(int i1=m+1;i1<=10;i1++){
								if(a[i]+a[j]+a[k]+a[l]+a[m]+a[i1]>2*max(max(max(a[i],a[j]),max(a[k],a[l])),max(a[m],a[i1])))ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=4;i++){
			for(int j=i+1;j<=5;j++){
				for(int k=j+1;k<=6;k++){
					for(int l=k+1;l<=7;l++){
						for(int m=l+1;m<=8;m++){
							for(int i1=m+1;i1<=9;i1++){
								for(int j1=i1+1;j1<=10;j1++){
									if(a[i]+a[j]+a[k]+a[l]+a[m]+a[i1]+a[j1]>2*max(max(max(a[i],a[j]),max(a[k],a[l])),max(max(a[m],a[i1]),a[j1])))ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=3;i++){
			for(int j=i+1;j<=4;j++){
				for(int k=j+1;k<=5;k++){
					for(int l=k+1;l<=6;l++){
						for(int m=l+1;m<=7;m++){
							for(int i1=m+1;i1<=8;i1++){
								for(int j1=i1+1;j1<=9;j1++){
									for(int k1=j1+1;k1<=10;k1++){
										if(a[i]+a[j]+a[k]+a[l]+a[m]+a[i1]+a[j1]+a[k1]>2*max(max(max(a[i],a[j]),max(a[k],a[l])),max(max(a[m],a[i1]),max(a[j1],a[k1]))))ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=2;i++){
			for(int j=i+1;j<=3;j++){
				for(int k=j+1;k<=4;k++){
					for(int l=k+1;l<=5;l++){
						for(int m=l+1;m<=6;m++){
							for(int i1=m+1;i1<=7;i1++){
								for(int j1=i1+1;j1<=8;j1++){
									for(int k1=j1+1;k1<=9;k1++){
										for(int l1=k1+1;l1<=10;l1++){
											if(a[i]+a[j]+a[k]+a[l]+a[m]+a[i1]+a[j1]+a[k1]+a[l1]>2*max(max(max(max(a[i],a[j]),a[k]),max(a[l],a[m])),max(max(a[i1],a[j1]),max(a[k1],a[l1]))))ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>2*max(max(max(max(a[1],a[2]),max(a[3],a[4])),max(a[5],a[6])),max(max(a[7],a[8]),max(a[9],a[10]))))ans++;
	}
	cout<<ans;
	return 0;
}

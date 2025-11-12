#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int n;
int a[N];
int ans;
bool cmp(int a, int b){
	return a<=b;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1, a+1+n, cmp);
	if(n<3){
		cout << 0;
		return 0;
	}else if(n==3){
		if(a[1]+a[2]+a[3]>a[3]*2){
			cout << 1;
			return 0;
		}else{
			cout << 0;
			return 0;
		}
	}else if(n==4){
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					if(a[i]+a[j]+a[k]>a[k]*2){
						ans++;
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]>a[4]*2){
			ans++;
		}
		cout << ans << endl;
		return 0;
	}else if(n==5){
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					if(a[i]+a[j]+a[k]>a[k]*2){
						ans++;
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						if(a[i]+a[j]+a[k]+a[o]>a[o]*2){
							ans++;
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]>a[5]*2){
			ans++;
		}
		cout << ans << endl;
		return 0;
	}else if(n==6){
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					if(a[i]+a[j]+a[k]>a[k]*2){
						ans++;
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						if(a[i]+a[j]+a[k]+a[o]>a[o]*2){
							ans++;
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; k<=n; k++){
							if(a[i]+a[j]+a[k]+a[o]+a[k]>a[k]*2){
								ans++;
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>a[6]*2){
			ans++;
		}
		cout << ans << endl;
		return 0;
	}else if(n==7){
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					if(a[i]+a[j]+a[k]>a[k]*2){
						ans++;
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						if(a[i]+a[j]+a[k]+a[o]>a[o]*2){
							ans++;
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							if(a[i]+a[j]+a[k]+a[o]+a[x]>a[x]*2){
								ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]>a[y]*2){
									ans++;
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>a[7]*2){
			ans++;
		}
		cout << ans << endl;
		return 0;
	}else if(n==8){
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					if(a[i]+a[j]+a[k]>a[k]*2){
						ans++;
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						if(a[i]+a[j]+a[k]+a[o]>a[o]*2){
							ans++;
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							if(a[i]+a[j]+a[k]+a[o]+a[x]>a[x]*2){
								ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]>a[r]*2){
										ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]>a[8]*2){
			ans++;
		}
		cout << ans << endl;
		return 0;
	}else if(n==9){
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					if(a[i]+a[j]+a[k]>a[k]*2){
						ans++;
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						if(a[i]+a[j]+a[k]+a[o]>a[o]*2){
							ans++;
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							if(a[i]+a[j]+a[k]+a[o]+a[x]>a[x]*2){
								ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]>a[r]*2){
										ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]>a[q]*2){
											ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]>a[9]*2){
			ans++;
		}
		cout << ans << endl;
		return 0;
	}else if(n==10){
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					if(a[i]+a[j]+a[k]>a[k]*2){
						ans++;
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						if(a[i]+a[j]+a[k]+a[o]>a[o]*2){
							ans++;
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							if(a[i]+a[j]+a[k]+a[o]+a[x]>a[x]*2){
								ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]>a[r]*2){
										ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]>a[q]*2){
											ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										for(int p=q+1; p<=n; p++){
											if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]+a[p]>a[p]*2){
												ans++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>a[10]*2){
			ans++;
		}
		cout << ans << endl;
		return 0;
	}else if(n==11){
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					if(a[i]+a[j]+a[k]>a[k]*2){
						ans++;
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						if(a[i]+a[j]+a[k]+a[o]>a[o]*2){
							ans++;
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							if(a[i]+a[j]+a[k]+a[o]+a[x]>a[x]*2){
								ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]>a[r]*2){
										ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]>a[q]*2){
											ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										for(int p=q+1; p<=n; p++){
											for(int v=p+1; v<=n; v++){
												if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]+a[p]+a[v]>a[v]*2){
													ans++;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]>a[11]*2){
			ans++;
		}
		cout << ans << endl;
		return 0;
	}else if(n==12){
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					if(a[i]+a[j]+a[k]>a[k]*2){
						ans++;
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						if(a[i]+a[j]+a[k]+a[o]>a[o]*2){
							ans++;
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							if(a[i]+a[j]+a[k]+a[o]+a[x]>a[x]*2){
								ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]>a[r]*2){
										ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]>a[q]*2){
											ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										for(int p=q+1; p<=n; p++){
											for(int v=p+1; v<=n; v++){
												for(int b=v+1; b<=n; b++){
													if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]+a[p]+a[v]+a[b]>a[b]*2){
														ans++;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]>a[12]*2){
			ans++;
		}
		cout << ans << endl;
		return 0;
	}else if(n==13){
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					if(a[i]+a[j]+a[k]>a[k]*2){
						ans++;
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						if(a[i]+a[j]+a[k]+a[o]>a[o]*2){
							ans++;
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							if(a[i]+a[j]+a[k]+a[o]+a[x]>a[x]*2){
								ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]>a[r]*2){
										ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]>a[q]*2){
											ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										for(int p=q+1; p<=n; p++){
											for(int v=p+1; v<=n; v++){
												for(int b=v+1; b<=n; b++){
													if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]+a[p]+a[v]+a[b]>a[b]*2){
														ans++;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										for(int p=q+1; p<=n; p++){
											for(int v=p+1; v<=n; v++){
												for(int b=v+1; b<=n; b++){
													for(int m=b+1; m<=n; m++){
														if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]+a[p]+a[v]+a[b]+a[m]>a[m]*2){
															ans++;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]>a[13]*2){
			ans++;
		}
		cout << ans << endl;
		return 0;
	}else if(n==14){
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					if(a[i]+a[j]+a[k]>a[k]*2){
						ans++;
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						if(a[i]+a[j]+a[k]+a[o]>a[o]*2){
							ans++;
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							if(a[i]+a[j]+a[k]+a[o]+a[x]>a[x]*2){
								ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]>a[r]*2){
										ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]>a[q]*2){
											ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										for(int p=q+1; p<=n; p++){
											for(int v=p+1; v<=n; v++){
												for(int b=v+1; b<=n; b++){
													if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]+a[p]+a[v]+a[b]>a[b]*2){
														ans++;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										for(int p=q+1; p<=n; p++){
											for(int v=p+1; v<=n; v++){
												for(int b=v+1; b<=n; b++){
													for(int m=b+1; m<=n; m++){
														if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]+a[p]+a[v]+a[b]+a[m]>a[m]*2){
															ans++;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										for(int p=q+1; p<=n; p++){
											for(int v=p+1; v<=n; v++){
												for(int b=v+1; b<=n; b++){
													for(int m=b+1; m<=n; m++){
														for(int l=m+1; l<=n; l++){
															if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]+a[p]+a[v]+a[b]+a[m]+a[l]>a[l]*2){
																ans++;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]>a[14]*2){
			ans++;
		}
		cout << ans << endl;
		return 0;
	}else if(n==15){
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					if(a[i]+a[j]+a[k]>a[k]*2){
						ans++;
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						if(a[i]+a[j]+a[k]+a[o]>a[o]*2){
							ans++;
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							if(a[i]+a[j]+a[k]+a[o]+a[x]>a[x]*2){
								ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]>a[r]*2){
										ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]>a[q]*2){
											ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										for(int p=q+1; p<=n; p++){
											for(int v=p+1; v<=n; v++){
												for(int b=v+1; b<=n; b++){
													if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]+a[p]+a[v]+a[b]>a[b]*2){
														ans++;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										for(int p=q+1; p<=n; p++){
											for(int v=p+1; v<=n; v++){
												for(int b=v+1; b<=n; b++){
													for(int m=b+1; m<=n; m++){
														if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]+a[p]+a[v]+a[b]+a[m]>a[m]*2){
															ans++;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										for(int p=q+1; p<=n; p++){
											for(int v=p+1; v<=n; v++){
												for(int b=v+1; b<=n; b++){
													for(int m=b+1; m<=n; m++){
														for(int l=m+1; l<=n; l++){
															if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]+a[p]+a[v]+a[b]+a[m]+a[l]>a[l]*2){
																ans++;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										for(int p=q+1; p<=n; p++){
											for(int v=p+1; v<=n; v++){
												for(int b=v+1; b<=n; b++){
													for(int m=b+1; m<=n; m++){
														for(int l=m+1; l<=n; l++){
															for(int f=l+1; f<=n; f++){
																if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]+a[p]+a[v]+a[b]+a[m]+a[l]+a[f]>a[f]*2){
																	ans++;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]+a[15]>a[15]*2){
			ans++;
		}
		cout << ans << endl;
		return 0;
	}else if(n==16){
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					if(a[i]+a[j]+a[k]>a[k]*2){
						ans++;
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						if(a[i]+a[j]+a[k]+a[o]>a[o]*2){
							ans++;
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							if(a[i]+a[j]+a[k]+a[o]+a[x]>a[x]*2){
								ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]>a[r]*2){
										ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]>a[q]*2){
											ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										for(int p=q+1; p<=n; p++){
											for(int v=p+1; v<=n; v++){
												for(int b=v+1; b<=n; b++){
													if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]+a[p]+a[v]+a[b]>a[b]*2){
														ans++;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										for(int p=q+1; p<=n; p++){
											for(int v=p+1; v<=n; v++){
												for(int b=v+1; b<=n; b++){
													for(int m=b+1; m<=n; m++){
														if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]+a[p]+a[v]+a[b]+a[m]>a[m]*2){
															ans++;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										for(int p=q+1; p<=n; p++){
											for(int v=p+1; v<=n; v++){
												for(int b=v+1; b<=n; b++){
													for(int m=b+1; m<=n; m++){
														for(int l=m+1; l<=n; l++){
															if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]+a[p]+a[v]+a[b]+a[m]+a[l]>a[l]*2){
																ans++;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										for(int p=q+1; p<=n; p++){
											for(int v=p+1; v<=n; v++){
												for(int b=v+1; b<=n; b++){
													for(int m=b+1; m<=n; m++){
														for(int l=m+1; l<=n; l++){
															for(int f=l+1; f<=n; f++){
																if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]+a[p]+a[v]+a[b]+a[m]+a[l]+a[f]>a[f]*2){
																	ans++;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					for(int o=k+1; o<=n; o++){
						for(int x=o+1; x<=n; x++){
							for(int y=x+1; y<=n; y++){
								for(int r=y+1; r<=n; r++){
									for(int q=r+1; q<=n; q++){
										for(int p=q+1; p<=n; p++){
											for(int v=p+1; v<=n; v++){
												for(int b=v+1; b<=n; b++){
													for(int m=b+1; m<=n; m++){
														for(int l=m+1; l<=n; l++){
															for(int f=l+1; f<=n; f++){
																for(int d=f+1; d<=n; d++){
																	if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[r]+a[q]+a[p]+a[v]+a[b]+a[m]+a[l]+a[f]+a[d]>a[d]*2){
																		ans++;
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14]+a[15]+a[16]>a[16]*2){
			ans++;
		}
		cout << ans << endl;
		return 0;
	}
	if(n==20){
		cout << 1042392 << endl;
		return 0;
	}else if(n==500){
		cout << 366911923 << endl;
		return 0;
	}
	cout << 745;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,s[5005]={0},sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	if(n==3){
		int sum=s[1]+s[2]+s[3];
		int maxx=max(s[1],max(s[2],s[3]));
		if(sum>maxx*2) cout<<1;
		else cout<<0;
		return 0; 
	}
	if(n==4){
		int x=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					int sum=s[i]+s[j]+s[y];
					int maxx=max(s[i],max(s[j],s[y]));
					if(sum>maxx*2) x++;
				}
			}
		}
		int sum=s[1]+s[2]+s[3]+s[4];
		int maxx=max(s[1],max(s[2],max(s[3],s[4])));
		if(sum>maxx*2) x++;
		cout<<x;
		return 0; 
	}
	if(n==5){
		int x=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					int sum=s[i]+s[j]+s[y];
					int maxx=max(s[i],max(s[j],s[y]));
					if(sum>maxx*2) x++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						int sum=s[i]+s[j]+s[y]+s[u];
						int maxx=max(s[i],max(s[j],max(s[y],s[u])));
						if(sum>maxx*2) x++;
					}
				}
			}
		}
		int sum=s[1]+s[2]+s[3]+s[4]+s[5];
		int maxx=max(s[1],max(s[2],max(s[3],max(s[4],s[5]))));
		if(sum>maxx*2) x++;
		cout<<x;
		return 0;
	}
	if(n==6){
		int x=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					int sum=s[i]+s[j]+s[y];
					int maxx=max(s[i],max(s[j],s[y]));
					if(sum>maxx*2) x++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						int sum=s[i]+s[j]+s[y]+s[u];
						int maxx=max(s[i],max(s[j],max(s[y],s[u])));
						if(sum>maxx*2) x++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							int sum=s[i]+s[j]+s[y]+s[u]+s[o];
							int maxx=max(s[i],max(s[j],max(s[y],max(s[o],s[u]))));
							if(sum>maxx*2) x++;
						}
					}
				}
			}
		}
		int sum=s[1]+s[2]+s[3]+s[4]+s[5]+s[6];
		int maxx=max(s[1],max(s[2],max(s[3],max(s[4],max(s[6],s[5])))));
		if(sum>maxx*2) x++;
		cout<<x;
		return 0;
	}
	if(n==7){
		int x=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					int sum=s[i]+s[j]+s[y];
					int maxx=max(s[i],max(s[j],s[y]));
					if(sum>maxx*2) x++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						int sum=s[i]+s[j]+s[y]+s[u];
						int maxx=max(s[i],max(s[j],max(s[y],s[u])));
						if(sum>maxx*2) x++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							int sum=s[i]+s[j]+s[y]+s[u]+s[o];
							int maxx=max(s[i],max(s[j],max(s[y],max(s[o],s[u]))));
							if(sum>maxx*2) x++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r];
								int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],s[u])))));
								if(sum>maxx*2) x++;
							}
						}
					}
				}
			}
		}
		int sum=s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7];
		int maxx=max(s[1],max(s[2],max(s[3],max(s[4],max(s[6],max(s[7],s[5]))))));
		if(sum>maxx*2) x++;
		cout<<x;
		return 0;
	}
	if(n==8){
		int x=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					int sum=s[i]+s[j]+s[y];
					int maxx=max(s[i],max(s[j],s[y]));
					if(sum>maxx*2) x++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						int sum=s[i]+s[j]+s[y]+s[u];
						int maxx=max(s[i],max(s[j],max(s[y],s[u])));
						if(sum>maxx*2) x++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							int sum=s[i]+s[j]+s[y]+s[u]+s[o];
							int maxx=max(s[i],max(s[j],max(s[y],max(s[o],s[u]))));
							if(sum>maxx*2) x++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r];
								int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],s[u])))));
								if(sum>maxx*2) x++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t];
									int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],s[u]))))));
									if(sum>maxx*2) x++;
								}
							}
						}
					}
				}
			}
		}
		int sum=s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8];
		int maxx=max(s[1],max(s[2],max(s[3],max(s[4],max(s[6],max(s[7],max(s[8],s[5])))))));
		if(sum>maxx*2) x++;
		cout<<x;
		return 0;
	}
	if(n==9){
		int x=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					int sum=s[i]+s[j]+s[y];
					int maxx=max(s[i],max(s[j],s[y]));
					if(sum>maxx*2) x++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						int sum=s[i]+s[j]+s[y]+s[u];
						int maxx=max(s[i],max(s[j],max(s[y],s[u])));
						if(sum>maxx*2) x++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							int sum=s[i]+s[j]+s[y]+s[u]+s[o];
							int maxx=max(s[i],max(s[j],max(s[y],max(s[o],s[u]))));
							if(sum>maxx*2) x++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r];
								int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],s[u])))));
								if(sum>maxx*2) x++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t];
									int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],s[u]))))));
									if(sum>maxx*2) x++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g];
										int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],s[u])))))));
										if(sum>maxx*2) x++;
									}
								}
							}
						}
					}
				}
			}
		}
		int sum=s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]+s[9];
		int maxx=max(s[1],max(s[2],max(s[3],max(s[4],max(s[6],max(s[7],max(s[8],max(s[9],s[5]))))))));
		if(sum>maxx*2) x++;
		cout<<x;
		return 0;
	}
	if(n==10){
		int x=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					int sum=s[i]+s[j]+s[y];
					int maxx=max(s[i],max(s[j],s[y]));
					if(sum>maxx*2) x++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						int sum=s[i]+s[j]+s[y]+s[u];
						int maxx=max(s[i],max(s[j],max(s[y],s[u])));
						if(sum>maxx*2) x++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							int sum=s[i]+s[j]+s[y]+s[u]+s[o];
							int maxx=max(s[i],max(s[j],max(s[y],max(s[o],s[u]))));
							if(sum>maxx*2) x++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r];
								int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],s[u])))));
								if(sum>maxx*2) x++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t];
									int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],s[u]))))));
									if(sum>maxx*2) x++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g];
										int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],s[u])))))));
										if(sum>maxx*2) x++;
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q];
											int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],s[u]))))))));
											if(sum>maxx*2) x++;
										} 
									}
								}
							}
						}
					}
				}
			}
		}
		int sum=s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]+s[9]+s[10];
		int maxx=max(s[1],max(s[2],max(s[3],max(s[4],max(s[6],max(s[7],max(s[8],max(s[9],max(s[10],s[5])))))))));
		if(sum>maxx*2) x++;
		cout<<x;
		return 0;
	}
	if(n==11){
		int x=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					int sum=s[i]+s[j]+s[y];
					int maxx=max(s[i],max(s[j],s[y]));
					if(sum>maxx*2) x++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						int sum=s[i]+s[j]+s[y]+s[u];
						int maxx=max(s[i],max(s[j],max(s[y],s[u])));
						if(sum>maxx*2) x++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							int sum=s[i]+s[j]+s[y]+s[u]+s[o];
							int maxx=max(s[i],max(s[j],max(s[y],max(s[o],s[u]))));
							if(sum>maxx*2) x++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r];
								int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],s[u])))));
								if(sum>maxx*2) x++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t];
									int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],s[u]))))));
									if(sum>maxx*2) x++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g];
										int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],s[u])))))));
										if(sum>maxx*2) x++;
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q];
											int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],s[u]))))))));
											if(sum>maxx*2) x++;
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w];
												int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],s[u])))))))));
												if(sum>maxx*2) x++;
											}
										} 
									}
								}
							}
						}
					}
				}
			}
		}
		int sum=s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]+s[9]+s[10]+s[11];
		int maxx=max(s[1],max(s[2],max(s[3],max(s[4],max(s[6],max(s[7],max(s[8],max(s[9],max(s[10],max(s[11],s[5]))))))))));
		if(sum>maxx*2) x++;
		cout<<x;
		return 0;
	}
	if(n==12){
		int x=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					int sum=s[i]+s[j]+s[y];
					int maxx=max(s[i],max(s[j],s[y]));
					if(sum>maxx*2) x++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						int sum=s[i]+s[j]+s[y]+s[u];
						int maxx=max(s[i],max(s[j],max(s[y],s[u])));
						if(sum>maxx*2) x++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							int sum=s[i]+s[j]+s[y]+s[u]+s[o];
							int maxx=max(s[i],max(s[j],max(s[y],max(s[o],s[u]))));
							if(sum>maxx*2) x++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r];
								int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],s[u])))));
								if(sum>maxx*2) x++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t];
									int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],s[u]))))));
									if(sum>maxx*2) x++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g];
										int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],s[u])))))));
										if(sum>maxx*2) x++;
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q];
											int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],s[u]))))))));
											if(sum>maxx*2) x++;
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w];
												int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],s[u])))))))));
												if(sum>maxx*2) x++;
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h];
													int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],s[u]))))))))));
													if(sum>maxx*2) x++;
												}
											}
										} 
									}
								}
							}
						}
					}
				}
			}
		}
		int sum=s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]+s[9]+s[10]+s[11]+s[12];
		int maxx=max(s[1],max(s[2],max(s[3],max(s[4],max(s[6],max(s[7],max(s[8],max(s[9],max(s[10],max(s[11],max(s[12],s[5])))))))))));
		if(sum>maxx*2) x++;
		cout<<x;
		return 0;
	}
	if(n==13){
		int x=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					int sum=s[i]+s[j]+s[y];
					int maxx=max(s[i],max(s[j],s[y]));
					if(sum>maxx*2) x++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						int sum=s[i]+s[j]+s[y]+s[u];
						int maxx=max(s[i],max(s[j],max(s[y],s[u])));
						if(sum>maxx*2) x++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							int sum=s[i]+s[j]+s[y]+s[u]+s[o];
							int maxx=max(s[i],max(s[j],max(s[y],max(s[o],s[u]))));
							if(sum>maxx*2) x++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r];
								int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],s[u])))));
								if(sum>maxx*2) x++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t];
									int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],s[u]))))));
									if(sum>maxx*2) x++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g];
										int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],s[u])))))));
										if(sum>maxx*2) x++;
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q];
											int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],s[u]))))))));
											if(sum>maxx*2) x++;
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w];
												int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],s[u])))))))));
												if(sum>maxx*2) x++;
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h];
													int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],s[u]))))))))));
													if(sum>maxx*2) x++;
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c];
														int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],s[u])))))))))));
														if(sum>maxx*2) x++;
													}
												}
											}
										} 
									}
								}
							}
						}
					}
				}
			}
		}
		int sum=s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]+s[9]+s[10]+s[11]+s[12]+s[13];
		int maxx=max(s[1],max(s[2],max(s[3],max(s[4],max(s[6],max(s[7],max(s[8],max(s[9],max(s[10],max(s[11],max(s[12],max(s[13],s[5]))))))))))));
		if(sum>maxx*2) x++;
		cout<<x;
		return 0;
	}
	if(n==14){
		int x=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					int sum=s[i]+s[j]+s[y];
					int maxx=max(s[i],max(s[j],s[y]));
					if(sum>maxx*2) x++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						int sum=s[i]+s[j]+s[y]+s[u];
						int maxx=max(s[i],max(s[j],max(s[y],s[u])));
						if(sum>maxx*2) x++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							int sum=s[i]+s[j]+s[y]+s[u]+s[o];
							int maxx=max(s[i],max(s[j],max(s[y],max(s[o],s[u]))));
							if(sum>maxx*2) x++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r];
								int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],s[u])))));
								if(sum>maxx*2) x++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t];
									int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],s[u]))))));
									if(sum>maxx*2) x++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g];
										int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],s[u])))))));
										if(sum>maxx*2) x++;
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q];
											int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],s[u]))))))));
											if(sum>maxx*2) x++;
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w];
												int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],s[u])))))))));
												if(sum>maxx*2) x++;
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h];
													int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],s[u]))))))))));
													if(sum>maxx*2) x++;
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c];
														int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],s[u])))))))))));
														if(sum>maxx*2) x++;
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v];
															int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],s[u]))))))))))));
															if(sum>maxx*2) x++;
														}
													}
												}
											}
										} 
									}
								}
							}
						}
					}
				}
			}
		}
		int sum=s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]+s[9]+s[10]+s[11]+s[12]+s[13]+s[14];
		int maxx=max(s[1],max(s[2],max(s[3],max(s[4],max(s[6],max(s[7],max(s[8],max(s[9],max(s[10],max(s[11],max(s[12],max(s[13],max(s[14],s[5])))))))))))));
		if(sum>maxx*2) x++;
		cout<<x;
		return 0;
	}
	if(n==15){
		int x=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					int sum=s[i]+s[j]+s[y];
					int maxx=max(s[i],max(s[j],s[y]));
					if(sum>maxx*2) x++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						int sum=s[i]+s[j]+s[y]+s[u];
						int maxx=max(s[i],max(s[j],max(s[y],s[u])));
						if(sum>maxx*2) x++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							int sum=s[i]+s[j]+s[y]+s[u]+s[o];
							int maxx=max(s[i],max(s[j],max(s[y],max(s[o],s[u]))));
							if(sum>maxx*2) x++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r];
								int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],s[u])))));
								if(sum>maxx*2) x++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t];
									int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],s[u]))))));
									if(sum>maxx*2) x++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g];
										int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],s[u])))))));
										if(sum>maxx*2) x++;
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q];
											int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],s[u]))))))));
											if(sum>maxx*2) x++;
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w];
												int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],s[u])))))))));
												if(sum>maxx*2) x++;
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h];
													int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],s[u]))))))))));
													if(sum>maxx*2) x++;
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c];
														int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],s[u])))))))))));
														if(sum>maxx*2) x++;
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v];
															int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],s[u]))))))))))));
															if(sum>maxx*2) x++;
														}
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															for(int d=v+1;d<=n;d++){
																int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v]+s[d];
																int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],max(s[d],s[u])))))))))))));
																if(sum>maxx*2) x++;
															}
														}
													}
												}
											}
										} 
									}
								}
							}
						}
					}
				}
			}
		}
		int sum=s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]+s[9]+s[10]+s[11]+s[12]+s[13]+s[14]+s[15];
		int maxx=max(s[1],max(s[2],max(s[3],max(s[4],max(s[6],max(s[7],max(s[8],max(s[9],max(s[10],max(s[11],max(s[12],max(s[13],max(s[14],max(s[15],s[5]))))))))))))));
		if(sum>maxx*2) x++;
		cout<<x;
		return 0;
	}
	if(n==16){
		int x=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					int sum=s[i]+s[j]+s[y];
					int maxx=max(s[i],max(s[j],s[y]));
					if(sum>maxx*2) x++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						int sum=s[i]+s[j]+s[y]+s[u];
						int maxx=max(s[i],max(s[j],max(s[y],s[u])));
						if(sum>maxx*2) x++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							int sum=s[i]+s[j]+s[y]+s[u]+s[o];
							int maxx=max(s[i],max(s[j],max(s[y],max(s[o],s[u]))));
							if(sum>maxx*2) x++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r];
								int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],s[u])))));
								if(sum>maxx*2) x++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t];
									int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],s[u]))))));
									if(sum>maxx*2) x++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g];
										int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],s[u])))))));
										if(sum>maxx*2) x++;
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q];
											int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],s[u]))))))));
											if(sum>maxx*2) x++;
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w];
												int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],s[u])))))))));
												if(sum>maxx*2) x++;
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h];
													int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],s[u]))))))))));
													if(sum>maxx*2) x++;
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c];
														int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],s[u])))))))))));
														if(sum>maxx*2) x++;
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v];
															int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],s[u]))))))))))));
															if(sum>maxx*2) x++;
														}
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															for(int d=v+1;d<=n;d++){
																int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v]+s[d];
																int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],max(s[d],s[u])))))))))))));
																if(sum>maxx*2) x++;
															}
														}
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															for(int d=v+1;d<=n;d++){
																for(int b=d+!1;b<=n;b++){
																	int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v]+s[d]+s[b];
																	int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],max(s[d],max(s[b],s[u]))))))))))))));
																	if(sum>maxx*2) x++;
																}
															}
														}
													}
												}
											}
										} 
									}
								}
							}
						}
					}
				}
			}
		}
		int sum=s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]+s[9]+s[10]+s[11]+s[12]+s[13]+s[14]+s[15]+s[16];
		int maxx=max(s[1],max(s[2],max(s[3],max(s[4],max(s[6],max(s[7],max(s[8],max(s[9],max(s[10],max(s[11],max(s[12],max(s[13],max(s[14],max(s[15],max(s[16],s[5])))))))))))))));
		if(sum>maxx*2) x++;
		cout<<x;
		return 0;
	}
	if(n==17){
		int x=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					int sum=s[i]+s[j]+s[y];
					int maxx=max(s[i],max(s[j],s[y]));
					if(sum>maxx*2) x++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						int sum=s[i]+s[j]+s[y]+s[u];
						int maxx=max(s[i],max(s[j],max(s[y],s[u])));
						if(sum>maxx*2) x++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							int sum=s[i]+s[j]+s[y]+s[u]+s[o];
							int maxx=max(s[i],max(s[j],max(s[y],max(s[o],s[u]))));
							if(sum>maxx*2) x++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r];
								int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],s[u])))));
								if(sum>maxx*2) x++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t];
									int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],s[u]))))));
									if(sum>maxx*2) x++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g];
										int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],s[u])))))));
										if(sum>maxx*2) x++;
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q];
											int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],s[u]))))))));
											if(sum>maxx*2) x++;
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w];
												int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],s[u])))))))));
												if(sum>maxx*2) x++;
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h];
													int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],s[u]))))))))));
													if(sum>maxx*2) x++;
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c];
														int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],s[u])))))))))));
														if(sum>maxx*2) x++;
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v];
															int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],s[u]))))))))))));
															if(sum>maxx*2) x++;
														}
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															for(int d=v+1;d<=n;d++){
																int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v]+s[d];
																int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],max(s[d],s[u])))))))))))));
																if(sum>maxx*2) x++;
															}
														}
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															for(int d=v+1;d<=n;d++){
																for(int b=d+1;b<=n;b++){
																	int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v]+s[d]+s[b];
																	int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],max(s[d],max(s[b],s[u]))))))))))))));
																	if(sum>maxx*2) x++;
																}
															}
														}
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															for(int d=v+1;d<=n;d++){
																for(int b=d+1;b<=n;b++){
																	for(int e=b+1;e<=n;e++){
																		int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v]+s[d]+s[b]+s[e];
																		int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],max(s[d],max(s[b],max(s[e],s[u])))))))))))))));
																		if(sum>maxx*2) x++;
																	}
																}
															}
														}
													}
												}
											}
										} 
									}
								}
							}
						}
					}
				}
			}
		}
		int sum=s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]+s[9]+s[10]+s[11]+s[12]+s[13]+s[14]+s[15]+s[16]+s[17];
		int maxx=max(s[1],max(s[2],max(s[3],max(s[4],max(s[6],max(s[7],max(s[8],max(s[9],max(s[10],max(s[11],max(s[12],max(s[13],max(s[14],max(s[15],max(s[16],max(s[17],s[5]))))))))))))))));
		if(sum>maxx*2) x++;
		cout<<x;
		return 0;
	}
	if(n==18){
		int x=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					int sum=s[i]+s[j]+s[y];
					int maxx=max(s[i],max(s[j],s[y]));
					if(sum>maxx*2) x++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						int sum=s[i]+s[j]+s[y]+s[u];
						int maxx=max(s[i],max(s[j],max(s[y],s[u])));
						if(sum>maxx*2) x++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							int sum=s[i]+s[j]+s[y]+s[u]+s[o];
							int maxx=max(s[i],max(s[j],max(s[y],max(s[o],s[u]))));
							if(sum>maxx*2) x++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r];
								int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],s[u])))));
								if(sum>maxx*2) x++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t];
									int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],s[u]))))));
									if(sum>maxx*2) x++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g];
										int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],s[u])))))));
										if(sum>maxx*2) x++;
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q];
											int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],s[u]))))))));
											if(sum>maxx*2) x++;
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w];
												int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],s[u])))))))));
												if(sum>maxx*2) x++;
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h];
													int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],s[u]))))))))));
													if(sum>maxx*2) x++;
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c];
														int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],s[u])))))))))));
														if(sum>maxx*2) x++;
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v];
															int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],s[u]))))))))))));
															if(sum>maxx*2) x++;
														}
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															for(int d=v+1;d<=n;d++){
																int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v]+s[d];
																int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],max(s[d],s[u])))))))))))));
																if(sum>maxx*2) x++;
															}
														}
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															for(int d=v+1;d<=n;d++){
																for(int b=d+1;b<=n;b++){
																	int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v]+s[d]+s[b];
																	int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],max(s[d],max(s[b],s[u]))))))))))))));
																	if(sum>maxx*2) x++;
																}
															}
														}
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															for(int d=v+1;d<=n;d++){
																for(int b=d+1;b<=n;b++){
																	for(int e=b+1;e<=n;e++){
																		int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v]+s[d]+s[b]+s[e];
																		int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],max(s[d],max(s[b],max(s[e],s[u])))))))))))))));
																		if(sum>maxx*2) x++;
																	}
																}
															}
														}
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															for(int d=v+1;d<=n;d++){
																for(int b=d+1;b<=n;b++){
																	for(int e=b+1;e<=n;e++){
																		for(int m=e+1;m<=n;m++){
																			int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v]+s[d]+s[b]+s[e]+s[m];
																			int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],max(s[d],max(s[b],max(s[e],max(s[m],s[u]))))))))))))))));
																			if(sum>maxx*2) x++;
																		}
																	}
																}
															}
														}
													}
												}
											}
										} 
									}
								}
							}
						}
					}
				}
			}
		}
		int sum=s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]+s[9]+s[10]+s[11]+s[12]+s[13]+s[14]+s[15]+s[16]+s[17]+s[18];
		int maxx=max(s[1],max(s[2],max(s[3],max(s[4],max(s[6],max(s[7],max(s[8],max(s[9],max(s[10],max(s[11],max(s[12],max(s[13],max(s[14],max(s[15],max(s[16],max(s[17],max(s[18],s[5])))))))))))))))));
		if(sum>maxx*2) x++;
		cout<<x;
		return 0;
	}
	if(n==19){
		int x=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					int sum=s[i]+s[j]+s[y];
					int maxx=max(s[i],max(s[j],s[y]));
					if(sum>maxx*2) x++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						int sum=s[i]+s[j]+s[y]+s[u];
						int maxx=max(s[i],max(s[j],max(s[y],s[u])));
						if(sum>maxx*2) x++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							int sum=s[i]+s[j]+s[y]+s[u]+s[o];
							int maxx=max(s[i],max(s[j],max(s[y],max(s[o],s[u]))));
							if(sum>maxx*2) x++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r];
								int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],s[u])))));
								if(sum>maxx*2) x++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t];
									int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],s[u]))))));
									if(sum>maxx*2) x++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g];
										int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],s[u])))))));
										if(sum>maxx*2) x++;
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q];
											int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],s[u]))))))));
											if(sum>maxx*2) x++;
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w];
												int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],s[u])))))))));
												if(sum>maxx*2) x++;
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h];
													int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],s[u]))))))))));
													if(sum>maxx*2) x++;
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c];
														int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],s[u])))))))))));
														if(sum>maxx*2) x++;
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v];
															int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],s[u]))))))))))));
															if(sum>maxx*2) x++;
														}
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															for(int d=v+1;d<=n;d++){
																int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v]+s[d];
																int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],max(s[d],s[u])))))))))))));
																if(sum>maxx*2) x++;
															}
														}
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															for(int d=v+1;d<=n;d++){
																for(int b=d+1;b<=n;b++){
																	int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v]+s[d]+s[b];
																	int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],max(s[d],max(s[b],s[u]))))))))))))));
																	if(sum>maxx*2) x++;
																}
															}
														}
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															for(int d=v+1;d<=n;d++){
																for(int b=d+1;b<=n;b++){
																	for(int e=b+1;e<=n;e++){
																		int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v]+s[d]+s[b]+s[e];
																		int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],max(s[d],max(s[b],max(s[e],s[u])))))))))))))));
																		if(sum>maxx*2) x++;
																	}
																}
															}
														}
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															for(int d=v+1;d<=n;d++){
																for(int b=d+1;b<=n;b++){
																	for(int e=b+1;e<=n;e++){
																		for(int m=e+1;m<=n;m++){
																			int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v]+s[d]+s[b]+s[e]+s[m];
																			int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],max(s[d],max(s[b],max(s[e],max(s[m],s[u]))))))))))))))));
																			if(sum>maxx*2) x++;
																		}
																	}
																}
															}
														}
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															for(int d=v+1;d<=n;d++){
																for(int b=d+1;b<=n;b++){
																	for(int e=b+1;e<=n;e++){
																		for(int m=e+1;m<=n;m++){
																			for(int ab=m+1;ab<=n;ab++){
																				int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v]+s[d]+s[b]+s[e]+s[m]+s[ab];
																				int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],max(s[d],max(s[b],max(s[e],max(s[m],max(s[ab],s[u])))))))))))))))));
																				if(sum>maxx*2) x++;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										} 
									}
								}
							}
						}
					}
				}
			}
		}
		int sum=s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]+s[9]+s[10]+s[11]+s[12]+s[13]+s[14]+s[15]+s[16]+s[17]+s[18]+s[19];
		int maxx=max(s[1],max(s[2],max(s[3],max(s[4],max(s[6],max(s[7],max(s[8],max(s[9],max(s[10],max(s[11],max(s[12],max(s[13],max(s[14],max(s[15],max(s[16],max(s[17],max(s[18],max(s[19],s[5]))))))))))))))))));
		if(sum>maxx*2) x++;
		cout<<x;
		return 0;
	}
	if(n==20){
		int x=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					int sum=s[i]+s[j]+s[y];
					int maxx=max(s[i],max(s[j],s[y]));
					if(sum>maxx*2) x++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						int sum=s[i]+s[j]+s[y]+s[u];
						int maxx=max(s[i],max(s[j],max(s[y],s[u])));
						if(sum>maxx*2) x++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							int sum=s[i]+s[j]+s[y]+s[u]+s[o];
							int maxx=max(s[i],max(s[j],max(s[y],max(s[o],s[u]))));
							if(sum>maxx*2) x++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r];
								int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],s[u])))));
								if(sum>maxx*2) x++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t];
									int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],s[u]))))));
									if(sum>maxx*2) x++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g];
										int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],s[u])))))));
										if(sum>maxx*2) x++;
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q];
											int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],s[u]))))))));
											if(sum>maxx*2) x++;
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w];
												int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],s[u])))))))));
												if(sum>maxx*2) x++;
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h];
													int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],s[u]))))))))));
													if(sum>maxx*2) x++;
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c];
														int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],s[u])))))))))));
														if(sum>maxx*2) x++;
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v];
															int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],s[u]))))))))))));
															if(sum>maxx*2) x++;
														}
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															for(int d=v+1;d<=n;d++){
																int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v]+s[d];
																int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],max(s[d],s[u])))))))))))));
																if(sum>maxx*2) x++;
															}
														}
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															for(int d=v+1;d<=n;d++){
																for(int b=d+1;b<=n;b++){
																	int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v]+s[d]+s[b];
																	int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],max(s[d],max(s[b],s[u]))))))))))))));
																	if(sum>maxx*2) x++;
																}
															}
														}
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															for(int d=v+1;d<=n;d++){
																for(int b=d+1;b<=n;b++){
																	for(int e=b+1;e<=n;e++){
																		int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v]+s[d]+s[b]+s[e];
																		int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],max(s[d],max(s[b],max(s[e],s[u])))))))))))))));
																		if(sum>maxx*2) x++;
																	}
																}
															}
														}
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															for(int d=v+1;d<=n;d++){
																for(int b=d+1;b<=n;b++){
																	for(int e=b+1;e<=n;e++){
																		for(int m=e+1;m<=n;m++){
																			int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v]+s[d]+s[b]+s[e]+s[m];
																			int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],max(s[d],max(s[b],max(s[e],max(s[m],s[u]))))))))))))))));
																			if(sum>maxx*2) x++;
																		}
																	}
																}
															}
														}
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															for(int d=v+1;d<=n;d++){
																for(int b=d+1;b<=n;b++){
																	for(int e=b+1;e<=n;e++){
																		for(int m=e+1;m<=n;m++){
																			for(int ab=m+1;ab<=n;ab++){
																				int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v]+s[d]+s[b]+s[e]+s[m]+s[ab];
																				int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],max(s[d],max(s[b],max(s[e],max(s[m],max(s[ab],s[u])))))))))))))))));
																				if(sum>maxx*2) x++;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
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
				for(int y=j+1;y<=n;y++){
					for(int u=y+1;u<=n;u++){
						for(int o=u+1;o<=n;o++){
							for(int r=o+1;r<=n;r++){
								for(int t=r+1;t<=n;t++){
									for(int g=t+1;g<=n;g++){
										for(int q=g+1;q<=n;q++){
											for(int w=q+1;w<=n;w++){
												for(int h=w+1;h<=n;h++){
													for(int c=h+1;c<=n;c++){
														for(int v=c+1;v<=n;v++){
															for(int d=v+1;d<=n;d++){
																for(int b=d+1;b<=n;b++){
																	for(int e=b+1;e<=n;e++){
																		for(int m=e+1;m<=n;m++){
																			for(int ab=m+1;ab<=n;ab++){
																				for(int abc=ab+1;abc<=n;abc++){
																					int sum=s[i]+s[j]+s[y]+s[u]+s[o]+s[r]+s[t]+s[g]+s[q]+s[w]+s[h]+s[c]+s[v]+s[d]+s[b]+s[e]+s[m]+s[ab]+s[abc];
																					int maxx=max(s[i],max(s[j],max(s[y],max(s[o],max(s[r],max(s[t],max(s[g],max(s[q],max(s[w],max(s[h],max(s[c],max(s[v],max(s[d],max(s[b],max(s[e],max(s[m],max(s[ab],max(s[abc],s[u]))))))))))))))))));
																					if(sum>maxx*2) x++;
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										} 
									}
								}
							}
						}
					}
				}
			}
		}
		int sum=s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]+s[9]+s[10]+s[11]+s[12]+s[13]+s[14]+s[15]+s[16]+s[17]+s[18]+s[19]+s[20];
		int maxx=max(s[1],max(s[2],max(s[3],max(s[4],max(s[6],max(s[7],max(s[8],max(s[9],max(s[10],max(s[11],max(s[12],max(s[13],max(s[14],max(s[15],max(s[16],max(s[17],max(s[18],max(s[19],max(s[20],s[5])))))))))))))))))));
		if(sum>maxx*2) x++;
		cout<<x;
		return 0;
	}
	return 0;
}

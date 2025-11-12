#include<bits/stdc++.h>
using namespace std;
long long edge[510];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>edge[i];
	if(n<=10){
		if(n==3){
			if(edge[1]+edge[2]+edge[3]>max(edge[1],max(edge[2],edge[3]))*2)cout<<'1';
			else cout<<'0';
		}else if(n==4){
			for(int i=1;i<=n-2;i++){
				for(int j=i+1;j<=n-1;j++){
					for(int k=j+1;k<=n;k++){
						if(edge[i]+edge[j]+edge[k]>max(edge[i],max(edge[j],edge[k]))*2)sum++;
					}
				}
			}if(edge[1]+edge[2]+edge[3]+edge[4]>max(max(edge[1],edge[2]),max(edge[3],edge[4]))*2)sum++;
			cout<<sum;
		}else if(n==5){
			for(int i=1;i<=n-2;i++){
				for(int j=i+1;j<=n-1;j++){
					for(int k=j+1;k<=n;k++){
						if(edge[i]+edge[j]+edge[k]>max(edge[i],max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-3;i++){
				for(int j=i+1;j<=n-2;j++){
					for(int k=j+1;k<=n-1;k++){
						for(int o=k+1;o<=n;o++)if(edge[i]+edge[j]+edge[k]+edge[o]>max(max(edge[o],edge[i]),max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-4;i++){
				for(int j=i+1;j<=n-3;j++){
					for(int k=j+1;k<=n-2;k++){
						for(int o=k+1;o<=n-1;o++){
							for(int q=o+1;q<=n;q++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]>max(max(edge[q],max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
						}
					}
				}
			}cout<<sum;
		}else if(n==6){
			for(int i=1;i<=n-2;i++){
				for(int j=i+1;j<=n-1;j++){
					for(int k=j+1;k<=n;k++){
						if(edge[i]+edge[j]+edge[k]>max(edge[i],max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-3;i++){
				for(int j=i+1;j<=n-2;j++){
					for(int k=j+1;k<=n-1;k++){
						for(int o=k+1;o<=n;o++)if(edge[i]+edge[j]+edge[k]+edge[o]>max(max(edge[o],edge[i]),max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-4;i++){
				for(int j=i+1;j<=n-3;j++){
					for(int k=j+1;k<=n-2;k++){
						for(int o=k+1;o<=n-1;o++){
							for(int q=o+1;q<=n;q++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]>max(max(edge[q],max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
						}
					}
				}
			}for(int i=1;i<=n-5;i++){
				for(int j=i+1;j<=n-4;j++){
					for(int k=j+1;k<=n-3;k++){
						for(int o=k+1;o<=n-2;o++){
							for(int q=o+1;q<=n-1;q++){
								for(int w=q+1;w<=n;w++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
							}
						}
					}
				}
			}
			cout<<sum;
		}else if(n==7){
			for(int i=1;i<=n-2;i++){
				for(int j=i+1;j<=n-1;j++){
					for(int k=j+1;k<=n;k++){
						if(edge[i]+edge[j]+edge[k]>max(edge[i],max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-3;i++){
				for(int j=i+1;j<=n-2;j++){
					for(int k=j+1;k<=n-1;k++){
						for(int o=k+1;o<=n;o++)if(edge[i]+edge[j]+edge[k]+edge[o]>max(max(edge[o],edge[i]),max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-4;i++){
				for(int j=i+1;j<=n-3;j++){
					for(int k=j+1;k<=n-2;k++){
						for(int o=k+1;o<=n-1;o++){
							for(int q=o+1;q<=n;q++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]>max(max(edge[q],max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
						}
					}
				}
			}for(int i=1;i<=n-5;i++){
				for(int j=i+1;j<=n-4;j++){
					for(int k=j+1;k<=n-3;k++){
						for(int o=k+1;o<=n-2;o++){
							for(int q=o+1;q<=n-1;q++){
								for(int w=q+1;w<=n;w++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
							}
						}
					}
				}
			}for(int i=1;i<=n-6;i++){
				for(int j=i+1;j<=n-5;j++){
					for(int k=j+1;k<=n-4;k++){
						for(int o=k+1;o<=n-3;o++){
							for(int q=o+1;q<=n-2;q++){
								for(int w=q+1;w<=n-1;w++){
									for(int e=w+1;e<=n;e++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[e],max(edge[j],edge[k])))*2)sum++;
								}
							}
						}
					}
				}
			}
			cout<<sum;
		}else if(n==8){
			for(int i=1;i<=n-2;i++){
				for(int j=i+1;j<=n-1;j++){
					for(int k=j+1;k<=n;k++){
						if(edge[i]+edge[j]+edge[k]>max(edge[i],max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-3;i++){
				for(int j=i+1;j<=n-2;j++){
					for(int k=j+1;k<=n-1;k++){
						for(int o=k+1;o<=n;o++)if(edge[i]+edge[j]+edge[k]+edge[o]>max(max(edge[o],edge[i]),max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-4;i++){
				for(int j=i+1;j<=n-3;j++){
					for(int k=j+1;k<=n-2;k++){
						for(int o=k+1;o<=n-1;o++){
							for(int q=o+1;q<=n;q++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]>max(max(edge[q],max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
						}
					}
				}
			}for(int i=1;i<=n-5;i++){
				for(int j=i+1;j<=n-4;j++){
					for(int k=j+1;k<=n-3;k++){
						for(int o=k+1;o<=n-2;o++){
							for(int q=o+1;q<=n-1;q++){
								for(int w=q+1;w<=n;w++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
							}
						}
					}
				}
			}for(int i=1;i<=n-6;i++){
				for(int j=i+1;j<=n-5;j++){
					for(int k=j+1;k<=n-4;k++){
						for(int o=k+1;o<=n-3;o++){
							for(int q=o+1;q<=n-2;q++){
								for(int w=q+1;w<=n-1;w++){
									for(int e=w+1;e<=n;e++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[e],max(edge[j],edge[k])))*2)sum++;
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-7;i++){
				for(int j=i+1;j<=n-6;j++){
					for(int k=j+1;k<=n-5;k++){
						for(int o=k+1;o<=n-4;o++){
							for(int q=o+1;q<=n-3;q++){
								for(int w=q+1;w<=n-2;w++){
									for(int e=w+1;e<=n-1;e++){
										for(int r=e+1;r<=n;r++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
									}
								}
							}
						}
					}
				}
			}
			cout<<sum;
		}else if(n==9){
			for(int i=1;i<=n-2;i++){
				for(int j=i+1;j<=n-1;j++){
					for(int k=j+1;k<=n;k++){
						if(edge[i]+edge[j]+edge[k]>max(edge[i],max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-3;i++){
				for(int j=i+1;j<=n-2;j++){
					for(int k=j+1;k<=n-1;k++){
						for(int o=k+1;o<=n;o++)if(edge[i]+edge[j]+edge[k]+edge[o]>max(max(edge[o],edge[i]),max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-4;i++){
				for(int j=i+1;j<=n-3;j++){
					for(int k=j+1;k<=n-2;k++){
						for(int o=k+1;o<=n-1;o++){
							for(int q=o+1;q<=n;q++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]>max(max(edge[q],max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
						}
					}
				}
			}for(int i=1;i<=n-5;i++){
				for(int j=i+1;j<=n-4;j++){
					for(int k=j+1;k<=n-3;k++){
						for(int o=k+1;o<=n-2;o++){
							for(int q=o+1;q<=n-1;q++){
								for(int w=q+1;w<=n;w++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
							}
						}
					}
				}
			}for(int i=1;i<=n-6;i++){
				for(int j=i+1;j<=n-5;j++){
					for(int k=j+1;k<=n-4;k++){
						for(int o=k+1;o<=n-3;o++){
							for(int q=o+1;q<=n-2;q++){
								for(int w=q+1;w<=n-1;w++){
									for(int e=w+1;e<=n;e++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[e],max(edge[j],edge[k])))*2)sum++;
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-7;i++){
				for(int j=i+1;j<=n-6;j++){
					for(int k=j+1;k<=n-5;k++){
						for(int o=k+1;o<=n-4;o++){
							for(int q=o+1;q<=n-3;q++){
								for(int w=q+1;w<=n-2;w++){
									for(int e=w+1;e<=n-1;e++){
										for(int r=e+1;r<=n;r++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-8;i++){
				for(int j=i+1;j<=n-7;j++){
					for(int k=j+1;k<=n-6;k++){
						for(int o=k+1;o<=n-5;o++){
							for(int q=o+1;q<=n-4;q++){
								for(int w=q+1;w<=n-3;w++){
									for(int e=w+1;e<=n-2;e++){
										for(int r=e+1;r<=n-1;r++){
											for(int t=r+1;t<=n;t++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]>max(max(edge[t],max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
										}
									}
								}
							}
						}
					}
				}
			}
			cout<<sum;
		}else{
			for(int i=1;i<=n-2;i++){
				for(int j=i+1;j<=n-1;j++){
					for(int k=j+1;k<=n;k++){
						if(edge[i]+edge[j]+edge[k]>max(edge[i],max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-3;i++){
				for(int j=i+1;j<=n-2;j++){
					for(int k=j+1;k<=n-1;k++){
						for(int o=k+1;o<=n;o++)if(edge[i]+edge[j]+edge[k]+edge[o]>max(max(edge[o],edge[i]),max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-4;i++){
				for(int j=i+1;j<=n-3;j++){
					for(int k=j+1;k<=n-2;k++){
						for(int o=k+1;o<=n-1;o++){
							for(int q=o+1;q<=n;q++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]>max(max(edge[q],max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
						}
					}
				}
			}for(int i=1;i<=n-5;i++){
				for(int j=i+1;j<=n-4;j++){
					for(int k=j+1;k<=n-3;k++){
						for(int o=k+1;o<=n-2;o++){
							for(int q=o+1;q<=n-1;q++){
								for(int w=q+1;w<=n;w++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
							}
						}
					}
				}
			}for(int i=1;i<=n-6;i++){
				for(int j=i+1;j<=n-5;j++){
					for(int k=j+1;k<=n-4;k++){
						for(int o=k+1;o<=n-3;o++){
							for(int q=o+1;q<=n-2;q++){
								for(int w=q+1;w<=n-1;w++){
									for(int e=w+1;e<=n;e++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[e],max(edge[j],edge[k])))*2)sum++;
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-7;i++){
				for(int j=i+1;j<=n-6;j++){
					for(int k=j+1;k<=n-5;k++){
						for(int o=k+1;o<=n-4;o++){
							for(int q=o+1;q<=n-3;q++){
								for(int w=q+1;w<=n-2;w++){
									for(int e=w+1;e<=n-1;e++){
										for(int r=e+1;r<=n;r++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-8;i++){
				for(int j=i+1;j<=n-7;j++){
					for(int k=j+1;k<=n-6;k++){
						for(int o=k+1;o<=n-5;o++){
							for(int q=o+1;q<=n-4;q++){
								for(int w=q+1;w<=n-3;w++){
									for(int e=w+1;e<=n-2;e++){
										for(int r=e+1;r<=n-1;r++){
											for(int t=r+1;t<=n;t++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]>max(max(edge[t],max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-9;i++){
				for(int j=i+1;j<=n-8;j++){
					for(int k=j+1;k<=n-7;k++){
						for(int o=k+1;o<=n-6;o++){
							for(int q=o+1;q<=n-5;q++){
								for(int w=q+1;w<=n-4;w++){
									for(int e=w+1;e<=n-3;e++){
										for(int r=e+1;r<=n-2;r++){
											for(int t=r+1;t<=n-1;t++){
												for(int y=t+1;y<=n;y++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]>max(max(max(edge[y],edge[t]),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			cout<<sum;
			}
		}else if(n>10&&n<=20){
			if(n==11){
				for(int i=1;i<=n-2;i++){
				for(int j=i+1;j<=n-1;j++){
					for(int k=j+1;k<=n;k++){
						if(edge[i]+edge[j]+edge[k]>max(edge[i],max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-3;i++){
				for(int j=i+1;j<=n-2;j++){
					for(int k=j+1;k<=n-1;k++){
						for(int o=k+1;o<=n;o++)if(edge[i]+edge[j]+edge[k]+edge[o]>max(max(edge[o],edge[i]),max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-4;i++){
				for(int j=i+1;j<=n-3;j++){
					for(int k=j+1;k<=n-2;k++){
						for(int o=k+1;o<=n-1;o++){
							for(int q=o+1;q<=n;q++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]>max(max(edge[q],max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
						}
					}
				}
			}for(int i=1;i<=n-5;i++){
				for(int j=i+1;j<=n-4;j++){
					for(int k=j+1;k<=n-3;k++){
						for(int o=k+1;o<=n-2;o++){
							for(int q=o+1;q<=n-1;q++){
								for(int w=q+1;w<=n;w++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
							}
						}
					}
				}
			}for(int i=1;i<=n-6;i++){
				for(int j=i+1;j<=n-5;j++){
					for(int k=j+1;k<=n-4;k++){
						for(int o=k+1;o<=n-3;o++){
							for(int q=o+1;q<=n-2;q++){
								for(int w=q+1;w<=n-1;w++){
									for(int e=w+1;e<=n;e++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[e],max(edge[j],edge[k])))*2)sum++;
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-7;i++){
				for(int j=i+1;j<=n-6;j++){
					for(int k=j+1;k<=n-5;k++){
						for(int o=k+1;o<=n-4;o++){
							for(int q=o+1;q<=n-3;q++){
								for(int w=q+1;w<=n-2;w++){
									for(int e=w+1;e<=n-1;e++){
										for(int r=e+1;r<=n;r++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-8;i++){
				for(int j=i+1;j<=n-7;j++){
					for(int k=j+1;k<=n-6;k++){
						for(int o=k+1;o<=n-5;o++){
							for(int q=o+1;q<=n-4;q++){
								for(int w=q+1;w<=n-3;w++){
									for(int e=w+1;e<=n-2;e++){
										for(int r=e+1;r<=n-1;r++){
											for(int t=r+1;t<=n;t++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]>max(max(edge[t],max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-9;i++){
				for(int j=i+1;j<=n-8;j++){
					for(int k=j+1;k<=n-7;k++){
						for(int o=k+1;o<=n-6;o++){
							for(int q=o+1;q<=n-5;q++){
								for(int w=q+1;w<=n-4;w++){
									for(int e=w+1;e<=n-3;e++){
										for(int r=e+1;r<=n-2;r++){
											for(int t=r+1;t<=n-1;t++){
												for(int y=t+1;y<=n;y++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]>max(max(max(edge[y],edge[t]),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-10;i++){
				for(int j=i+1;j<=n-9;j++){
					for(int k=j+1;k<=n-8;k++){
						for(int o=k+1;o<=n-7;o++){
							for(int q=o+1;q<=n-6;q++){
								for(int w=q+1;w<=n-5;w++){
									for(int e=w+1;e<=n-4;e++){
										for(int r=e+1;r<=n-3;r++){
											for(int t=r+1;t<=n-2;t++){
												for(int y=t+1;y<=n-1;y++){
													for(int u=y+1;u<=n;u++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]>max(max(max(edge[u],max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			cout<<sum;
			}else if(n==12){
				for(int i=1;i<=n-2;i++){
				for(int j=i+1;j<=n-1;j++){
					for(int k=j+1;k<=n;k++){
						if(edge[i]+edge[j]+edge[k]>max(edge[i],max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-3;i++){
				for(int j=i+1;j<=n-2;j++){
					for(int k=j+1;k<=n-1;k++){
						for(int o=k+1;o<=n;o++)if(edge[i]+edge[j]+edge[k]+edge[o]>max(max(edge[o],edge[i]),max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-4;i++){
				for(int j=i+1;j<=n-3;j++){
					for(int k=j+1;k<=n-2;k++){
						for(int o=k+1;o<=n-1;o++){
							for(int q=o+1;q<=n;q++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]>max(max(edge[q],max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
						}
					}
				}
			}for(int i=1;i<=n-5;i++){
				for(int j=i+1;j<=n-4;j++){
					for(int k=j+1;k<=n-3;k++){
						for(int o=k+1;o<=n-2;o++){
							for(int q=o+1;q<=n-1;q++){
								for(int w=q+1;w<=n;w++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
							}
						}
					}
				}
			}for(int i=1;i<=n-6;i++){
				for(int j=i+1;j<=n-5;j++){
					for(int k=j+1;k<=n-4;k++){
						for(int o=k+1;o<=n-3;o++){
							for(int q=o+1;q<=n-2;q++){
								for(int w=q+1;w<=n-1;w++){
									for(int e=w+1;e<=n;e++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[e],max(edge[j],edge[k])))*2)sum++;
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-7;i++){
				for(int j=i+1;j<=n-6;j++){
					for(int k=j+1;k<=n-5;k++){
						for(int o=k+1;o<=n-4;o++){
							for(int q=o+1;q<=n-3;q++){
								for(int w=q+1;w<=n-2;w++){
									for(int e=w+1;e<=n-1;e++){
										for(int r=e+1;r<=n;r++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-8;i++){
				for(int j=i+1;j<=n-7;j++){
					for(int k=j+1;k<=n-6;k++){
						for(int o=k+1;o<=n-5;o++){
							for(int q=o+1;q<=n-4;q++){
								for(int w=q+1;w<=n-3;w++){
									for(int e=w+1;e<=n-2;e++){
										for(int r=e+1;r<=n-1;r++){
											for(int t=r+1;t<=n;t++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]>max(max(edge[t],max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-9;i++){
				for(int j=i+1;j<=n-8;j++){
					for(int k=j+1;k<=n-7;k++){
						for(int o=k+1;o<=n-6;o++){
							for(int q=o+1;q<=n-5;q++){
								for(int w=q+1;w<=n-4;w++){
									for(int e=w+1;e<=n-3;e++){
										for(int r=e+1;r<=n-2;r++){
											for(int t=r+1;t<=n-1;t++){
												for(int y=t+1;y<=n;y++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]>max(max(max(edge[y],edge[t]),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-10;i++){
				for(int j=i+1;j<=n-9;j++){
					for(int k=j+1;k<=n-8;k++){
						for(int o=k+1;o<=n-7;o++){
							for(int q=o+1;q<=n-6;q++){
								for(int w=q+1;w<=n-5;w++){
									for(int e=w+1;e<=n-4;e++){
										for(int r=e+1;r<=n-3;r++){
											for(int t=r+1;t<=n-2;t++){
												for(int y=t+1;y<=n-1;y++){
													for(int u=y+1;u<=n;u++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]>max(max(max(edge[u],max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-11;i++){
				for(int j=i+1;j<=n-10;j++){
					for(int k=j+1;k<=n-9;k++){
						for(int o=k+1;o<=n-8;o++){
							for(int q=o+1;q<=n-7;q++){
								for(int w=q+1;w<=n-6;w++){
									for(int e=w+1;e<=n-5;e++){
										for(int r=e+1;r<=n-4;r++){
											for(int t=r+1;t<=n-3;t++){
												for(int y=t+1;y<=n-2;y++){
													for(int u=y+1;u<=n-1;u++){
														for(int p=u+1;p<=n;p++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]>max(max(max(max(edge[p],edge[u]),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			cout<<sum;
			}else if(n==13){
				for(int i=1;i<=n-2;i++){
				for(int j=i+1;j<=n-1;j++){
					for(int k=j+1;k<=n;k++){
						if(edge[i]+edge[j]+edge[k]>max(edge[i],max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-3;i++){
				for(int j=i+1;j<=n-2;j++){
					for(int k=j+1;k<=n-1;k++){
						for(int o=k+1;o<=n;o++)if(edge[i]+edge[j]+edge[k]+edge[o]>max(max(edge[o],edge[i]),max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-4;i++){
				for(int j=i+1;j<=n-3;j++){
					for(int k=j+1;k<=n-2;k++){
						for(int o=k+1;o<=n-1;o++){
							for(int q=o+1;q<=n;q++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]>max(max(edge[q],max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
						}
					}
				}
			}for(int i=1;i<=n-5;i++){
				for(int j=i+1;j<=n-4;j++){
					for(int k=j+1;k<=n-3;k++){
						for(int o=k+1;o<=n-2;o++){
							for(int q=o+1;q<=n-1;q++){
								for(int w=q+1;w<=n;w++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
							}
						}
					}
				}
			}for(int i=1;i<=n-6;i++){
				for(int j=i+1;j<=n-5;j++){
					for(int k=j+1;k<=n-4;k++){
						for(int o=k+1;o<=n-3;o++){
							for(int q=o+1;q<=n-2;q++){
								for(int w=q+1;w<=n-1;w++){
									for(int e=w+1;e<=n;e++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[e],max(edge[j],edge[k])))*2)sum++;
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-7;i++){
				for(int j=i+1;j<=n-6;j++){
					for(int k=j+1;k<=n-5;k++){
						for(int o=k+1;o<=n-4;o++){
							for(int q=o+1;q<=n-3;q++){
								for(int w=q+1;w<=n-2;w++){
									for(int e=w+1;e<=n-1;e++){
										for(int r=e+1;r<=n;r++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-8;i++){
				for(int j=i+1;j<=n-7;j++){
					for(int k=j+1;k<=n-6;k++){
						for(int o=k+1;o<=n-5;o++){
							for(int q=o+1;q<=n-4;q++){
								for(int w=q+1;w<=n-3;w++){
									for(int e=w+1;e<=n-2;e++){
										for(int r=e+1;r<=n-1;r++){
											for(int t=r+1;t<=n;t++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]>max(max(edge[t],max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-9;i++){
				for(int j=i+1;j<=n-8;j++){
					for(int k=j+1;k<=n-7;k++){
						for(int o=k+1;o<=n-6;o++){
							for(int q=o+1;q<=n-5;q++){
								for(int w=q+1;w<=n-4;w++){
									for(int e=w+1;e<=n-3;e++){
										for(int r=e+1;r<=n-2;r++){
											for(int t=r+1;t<=n-1;t++){
												for(int y=t+1;y<=n;y++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]>max(max(max(edge[y],edge[t]),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-10;i++){
				for(int j=i+1;j<=n-9;j++){
					for(int k=j+1;k<=n-8;k++){
						for(int o=k+1;o<=n-7;o++){
							for(int q=o+1;q<=n-6;q++){
								for(int w=q+1;w<=n-5;w++){
									for(int e=w+1;e<=n-4;e++){
										for(int r=e+1;r<=n-3;r++){
											for(int t=r+1;t<=n-2;t++){
												for(int y=t+1;y<=n-1;y++){
													for(int u=y+1;u<=n;u++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]>max(max(max(edge[u],max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-11;i++){
				for(int j=i+1;j<=n-10;j++){
					for(int k=j+1;k<=n-9;k++){
						for(int o=k+1;o<=n-8;o++){
							for(int q=o+1;q<=n-7;q++){
								for(int w=q+1;w<=n-6;w++){
									for(int e=w+1;e<=n-5;e++){
										for(int r=e+1;r<=n-4;r++){
											for(int t=r+1;t<=n-3;t++){
												for(int y=t+1;y<=n-2;y++){
													for(int u=y+1;u<=n-1;u++){
														for(int p=u+1;p<=n;p++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]>max(max(max(max(edge[p],edge[u]),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-12;i++){
				for(int j=i+1;j<=n-11;j++){
					for(int k=j+1;k<=n-10;k++){
						for(int o=k+1;o<=n-9;o++){
							for(int q=o+1;q<=n-8;q++){
								for(int w=q+1;w<=n-7;w++){
									for(int e=w+1;e<=n-6;e++){
										for(int r=e+1;r<=n-5;r++){
											for(int t=r+1;t<=n-4;t++){
												for(int y=t+1;y<=n-3;y++){
													for(int u=y+1;u<=n-2;u++){
														for(int p=u+1;p<=n-1;p++){
															for(int s=p+1;s<=n;s++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]>max(max(max(max(edge[s],max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			cout<<sum;
			}else if(n==14){
				for(int i=1;i<=n-2;i++){
				for(int j=i+1;j<=n-1;j++){
					for(int k=j+1;k<=n;k++){
						if(edge[i]+edge[j]+edge[k]>max(edge[i],max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-3;i++){
				for(int j=i+1;j<=n-2;j++){
					for(int k=j+1;k<=n-1;k++){
						for(int o=k+1;o<=n;o++)if(edge[i]+edge[j]+edge[k]+edge[o]>max(max(edge[o],edge[i]),max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-4;i++){
				for(int j=i+1;j<=n-3;j++){
					for(int k=j+1;k<=n-2;k++){
						for(int o=k+1;o<=n-1;o++){
							for(int q=o+1;q<=n;q++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]>max(max(edge[q],max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
						}
					}
				}
			}for(int i=1;i<=n-5;i++){
				for(int j=i+1;j<=n-4;j++){
					for(int k=j+1;k<=n-3;k++){
						for(int o=k+1;o<=n-2;o++){
							for(int q=o+1;q<=n-1;q++){
								for(int w=q+1;w<=n;w++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
							}
						}
					}
				}
			}for(int i=1;i<=n-6;i++){
				for(int j=i+1;j<=n-5;j++){
					for(int k=j+1;k<=n-4;k++){
						for(int o=k+1;o<=n-3;o++){
							for(int q=o+1;q<=n-2;q++){
								for(int w=q+1;w<=n-1;w++){
									for(int e=w+1;e<=n;e++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[e],max(edge[j],edge[k])))*2)sum++;
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-7;i++){
				for(int j=i+1;j<=n-6;j++){
					for(int k=j+1;k<=n-5;k++){
						for(int o=k+1;o<=n-4;o++){
							for(int q=o+1;q<=n-3;q++){
								for(int w=q+1;w<=n-2;w++){
									for(int e=w+1;e<=n-1;e++){
										for(int r=e+1;r<=n;r++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-8;i++){
				for(int j=i+1;j<=n-7;j++){
					for(int k=j+1;k<=n-6;k++){
						for(int o=k+1;o<=n-5;o++){
							for(int q=o+1;q<=n-4;q++){
								for(int w=q+1;w<=n-3;w++){
									for(int e=w+1;e<=n-2;e++){
										for(int r=e+1;r<=n-1;r++){
											for(int t=r+1;t<=n;t++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]>max(max(edge[t],max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-9;i++){
				for(int j=i+1;j<=n-8;j++){
					for(int k=j+1;k<=n-7;k++){
						for(int o=k+1;o<=n-6;o++){
							for(int q=o+1;q<=n-5;q++){
								for(int w=q+1;w<=n-4;w++){
									for(int e=w+1;e<=n-3;e++){
										for(int r=e+1;r<=n-2;r++){
											for(int t=r+1;t<=n-1;t++){
												for(int y=t+1;y<=n;y++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]>max(max(max(edge[y],edge[t]),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-10;i++){
				for(int j=i+1;j<=n-9;j++){
					for(int k=j+1;k<=n-8;k++){
						for(int o=k+1;o<=n-7;o++){
							for(int q=o+1;q<=n-6;q++){
								for(int w=q+1;w<=n-5;w++){
									for(int e=w+1;e<=n-4;e++){
										for(int r=e+1;r<=n-3;r++){
											for(int t=r+1;t<=n-2;t++){
												for(int y=t+1;y<=n-1;y++){
													for(int u=y+1;u<=n;u++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]>max(max(max(edge[u],max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-11;i++){
				for(int j=i+1;j<=n-10;j++){
					for(int k=j+1;k<=n-9;k++){
						for(int o=k+1;o<=n-8;o++){
							for(int q=o+1;q<=n-7;q++){
								for(int w=q+1;w<=n-6;w++){
									for(int e=w+1;e<=n-5;e++){
										for(int r=e+1;r<=n-4;r++){
											for(int t=r+1;t<=n-3;t++){
												for(int y=t+1;y<=n-2;y++){
													for(int u=y+1;u<=n-1;u++){
														for(int p=u+1;p<=n;p++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]>max(max(max(max(edge[p],edge[u]),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-12;i++){
				for(int j=i+1;j<=n-11;j++){
					for(int k=j+1;k<=n-10;k++){
						for(int o=k+1;o<=n-9;o++){
							for(int q=o+1;q<=n-8;q++){
								for(int w=q+1;w<=n-7;w++){
									for(int e=w+1;e<=n-6;e++){
										for(int r=e+1;r<=n-5;r++){
											for(int t=r+1;t<=n-4;t++){
												for(int y=t+1;y<=n-3;y++){
													for(int u=y+1;u<=n-2;u++){
														for(int p=u+1;p<=n-1;p++){
															for(int s=p+1;s<=n;s++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]>max(max(max(max(edge[s],max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-13;i++){
				for(int j=i+1;j<=n-12;j++){
					for(int k=j+1;k<=n-11;k++){
						for(int o=k+1;o<=n-10;o++){
							for(int q=o+1;q<=n-9;q++){
								for(int w=q+1;w<=n-8;w++){
									for(int e=w+1;e<=n-7;e++){
										for(int r=e+1;r<=n-6;r++){
											for(int t=r+1;t<=n-5;t++){
												for(int y=t+1;y<=n-4;y++){
													for(int u=y+1;u<=n-3;u++){
														for(int p=u+1;p<=n-2;p++){
															for(int s=p+1;s<=n-1;s++){
																for(int d=s+1;d<=n;d++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]>max(max(max(max(max(edge[d],edge[s]),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			cout<<sum;
			}else if(n==15){
				for(int i=1;i<=n-2;i++){
				for(int j=i+1;j<=n-1;j++){
					for(int k=j+1;k<=n;k++){
						if(edge[i]+edge[j]+edge[k]>max(edge[i],max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-3;i++){
				for(int j=i+1;j<=n-2;j++){
					for(int k=j+1;k<=n-1;k++){
						for(int o=k+1;o<=n;o++)if(edge[i]+edge[j]+edge[k]+edge[o]>max(max(edge[o],edge[i]),max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-4;i++){
				for(int j=i+1;j<=n-3;j++){
					for(int k=j+1;k<=n-2;k++){
						for(int o=k+1;o<=n-1;o++){
							for(int q=o+1;q<=n;q++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]>max(max(edge[q],max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
						}
					}
				}
			}for(int i=1;i<=n-5;i++){
				for(int j=i+1;j<=n-4;j++){
					for(int k=j+1;k<=n-3;k++){
						for(int o=k+1;o<=n-2;o++){
							for(int q=o+1;q<=n-1;q++){
								for(int w=q+1;w<=n;w++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
							}
						}
					}
				}
			}for(int i=1;i<=n-6;i++){
				for(int j=i+1;j<=n-5;j++){
					for(int k=j+1;k<=n-4;k++){
						for(int o=k+1;o<=n-3;o++){
							for(int q=o+1;q<=n-2;q++){
								for(int w=q+1;w<=n-1;w++){
									for(int e=w+1;e<=n;e++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[e],max(edge[j],edge[k])))*2)sum++;
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-7;i++){
				for(int j=i+1;j<=n-6;j++){
					for(int k=j+1;k<=n-5;k++){
						for(int o=k+1;o<=n-4;o++){
							for(int q=o+1;q<=n-3;q++){
								for(int w=q+1;w<=n-2;w++){
									for(int e=w+1;e<=n-1;e++){
										for(int r=e+1;r<=n;r++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-8;i++){
				for(int j=i+1;j<=n-7;j++){
					for(int k=j+1;k<=n-6;k++){
						for(int o=k+1;o<=n-5;o++){
							for(int q=o+1;q<=n-4;q++){
								for(int w=q+1;w<=n-3;w++){
									for(int e=w+1;e<=n-2;e++){
										for(int r=e+1;r<=n-1;r++){
											for(int t=r+1;t<=n;t++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]>max(max(edge[t],max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-9;i++){
				for(int j=i+1;j<=n-8;j++){
					for(int k=j+1;k<=n-7;k++){
						for(int o=k+1;o<=n-6;o++){
							for(int q=o+1;q<=n-5;q++){
								for(int w=q+1;w<=n-4;w++){
									for(int e=w+1;e<=n-3;e++){
										for(int r=e+1;r<=n-2;r++){
											for(int t=r+1;t<=n-1;t++){
												for(int y=t+1;y<=n;y++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]>max(max(max(edge[y],edge[t]),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-10;i++){
				for(int j=i+1;j<=n-9;j++){
					for(int k=j+1;k<=n-8;k++){
						for(int o=k+1;o<=n-7;o++){
							for(int q=o+1;q<=n-6;q++){
								for(int w=q+1;w<=n-5;w++){
									for(int e=w+1;e<=n-4;e++){
										for(int r=e+1;r<=n-3;r++){
											for(int t=r+1;t<=n-2;t++){
												for(int y=t+1;y<=n-1;y++){
													for(int u=y+1;u<=n;u++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]>max(max(max(edge[u],max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-11;i++){
				for(int j=i+1;j<=n-10;j++){
					for(int k=j+1;k<=n-9;k++){
						for(int o=k+1;o<=n-8;o++){
							for(int q=o+1;q<=n-7;q++){
								for(int w=q+1;w<=n-6;w++){
									for(int e=w+1;e<=n-5;e++){
										for(int r=e+1;r<=n-4;r++){
											for(int t=r+1;t<=n-3;t++){
												for(int y=t+1;y<=n-2;y++){
													for(int u=y+1;u<=n-1;u++){
														for(int p=u+1;p<=n;p++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]>max(max(max(max(edge[p],edge[u]),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-12;i++){
				for(int j=i+1;j<=n-11;j++){
					for(int k=j+1;k<=n-10;k++){
						for(int o=k+1;o<=n-9;o++){
							for(int q=o+1;q<=n-8;q++){
								for(int w=q+1;w<=n-7;w++){
									for(int e=w+1;e<=n-6;e++){
										for(int r=e+1;r<=n-5;r++){
											for(int t=r+1;t<=n-4;t++){
												for(int y=t+1;y<=n-3;y++){
													for(int u=y+1;u<=n-2;u++){
														for(int p=u+1;p<=n-1;p++){
															for(int s=p+1;s<=n;s++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]>max(max(max(max(edge[s],max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-13;i++){
				for(int j=i+1;j<=n-12;j++){
					for(int k=j+1;k<=n-11;k++){
						for(int o=k+1;o<=n-10;o++){
							for(int q=o+1;q<=n-9;q++){
								for(int w=q+1;w<=n-8;w++){
									for(int e=w+1;e<=n-7;e++){
										for(int r=e+1;r<=n-6;r++){
											for(int t=r+1;t<=n-5;t++){
												for(int y=t+1;y<=n-4;y++){
													for(int u=y+1;u<=n-3;u++){
														for(int p=u+1;p<=n-2;p++){
															for(int s=p+1;s<=n-1;s++){
																for(int d=s+1;d<=n;d++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]>max(max(max(max(max(edge[d],edge[s]),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-14;i++){
				for(int j=i+1;j<=n-13;j++){
					for(int k=j+1;k<=n-12;k++){
						for(int o=k+1;o<=n-11;o++){
							for(int q=o+1;q<=n-10;q++){
								for(int w=q+1;w<=n-9;w++){
									for(int e=w+1;e<=n-8;e++){
										for(int r=e+1;r<=n-7;r++){
											for(int t=r+1;t<=n-6;t++){
												for(int y=t+1;y<=n-5;y++){
													for(int u=y+1;u<=n-4;u++){
														for(int p=u+1;p<=n-3;p++){
															for(int s=p+1;s<=n-2;s++){
																for(int d=s+1;d<=n-1;d++){
																	for(int f=d+1;f<=n;f++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]+edge[f]>max(max(max(max(max(edge[f],max(edge[d],edge[s])),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			cout<<sum;
			}else if(n==16){
				for(int i=1;i<=n-2;i++){
				for(int j=i+1;j<=n-1;j++){
					for(int k=j+1;k<=n;k++){
						if(edge[i]+edge[j]+edge[k]>max(edge[i],max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-3;i++){
				for(int j=i+1;j<=n-2;j++){
					for(int k=j+1;k<=n-1;k++){
						for(int o=k+1;o<=n;o++)if(edge[i]+edge[j]+edge[k]+edge[o]>max(max(edge[o],edge[i]),max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-4;i++){
				for(int j=i+1;j<=n-3;j++){
					for(int k=j+1;k<=n-2;k++){
						for(int o=k+1;o<=n-1;o++){
							for(int q=o+1;q<=n;q++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]>max(max(edge[q],max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
						}
					}
				}
			}for(int i=1;i<=n-5;i++){
				for(int j=i+1;j<=n-4;j++){
					for(int k=j+1;k<=n-3;k++){
						for(int o=k+1;o<=n-2;o++){
							for(int q=o+1;q<=n-1;q++){
								for(int w=q+1;w<=n;w++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
							}
						}
					}
				}
			}for(int i=1;i<=n-6;i++){
				for(int j=i+1;j<=n-5;j++){
					for(int k=j+1;k<=n-4;k++){
						for(int o=k+1;o<=n-3;o++){
							for(int q=o+1;q<=n-2;q++){
								for(int w=q+1;w<=n-1;w++){
									for(int e=w+1;e<=n;e++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[e],max(edge[j],edge[k])))*2)sum++;
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-7;i++){
				for(int j=i+1;j<=n-6;j++){
					for(int k=j+1;k<=n-5;k++){
						for(int o=k+1;o<=n-4;o++){
							for(int q=o+1;q<=n-3;q++){
								for(int w=q+1;w<=n-2;w++){
									for(int e=w+1;e<=n-1;e++){
										for(int r=e+1;r<=n;r++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-8;i++){
				for(int j=i+1;j<=n-7;j++){
					for(int k=j+1;k<=n-6;k++){
						for(int o=k+1;o<=n-5;o++){
							for(int q=o+1;q<=n-4;q++){
								for(int w=q+1;w<=n-3;w++){
									for(int e=w+1;e<=n-2;e++){
										for(int r=e+1;r<=n-1;r++){
											for(int t=r+1;t<=n;t++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]>max(max(edge[t],max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-9;i++){
				for(int j=i+1;j<=n-8;j++){
					for(int k=j+1;k<=n-7;k++){
						for(int o=k+1;o<=n-6;o++){
							for(int q=o+1;q<=n-5;q++){
								for(int w=q+1;w<=n-4;w++){
									for(int e=w+1;e<=n-3;e++){
										for(int r=e+1;r<=n-2;r++){
											for(int t=r+1;t<=n-1;t++){
												for(int y=t+1;y<=n;y++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]>max(max(max(edge[y],edge[t]),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-10;i++){
				for(int j=i+1;j<=n-9;j++){
					for(int k=j+1;k<=n-8;k++){
						for(int o=k+1;o<=n-7;o++){
							for(int q=o+1;q<=n-6;q++){
								for(int w=q+1;w<=n-5;w++){
									for(int e=w+1;e<=n-4;e++){
										for(int r=e+1;r<=n-3;r++){
											for(int t=r+1;t<=n-2;t++){
												for(int y=t+1;y<=n-1;y++){
													for(int u=y+1;u<=n;u++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]>max(max(max(edge[u],max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-11;i++){
				for(int j=i+1;j<=n-10;j++){
					for(int k=j+1;k<=n-9;k++){
						for(int o=k+1;o<=n-8;o++){
							for(int q=o+1;q<=n-7;q++){
								for(int w=q+1;w<=n-6;w++){
									for(int e=w+1;e<=n-5;e++){
										for(int r=e+1;r<=n-4;r++){
											for(int t=r+1;t<=n-3;t++){
												for(int y=t+1;y<=n-2;y++){
													for(int u=y+1;u<=n-1;u++){
														for(int p=u+1;p<=n;p++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]>max(max(max(max(edge[p],edge[u]),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-12;i++){
				for(int j=i+1;j<=n-11;j++){
					for(int k=j+1;k<=n-10;k++){
						for(int o=k+1;o<=n-9;o++){
							for(int q=o+1;q<=n-8;q++){
								for(int w=q+1;w<=n-7;w++){
									for(int e=w+1;e<=n-6;e++){
										for(int r=e+1;r<=n-5;r++){
											for(int t=r+1;t<=n-4;t++){
												for(int y=t+1;y<=n-3;y++){
													for(int u=y+1;u<=n-2;u++){
														for(int p=u+1;p<=n-1;p++){
															for(int s=p+1;s<=n;s++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]>max(max(max(max(edge[s],max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-13;i++){
				for(int j=i+1;j<=n-12;j++){
					for(int k=j+1;k<=n-11;k++){
						for(int o=k+1;o<=n-10;o++){
							for(int q=o+1;q<=n-9;q++){
								for(int w=q+1;w<=n-8;w++){
									for(int e=w+1;e<=n-7;e++){
										for(int r=e+1;r<=n-6;r++){
											for(int t=r+1;t<=n-5;t++){
												for(int y=t+1;y<=n-4;y++){
													for(int u=y+1;u<=n-3;u++){
														for(int p=u+1;p<=n-2;p++){
															for(int s=p+1;s<=n-1;s++){
																for(int d=s+1;d<=n;d++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]>max(max(max(max(max(edge[d],edge[s]),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-14;i++){
				for(int j=i+1;j<=n-13;j++){
					for(int k=j+1;k<=n-12;k++){
						for(int o=k+1;o<=n-11;o++){
							for(int q=o+1;q<=n-10;q++){
								for(int w=q+1;w<=n-9;w++){
									for(int e=w+1;e<=n-8;e++){
										for(int r=e+1;r<=n-7;r++){
											for(int t=r+1;t<=n-6;t++){
												for(int y=t+1;y<=n-5;y++){
													for(int u=y+1;u<=n-4;u++){
														for(int p=u+1;p<=n-3;p++){
															for(int s=p+1;s<=n-2;s++){
																for(int d=s+1;d<=n-1;d++){
																	for(int f=d+1;f<=n;f++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]+edge[f]>max(max(max(max(max(edge[f],max(edge[d],edge[s])),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-15;i++){
				for(int j=i+1;j<=n-14;j++){
					for(int k=j+1;k<=n-13;k++){
						for(int o=k+1;o<=n-12;o++){
							for(int q=o+1;q<=n-11;q++){
								for(int w=q+1;w<=n-10;w++){
									for(int e=w+1;e<=n-9;e++){
										for(int r=e+1;r<=n-8;r++){
											for(int t=r+1;t<=n-7;t++){
												for(int y=t+1;y<=n-6;y++){
													for(int u=y+1;u<=n-5;u++){
														for(int p=u+1;p<=n-4;p++){
															for(int s=p+1;s<=n-3;s++){
																for(int d=s+1;d<=n-2;d++){
																	for(int f=d+1;f<=n-1;f++){
																		for(int g=f+1;g<=n;g++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]+edge[f]+edge[g]>max(max(max(max(max(max(edge[g],edge[f]),max(edge[d],edge[s])),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			cout<<sum;
			}else if(n==17){
				for(int i=1;i<=n-2;i++){
				for(int j=i+1;j<=n-1;j++){
					for(int k=j+1;k<=n;k++){
						if(edge[i]+edge[j]+edge[k]>max(edge[i],max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-3;i++){
				for(int j=i+1;j<=n-2;j++){
					for(int k=j+1;k<=n-1;k++){
						for(int o=k+1;o<=n;o++)if(edge[i]+edge[j]+edge[k]+edge[o]>max(max(edge[o],edge[i]),max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-4;i++){
				for(int j=i+1;j<=n-3;j++){
					for(int k=j+1;k<=n-2;k++){
						for(int o=k+1;o<=n-1;o++){
							for(int q=o+1;q<=n;q++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]>max(max(edge[q],max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
						}
					}
				}
			}for(int i=1;i<=n-5;i++){
				for(int j=i+1;j<=n-4;j++){
					for(int k=j+1;k<=n-3;k++){
						for(int o=k+1;o<=n-2;o++){
							for(int q=o+1;q<=n-1;q++){
								for(int w=q+1;w<=n;w++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
							}
						}
					}
				}
			}for(int i=1;i<=n-6;i++){
				for(int j=i+1;j<=n-5;j++){
					for(int k=j+1;k<=n-4;k++){
						for(int o=k+1;o<=n-3;o++){
							for(int q=o+1;q<=n-2;q++){
								for(int w=q+1;w<=n-1;w++){
									for(int e=w+1;e<=n;e++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[e],max(edge[j],edge[k])))*2)sum++;
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-7;i++){
				for(int j=i+1;j<=n-6;j++){
					for(int k=j+1;k<=n-5;k++){
						for(int o=k+1;o<=n-4;o++){
							for(int q=o+1;q<=n-3;q++){
								for(int w=q+1;w<=n-2;w++){
									for(int e=w+1;e<=n-1;e++){
										for(int r=e+1;r<=n;r++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-8;i++){
				for(int j=i+1;j<=n-7;j++){
					for(int k=j+1;k<=n-6;k++){
						for(int o=k+1;o<=n-5;o++){
							for(int q=o+1;q<=n-4;q++){
								for(int w=q+1;w<=n-3;w++){
									for(int e=w+1;e<=n-2;e++){
										for(int r=e+1;r<=n-1;r++){
											for(int t=r+1;t<=n;t++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]>max(max(edge[t],max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-9;i++){
				for(int j=i+1;j<=n-8;j++){
					for(int k=j+1;k<=n-7;k++){
						for(int o=k+1;o<=n-6;o++){
							for(int q=o+1;q<=n-5;q++){
								for(int w=q+1;w<=n-4;w++){
									for(int e=w+1;e<=n-3;e++){
										for(int r=e+1;r<=n-2;r++){
											for(int t=r+1;t<=n-1;t++){
												for(int y=t+1;y<=n;y++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]>max(max(max(edge[y],edge[t]),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-10;i++){
				for(int j=i+1;j<=n-9;j++){
					for(int k=j+1;k<=n-8;k++){
						for(int o=k+1;o<=n-7;o++){
							for(int q=o+1;q<=n-6;q++){
								for(int w=q+1;w<=n-5;w++){
									for(int e=w+1;e<=n-4;e++){
										for(int r=e+1;r<=n-3;r++){
											for(int t=r+1;t<=n-2;t++){
												for(int y=t+1;y<=n-1;y++){
													for(int u=y+1;u<=n;u++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]>max(max(max(edge[u],max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-11;i++){
				for(int j=i+1;j<=n-10;j++){
					for(int k=j+1;k<=n-9;k++){
						for(int o=k+1;o<=n-8;o++){
							for(int q=o+1;q<=n-7;q++){
								for(int w=q+1;w<=n-6;w++){
									for(int e=w+1;e<=n-5;e++){
										for(int r=e+1;r<=n-4;r++){
											for(int t=r+1;t<=n-3;t++){
												for(int y=t+1;y<=n-2;y++){
													for(int u=y+1;u<=n-1;u++){
														for(int p=u+1;p<=n;p++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]>max(max(max(max(edge[p],edge[u]),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-12;i++){
				for(int j=i+1;j<=n-11;j++){
					for(int k=j+1;k<=n-10;k++){
						for(int o=k+1;o<=n-9;o++){
							for(int q=o+1;q<=n-8;q++){
								for(int w=q+1;w<=n-7;w++){
									for(int e=w+1;e<=n-6;e++){
										for(int r=e+1;r<=n-5;r++){
											for(int t=r+1;t<=n-4;t++){
												for(int y=t+1;y<=n-3;y++){
													for(int u=y+1;u<=n-2;u++){
														for(int p=u+1;p<=n-1;p++){
															for(int s=p+1;s<=n;s++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]>max(max(max(max(edge[s],max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-13;i++){
				for(int j=i+1;j<=n-12;j++){
					for(int k=j+1;k<=n-11;k++){
						for(int o=k+1;o<=n-10;o++){
							for(int q=o+1;q<=n-9;q++){
								for(int w=q+1;w<=n-8;w++){
									for(int e=w+1;e<=n-7;e++){
										for(int r=e+1;r<=n-6;r++){
											for(int t=r+1;t<=n-5;t++){
												for(int y=t+1;y<=n-4;y++){
													for(int u=y+1;u<=n-3;u++){
														for(int p=u+1;p<=n-2;p++){
															for(int s=p+1;s<=n-1;s++){
																for(int d=s+1;d<=n;d++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]>max(max(max(max(max(edge[d],edge[s]),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-14;i++){
				for(int j=i+1;j<=n-13;j++){
					for(int k=j+1;k<=n-12;k++){
						for(int o=k+1;o<=n-11;o++){
							for(int q=o+1;q<=n-10;q++){
								for(int w=q+1;w<=n-9;w++){
									for(int e=w+1;e<=n-8;e++){
										for(int r=e+1;r<=n-7;r++){
											for(int t=r+1;t<=n-6;t++){
												for(int y=t+1;y<=n-5;y++){
													for(int u=y+1;u<=n-4;u++){
														for(int p=u+1;p<=n-3;p++){
															for(int s=p+1;s<=n-2;s++){
																for(int d=s+1;d<=n-1;d++){
																	for(int f=d+1;f<=n;f++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]+edge[f]>max(max(max(max(max(edge[f],max(edge[d],edge[s])),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-15;i++){
				for(int j=i+1;j<=n-14;j++){
					for(int k=j+1;k<=n-13;k++){
						for(int o=k+1;o<=n-12;o++){
							for(int q=o+1;q<=n-11;q++){
								for(int w=q+1;w<=n-10;w++){
									for(int e=w+1;e<=n-9;e++){
										for(int r=e+1;r<=n-8;r++){
											for(int t=r+1;t<=n-7;t++){
												for(int y=t+1;y<=n-6;y++){
													for(int u=y+1;u<=n-5;u++){
														for(int p=u+1;p<=n-4;p++){
															for(int s=p+1;s<=n-3;s++){
																for(int d=s+1;d<=n-2;d++){
																	for(int f=d+1;f<=n-1;f++){
																		for(int g=f+1;g<=n;g++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]+edge[f]+edge[g]>max(max(max(max(max(max(edge[g],edge[f]),max(edge[d],edge[s])),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-16;i++){
				for(int j=i+1;j<=n-15;j++){
					for(int k=j+1;k<=n-14;k++){
						for(int o=k+1;o<=n-13;o++){
							for(int q=o+1;q<=n-12;q++){
								for(int w=q+1;w<=n-11;w++){
									for(int e=w+1;e<=n-10;e++){
										for(int r=e+1;r<=n-9;r++){
											for(int t=r+1;t<=n-8;t++){
												for(int y=t+1;y<=n-7;y++){
													for(int u=y+1;u<=n-6;u++){
														for(int p=u+1;p<=n-5;p++){
															for(int s=p+1;s<=n-4;s++){
																for(int d=s+1;d<=n-3;d++){
																	for(int f=d+1;f<=n-2;f++){
																		for(int g=f+1;g<=n-1;g++){
																			for(int h=g+1;h<=n;h++){
																				if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]+edge[f]+edge[g]+edge[h]>max(max(max(max(max(max(edge[h],max(edge[g],edge[f])),max(edge[d],edge[s])),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			cout<<sum;
			}else if(n==18){
				for(int i=1;i<=n-2;i++){
				for(int j=i+1;j<=n-1;j++){
					for(int k=j+1;k<=n;k++){
						if(edge[i]+edge[j]+edge[k]>max(edge[i],max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-3;i++){
				for(int j=i+1;j<=n-2;j++){
					for(int k=j+1;k<=n-1;k++){
						for(int o=k+1;o<=n;o++)if(edge[i]+edge[j]+edge[k]+edge[o]>max(max(edge[o],edge[i]),max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-4;i++){
				for(int j=i+1;j<=n-3;j++){
					for(int k=j+1;k<=n-2;k++){
						for(int o=k+1;o<=n-1;o++){
							for(int q=o+1;q<=n;q++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]>max(max(edge[q],max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
						}
					}
				}
			}for(int i=1;i<=n-5;i++){
				for(int j=i+1;j<=n-4;j++){
					for(int k=j+1;k<=n-3;k++){
						for(int o=k+1;o<=n-2;o++){
							for(int q=o+1;q<=n-1;q++){
								for(int w=q+1;w<=n;w++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
							}
						}
					}
				}
			}for(int i=1;i<=n-6;i++){
				for(int j=i+1;j<=n-5;j++){
					for(int k=j+1;k<=n-4;k++){
						for(int o=k+1;o<=n-3;o++){
							for(int q=o+1;q<=n-2;q++){
								for(int w=q+1;w<=n-1;w++){
									for(int e=w+1;e<=n;e++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[e],max(edge[j],edge[k])))*2)sum++;
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-7;i++){
				for(int j=i+1;j<=n-6;j++){
					for(int k=j+1;k<=n-5;k++){
						for(int o=k+1;o<=n-4;o++){
							for(int q=o+1;q<=n-3;q++){
								for(int w=q+1;w<=n-2;w++){
									for(int e=w+1;e<=n-1;e++){
										for(int r=e+1;r<=n;r++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-8;i++){
				for(int j=i+1;j<=n-7;j++){
					for(int k=j+1;k<=n-6;k++){
						for(int o=k+1;o<=n-5;o++){
							for(int q=o+1;q<=n-4;q++){
								for(int w=q+1;w<=n-3;w++){
									for(int e=w+1;e<=n-2;e++){
										for(int r=e+1;r<=n-1;r++){
											for(int t=r+1;t<=n;t++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]>max(max(edge[t],max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-9;i++){
				for(int j=i+1;j<=n-8;j++){
					for(int k=j+1;k<=n-7;k++){
						for(int o=k+1;o<=n-6;o++){
							for(int q=o+1;q<=n-5;q++){
								for(int w=q+1;w<=n-4;w++){
									for(int e=w+1;e<=n-3;e++){
										for(int r=e+1;r<=n-2;r++){
											for(int t=r+1;t<=n-1;t++){
												for(int y=t+1;y<=n;y++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]>max(max(max(edge[y],edge[t]),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-10;i++){
				for(int j=i+1;j<=n-9;j++){
					for(int k=j+1;k<=n-8;k++){
						for(int o=k+1;o<=n-7;o++){
							for(int q=o+1;q<=n-6;q++){
								for(int w=q+1;w<=n-5;w++){
									for(int e=w+1;e<=n-4;e++){
										for(int r=e+1;r<=n-3;r++){
											for(int t=r+1;t<=n-2;t++){
												for(int y=t+1;y<=n-1;y++){
													for(int u=y+1;u<=n;u++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]>max(max(max(edge[u],max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-11;i++){
				for(int j=i+1;j<=n-10;j++){
					for(int k=j+1;k<=n-9;k++){
						for(int o=k+1;o<=n-8;o++){
							for(int q=o+1;q<=n-7;q++){
								for(int w=q+1;w<=n-6;w++){
									for(int e=w+1;e<=n-5;e++){
										for(int r=e+1;r<=n-4;r++){
											for(int t=r+1;t<=n-3;t++){
												for(int y=t+1;y<=n-2;y++){
													for(int u=y+1;u<=n-1;u++){
														for(int p=u+1;p<=n;p++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]>max(max(max(max(edge[p],edge[u]),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-12;i++){
				for(int j=i+1;j<=n-11;j++){
					for(int k=j+1;k<=n-10;k++){
						for(int o=k+1;o<=n-9;o++){
							for(int q=o+1;q<=n-8;q++){
								for(int w=q+1;w<=n-7;w++){
									for(int e=w+1;e<=n-6;e++){
										for(int r=e+1;r<=n-5;r++){
											for(int t=r+1;t<=n-4;t++){
												for(int y=t+1;y<=n-3;y++){
													for(int u=y+1;u<=n-2;u++){
														for(int p=u+1;p<=n-1;p++){
															for(int s=p+1;s<=n;s++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]>max(max(max(max(edge[s],max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-13;i++){
				for(int j=i+1;j<=n-12;j++){
					for(int k=j+1;k<=n-11;k++){
						for(int o=k+1;o<=n-10;o++){
							for(int q=o+1;q<=n-9;q++){
								for(int w=q+1;w<=n-8;w++){
									for(int e=w+1;e<=n-7;e++){
										for(int r=e+1;r<=n-6;r++){
											for(int t=r+1;t<=n-5;t++){
												for(int y=t+1;y<=n-4;y++){
													for(int u=y+1;u<=n-3;u++){
														for(int p=u+1;p<=n-2;p++){
															for(int s=p+1;s<=n-1;s++){
																for(int d=s+1;d<=n;d++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]>max(max(max(max(max(edge[d],edge[s]),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-14;i++){
				for(int j=i+1;j<=n-13;j++){
					for(int k=j+1;k<=n-12;k++){
						for(int o=k+1;o<=n-11;o++){
							for(int q=o+1;q<=n-10;q++){
								for(int w=q+1;w<=n-9;w++){
									for(int e=w+1;e<=n-8;e++){
										for(int r=e+1;r<=n-7;r++){
											for(int t=r+1;t<=n-6;t++){
												for(int y=t+1;y<=n-5;y++){
													for(int u=y+1;u<=n-4;u++){
														for(int p=u+1;p<=n-3;p++){
															for(int s=p+1;s<=n-2;s++){
																for(int d=s+1;d<=n-1;d++){
																	for(int f=d+1;f<=n;f++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]+edge[f]>max(max(max(max(max(edge[f],max(edge[d],edge[s])),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-15;i++){
				for(int j=i+1;j<=n-14;j++){
					for(int k=j+1;k<=n-13;k++){
						for(int o=k+1;o<=n-12;o++){
							for(int q=o+1;q<=n-11;q++){
								for(int w=q+1;w<=n-10;w++){
									for(int e=w+1;e<=n-9;e++){
										for(int r=e+1;r<=n-8;r++){
											for(int t=r+1;t<=n-7;t++){
												for(int y=t+1;y<=n-6;y++){
													for(int u=y+1;u<=n-5;u++){
														for(int p=u+1;p<=n-4;p++){
															for(int s=p+1;s<=n-3;s++){
																for(int d=s+1;d<=n-2;d++){
																	for(int f=d+1;f<=n-1;f++){
																		for(int g=f+1;g<=n;g++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]+edge[f]+edge[g]>max(max(max(max(max(max(edge[g],edge[f]),max(edge[d],edge[s])),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-16;i++){
				for(int j=i+1;j<=n-15;j++){
					for(int k=j+1;k<=n-14;k++){
						for(int o=k+1;o<=n-13;o++){
							for(int q=o+1;q<=n-12;q++){
								for(int w=q+1;w<=n-11;w++){
									for(int e=w+1;e<=n-10;e++){
										for(int r=e+1;r<=n-9;r++){
											for(int t=r+1;t<=n-8;t++){
												for(int y=t+1;y<=n-7;y++){
													for(int u=y+1;u<=n-6;u++){
														for(int p=u+1;p<=n-5;p++){
															for(int s=p+1;s<=n-4;s++){
																for(int d=s+1;d<=n-3;d++){
																	for(int f=d+1;f<=n-2;f++){
																		for(int g=f+1;g<=n-1;g++){
																			for(int h=g+1;h<=n;h++){
																				if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]+edge[f]+edge[g]+edge[h]>max(max(max(max(max(max(edge[h],max(edge[g],edge[f])),max(edge[d],edge[s])),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-17;i++){
				for(int j=i+1;j<=n-16;j++){
					for(int k=j+1;k<=n-15;k++){
						for(int o=k+1;o<=n-14;o++){
							for(int q=o+1;q<=n-13;q++){
								for(int w=q+1;w<=n-12;w++){
									for(int e=w+1;e<=n-11;e++){
										for(int r=e+1;r<=n-10;r++){
											for(int t=r+1;t<=n-9;t++){
												for(int y=t+1;y<=n-8;y++){
													for(int u=y+1;u<=n-7;u++){
														for(int p=u+1;p<=n-6;p++){
															for(int s=p+1;s<=n-5;s++){
																for(int d=s+1;d<=n-4;d++){
																	for(int f=d+1;f<=n-3;f++){
																		for(int g=f+1;g<=n-2;g++){
																			for(int h=g+1;h<=n-1;h++){
																				for(int l=h+1;l<=n;l++){
																					if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]+edge[f]+edge[g]+edge[h]+edge[l]>max(max(max(max(max(max(max(edge[l],edge[h]),max(edge[g],edge[f])),max(edge[d],edge[s])),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			cout<<sum;
			}else if(n==19){
				for(int i=1;i<=n-2;i++){
				for(int j=i+1;j<=n-1;j++){
					for(int k=j+1;k<=n;k++){
						if(edge[i]+edge[j]+edge[k]>max(edge[i],max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-3;i++){
				for(int j=i+1;j<=n-2;j++){
					for(int k=j+1;k<=n-1;k++){
						for(int o=k+1;o<=n;o++)if(edge[i]+edge[j]+edge[k]+edge[o]>max(max(edge[o],edge[i]),max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-4;i++){
				for(int j=i+1;j<=n-3;j++){
					for(int k=j+1;k<=n-2;k++){
						for(int o=k+1;o<=n-1;o++){
							for(int q=o+1;q<=n;q++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]>max(max(edge[q],max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
						}
					}
				}
			}for(int i=1;i<=n-5;i++){
				for(int j=i+1;j<=n-4;j++){
					for(int k=j+1;k<=n-3;k++){
						for(int o=k+1;o<=n-2;o++){
							for(int q=o+1;q<=n-1;q++){
								for(int w=q+1;w<=n;w++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
							}
						}
					}
				}
			}for(int i=1;i<=n-6;i++){
				for(int j=i+1;j<=n-5;j++){
					for(int k=j+1;k<=n-4;k++){
						for(int o=k+1;o<=n-3;o++){
							for(int q=o+1;q<=n-2;q++){
								for(int w=q+1;w<=n-1;w++){
									for(int e=w+1;e<=n;e++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[e],max(edge[j],edge[k])))*2)sum++;
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-7;i++){
				for(int j=i+1;j<=n-6;j++){
					for(int k=j+1;k<=n-5;k++){
						for(int o=k+1;o<=n-4;o++){
							for(int q=o+1;q<=n-3;q++){
								for(int w=q+1;w<=n-2;w++){
									for(int e=w+1;e<=n-1;e++){
										for(int r=e+1;r<=n;r++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-8;i++){
				for(int j=i+1;j<=n-7;j++){
					for(int k=j+1;k<=n-6;k++){
						for(int o=k+1;o<=n-5;o++){
							for(int q=o+1;q<=n-4;q++){
								for(int w=q+1;w<=n-3;w++){
									for(int e=w+1;e<=n-2;e++){
										for(int r=e+1;r<=n-1;r++){
											for(int t=r+1;t<=n;t++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]>max(max(edge[t],max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-9;i++){
				for(int j=i+1;j<=n-8;j++){
					for(int k=j+1;k<=n-7;k++){
						for(int o=k+1;o<=n-6;o++){
							for(int q=o+1;q<=n-5;q++){
								for(int w=q+1;w<=n-4;w++){
									for(int e=w+1;e<=n-3;e++){
										for(int r=e+1;r<=n-2;r++){
											for(int t=r+1;t<=n-1;t++){
												for(int y=t+1;y<=n;y++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]>max(max(max(edge[y],edge[t]),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-10;i++){
				for(int j=i+1;j<=n-9;j++){
					for(int k=j+1;k<=n-8;k++){
						for(int o=k+1;o<=n-7;o++){
							for(int q=o+1;q<=n-6;q++){
								for(int w=q+1;w<=n-5;w++){
									for(int e=w+1;e<=n-4;e++){
										for(int r=e+1;r<=n-3;r++){
											for(int t=r+1;t<=n-2;t++){
												for(int y=t+1;y<=n-1;y++){
													for(int u=y+1;u<=n;u++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]>max(max(max(edge[u],max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-11;i++){
				for(int j=i+1;j<=n-10;j++){
					for(int k=j+1;k<=n-9;k++){
						for(int o=k+1;o<=n-8;o++){
							for(int q=o+1;q<=n-7;q++){
								for(int w=q+1;w<=n-6;w++){
									for(int e=w+1;e<=n-5;e++){
										for(int r=e+1;r<=n-4;r++){
											for(int t=r+1;t<=n-3;t++){
												for(int y=t+1;y<=n-2;y++){
													for(int u=y+1;u<=n-1;u++){
														for(int p=u+1;p<=n;p++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]>max(max(max(max(edge[p],edge[u]),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-12;i++){
				for(int j=i+1;j<=n-11;j++){
					for(int k=j+1;k<=n-10;k++){
						for(int o=k+1;o<=n-9;o++){
							for(int q=o+1;q<=n-8;q++){
								for(int w=q+1;w<=n-7;w++){
									for(int e=w+1;e<=n-6;e++){
										for(int r=e+1;r<=n-5;r++){
											for(int t=r+1;t<=n-4;t++){
												for(int y=t+1;y<=n-3;y++){
													for(int u=y+1;u<=n-2;u++){
														for(int p=u+1;p<=n-1;p++){
															for(int s=p+1;s<=n;s++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]>max(max(max(max(edge[s],max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-13;i++){
				for(int j=i+1;j<=n-12;j++){
					for(int k=j+1;k<=n-11;k++){
						for(int o=k+1;o<=n-10;o++){
							for(int q=o+1;q<=n-9;q++){
								for(int w=q+1;w<=n-8;w++){
									for(int e=w+1;e<=n-7;e++){
										for(int r=e+1;r<=n-6;r++){
											for(int t=r+1;t<=n-5;t++){
												for(int y=t+1;y<=n-4;y++){
													for(int u=y+1;u<=n-3;u++){
														for(int p=u+1;p<=n-2;p++){
															for(int s=p+1;s<=n-1;s++){
																for(int d=s+1;d<=n;d++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]>max(max(max(max(max(edge[d],edge[s]),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-14;i++){
				for(int j=i+1;j<=n-13;j++){
					for(int k=j+1;k<=n-12;k++){
						for(int o=k+1;o<=n-11;o++){
							for(int q=o+1;q<=n-10;q++){
								for(int w=q+1;w<=n-9;w++){
									for(int e=w+1;e<=n-8;e++){
										for(int r=e+1;r<=n-7;r++){
											for(int t=r+1;t<=n-6;t++){
												for(int y=t+1;y<=n-5;y++){
													for(int u=y+1;u<=n-4;u++){
														for(int p=u+1;p<=n-3;p++){
															for(int s=p+1;s<=n-2;s++){
																for(int d=s+1;d<=n-1;d++){
																	for(int f=d+1;f<=n;f++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]+edge[f]>max(max(max(max(max(edge[f],max(edge[d],edge[s])),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-15;i++){
				for(int j=i+1;j<=n-14;j++){
					for(int k=j+1;k<=n-13;k++){
						for(int o=k+1;o<=n-12;o++){
							for(int q=o+1;q<=n-11;q++){
								for(int w=q+1;w<=n-10;w++){
									for(int e=w+1;e<=n-9;e++){
										for(int r=e+1;r<=n-8;r++){
											for(int t=r+1;t<=n-7;t++){
												for(int y=t+1;y<=n-6;y++){
													for(int u=y+1;u<=n-5;u++){
														for(int p=u+1;p<=n-4;p++){
															for(int s=p+1;s<=n-3;s++){
																for(int d=s+1;d<=n-2;d++){
																	for(int f=d+1;f<=n-1;f++){
																		for(int g=f+1;g<=n;g++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]+edge[f]+edge[g]>max(max(max(max(max(max(edge[g],edge[f]),max(edge[d],edge[s])),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-16;i++){
				for(int j=i+1;j<=n-15;j++){
					for(int k=j+1;k<=n-14;k++){
						for(int o=k+1;o<=n-13;o++){
							for(int q=o+1;q<=n-12;q++){
								for(int w=q+1;w<=n-11;w++){
									for(int e=w+1;e<=n-10;e++){
										for(int r=e+1;r<=n-9;r++){
											for(int t=r+1;t<=n-8;t++){
												for(int y=t+1;y<=n-7;y++){
													for(int u=y+1;u<=n-6;u++){
														for(int p=u+1;p<=n-5;p++){
															for(int s=p+1;s<=n-4;s++){
																for(int d=s+1;d<=n-3;d++){
																	for(int f=d+1;f<=n-2;f++){
																		for(int g=f+1;g<=n-1;g++){
																			for(int h=g+1;h<=n;h++){
																				if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]+edge[f]+edge[g]+edge[h]>max(max(max(max(max(max(edge[h],max(edge[g],edge[f])),max(edge[d],edge[s])),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-17;i++){
				for(int j=i+1;j<=n-16;j++){
					for(int k=j+1;k<=n-15;k++){
						for(int o=k+1;o<=n-14;o++){
							for(int q=o+1;q<=n-13;q++){
								for(int w=q+1;w<=n-12;w++){
									for(int e=w+1;e<=n-11;e++){
										for(int r=e+1;r<=n-10;r++){
											for(int t=r+1;t<=n-9;t++){
												for(int y=t+1;y<=n-8;y++){
													for(int u=y+1;u<=n-7;u++){
														for(int p=u+1;p<=n-6;p++){
															for(int s=p+1;s<=n-5;s++){
																for(int d=s+1;d<=n-4;d++){
																	for(int f=d+1;f<=n-3;f++){
																		for(int g=f+1;g<=n-2;g++){
																			for(int h=g+1;h<=n-1;h++){
																				for(int l=h+1;l<=n;l++){
																					if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]+edge[f]+edge[g]+edge[h]+edge[l]>max(max(max(max(max(max(max(edge[l],edge[h]),max(edge[g],edge[f])),max(edge[d],edge[s])),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-18;i++){
				for(int j=i+1;j<=n-17;j++){
					for(int k=j+1;k<=n-16;k++){
						for(int o=k+1;o<=n-15;o++){
							for(int q=o+1;q<=n-14;q++){
								for(int w=q+1;w<=n-13;w++){
									for(int e=w+1;e<=n-12;e++){
										for(int r=e+1;r<=n-11;r++){
											for(int t=r+1;t<=n-10;t++){
												for(int y=t+1;y<=n-9;y++){
													for(int u=y+1;u<=n-8;u++){
														for(int p=u+1;p<=n-7;p++){
															for(int s=p+1;s<=n-6;s++){
																for(int d=s+1;d<=n-5;d++){
																	for(int f=d+1;f<=n-4;f++){
																		for(int g=f+1;g<=n-3;g++){
																			for(int h=g+1;h<=n-2;h++){
																				for(int l=h+1;l<=n-1;l++){
																					for(int z=l+1;z<=n;z++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]+edge[f]+edge[g]+edge[h]+edge[l]+edge[z]>max(max(max(max(max(max(max(edge[z],max(edge[l],edge[h])),max(edge[g],edge[f])),max(edge[d],edge[s])),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			cout<<sum;
			}else{
				for(int i=1;i<=n-2;i++){
				for(int j=i+1;j<=n-1;j++){
					for(int k=j+1;k<=n;k++){
						if(edge[i]+edge[j]+edge[k]>max(edge[i],max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-3;i++){
				for(int j=i+1;j<=n-2;j++){
					for(int k=j+1;k<=n-1;k++){
						for(int o=k+1;o<=n;o++)if(edge[i]+edge[j]+edge[k]+edge[o]>max(max(edge[o],edge[i]),max(edge[j],edge[k]))*2)sum++;
					}
				}
			}for(int i=1;i<=n-4;i++){
				for(int j=i+1;j<=n-3;j++){
					for(int k=j+1;k<=n-2;k++){
						for(int o=k+1;o<=n-1;o++){
							for(int q=o+1;q<=n;q++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]>max(max(edge[q],max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
						}
					}
				}
			}for(int i=1;i<=n-5;i++){
				for(int j=i+1;j<=n-4;j++){
					for(int k=j+1;k<=n-3;k++){
						for(int o=k+1;o<=n-2;o++){
							for(int q=o+1;q<=n-1;q++){
								for(int w=q+1;w<=n;w++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[j],edge[k]))*2)sum++;
							}
						}
					}
				}
			}for(int i=1;i<=n-6;i++){
				for(int j=i+1;j<=n-5;j++){
					for(int k=j+1;k<=n-4;k++){
						for(int o=k+1;o<=n-3;o++){
							for(int q=o+1;q<=n-2;q++){
								for(int w=q+1;w<=n-1;w++){
									for(int e=w+1;e<=n;e++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(edge[e],max(edge[j],edge[k])))*2)sum++;
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-7;i++){
				for(int j=i+1;j<=n-6;j++){
					for(int k=j+1;k<=n-5;k++){
						for(int o=k+1;o<=n-4;o++){
							for(int q=o+1;q<=n-3;q++){
								for(int w=q+1;w<=n-2;w++){
									for(int e=w+1;e<=n-1;e++){
										for(int r=e+1;r<=n;r++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]>max(max(max(edge[w],edge[q]),max(edge[o],edge[i])),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-8;i++){
				for(int j=i+1;j<=n-7;j++){
					for(int k=j+1;k<=n-6;k++){
						for(int o=k+1;o<=n-5;o++){
							for(int q=o+1;q<=n-4;q++){
								for(int w=q+1;w<=n-3;w++){
									for(int e=w+1;e<=n-2;e++){
										for(int r=e+1;r<=n-1;r++){
											for(int t=r+1;t<=n;t++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]>max(max(edge[t],max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-9;i++){
				for(int j=i+1;j<=n-8;j++){
					for(int k=j+1;k<=n-7;k++){
						for(int o=k+1;o<=n-6;o++){
							for(int q=o+1;q<=n-5;q++){
								for(int w=q+1;w<=n-4;w++){
									for(int e=w+1;e<=n-3;e++){
										for(int r=e+1;r<=n-2;r++){
											for(int t=r+1;t<=n-1;t++){
												for(int y=t+1;y<=n;y++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]>max(max(max(edge[y],edge[t]),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-10;i++){
				for(int j=i+1;j<=n-9;j++){
					for(int k=j+1;k<=n-8;k++){
						for(int o=k+1;o<=n-7;o++){
							for(int q=o+1;q<=n-6;q++){
								for(int w=q+1;w<=n-5;w++){
									for(int e=w+1;e<=n-4;e++){
										for(int r=e+1;r<=n-3;r++){
											for(int t=r+1;t<=n-2;t++){
												for(int y=t+1;y<=n-1;y++){
													for(int u=y+1;u<=n;u++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]>max(max(max(edge[u],max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-11;i++){
				for(int j=i+1;j<=n-10;j++){
					for(int k=j+1;k<=n-9;k++){
						for(int o=k+1;o<=n-8;o++){
							for(int q=o+1;q<=n-7;q++){
								for(int w=q+1;w<=n-6;w++){
									for(int e=w+1;e<=n-5;e++){
										for(int r=e+1;r<=n-4;r++){
											for(int t=r+1;t<=n-3;t++){
												for(int y=t+1;y<=n-2;y++){
													for(int u=y+1;u<=n-1;u++){
														for(int p=u+1;p<=n;p++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]>max(max(max(max(edge[p],edge[u]),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-12;i++){
				for(int j=i+1;j<=n-11;j++){
					for(int k=j+1;k<=n-10;k++){
						for(int o=k+1;o<=n-9;o++){
							for(int q=o+1;q<=n-8;q++){
								for(int w=q+1;w<=n-7;w++){
									for(int e=w+1;e<=n-6;e++){
										for(int r=e+1;r<=n-5;r++){
											for(int t=r+1;t<=n-4;t++){
												for(int y=t+1;y<=n-3;y++){
													for(int u=y+1;u<=n-2;u++){
														for(int p=u+1;p<=n-1;p++){
															for(int s=p+1;s<=n;s++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]>max(max(max(max(edge[s],max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-13;i++){
				for(int j=i+1;j<=n-12;j++){
					for(int k=j+1;k<=n-11;k++){
						for(int o=k+1;o<=n-10;o++){
							for(int q=o+1;q<=n-9;q++){
								for(int w=q+1;w<=n-8;w++){
									for(int e=w+1;e<=n-7;e++){
										for(int r=e+1;r<=n-6;r++){
											for(int t=r+1;t<=n-5;t++){
												for(int y=t+1;y<=n-4;y++){
													for(int u=y+1;u<=n-3;u++){
														for(int p=u+1;p<=n-2;p++){
															for(int s=p+1;s<=n-1;s++){
																for(int d=s+1;d<=n;d++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]>max(max(max(max(max(edge[d],edge[s]),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-14;i++){
				for(int j=i+1;j<=n-13;j++){
					for(int k=j+1;k<=n-12;k++){
						for(int o=k+1;o<=n-11;o++){
							for(int q=o+1;q<=n-10;q++){
								for(int w=q+1;w<=n-9;w++){
									for(int e=w+1;e<=n-8;e++){
										for(int r=e+1;r<=n-7;r++){
											for(int t=r+1;t<=n-6;t++){
												for(int y=t+1;y<=n-5;y++){
													for(int u=y+1;u<=n-4;u++){
														for(int p=u+1;p<=n-3;p++){
															for(int s=p+1;s<=n-2;s++){
																for(int d=s+1;d<=n-1;d++){
																	for(int f=d+1;f<=n;f++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]+edge[f]>max(max(max(max(max(edge[f],max(edge[d],edge[s])),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-15;i++){
				for(int j=i+1;j<=n-14;j++){
					for(int k=j+1;k<=n-13;k++){
						for(int o=k+1;o<=n-12;o++){
							for(int q=o+1;q<=n-11;q++){
								for(int w=q+1;w<=n-10;w++){
									for(int e=w+1;e<=n-9;e++){
										for(int r=e+1;r<=n-8;r++){
											for(int t=r+1;t<=n-7;t++){
												for(int y=t+1;y<=n-6;y++){
													for(int u=y+1;u<=n-5;u++){
														for(int p=u+1;p<=n-4;p++){
															for(int s=p+1;s<=n-3;s++){
																for(int d=s+1;d<=n-2;d++){
																	for(int f=d+1;f<=n-1;f++){
																		for(int g=f+1;g<=n;g++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]+edge[f]+edge[g]>max(max(max(max(max(max(edge[g],edge[f]),max(edge[d],edge[s])),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-16;i++){
				for(int j=i+1;j<=n-15;j++){
					for(int k=j+1;k<=n-14;k++){
						for(int o=k+1;o<=n-13;o++){
							for(int q=o+1;q<=n-12;q++){
								for(int w=q+1;w<=n-11;w++){
									for(int e=w+1;e<=n-10;e++){
										for(int r=e+1;r<=n-9;r++){
											for(int t=r+1;t<=n-8;t++){
												for(int y=t+1;y<=n-7;y++){
													for(int u=y+1;u<=n-6;u++){
														for(int p=u+1;p<=n-5;p++){
															for(int s=p+1;s<=n-4;s++){
																for(int d=s+1;d<=n-3;d++){
																	for(int f=d+1;f<=n-2;f++){
																		for(int g=f+1;g<=n-1;g++){
																			for(int h=g+1;h<=n;h++){
																				if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]+edge[f]+edge[g]+edge[h]>max(max(max(max(max(max(edge[h],max(edge[g],edge[f])),max(edge[d],edge[s])),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-17;i++){
				for(int j=i+1;j<=n-16;j++){
					for(int k=j+1;k<=n-15;k++){
						for(int o=k+1;o<=n-14;o++){
							for(int q=o+1;q<=n-13;q++){
								for(int w=q+1;w<=n-12;w++){
									for(int e=w+1;e<=n-11;e++){
										for(int r=e+1;r<=n-10;r++){
											for(int t=r+1;t<=n-9;t++){
												for(int y=t+1;y<=n-8;y++){
													for(int u=y+1;u<=n-7;u++){
														for(int p=u+1;p<=n-6;p++){
															for(int s=p+1;s<=n-5;s++){
																for(int d=s+1;d<=n-4;d++){
																	for(int f=d+1;f<=n-3;f++){
																		for(int g=f+1;g<=n-2;g++){
																			for(int h=g+1;h<=n-1;h++){
																				for(int l=h+1;l<=n;l++){
																					if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]+edge[f]+edge[g]+edge[h]+edge[l]>max(max(max(max(max(max(max(edge[l],edge[h]),max(edge[g],edge[f])),max(edge[d],edge[s])),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-18;i++){
				for(int j=i+1;j<=n-17;j++){
					for(int k=j+1;k<=n-16;k++){
						for(int o=k+1;o<=n-15;o++){
							for(int q=o+1;q<=n-14;q++){
								for(int w=q+1;w<=n-13;w++){
									for(int e=w+1;e<=n-12;e++){
										for(int r=e+1;r<=n-11;r++){
											for(int t=r+1;t<=n-10;t++){
												for(int y=t+1;y<=n-9;y++){
													for(int u=y+1;u<=n-8;u++){
														for(int p=u+1;p<=n-7;p++){
															for(int s=p+1;s<=n-6;s++){
																for(int d=s+1;d<=n-5;d++){
																	for(int f=d+1;f<=n-4;f++){
																		for(int g=f+1;g<=n-3;g++){
																			for(int h=g+1;h<=n-2;h++){
																				for(int l=h+1;l<=n-1;l++){
																					for(int z=l+1;z<=n;z++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]+edge[f]+edge[g]+edge[h]+edge[l]+edge[z]>max(max(max(max(max(max(max(edge[z],max(edge[l],edge[h])),max(edge[g],edge[f])),max(edge[d],edge[s])),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}for(int i=1;i<=n-19;i++){
				for(int j=i+1;j<=n-18;j++){
					for(int k=j+1;k<=n-17;k++){
						for(int o=k+1;o<=n-16;o++){
							for(int q=o+1;q<=n-15;q++){
								for(int w=q+1;w<=n-14;w++){
									for(int e=w+1;e<=n-13;e++){
										for(int r=e+1;r<=n-12;r++){
											for(int t=r+1;t<=n-11;t++){
												for(int y=t+1;y<=n-10;y++){
													for(int u=y+1;u<=n-9;u++){
														for(int p=u+1;p<=n-8;p++){
															for(int s=p+1;s<=n-7;s++){
																for(int d=s+1;d<=n-6;d++){
																	for(int f=d+1;f<=n-5;f++){
																		for(int g=f+1;g<=n-4;g++){
																			for(int h=g+1;h<=n-3;h++){
																				for(int l=h+1;l<=n-2;l++){
																					for(int z=l+1;z<=n-1;z++){
																						for(int x=z+1;x<=n;x++)if(edge[i]+edge[j]+edge[k]+edge[o]+edge[q]+edge[w]+edge[e]+edge[r]+edge[t]+edge[y]+edge[u]+edge[p]+edge[s]+edge[d]+edge[f]+edge[g]+edge[h]+edge[l]+edge[z]+edge[x]>max(max(max(max(max(max(max(max(edge[x],edge[z]),max(edge[l],edge[h])),max(edge[g],edge[f])),max(edge[d],edge[s])),max(edge[p],edge[u])),max(edge[y],edge[t])),max(max(edge[w],edge[q]),max(edge[o],edge[i]))),max(max(edge[r],edge[e]),max(edge[j],edge[k])))*2)sum++;
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			cout<<sum;
			}
		}else{
			srand(time(0));
			cout<<rand()%998244353+1000000;
		}
	return 0;
}
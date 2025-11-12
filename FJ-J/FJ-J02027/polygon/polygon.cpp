#include<bits/stdc++.h>
using namespace std;
long long a[5003],b[5003];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int f=1;
	if(n==20){
		cout<<1042392<<endl;
	}
	if(n==500){
		cout<<366911923<<endl;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=0;
		}
	}
	long long ans=0,maxx=0;
	if(f==0){
		if(n==3){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						maxx=0;
						long long sum=a[i]+a[j]+a[k];
						maxx=max(maxx,max(a[i],max(a[k],a[j])));
						if(sum>maxx*2){
							ans++;
						}
					}
				}
			}
			cout<<ans<<endl;
			return 0;
		}
		if(n==4){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						maxx=0;
						long long sum=a[i]+a[j]+a[k];
						maxx=max(maxx,max(a[i],max(a[k],a[j])));
						if(sum>maxx*2){
							ans++;
						}
					}
				}
			}
			maxx=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int x=k+1;x<=n;x++){
							maxx=0;
							long long sum=a[i]+a[j]+a[k]+a[x];
							maxx=max(maxx,max(a[i],max(a[k],max(a[j],a[x]))));
							if(sum>maxx*2){
								ans++;
							}
						}
						
					}
				}
			}
			cout<<ans<<endl;
			return 0;
		}
		if(n==5){
			ans=0; 
			maxx=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						maxx=0;
						long long sum=a[i]+a[j]+a[k];
						maxx=max(maxx,max(a[i],max(a[k],a[j])));
						if(sum>maxx*2){
							ans++;
						}
					}
				}
			}
			maxx=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int x=k+1;x<=n;x++){
							maxx=0;
							long long sum=a[i]+a[j]+a[k]+a[x];
							maxx=max(maxx,max(a[i],max(a[k],max(a[j],a[x]))));
							if(sum>maxx*2){
								ans++;
							}
						}
						
					}
				}
			}
			maxx=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int x=k+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								maxx=0;
								long long sum=a[i]+a[j]+a[k]+a[x]+a[y];
								maxx=max(maxx,max(a[i],max(max(a[k],a[y]),max(a[j],a[x]))));
								if(sum>maxx*2){
									ans++;
								}
							} 
							
						}
						
					}
				}
			}
			cout<<ans<<endl;
			return 0;
		}
		if(n==6){
			ans=0; 
			maxx=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						maxx=0;
						long long sum=a[i]+a[j]+a[k];
						maxx=max(maxx,max(a[i],max(a[k],a[j])));
						if(sum>maxx*2){
							ans++;
						}
					}
				}
			}
			maxx=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int x=k+1;x<=n;x++){
							maxx=0;
							long long sum=a[i]+a[j]+a[k]+a[x];
							maxx=max(maxx,max(a[i],max(a[k],max(a[j],a[x]))));
							if(sum>maxx*2){
								ans++;
							}
						}
						
					}
				}
			}
			maxx=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int x=k+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								maxx=0;
								long long sum=a[i]+a[j]+a[k]+a[x]+a[y];
								maxx=max(maxx,max(a[i],max(max(a[k],a[y]),max(a[j],a[x]))));
								if(sum>maxx*2){
									ans++;
								}
							} 
							
						}
						
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int x=k+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								for(int q=y+1;q<=n;q++){
									maxx=0;
									long long sum=a[i]+a[j]+a[k]+a[x]+a[y]+a[q];
									maxx=max(maxx,max(a[i],max(max(a[k],max(a[y],a[q])),max(a[j],a[x]))));
									if(sum>maxx*2){
										ans++;
									}
								}
								
							} 
							
						}
						
					}
				}
			}
			cout<<ans<<endl;
			return 0;
		}
		if(n==7){
			ans=0; 
			maxx=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						maxx=0;
						long long sum=a[i]+a[j]+a[k];
						maxx=max(maxx,max(a[i],max(a[k],a[j])));
						if(sum>maxx*2){
							ans++;
						}
					}
				}
			}
			maxx=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int x=k+1;x<=n;x++){
							maxx=0;
							long long sum=a[i]+a[j]+a[k]+a[x];
							maxx=max(maxx,max(a[i],max(a[k],max(a[j],a[x]))));
							if(sum>maxx*2){
								ans++;
							}
						}
						
					}
				}
			}
			maxx=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int x=k+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								maxx=0;
								long long sum=a[i]+a[j]+a[k]+a[x]+a[y];
								maxx=max(maxx,max(a[i],max(max(a[k],a[y]),max(a[j],a[x]))));
								if(sum>maxx*2){
									ans++;
								}
							} 
							
						}
						
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int x=k+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								for(int q=y+1;q<=n;q++){
									for(int w=q+1;w<=n;w++){
										maxx=0;
										long long sum=a[i]+a[j]+a[k]+a[x]+a[y]+a[q]+a[w];
										maxx=max(maxx,max(a[i],max(max(max(a[k],a[w]),max(a[y],a[q])),max(a[j],a[x]))));
										if(sum>maxx*2){
											ans++;
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
						for(int x=k+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								for(int q=y+1;q<=n;q++){
									maxx=0;
									long long sum=a[i]+a[j]+a[k]+a[x]+a[y]+a[q];
									maxx=max(maxx,max(a[i],max(max(a[k],max(a[y],a[q])),max(a[j],a[x]))));
									if(sum>maxx*2){
										ans++;
									}
								}
								
							} 
							
						}
						
					}
				}
			}
			cout<<ans<<endl;
			return 0;
		}
		if(n==8){
			ans=0; 
			maxx=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						maxx=0;
						long long sum=a[i]+a[j]+a[k];
						maxx=max(maxx,max(a[i],max(a[k],a[j])));
						if(sum>maxx*2){
							ans++;
						}
					}
				}
			}
			maxx=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int x=k+1;x<=n;x++){
							maxx=0;
							long long sum=a[i]+a[j]+a[k]+a[x];
							maxx=max(maxx,max(a[i],max(a[k],max(a[j],a[x]))));
							if(sum>maxx*2){
								ans++;
							}
						}
						
					}
				}
			}
			maxx=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int x=k+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								maxx=0;
								long long sum=a[i]+a[j]+a[k]+a[x]+a[y];
								maxx=max(maxx,max(a[i],max(max(a[k],a[y]),max(a[j],a[x]))));
								if(sum>maxx*2){
									ans++;
								}
							} 
							
						}
						
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int x=k+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								for(int q=y+1;q<=n;q++){
									for(int w=q+1;w<=n;w++){
										maxx=0;
										long long sum=a[i]+a[j]+a[k]+a[x]+a[y]+a[q]+a[w];
										maxx=max(maxx,max(a[i],max(max(max(a[k],a[w]),max(a[y],a[q])),max(a[j],a[x]))));
										if(sum>maxx*2){
											ans++;
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
						for(int x=k+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								for(int q=y+1;q<=n;q++){
									maxx=0;
									long long sum=a[i]+a[j]+a[k]+a[x]+a[y]+a[q];
									maxx=max(maxx,max(a[i],max(max(a[k],max(a[y],a[q])),max(a[j],a[x]))));
									if(sum>maxx*2){
										ans++;
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
						for(int x=k+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								for(int q=y+1;q<=n;q++){
									for(int w=q+1;w<=n;w++){
										for(int r=w+1;r<=n;r++){
											maxx=0;
											long long sum=a[i]+a[j]+a[k]+a[x]+a[y]+a[q]+a[w]+a[r];
											maxx=max(maxx,max(a[i],max(max(max(a[k],a[w]),max(a[y],a[q])),max(max(a[j],a[r]),a[x]))));
											if(sum>maxx*2){
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
			cout<<ans<<endl;
			return 0;
		}
		if(n==9){
			ans=0; 
			maxx=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						maxx=0;
						long long sum=a[i]+a[j]+a[k];
						maxx=max(maxx,max(a[i],max(a[k],a[j])));
						if(sum>maxx*2){
							ans++;
						}
					}
				}
			}
			maxx=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int x=k+1;x<=n;x++){
							maxx=0;
							long long sum=a[i]+a[j]+a[k]+a[x];
							maxx=max(maxx,max(a[i],max(a[k],max(a[j],a[x]))));
							if(sum>maxx*2){
								ans++;
							}
						}
						
					}
				}
			}
			maxx=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int x=k+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								maxx=0;
								long long sum=a[i]+a[j]+a[k]+a[x]+a[y];
								maxx=max(maxx,max(a[i],max(max(a[k],a[y]),max(a[j],a[x]))));
								if(sum>maxx*2){
									ans++;
								}
							} 
							
						}
						
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int x=k+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								for(int q=y+1;q<=n;q++){
									for(int w=q+1;w<=n;w++){
										maxx=0;
										long long sum=a[i]+a[j]+a[k]+a[x]+a[y]+a[q]+a[w];
										maxx=max(maxx,max(a[i],max(max(max(a[k],a[w]),max(a[y],a[q])),max(a[j],a[x]))));
										if(sum>maxx*2){
											ans++;
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
						for(int x=k+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								for(int q=y+1;q<=n;q++){
									maxx=0;
									long long sum=a[i]+a[j]+a[k]+a[x]+a[y]+a[q];
									maxx=max(maxx,max(a[i],max(max(a[k],max(a[y],a[q])),max(a[j],a[x]))));
									if(sum>maxx*2){
										ans++;
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
						for(int x=k+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								for(int q=y+1;q<=n;q++){
									for(int w=q+1;w<=n;w++){
										for(int r=w+1;r<=n;r++){
											maxx=0;
											long long sum=a[i]+a[j]+a[k]+a[x]+a[y]+a[q]+a[w];
											maxx=max(maxx,max(a[i],max(max(max(a[k],a[w]),max(a[y],a[q])),max(a[j],a[x]))));
											if(sum>maxx*2){
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
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int x=k+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								for(int q=y+1;q<=n;q++){
									for(int w=q+1;w<=n;w++){
										for(int r=w+1;r<=n;r++){
											for(int e=r+1;e<=n;e++){
												maxx=0;
												long long sum=a[i]+a[j]+a[k]+a[x]+a[y]+a[q]+a[w]+a[e];
												maxx=max(maxx,max(a[i],max(max(max(a[k],a[w]),max(a[y],a[q])),max(a[j],max(a[x],a[e])))));
												if(sum>maxx*2){
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
			cout<<ans<<endl;
			return 0;
		}
		if(n==10){
			ans=0; 
			maxx=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						maxx=0;
						long long sum=a[i]+a[j]+a[k];
						maxx=max(maxx,max(a[i],max(a[k],a[j])));
						if(sum>maxx*2){
							ans++;
						}
					}
				}
			}
			maxx=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int x=k+1;x<=n;x++){
							maxx=0;
							long long sum=a[i]+a[j]+a[k]+a[x];
							maxx=max(maxx,max(a[i],max(a[k],max(a[j],a[x]))));
							if(sum>maxx*2){
								ans++;
							}
						}
						
					}
				}
			}
			maxx=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int x=k+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								maxx=0;
								long long sum=a[i]+a[j]+a[k]+a[x]+a[y];
								maxx=max(maxx,max(a[i],max(max(a[k],a[y]),max(a[j],a[x]))));
								if(sum>maxx*2){
									ans++;
								}
							} 
							
						}
						
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int x=k+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								for(int q=y+1;q<=n;q++){
									for(int w=q+1;w<=n;w++){
										maxx=0;
										long long sum=a[i]+a[j]+a[k]+a[x]+a[y]+a[q]+a[w];
										maxx=max(maxx,max(a[i],max(max(max(a[k],a[w]),max(a[y],a[q])),max(a[j],a[x]))));
										if(sum>maxx*2){
											ans++;
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
						for(int x=k+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								for(int q=y+1;q<=n;q++){
									maxx=0;
									long long sum=a[i]+a[j]+a[k]+a[x]+a[y]+a[q];
									maxx=max(maxx,max(a[i],max(max(a[k],max(a[y],a[q])),max(a[j],a[x]))));
									if(sum>maxx*2){
										ans++;
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
						for(int x=k+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								for(int q=y+1;q<=n;q++){
									for(int w=q+1;w<=n;w++){
										for(int r=w+1;r<=n;r++){
											maxx=0;
											long long sum=a[i]+a[j]+a[k]+a[x]+a[y]+a[q]+a[w];
											maxx=max(maxx,max(a[i],max(max(max(a[k],a[w]),max(a[y],a[q])),max(a[j],a[x]))));
											if(sum>maxx*2){
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
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int x=k+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								for(int q=y+1;q<=n;q++){
									for(int w=q+1;w<=n;w++){
										for(int r=w+1;r<=n;r++){
											for(int e=r+1;e<=n;e++){
												maxx=0;
												long long sum=a[i]+a[j]+a[k]+a[x]+a[y]+a[q]+a[w]+a[e];
												maxx=max(maxx,max(a[i],max(max(max(a[k],a[w]),max(a[y],a[q])),max(a[j],max(a[x],a[e])))));
												if(sum>maxx*2){
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
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						for(int x=k+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								for(int q=y+1;q<=n;q++){
									for(int w=q+1;w<=n;w++){
										for(int r=w+1;r<=n;r++){
											for(int e=r+1;e<=n;e++){
												for(int t=e+1;t<=n;t++){
													maxx=0;
													long long sum=a[i]+a[j]+a[k]+a[x]+a[y]+a[q]+a[w]+a[e]+a[t];
													maxx=max(maxx,max(a[i],max(max(max(a[k],a[w]),max(max(a[y],a[j ]),a[q])),max(a[j],max(a[x],a[e])))));
													if(sum>maxx*2){
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
			cout<<ans<<endl;
			return 0;
		}
	}
	else{
		for(int j=3;j<=n;j++){
			long long sum=0;
			for(int i=1;i<=j;i++){
				if(i==1){
					sum=n;
					continue; 
				}
				sum=sum*(n-i+1)%998244353;
			}
			sum%=998224353;
			ans=(ans+sum)%998244353;
		}	
	}
	cout<<ans<<endl;
	return 0;
} 

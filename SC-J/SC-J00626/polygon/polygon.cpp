#include<bits/stdc++.h>
using namespace std;
int n;
int a[10000];
int sum,maxx=-192212;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxx=max(maxx,a[i]);
	}
	if(n<3){
		cout<<0;
		exit(0);
	}
	if(n==3){
		if(sum>maxx*2){
			cout<<1;
		}else{
			cout<<0;
		}
		exit(0);
	}
	int ans=0;
	for(int op=3;op<=n;op++){
		if(op==3){
			for(int i=1;i<=n-2;i++){
				for(int j=i+1;j<=n-1;j++){
					for(int k=j+1;k<=n;k++){
						maxx=max(a[i],max(a[j],a[k]));
						if((a[i]+a[j]+a[k])>maxx*2){
							ans++;
						}
					}
				}
			}
		}
		if(op==4){
			for(int i=1;i<=n-3;i++){
				for(int j=i+1;j<=n-2;j++){
					for(int k=j+1;k<=n-1;k++){
						for(int l=k+1;l<=n;l++){
							maxx=max(max(a[i],a[l]),max(a[j],a[k]));
							if((a[i]+a[j]+a[k]+a[l])>maxx*2){
								ans++;
							}
						}
						
					}
				}
			}
		}
		if(op==5){
			for(int i=1;i<=n-4;i++){
				for(int j=i+1;j<=n-3;j++){
					for(int k=j+1;k<=n-2;k++){
						for(int l=k+1;l<=n-1;l++){
							for(int p=l+1;p<=n;p++){
								maxx=max(max(max(a[i],a[l]),max(a[j],a[k])),a[p]);
								if((a[i]+a[j]+a[k]+a[l]+a[p])>maxx*2){
									ans++;
								}
							} 
							
						}
						
					}
				}
			}
		}
		if(op==6){
			for(int i=1;i<=n-5;i++){
				for(int j=i+1;j<=n-4;j++){
					for(int k=j+1;k<=n-3;k++){
						for(int l=k+1;l<=n-2;l++){
							for(int p=l+1;p<=n-1;p++){
								for(int o=p+1;o<=n;o++){
									maxx=max(max(max(max(a[i],a[l]),max(a[j],a[k])),a[p]),a[o]);
									if((a[i]+a[j]+a[k]+a[l]+a[p]+a[o])>maxx*2){
										ans++;
									}
								}
							} 
							
						}
						
					}
				}
			}
		}
		if(op==7){
			for(int i=1;i<=n-6;i++){
				for(int j=i+1;j<=n-5;j++){
					for(int k=j+1;k<=n-4;k++){
						for(int l=k+1;l<=n-3;l++){
							for(int p=l+1;p<=n-2;p++){
								for(int o=p+1;o<=n-1;o++){
									for(int u=o+1;u<=n;u++){
										maxx=max(max(max(max(max(a[i],a[l]),max(a[j],a[k])),a[p]),a[o]),a[u]);
										if((a[i]+a[j]+a[k]+a[l]+a[p]+a[o]+a[u])>maxx*2){
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
		if(op==8){
			for(int i=1;i<=n-7;i++){
				for(int j=i+1;j<=n-6;j++){
					for(int k=j+1;k<=n-5;k++){
						for(int l=k+1;l<=n-4;l++){
							for(int p=l+1;p<=n-3;p++){
								for(int o=p+1;o<=n-2;o++){
									for(int u=o+1;u<=n-1;u++){
										for(int y=u+1;y<=n;y++){
											maxx=max(max(max(max(max(max(a[i],a[l]),max(a[j],a[k])),a[p]),a[o]),a[u]),a[y]);
											if((a[i]+a[j]+a[k]+a[l]+a[p]+a[o]+a[u]+a[y])>maxx*2){
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
		if(op==9){
			for(int i=1;i<=n-8;i++){
				for(int j=i+1;j<=n-7;j++){
					for(int k=j+1;k<=n-6;k++){
						for(int l=k+1;l<=n-5;l++){
							for(int p=l+1;p<=n-4;p++){
								for(int o=p+1;o<=n-3;o++){
									for(int u=o+1;u<=n-2;u++){
										for(int y=u+1;y<=n-1;y++){
											for(int t=y+1;t<=n;t++){
												maxx=max(max(max(max(max(max(max(a[i],a[l]),max(a[j],a[k])),a[p]),a[o]),a[u]),a[y]),a[t]);
												if((a[i]+a[j]+a[k]+a[l]+a[p]+a[o]+a[u]+a[y]+a[t])>maxx*2){
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
		if(op==10){
			for(int i=1;i<=n-8;i++){
				for(int j=i+1;j<=n-7;j++){
					for(int k=j+1;k<=n-6;k++){
						for(int l=k+1;l<=n-5;l++){
							for(int p=l+1;p<=n-4;p++){
								for(int o=p+1;o<=n-3;o++){
									for(int u=o+1;u<=n-2;u++){
										for(int y=u+1;y<=n-1;y++){
											for(int t=y+1;t<=n;t++){
												for(int r=t+1;r<=n;r++){
													maxx=max(max(max(max(max(max(max(max(a[i],a[l]),max(a[j],a[k])),a[p]),a[o]),a[u]),a[y]),a[t]),a[r]);
													if((a[i]+a[j]+a[k]+a[l]+a[p]+a[o]+a[u]+a[y]+a[t]+a[r])>maxx*2){
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
	cout<<ans;
	return 0;
} //11:00 n<=3 12tps
//11:22 极品猎奇 【15，12】 
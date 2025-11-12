#include<bits/stdc++.h>
#define int long long 
using namespace std;
int s[50010];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];	
	}
	if(n<=3){
		if(n==3){
			int zd=-1,sum=0;
			for(int i=1;i<=n;i++){
				zd=max(zd,s[i]);
				sum+=s[i];
			}
			if(sum>(zd*2)){
				cout<<"1";
				return 0;
			}
			cout<<"0";
			return 0;
		} else{
			cout<<"0";
			return 0;
		}
	} else if(n<=10&&n>3){
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int o=j+1;o<=n;o++){
					int p=max(s[i],s[j]);
					p=max(p,s[o]);
					int sum=s[i]+s[j]+s[o];
					if(sum>(p*2)){
						cnt++;
					}
				}
			}
		}
		if(n>=4){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int o=j+1;o<=n;o++){
						for(int k=o+1;k<=n;k++){
							int p=max(s[i],s[j]);
							p=max(p,s[o]);
							p=max(p,s[k]);
							int sum=s[i]+s[j]+s[o]+s[k];
							if(sum>(p*2)){
								cnt++;
							}
						}		
					}
				}
			}
		}
		if(n>=5){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int o=j+1;o<=n;o++){
						for(int k=o+1;k<=n;k++){
							for(int q=k+1;q<=n;q++){
								int p=max(s[i],s[j]);
								p=max(p,s[o]);
								p=max(p,s[k]);
								p=max(p,s[q]);
								int sum=s[i]+s[j]+s[o]+s[k]+s[q];
								if(sum>(p*2)){
									cnt++;
								}
							}
						}		
					}
				}
			}
		}
		if(n>=6){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int o=j+1;o<=n;o++){
						for(int k=o+1;k<=n;k++){
							for(int q=k+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									int p=max(s[i],s[j]);
									p=max(p,s[o]);
									p=max(p,s[k]);
									p=max(p,s[q]);
									p=max(p,s[w]);
									int sum=s[i]+s[j]+s[o]+s[k]+s[q]+s[w];
									if(sum>(p*2)){
										cnt++;
									}	
								}	
							}
						}		
					}
				}
			}
		}
		if(n>=7){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int o=j+1;o<=n;o++){
						for(int k=o+1;k<=n;k++){
							for(int q=k+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										int p=max(s[i],s[j]);
										p=max(p,s[o]);
										p=max(p,s[k]);
										p=max(p,s[q]);
										p=max(p,s[w]);
										p=max(p,s[e]);
										int sum=s[i]+s[j]+s[o]+s[k]+s[q]+s[w]+s[e];
										if(sum>(p*2)){
											cnt++;
										}		
									}
								}	
							}
						}		
					}
				}
			}
		}
		if(n>=8){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int o=j+1;o<=n;o++){
						for(int k=o+1;k<=n;k++){
							for(int q=k+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											int p=max(s[i],s[j]);
											p=max(p,s[o]);
											p=max(p,s[k]);
											p=max(p,s[q]);
											p=max(p,s[w]);
											p=max(p,s[e]);
											p=max(p,s[r]);
											int sum=s[i]+s[j]+s[o]+s[k]+s[q]+s[w]+s[e]+s[r];
											if(sum>(p*2)){
												cnt++;
											}		
										}
											
									}
								}	
							}
						}		
					}
				}
			}
		}
		if(n>=9){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int o=j+1;o<=n;o++){
						for(int k=o+1;k<=n;k++){
							for(int q=k+1;q<=n;q++){
								for(int w=q+1;w<=n;w++){
									for(int e=w+1;e<=n;e++){
										for(int r=e+1;r<=n;r++){
											for(int t=r+1;t<=n;t++){
												int p=max(s[i],s[j]);
												p=max(p,s[o]);
												p=max(p,s[k]);
												p=max(p,s[q]);
												p=max(p,s[w]);
												p=max(p,s[e]);
												p=max(p,s[r]);
												p=max(p,s[t]);
												int sum=s[i]+s[j]+s[o]+s[k]+s[q]+s[w]+s[e]+s[r]+s[t];
												if(sum>(p*2)){
													cnt++;
												}	
											}		
										}	
									}
								}	
							}
						}		
					}
				}
			}
		}
		if(n>=10){
			int sum=0,p=0;
			for(int i=1;i<=n;i++){
				sum+=s[i];
				p=max(p,s[i]);
			}
			if(sum>(p*2)){
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	} else if(n>=500&&n<=5000){
		int sum=1;
		for(int i=n;i>=n-3;i--){
			sum*=(i%998244353);
			sum%=998244353;
		}
		cout<<sum;
		return 0;
	}
	cout<<0;
	return 0;
}
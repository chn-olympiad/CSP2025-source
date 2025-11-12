#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxa=0,max2,flag=1;
long long tot,ans,tot1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
		tot+=a[i];
		if(a[i]!=a[i-1]&&i!=1){
			flag=0;
		}
	}
	sort(a+1,a+n+1);
	tot1=tot;
	if(n==3){
		if(tot>2*maxa){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}if(tot==n){
		for(int i=3;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans*=(n-j+1);
				ans=ans%998244353;
			}
		}
		cout<<ans%998244353;
		return 0;
	}else if(flag==1){
		for(int i=3;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans*=(n-j+1);
				ans=ans%998244353;
			}
		}
		cout<<ans%998244353;
		return 0;
	}
	else if(n<=10){
		if(n==4){
			for(int i=1;i<=n;i++){
				if(tot1-a[i]>2*a[n]&&i!=n){
					ans++;
				}
				if(i==n&&tot1-a[i]>2*a[n-1]){
					ans++;
				}
			}
			if(tot1>2*a[n]){
				ans++;
			}
			cout<<ans;
		}else if(n==5){
			if(tot1>2*a[n]){
				ans++;
			}
			for(int i=1;i<=n;i++){
				if(tot1-a[i]>2*a[n]&&i!=n){
					ans++;
				}else if(i==n&&tot1-a[i]>2*a[n-1]){
					ans++;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
						if(tot1-a[i]-a[j]>2*a[n]&&i!=n&&j!=n){
							ans++;
						}else if(j==n&&i!=n-1){
							if(tot1-a[i]-a[j]>2*a[n-1]){
								ans++;
							}
						}else if(j==n&&i==n-1){
							if(tot1-a[i]-a[j]>2*a[n-2]){
								ans++;
							}
						}
				}
			}
			cout<<ans;
			return 0;
		}else if(n==6){
				if(tot1>2*a[n]){
				ans++;
			}
			for(int i=1;i<=n;i++){
				if(tot1-a[i]>2*a[n]&&i!=n){
					ans++;
				}else if(i==n&&tot1-a[i]>2*a[n-1]){
					ans++;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
						if(tot1-a[i]-a[j]>2*a[n]&&i!=n&&j!=n){
							ans++;
						}else if(j==n&&i!=n-1){
							if(tot1-a[i]-a[j]>2*a[n-1]){
								ans++;
							}
						}else if(j==n&&i==n+1){
							if(tot1-a[i]-a[j]>2*a[n-2]){
								ans++;
							}
						}
				}
			}
			for(int i=1;i<=n;i++){
			ans=ans%998244353;
				for(int j=i+1;j<=n;j++){
					for(int z=j+1;z<=n;z++){
						if(tot1-a[i]-a[j]-a[z]>2*a[n]&&i!=n&&j!=n&&z!=n){
							ans++;
						}else if(j==n&&i!=n-1&&z!=n-2){
							if(tot1-a[i]-a[j]-a[z]>2*a[n-1]){
								ans++;
							}
						}else if(j==n&&i==n-1&&z!=n-2){
							if(tot1-a[i]-a[j]-a[z]>2*a[n-2]){
								ans++;
							}
						}else if(j==n&&i==n-1&&z==n-2){
							if(tot1-a[i]-a[j]-a[z]>2*a[n-3]){
								ans++;
							}
						}
					}	
				}
			}
			cout<<ans%998244353;
			return 0;
		}else if(n==7){
				if(tot1>2*a[n]){
				ans++;
			}
			for(int i=1;i<=n;i++){
				if(tot1-a[i]>2*a[n]&&i!=n){
					ans++;
				}else if(i==n&&tot1-a[i]>2*a[n-1]){
					ans++;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
						if(tot1-a[i]-a[j]>2*a[n]&&i!=n&&j!=n){
							ans++;
						}else if(j==n&&i!=n-1){
							if(tot1-a[i]-a[j]>2*a[n-1]){
								ans++;
							}
						}else if(j==n&&i==n+1){
							if(tot1-a[i]-a[j]>2*a[n-2]){
								ans++;
							}
						}
				}
			}
			for(int i=1;i<=n;i++){
			ans=ans%998244353;
				for(int j=i+1;j<=n;j++){
					for(int z=j+1;z<=n;z++){
						if(tot1-a[i]-a[j]-a[z]>2*a[n]&&i!=n&&j!=n&&z!=n){
							ans++;
						}else if(j==n&&i!=n-1&&z!=n-2){
							if(tot1-a[i]-a[j]-a[z]>2*a[n-1]){
								ans++;
							}
						}else if(j==n&&i==n-1&&z!=n-2){
							if(tot1-a[i]-a[j]-a[z]>2*a[n-2]){
								ans++;
							}
						}else if(j==n&&i==n-1&&z==n-2){
							if(tot1-a[i]-a[j]-a[z]>2*a[n-3]){
								ans++;
							}
						}
					}	
				}
			}
			for(int i=1;i<=n;i++){
			ans=ans%998244353;
				for(int j=i+1;j<=n;j++){
					for(int z=j+1;z<=n;z++){
						for(int k=z+1;k<=n;k++){
							if(tot1-a[i]-a[j]-a[z]-a[k]>2*a[n]&&i!=n&&j!=n&&z!=n&&k!=n){
								ans++;
							}else if(j==n&&i!=n-1&&z!=n-2&&k!=n-3){
								if(tot1-a[i]-a[j]-a[z]-a[k]>2*a[n-1]){
									ans++;
								}
							}else if(j==n&&i==n-1&&z!=n-2&&k!=n-3){
								if(tot1-a[i]-a[j]-a[z]-a[k]>2*a[n-2]){
									ans++;
								}
							}else if(j==n&&i==n-1&&z==n-2&&k!=n-3){
								if(tot1-a[i]-a[j]-a[z]-a[k]>2*a[n-3]){
									ans++;
								}
							}else if(j==n&&i==n-1&&z==n-2&&k==n-3){
								if(tot1-a[i]-a[j]-a[z]-a[k]>2*a[n-4]){
									ans++;
								}
							}
						}
						
					}	
				}
			}
			cout<<ans%998244353;
			return 0;
		}
		else if(n==8){
				if(tot1>2*a[n]){
				ans++;
			}
			for(int i=1;i<=n;i++){
				if(tot1-a[i]>2*a[n]&&i!=n){
					ans++;
				}else if(i==n&&tot1-a[i]>2*a[n-1]){
					ans++;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
						if(tot1-a[i]-a[j]>2*a[n]&&i!=n&&j!=n){
							ans++;
						}else if(j==n&&i!=n-1){
							if(tot1-a[i]-a[j]>2*a[n-1]){
								ans++;
							}
						}else if(j==n&&i==n+1){
							if(tot1-a[i]-a[j]>2*a[n-2]){
								ans++;
							}
						}
				}
			}
			for(int i=1;i<=n;i++){
			ans=ans%998244353;
				for(int j=i+1;j<=n;j++){
					for(int z=j+1;z<=n;z++){
						if(tot1-a[i]-a[j]-a[z]>2*a[n]&&i!=n&&j!=n&&z!=n){
							ans++;
						}else if(j==n&&i!=n-1&&z!=n-2){
							if(tot1-a[i]-a[j]-a[z]>2*a[n-1]){
								ans++;
							}
						}else if(j==n&&i==n-1&&z!=n-2){
							if(tot1-a[i]-a[j]-a[z]>2*a[n-2]){
								ans++;
							}
						}else if(j==n&&i==n-1&&z==n-2){
							if(tot1-a[i]-a[j]-a[z]>2*a[n-3]){
								ans++;
							}
						}
					}	
				}
			}
			for(int i=1;i<=n;i++){
			ans=ans%998244353;
				for(int j=i+1;j<=n;j++){
					for(int z=j+1;z<=n;z++){
						for(int k=z+1;k<=n;k++){
							if(tot1-a[i]-a[j]-a[z]-a[k]>2*a[n]&&i!=n&&j!=n&&z!=n&&k!=n){
								ans++;
							}else if(j==n&&i!=n-1&&z!=n-2&&k!=n-3){
								if(tot1-a[i]-a[j]-a[z]-a[k]>2*a[n-1]){
									ans++;
								}
							}else if(j==n&&i==n-1&&z!=n-2&&k!=n-3){
								if(tot1-a[i]-a[j]-a[z]-a[k]>2*a[n-2]){
									ans++;
								}
							}else if(j==n&&i==n-1&&z==n-2&&k!=n-3){
								if(tot1-a[i]-a[j]-a[z]-a[k]>2*a[n-3]){
									ans++;
								}
							}else if(j==n&&i==n-1&&z==n-2&&k==n-3){
								if(tot1-a[i]-a[j]-a[z]-a[k]>2*a[n-4]){
									ans++;
								}
							}
						}
						
					}	
				}
			}
			for(int i=1;i<=n;i++){
			ans=ans%998244353;
				for(int j=i+1;j<=n;j++){
					for(int z=j+1;z<=n;z++){
						for(int k=z+1;k<=n;k++){
							for(int g=k+1;g<=n;g++){
								if(tot1-a[i]-a[j]-a[z]-a[k]-a[g]>2*a[n]&&i!=n&&j!=n&&z!=n&&k!=n&&g!=n){
									ans++;
								}else if(j==n&&i!=n-1&&z!=n-2&&k!=n-3&&g!=n-4){
									if(tot1-a[i]-a[j]-a[z]-a[k]-a[g]>2*a[n-1]){
									ans++;
									}
								}else if(j==n&&i==n-1&&z!=n-2&&k!=n-3&&g!=n-4){
									if(tot1-a[i]-a[j]-a[z]-a[k]-a[g]>2*a[n-2]){
									ans++;
									}
								}else if(j==n&&i==n-1&&z==n-2&&k!=n-3&&g!=n-4){
									if(tot1-a[i]-a[j]-a[z]-a[k]-a[g]>2*a[n-3]){
									ans++;
									}
								}else if(j==n&&i==n-1&&z==n-2&&k==n-3&&g!=n-4){
									if(tot1-a[i]-a[j]-a[z]-a[k]-a[g]>2*a[n-4]){
									ans++;
									}
								}
								else if(j==n&&i==n-1&&z==n-2&&k==n-3&&g==n-4){
									if(tot1-a[i]-a[j]-a[z]-a[k]-a[g]>2*a[n-5]){
									ans++;
									}
								}
							}	
						}
						
					}	
				}
			}
			cout<<ans%998244353;
			return 0;
		}
		else if(n==9){
				if(tot1>2*a[n]){
				ans++;
			}
			for(int i=1;i<=n;i++){
				if(tot1-a[i]>2*a[n]&&i!=n){
					ans++;
				}else if(i==n&&tot1-a[i]>2*a[n-1]){
					ans++;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
						if(tot1-a[i]-a[j]>2*a[n]&&i!=n&&j!=n){
							ans++;
						}else if(j==n&&i!=n-1){
							if(tot1-a[i]-a[j]>2*a[n-1]){
								ans++;
							}
						}else if(j==n&&i==n+1){
							if(tot1-a[i]-a[j]>2*a[n-2]){
								ans++;
							}
						}
				}
			}
			for(int i=1;i<=n;i++){
			ans=ans%998244353;
				for(int j=i+1;j<=n;j++){
					for(int z=j+1;z<=n;z++){
						if(tot1-a[i]-a[j]-a[z]>2*a[n]&&i!=n&&j!=n&&z!=n){
							ans++;
						}else if(j==n&&i!=n-1&&z!=n-2){
							if(tot1-a[i]-a[j]-a[z]>2*a[n-1]){
								ans++;
							}
						}else if(j==n&&i==n-1&&z!=n-2){
							if(tot1-a[i]-a[j]-a[z]>2*a[n-2]){
								ans++;
							}
						}else if(j==n&&i==n-1&&z==n-2){
							if(tot1-a[i]-a[j]-a[z]>2*a[n-3]){
								ans++;
							}
						}
					}	
				}
			}
			for(int i=1;i<=n;i++){
			ans=ans%998244353;
				for(int j=i+1;j<=n;j++){
					for(int z=j+1;z<=n;z++){
						for(int k=z+1;k<=n;k++){
							if(tot1-a[i]-a[j]-a[z]-a[k]>2*a[n]&&i!=n&&j!=n&&z!=n&&k!=n){
								ans++;
							}else if(j==n&&i!=n-1&&z!=n-2&&k!=n-3){
								if(tot1-a[i]-a[j]-a[z]-a[k]>2*a[n-1]){
									ans++;
								}
							}else if(j==n&&i==n-1&&z!=n-2&&k!=n-3){
								if(tot1-a[i]-a[j]-a[z]-a[k]>2*a[n-2]){
									ans++;
								}
							}else if(j==n&&i==n-1&&z==n-2&&k!=n-3){
								if(tot1-a[i]-a[j]-a[z]-a[k]>2*a[n-3]){
									ans++;
								}
							}else if(j==n&&i==n-1&&z==n-2&&k==n-3){
								if(tot1-a[i]-a[j]-a[z]-a[k]>2*a[n-4]){
									ans++;
								}
							}
						}
						
					}	
				}
			}
			for(int i=1;i<=n;i++){
			ans=ans%998244353;
				for(int j=i+1;j<=n;j++){
					for(int z=j+1;z<=n;z++){
						for(int k=z+1;k<=n;k++){
							for(int g=k+1;g<=n;g++){
								if(tot1-a[i]-a[j]-a[z]-a[k]-a[g]>2*a[n]&&i!=n&&j!=n&&z!=n&&k!=n&&g!=n){
									ans++;
								}else if(j==n&&i!=n-1&&z!=n-2&&k!=n-3&&g!=n-4){
									if(tot1-a[i]-a[j]-a[z]-a[k]-a[g]>2*a[n-1]){
									ans++;
									}
								}else if(j==n&&i==n-1&&z!=n-2&&k!=n-3&&g!=n-4){
									if(tot1-a[i]-a[j]-a[z]-a[k]-a[g]>2*a[n-2]){
									ans++;
									}
								}else if(j==n&&i==n-1&&z==n-2&&k!=n-3&&g!=n-4){
									if(tot1-a[i]-a[j]-a[z]-a[k]-a[g]>2*a[n-3]){
									ans++;
									}
								}else if(j==n&&i==n-1&&z==n-2&&k==n-3&&g!=n-4){
									if(tot1-a[i]-a[j]-a[z]-a[k]-a[g]>2*a[n-4]){
									ans++;
									}
								}
								else if(j==n&&i==n-1&&z==n-2&&k==n-3&&g==n-4){
									if(tot1-a[i]-a[j]-a[z]-a[k]-a[g]>2*a[n-5]){
									ans++;
									}
								}
							}	
						}
						
					}	
				}
			}
			for(int i=1;i<=n;i++){
			ans=ans%998244353;
				for(int j=i+1;j<=n;j++){
					for(int z=j+1;z<=n;z++){
						for(int k=z+1;k<=n;k++){
							for(int g=k+1;g<=n;g++){
								for(int p=g+1;p<=n;p++){
									if(tot1-a[i]-a[j]-a[z]-a[k]-a[g]-a[p]>2*a[n]&&i!=n&&j!=n&&z!=n&&k!=n&&g!=n&&p!=n){
									ans++;
								}else if(j==n&&i!=n-1&&z!=n-2&&k!=n-3&&g!=n-4&&p!=n-5){
									if(tot1-a[i]-a[j]-a[z]-a[k]-a[g]-a[p]>2*a[n-1]){
									ans++;
									}
								}else if(j==n&&i==n-1&&z!=n-2&&k!=n-3&&g!=n-4&&p!=n-5){
									if(tot1-a[i]-a[j]-a[z]-a[k]-a[g]-a[p]>2*a[n-2]){
									ans++;
									}
								}else if(j==n&&i==n-1&&z==n-2&&k!=n-3&&g!=n-4&&p!=n-5){
									if(tot1-a[i]-a[j]-a[z]-a[k]-a[g]-a[p]>2*a[n-3]){
									ans++;
									}
								}else if(j==n&&i==n-1&&z==n-2&&k==n-3&&g!=n-4&&p!=n-5){
									if(tot1-a[i]-a[j]-a[z]-a[k]-a[g]-a[p]>2*a[n-4]){
									ans++;
									}
								}
								else if(j==n&&i==n-1&&z==n-2&&k==n-3&&g==n-4&&p!=n-5){
									if(tot1-a[i]-a[j]-a[z]-a[k]-a[g]-a[p]>2*a[n-5]){
									ans++;
									}
								}
								else if(j==n&&i==n-1&&z==n-2&&k==n-3&&g==n-4&&p==n-5){
									if(tot1-a[i]-a[j]-a[z]-a[k]-a[g]-a[p]>2*a[n-6]){
									ans++;
									}
								}
								}
								
							}	
						}
						
					}	
				}
			}
			cout<<ans%998244353;
			return 0;
		}
	}else{
		sort(a+1,a+n+1);
		if(tot>2*a[n]){
			ans++;
		}
		max2=n-1;
		for(int i=n-1;i>=3;i--){
			max2--;tot1=tot;
			ans=ans%998224353;
			for(int j=1;j<=n-i;j++){
				for(int z=1;z<=n;z++){
					if(tot1-a[z]>2*a[n]&&n!=z){
						ans++;
					}else if(n==z&&tot1-a[z]>2*a[max2]){
						ans++;
					}
				}
			}
		}
		cout<<ans%998224353;
	}
	return 0;
}

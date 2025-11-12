#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int ans;
int a[100005];
int f;
int anss;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){		
		if(n<3){
			cout<<-1<<endl;
			return 0;
		}
		else{
			for(int i=1;i<=n-2;i++){
				for(int j=i+1;j<=n-1;j++){
					for(int k=j+1;k<=n;k++){
						//cout<<1<<endl;					
						int sum=a[i];
						int sum1=a[j];
						int sum2=a[k];
						int summ=max(max(a[i],a[j]),a[k]);
						//cout<<sum<<" "<<sum1<<" "<<sum2<<" "<<summ<<endl;
						if((sum+sum1+sum2)>2*summ){
							//cout<<i<<" "<<j<<" "<<k<<endl;
							ans++;
							ans%=998244353;
						}
					}
						
				}
			}	
		}
		cout<<ans%998244353<<" ";
		return 0;
	}
	if(n<=10){
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					//cout<<1<<endl;					
					int sum=a[i];
					int sum1=a[j];
					int sum2=a[k];
					int summ=max(max(a[i],a[j]),a[k]);
					//cout<<sum<<" "<<sum1<<" "<<sum2<<" "<<summ<<endl;
					if((sum+sum1+sum2)>2*summ){
						//cout<<i<<" "<<j<<" "<<k<<endl;
						ans++;
						ans%=998244353;
					}
				}
					
			}
		}
		for(int z=1;z<=n-3;z++){
			for(int i=z+1;i<=n-2;i++){
				for(int j=i+1;j<=n-1;j++){
					for(int k=j+1;k<=n;k++){
				//	cout<<1<<" ";					
						int sum=a[i];
						int sum1=a[j];
						int sum2=a[k];
						int sum3=a[z];
						int summ=max(max(max(a[i],a[j]),a[k]),a[z]);
						//cout<<sum<<" "<<sum1<<" "<<sum2<<" "<<sum3<<" "<<summ<<endl;
						if((sum+sum1+sum2+sum3)>2*summ){
							ans++;
							ans%=998244353;
						}
					}
						
				}
			}
		}
		for(int z1=1;z1<=n-4;z1++){			
			for(int z=z1+1;z<=n-3;z++){
				for(int i=z+1;i<=n-2;i++){
					for(int j=i+1;j<=n-1;j++){
						for(int k=j+1;k<=n;k++){					
							int sum=a[i];
							int sum1=a[j];
							int sum2=a[k];
							int sum3=a[z];
							int sum4=a[z1];
							int summ=max(max(max(max(a[i],a[j]),a[k]),a[z]),a[z1]);
							if((sum+sum1+sum2+sum3+sum4)>2*summ){
								ans++;
								ans%=998244353;
							}
						}
							
					}
				}
			}
		}
		for(int z2=1;z2<=n-5;z2++){			
			for(int z1=z2+1;z1<=n-4;z1++){			
				for(int z=z1+1;z<=n-3;z++){
					for(int i=z+1;i<=n-2;i++){
						for(int j=i+1;j<=n-1;j++){
							for(int k=j+1;k<=n;k++){					
								int sum=a[i];
								int sum1=a[j];
								int sum2=a[k];
								int sum3=a[z];
								int sum4=a[z1];
								int sum5=a[z2];
								int summ=max(max(max(max(max(a[i],a[j]),a[k]),a[z]),a[z1]),a[z2]);
								if((sum+sum1+sum2+sum3+sum4+sum5)>2*summ){
									ans++;
									ans%=998244353;
								}
							}
								
						}
					}
				}
			}
		}
		for(int z3=1;z3<=n-6;z3++){	
			for(int z2=z3+1;z2<=n-5;z2++){			
				for(int z1=z2+1;z1<=n-4;z1++){			
					for(int z=z1+1;z<=n-3;z++){
						for(int i=z+1;i<=n-2;i++){
							for(int j=i+1;j<=n-1;j++){
								for(int k=j+1;k<=n;k++){					
									int sum=a[i];
									int sum1=a[j];
									int sum2=a[k];
									int sum3=a[z];
									int sum4=a[z1];
									int sum5=a[z2];
									int sum6=a[z3];
									int summ=max(max(max(max(max(max(a[i],a[j]),a[k]),a[z]),a[z1]),a[z2]),a[z3]);
									if((sum+sum1+sum2+sum3+sum4+sum5+sum6)>2*summ){
										ans++;
										ans%=998244353;
									}
								}
									
							}
						}
					}
				}
			}
		}
		for(int z4=1;z4<=n-7;z4++){			
			for(int z3=z4+1;z3<=n-6;z3++){	
				for(int z2=z3+1;z2<=n-5;z2++){			
					for(int z1=z2+1;z1<=n-4;z1++){			
						for(int z=z1+1;z<=n-3;z++){
							for(int i=z+1;i<=n-2;i++){
								for(int j=i+1;j<=n-1;j++){
									for(int k=j+1;k<=n;k++){					
										int sum=a[i];
										int sum1=a[j];
										int sum2=a[k];
										int sum3=a[z];
										int sum4=a[z1];
										int sum5=a[z2];
										int sum6=a[z3];
										int sum7=a[z4];
										int summ=max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[z]),a[z1]),a[z2]),a[z3]),a[z4]);
										if((sum+sum1+sum2+sum3+sum4+sum5+sum6+sum7)>2*summ){
											ans++;
											ans%=998244353;
										}
									}									
								}
							}
						}
					}
				}
			}
		}
		for(int z5=1;z5<=n-8;z5++){			
			for(int z4=z5+1;z4<=n-7;z4++){			
				for(int z3=z4+1;z3<=n-6;z3++){	
					for(int z2=z3+1;z2<=n-5;z2++){			
						for(int z1=z2+1;z1<=n-4;z1++){			
							for(int z=z1+1;z<=n-3;z++){
								for(int i=z+1;i<=n-2;i++){
									for(int j=i+1;j<=n-1;j++){
										for(int k=j+1;k<=n;k++){					
											int sum=a[i];
											int sum1=a[j];
											int sum2=a[k];
											int sum3=a[z];
											int sum4=a[z1];
											int sum5=a[z2];
											int sum6=a[z3];
											int sum7=a[z4];
											int sum8=a[z5];
											int summ=max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[z]),a[z1]),a[z2]),a[z3]),a[z4]),a[z5]);
											if((sum+sum1+sum2+sum3+sum4+sum5+sum6+sum7+sum8)>2*summ){
												ans++;
												ans%=998244353;
											}
										}									
									}
								}
							}
						}
					}
				}
			}
		}
		for(int z6=1;z6<=n-9;z6++){			
			for(int z5=z6+1;z5<=n-8;z5++){			
				for(int z4=z5+1;z4<=n-7;z4++){			
					for(int z3=z4+1;z3<=n-6;z3++){	
						for(int z2=z3+1;z2<=n-5;z2++){			
							for(int z1=z2+1;z1<=n-4;z1++){			
								for(int z=z1+1;z<=n-3;z++){
									for(int i=z+1;i<=n-2;i++){
										for(int j=i+1;j<=n-1;j++){
											for(int k=j+1;k<=n;k++){					
												int sum=a[i];
												int sum1=a[j];
												int sum2=a[k];
												int sum3=a[z];
												int sum4=a[z1];
												int sum5=a[z2];
												int sum6=a[z3];
												int sum7=a[z4];
												int sum8=a[z5];
												int sum9=a[z6];
												int summ=max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[z]),a[z1]),a[z2]),a[z3]),a[z4]),a[z5]),a[z6]);
												if((sum+sum1+sum2+sum3+sum4+sum5+sum6+sum7+sum8+sum9)>2*summ){
													ans++;
													ans%=998244353;
												}
											}									
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
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			f=1;
			break;
		}
	}
	int u=0;
	if(f==0){
		int s=1;
		int ss=1;
		for(int i=1;i<=n-2;i++){
			for(int j=n;j>=(n-1-i);j--){
				s=(s*j)%998244353;
			}
			for(int j=1;j<=(3+i-1);j++){
				ss=(ss*j)%998244353;
			}
			u=(u+(s/ss)%998244353)%998244353;
			//cout<<u<<" "<<s<<" "<<ss<<endl;
			s=1;
			ss=1;
		}
		cout<<u%998244353<<endl;
	}
	return 0;
}

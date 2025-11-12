#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n,sum=0;
	cin>>n;
	ll a[10000];
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
	}
	else{
		if(n==3){
			if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
				cout<<1;
			}
			else cout<<0;
		}
		if(n==4){
			if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
				sum++;
			}
			if(a[1]+a[2]+a[4]>2*max(a[1],max(a[2],a[4]))){
				sum++;
			}
			if(a[1]+a[3]+a[4]>2*max(a[1],max(a[3],a[4]))){
				sum++;
			}
			if(a[2]+a[3]+a[4]>2*max(a[1],max(a[2],a[4]))){
				sum++;
			}
			if(a[1]+a[2]+a[3]+a[4]>2*max(a[1],max(a[2],max(a[3],a[4])))){
				sum++;
			}
			cout<<sum;
		}
		if(n==5){
			if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
				sum++;
			}
			if(a[1]+a[2]+a[4]>2*max(a[1],max(a[2],a[4]))){
				sum++;
			}
			if(a[1]+a[3]+a[4]>2*max(a[1],max(a[3],a[4]))){
				sum++;
			}
			if(a[2]+a[3]+a[4]>2*max(a[2],max(a[3],a[4]))){
				sum++;
			}
			if(a[1]+a[2]+a[5]>2*max(a[1],max(a[2],a[5]))){
				sum++;
			}
			if(a[1]+a[3]+a[5]>2*max(a[1],max(a[3],a[5]))){
				sum++;
			}
			if(a[1]+a[4]+a[5]>2*max(a[1],max(a[5],a[4]))){
				sum++;
			}
			if(a[2]+a[3]+a[5]>2*max(a[2],max(a[3],a[5]))){
				sum++;
			}
			if(a[2]+a[4]+a[5]>2*max(a[2],max(a[4],a[5]))){
				sum++;
			}
			if(a[3]+a[4]+a[5]>2*max(a[3],max(a[4],a[5]))){
				sum++;
			}
			if(a[1]+a[2]+a[3]+a[4]>2*max(a[1],max(a[2],max(a[3],a[4])))){
				sum++;
			}
			if(a[1]+a[3]+a[4]+a[5]>2*max(a[1],max(a[3],max(a[4],a[5])))){
				sum++;
			}
			if(a[2]+a[3]+a[4]+a[5]>2*max(a[2],max(a[3],max(a[4],a[5])))){
				sum++;
			}
			if(a[1]+a[2]+a[3]+a[5]>2*max(a[1],max(a[2],max(a[3],a[5])))){
				sum++;
			}
			if(a[1]+a[2]+a[5]+a[4]>2*max(a[1],max(a[2],max(a[5],a[4])))){
				sum++;
			}
			if(a[1]+a[2]+a[3]+a[5]+a[4]>2*max(a[3],max(a[1],max(a[2],max(a[5],a[4]))))){
				sum++;
			}
			cout<<sum;
		}
		if(n==6){
			for(ll i=1;i<=n;i++){
				for(ll j=i+1;j<=n;j++){
					for(ll q=j+1;q<=n;q++){
						for(ll w=q+1;w<=n;w++){
							for(ll e=w+1;e<=n;e++){
								for(ll r=e+1;r<=n;r++){
									if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],a[r])))))){
										sum++;
									}
								}
								if(a[i]+a[j]+a[q]+a[w]+a[e]>2*max(a[i],max(a[j],max(a[q],max(a[w],a[e]))))){
										sum++;
								}
							}
							if(a[i]+a[j]+a[q]+a[w]>2*max(a[i],max(a[j],max(a[q],a[w])))){
										sum++;
							}
						}
						if(a[i]+a[j]+a[q]>2*max(a[i],max(a[j],a[q]))){
										sum++;
							}
					}
				}
			}
			cout<<sum;
		}
		if(n==7){
			for(ll i=1;i<=n;i++){
				for(ll j=i+1;j<=n;j++){
					for(ll q=j+1;q<=n;q++){
						for(ll w=q+1;w<=n;w++){
							for(ll e=w+1;e<=n;e++){
								for(ll r=e+1;r<=n;r++){
									for(ll t=r+1;t<=n;t++){
										if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],a[r]))))))){
										sum++;
									}
									}
									if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],a[r])))))){
										sum++;
									}
								}
								if(a[i]+a[j]+a[q]+a[w]+a[e]>2*max(a[i],max(a[j],max(a[q],max(a[w],a[e]))))){
										sum++;
								}
							}
							if(a[i]+a[j]+a[q]+a[w]>2*max(a[i],max(a[j],max(a[q],a[w])))){
										sum++;
							}
						}
						if(a[i]+a[j]+a[q]>2*max(a[i],max(a[j],a[q]))){
										sum++;
							}
					}
				}
			}
			cout<<sum;
		}
		if(n==8){
			for(ll i=1;i<=n;i++){
				for(ll j=i+1;j<=n;j++){
					for(ll q=j+1;q<=n;q++){
						for(ll w=q+1;w<=n;w++){
							for(ll e=w+1;e<=n;e++){
								for(ll r=e+1;r<=n;r++){
									for(ll t=r+1;t<=n;t++){
										for(ll y=t+1;y<=n;y++){
											if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],a[r])))))))){
												sum++;
											}
										}
										if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],a[r]))))))){
										sum++;
									}
									}
									if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],a[r])))))){
										sum++;
									}
								}
								if(a[i]+a[j]+a[q]+a[w]+a[e]>2*max(a[i],max(a[j],max(a[q],max(a[w],a[e]))))){
										sum++;
								}
							}
							if(a[i]+a[j]+a[q]+a[w]>2*max(a[i],max(a[j],max(a[q],a[w])))){
										sum++;
							}
						}
						if(a[i]+a[j]+a[q]>2*max(a[i],max(a[j],a[q]))){
										sum++;
							}
					}
				}
			}
			cout<<sum;
		}
		if(n==9){
			for(ll i=1;i<=n;i++){
				for(ll j=i+1;j<=n;j++){
					for(ll q=j+1;q<=n;q++){
						for(ll w=q+1;w<=n;w++){
							for(ll e=w+1;e<=n;e++){
								for(ll r=e+1;r<=n;r++){
									for(ll t=r+1;t<=n;t++){
										for(ll y=t+1;y<=n;y++){
											for(ll s=y+1;s<=n;s++){
												if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],a[r]))))))))){
												sum++;
											}
											}
											if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],a[r])))))))){
												sum++;
											}
										}
										if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],a[r]))))))){
										sum++;
									}
									}
									if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],a[r])))))){
										sum++;
									}
								}
								if(a[i]+a[j]+a[q]+a[w]+a[e]>2*max(a[i],max(a[j],max(a[q],max(a[w],a[e]))))){
										sum++;
								}
							}
							if(a[i]+a[j]+a[q]+a[w]>2*max(a[i],max(a[j],max(a[q],a[w])))){
										sum++;
							}
						}
						if(a[i]+a[j]+a[q]>2*max(a[i],max(a[j],a[q]))){
										sum++;
							}
					}
				}
			}
			cout<<sum;
		}
		if(n==10){
			
			for(ll i=1;i<=n;i++){
				for(ll j=i+1;j<=n;j++){
					for(ll q=j+1;q<=n;q++){
						for(ll w=q+1;w<=n;w++){
							for(ll e=w+1;e<=n;e++){
								for(ll r=e+1;r<=n;r++){
									for(ll t=r+1;t<=n;t++){
										for(ll y=t+1;y<=n;y++){
											for(ll s=y+1;s<=n;s++){
												for(ll d=s+1;d<=n;d++){
													if(a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],a[r])))))))))){
												sum++;
											}
												}
												if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],a[r]))))))))){
												sum++;
											}
											}
											if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],a[r])))))))){
												sum++;
											}
										}
										if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],a[r]))))))){
										sum++;
									}
									}
									if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],a[r])))))){
										sum++;
									}
								}
								if(a[i]+a[j]+a[q]+a[w]+a[e]>2*max(a[i],max(a[j],max(a[q],max(a[w],a[e]))))){
										sum++;
								}
							}
							if(a[i]+a[j]+a[q]+a[w]>2*max(a[i],max(a[j],max(a[q],a[w])))){
										sum++;
							}
						}
						if(a[i]+a[j]+a[q]>2*max(a[i],max(a[j],a[q]))){
										sum++;
							}
					}
				}
			}
			cout<<sum;
		}
		if(n==11){
			for(ll i=1;i<=n;i++){
				for(ll j=i+1;j<=n;j++){
					for(ll q=j+1;q<=n;q++){
						for(ll w=q+1;w<=n;w++){
							for(ll e=w+1;e<=n;e++){
								for(ll r=e+1;r<=n;r++){
									for(ll t=r+1;t<=n;t++){
										for(ll y=t+1;y<=n;y++){
											for(ll s=y+1;s<=n;s++){
												for(ll d=s+1;d<=n;d++){
													for(ll c=d+1;c<=n;c++){
														if(a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],a[r]))))))))))){
												sum++;
											}
													}
													if(a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],a[r])))))))))){
												sum++;
											}
												}
												if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],a[r]))))))))){
												sum++;
											}
											}
											if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],a[r])))))))){
												sum++;
											}
										}
										if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],a[r]))))))){
										sum++;
									}
									}
									if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],a[r])))))){
										sum++;
									}
								}
								if(a[i]+a[j]+a[q]+a[w]+a[e]>2*max(a[i],max(a[j],max(a[q],max(a[w],a[e]))))){
										sum++;
								}
							}
							if(a[i]+a[j]+a[q]+a[w]>2*max(a[i],max(a[j],max(a[q],a[w])))){
										sum++;
							}
						}
						if(a[i]+a[j]+a[q]>2*max(a[i],max(a[j],a[q]))){
										sum++;
							}
					}
				}
			}
			cout<<sum;
		}
		if(n==12){
			for(ll i=1;i<=n;i++){
				for(ll j=i+1;j<=n;j++){
					for(ll q=j+1;q<=n;q++){
						for(ll w=q+1;w<=n;w++){
							for(ll e=w+1;e<=n;e++){
								for(ll r=e+1;r<=n;r++){
									for(ll t=r+1;t<=n;t++){
										for(ll y=t+1;y<=n;y++){
											for(ll s=y+1;s<=n;s++){
												for(ll d=s+1;d<=n;d++){
													for(ll c=d+1;c<=n;c++){
														for(ll a1=c+1;a1<=n;a1++){
															if(a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],a[r])))))))))))){
												sum++;
											}
														}
														if(a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],a[r]))))))))))){
												sum++;
											}
													}
													if(a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],a[r])))))))))){
												sum++;
											}
												}
												if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],a[r]))))))))){
												sum++;
											}
											}
											if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],a[r])))))))){
												sum++;
											}
										}
										if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],a[r]))))))){
										sum++;
									}
									}
									if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],a[r])))))){
										sum++;
									}
								}
								if(a[i]+a[j]+a[q]+a[w]+a[e]>2*max(a[i],max(a[j],max(a[q],max(a[w],a[e]))))){
										sum++;
								}
							}
							if(a[i]+a[j]+a[q]+a[w]>2*max(a[i],max(a[j],max(a[q],a[w])))){
										sum++;
							}
						}
						if(a[i]+a[j]+a[q]>2*max(a[i],max(a[j],a[q]))){
										sum++;
							}
					}
				}
			}
			cout<<sum;
		}
		if(n==13){
			for(ll i=1;i<=n;i++){
				for(ll j=i+1;j<=n;j++){
					for(ll q=j+1;q<=n;q++){
						for(ll w=q+1;w<=n;w++){
							for(ll e=w+1;e<=n;e++){
								for(ll r=e+1;r<=n;r++){
									for(ll t=r+1;t<=n;t++){
										for(ll y=t+1;y<=n;y++){
											for(ll s=y+1;s<=n;s++){
												for(ll d=s+1;d<=n;d++){
													for(ll c=d+1;c<=n;c++){
														for(ll a1=c+1;a1<=n;a1++){
															for(ll a2=a1+1;a2<=n;a2++){
																if(a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],a[r]))))))))))))){
												sum++;
											}
															}
															if(a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],a[r])))))))))))){
												sum++;
											}
														}
														if(a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],a[r]))))))))))){
												sum++;
											}
													}
													if(a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],a[r])))))))))){
												sum++;
											}
												}
												if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],a[r]))))))))){
												sum++;
											}
											}
											if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],a[r])))))))){
												sum++;
											}
										}
										if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],a[r]))))))){
										sum++;
									}
									}
									if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],a[r])))))){
										sum++;
									}
								}
								if(a[i]+a[j]+a[q]+a[w]+a[e]>2*max(a[i],max(a[j],max(a[q],max(a[w],a[e]))))){
										sum++;
								}
							}
							if(a[i]+a[j]+a[q]+a[w]>2*max(a[i],max(a[j],max(a[q],a[w])))){
										sum++;
							}
						}
						if(a[i]+a[j]+a[q]>2*max(a[i],max(a[j],a[q]))){
										sum++;
							}
					}
				}
			}
			cout<<sum;
		}
		if(n==14){
			for(ll i=1;i<=n;i++){
				for(ll j=i+1;j<=n;j++){
					for(ll q=j+1;q<=n;q++){
						for(ll w=q+1;w<=n;w++){
							for(ll e=w+1;e<=n;e++){
								for(ll r=e+1;r<=n;r++){
									for(ll t=r+1;t<=n;t++){
										for(ll y=t+1;y<=n;y++){
											for(ll s=y+1;s<=n;s++){
												for(ll d=s+1;d<=n;d++){
													for(ll c=d+1;c<=n;c++){
														for(ll a1=c+1;a1<=n;a1++){
															for(ll a2=a1+1;a2<=n;a2++){
																for(ll a3=a2+1;a3<=n;a3++){
																	if(a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a3],a[r])))))))))))))){
												sum++;
											}
																}
																if(a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],a[r]))))))))))))){
												sum++;
											}
															}
															if(a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],a[r])))))))))))){
												sum++;
											}
														}
														if(a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],a[r]))))))))))){
												sum++;
											}
													}
													if(a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],a[r])))))))))){
												sum++;
											}
												}
												if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],a[r]))))))))){
												sum++;
											}
											}
											if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],a[r])))))))){
												sum++;
											}
										}
										if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],a[r]))))))){
										sum++;
									}
									}
									if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],a[r])))))){
										sum++;
									}
								}
								if(a[i]+a[j]+a[q]+a[w]+a[e]>2*max(a[i],max(a[j],max(a[q],max(a[w],a[e]))))){
										sum++;
								}
							}
							if(a[i]+a[j]+a[q]+a[w]>2*max(a[i],max(a[j],max(a[q],a[w])))){
										sum++;
							}
						}
						if(a[i]+a[j]+a[q]>2*max(a[i],max(a[j],a[q]))){
										sum++;
							}
					}
				}
			}
			cout<<sum;
		}
		if(n==15){
			for(ll i=1;i<=n;i++){
				for(ll j=i+1;j<=n;j++){
					for(ll q=j+1;q<=n;q++){
						for(ll w=q+1;w<=n;w++){
							for(ll e=w+1;e<=n;e++){
								for(ll r=e+1;r<=n;r++){
									for(ll t=r+1;t<=n;t++){
										for(ll y=t+1;y<=n;y++){
											for(ll s=y+1;s<=n;s++){
												for(ll d=s+1;d<=n;d++){
													for(ll c=d+1;c<=n;c++){
														for(ll a1=c+1;a1<=n;a1++){
															for(ll a2=a1+1;a2<=n;a2++){
																for(ll a3=a2+1;a3<=n;a3++){
																	for(ll a4=a3+1;a4<=n;a4++){
																		if(a[a4]+a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a4],max(a[a3],a[r]))))))))))))))){
												sum++;
											}
																	}
																	if(a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a3],a[r])))))))))))))){
												sum++;
											}
																}
																if(a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],a[r]))))))))))))){
												sum++;
											}
															}
															if(a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],a[r])))))))))))){
												sum++;
											}
														}
														if(a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],a[r]))))))))))){
												sum++;
											}
													}
													if(a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],a[r])))))))))){
												sum++;
											}
												}
												if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],a[r]))))))))){
												sum++;
											}
											}
											if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],a[r])))))))){
												sum++;
											}
										}
										if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],a[r]))))))){
										sum++;
									}
									}
									if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],a[r])))))){
										sum++;
									}
								}
								if(a[i]+a[j]+a[q]+a[w]+a[e]>2*max(a[i],max(a[j],max(a[q],max(a[w],a[e]))))){
										sum++;
								}
							}
							if(a[i]+a[j]+a[q]+a[w]>2*max(a[i],max(a[j],max(a[q],a[w])))){
										sum++;
							}
						}
						if(a[i]+a[j]+a[q]>2*max(a[i],max(a[j],a[q]))){
										sum++;
							}
					}
				}
			}
			cout<<sum;
		}
			if(n==16){
			for(ll i=1;i<=n;i++){
				for(ll j=i+1;j<=n;j++){
					for(ll q=j+1;q<=n;q++){
						for(ll w=q+1;w<=n;w++){
							for(ll e=w+1;e<=n;e++){
								for(ll r=e+1;r<=n;r++){
									for(ll t=r+1;t<=n;t++){
										for(ll y=t+1;y<=n;y++){
											for(ll s=y+1;s<=n;s++){
												for(ll d=s+1;d<=n;d++){
													for(ll c=d+1;c<=n;c++){
														for(ll a1=c+1;a1<=n;a1++){
															for(ll a2=a1+1;a2<=n;a2++){
																for(ll a3=a2+1;a3<=n;a3++){
																	for(ll a4=a3+1;a4<=n;a4++){
																		for(ll g=a4+1;g<=n;g++){
																			if(a[g]+a[a4]+a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a4],max(a[g],max(a[a3],a[r])))))))))))))))){
												sum++;
											}
																		}
																		if(a[a4]+a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a4],max(a[a3],a[r]))))))))))))))){
												sum++;
											}
																	}
																	if(a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a3],a[r])))))))))))))){
												sum++;
											}
																}
																if(a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],a[r]))))))))))))){
												sum++;
											}
															}
															if(a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],a[r])))))))))))){
												sum++;
											}
														}
														if(a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],a[r]))))))))))){
												sum++;
											}
													}
													if(a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],a[r])))))))))){
												sum++;
											}
												}
												if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],a[r]))))))))){
												sum++;
											}
											}
											if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],a[r])))))))){
												sum++;
											}
										}
										if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],a[r]))))))){
										sum++;
									}
									}
									if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],a[r])))))){
										sum++;
									}
								}
								if(a[i]+a[j]+a[q]+a[w]+a[e]>2*max(a[i],max(a[j],max(a[q],max(a[w],a[e]))))){
										sum++;
								}
							}
							if(a[i]+a[j]+a[q]+a[w]>2*max(a[i],max(a[j],max(a[q],a[w])))){
										sum++;
							}
						}
						if(a[i]+a[j]+a[q]>2*max(a[i],max(a[j],a[q]))){
										sum++;
							}
					}
				}
			}
			cout<<sum;
		}
		if(n==17){
			for(ll i=1;i<=n;i++){
				for(ll j=i+1;j<=n;j++){
					for(ll q=j+1;q<=n;q++){
						for(ll w=q+1;w<=n;w++){
							for(ll e=w+1;e<=n;e++){
								for(ll r=e+1;r<=n;r++){
									for(ll t=r+1;t<=n;t++){
										for(ll y=t+1;y<=n;y++){
											for(ll s=y+1;s<=n;s++){
												for(ll d=s+1;d<=n;d++){
													for(ll c=d+1;c<=n;c++){
														for(ll a1=c+1;a1<=n;a1++){
															for(ll a2=a1+1;a2<=n;a2++){
																for(ll a3=a2+1;a3<=n;a3++){
																	for(ll a4=a3+1;a4<=n;a4++){
																		for(ll g=a4+1;g<=n;g++){
																			for(ll h=g+1;h<=n;h++){
																				if(a[h]+a[g]+a[a4]+a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a4],max(a[g],max(a[a3],max(a[h],a[r]))))))))))))))))){
												sum++;
											}
																			}
																			if(a[g]+a[a4]+a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a4],max(a[g],max(a[a3],a[r])))))))))))))))){
												sum++;
											}
																		}
																		if(a[a4]+a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a4],max(a[a3],a[r]))))))))))))))){
												sum++;
											}
																	}
																	if(a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a3],a[r])))))))))))))){
												sum++;
											}
																}
																if(a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],a[r]))))))))))))){
												sum++;
											}
															}
															if(a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],a[r])))))))))))){
												sum++;
											}
														}
														if(a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],a[r]))))))))))){
												sum++;
											}
													}
													if(a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],a[r])))))))))){
												sum++;
											}
												}
												if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],a[r]))))))))){
												sum++;
											}
											}
											if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],a[r])))))))){
												sum++;
											}
										}
										if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],a[r]))))))){
										sum++;
									}
									}
									if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],a[r])))))){
										sum++;
									}
								}
								if(a[i]+a[j]+a[q]+a[w]+a[e]>2*max(a[i],max(a[j],max(a[q],max(a[w],a[e]))))){
										sum++;
								}
							}
							if(a[i]+a[j]+a[q]+a[w]>2*max(a[i],max(a[j],max(a[q],a[w])))){
										sum++;
							}
						}
						if(a[i]+a[j]+a[q]>2*max(a[i],max(a[j],a[q]))){
										sum++;
							}
					}
				}
			}
			cout<<sum;
		}
		if(n==18){
			for(ll i=1;i<=n;i++){
				for(ll j=i+1;j<=n;j++){
					for(ll q=j+1;q<=n;q++){
						for(ll w=q+1;w<=n;w++){
							for(ll e=w+1;e<=n;e++){
								for(ll r=e+1;r<=n;r++){
									for(ll t=r+1;t<=n;t++){
										for(ll y=t+1;y<=n;y++){
											for(ll s=y+1;s<=n;s++){
												for(ll d=s+1;d<=n;d++){
													for(ll c=d+1;c<=n;c++){
														for(ll a1=c+1;a1<=n;a1++){
															for(ll a2=a1+1;a2<=n;a2++){
																for(ll a3=a2+1;a3<=n;a3++){
																	for(ll a4=a3+1;a4<=n;a4++){
																		for(ll g=a4+1;g<=n;g++){
																			for(ll h=g+1;h<=n;h++){
																				for(ll z1=h+1;z1<=n;z1++){
																					if(a[z1]+a[h]+a[g]+a[a4]+a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a4],max(a[g],max(a[a3],max(a[h],max(a[z1],a[r])))))))))))))))))){
												sum++;
											}
																				}
																				if(a[h]+a[g]+a[a4]+a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a4],max(a[g],max(a[a3],max(a[h],a[r]))))))))))))))))){
												sum++;
											}
																			}
																			if(a[g]+a[a4]+a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a4],max(a[g],max(a[a3],a[r])))))))))))))))){
												sum++;
											}
																		}
																		if(a[a4]+a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a4],max(a[a3],a[r]))))))))))))))){
												sum++;
											}
																	}
																	if(a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a3],a[r])))))))))))))){
												sum++;
											}
																}
																if(a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],a[r]))))))))))))){
												sum++;
											}
															}
															if(a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],a[r])))))))))))){
												sum++;
											}
														}
														if(a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],a[r]))))))))))){
												sum++;
											}
													}
													if(a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],a[r])))))))))){
												sum++;
											}
												}
												if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],a[r]))))))))){
												sum++;
											}
											}
											if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],a[r])))))))){
												sum++;
											}
										}
										if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],a[r]))))))){
										sum++;
									}
									}
									if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],a[r])))))){
										sum++;
									}
								}
								if(a[i]+a[j]+a[q]+a[w]+a[e]>2*max(a[i],max(a[j],max(a[q],max(a[w],a[e]))))){
										sum++;
								}
							}
							if(a[i]+a[j]+a[q]+a[w]>2*max(a[i],max(a[j],max(a[q],a[w])))){
										sum++;
							}
						}
						if(a[i]+a[j]+a[q]>2*max(a[i],max(a[j],a[q]))){
										sum++;
							}
					}
				}
			}
			cout<<sum;
		}
		if(n==19){
			for(ll i=1;i<=n;i++){
				for(ll j=i+1;j<=n;j++){
					for(ll q=j+1;q<=n;q++){
						for(ll w=q+1;w<=n;w++){
							for(ll e=w+1;e<=n;e++){
								for(ll r=e+1;r<=n;r++){
									for(ll t=r+1;t<=n;t++){
										for(ll y=t+1;y<=n;y++){
											for(ll s=y+1;s<=n;s++){
												for(ll d=s+1;d<=n;d++){
													for(ll c=d+1;c<=n;c++){
														for(ll a1=c+1;a1<=n;a1++){
															for(ll a2=a1+1;a2<=n;a2++){
																for(ll a3=a2+1;a3<=n;a3++){
																	for(ll a4=a3+1;a4<=n;a4++){
																		for(ll g=a4+1;g<=n;g++){
																			for(ll h=g+1;h<=n;h++){
																				for(ll z1=h+1;z1<=n;z1++){
																					for(ll m=z1+1;m<=n;m++){
																						if(a[m]+a[z1]+a[h]+a[g]+a[a4]+a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a4],max(a[g],max(a[a3],max(a[h],max(a[z1],max(a[m],a[r]))))))))))))))))))){
												sum++;
											}
																					}
																					if(a[z1]+a[h]+a[g]+a[a4]+a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a4],max(a[g],max(a[a3],max(a[h],max(a[z1],a[r])))))))))))))))))){
												sum++;
											}
																				}
																				if(a[h]+a[g]+a[a4]+a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a4],max(a[g],max(a[a3],max(a[h],a[r]))))))))))))))))){
												sum++;
											}
																			}
																			if(a[g]+a[a4]+a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a4],max(a[g],max(a[a3],a[r])))))))))))))))){
												sum++;
											}
																		}
																		if(a[a4]+a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a4],max(a[a3],a[r]))))))))))))))){
												sum++;
											}
																	}
																	if(a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a3],a[r])))))))))))))){
												sum++;
											}
																}
																if(a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],a[r]))))))))))))){
												sum++;
											}
															}
															if(a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],a[r])))))))))))){
												sum++;
											}
														}
														if(a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],a[r]))))))))))){
												sum++;
											}
													}
													if(a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],a[r])))))))))){
												sum++;
											}
												}
												if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],a[r]))))))))){
												sum++;
											}
											}
											if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],a[r])))))))){
												sum++;
											}
										}
										if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],a[r]))))))){
										sum++;
									}
									}
									if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],a[r])))))){
										sum++;
									}
								}
								if(a[i]+a[j]+a[q]+a[w]+a[e]>2*max(a[i],max(a[j],max(a[q],max(a[w],a[e]))))){
										sum++;
								}
							}
							if(a[i]+a[j]+a[q]+a[w]>2*max(a[i],max(a[j],max(a[q],a[w])))){
										sum++;
							}
						}
						if(a[i]+a[j]+a[q]>2*max(a[i],max(a[j],a[q]))){
										sum++;
							}
					}
				}
			}
			cout<<sum;
		}
		if(n==20){
			for(ll i=1;i<=n;i++){
				for(ll j=i+1;j<=n;j++){
					for(ll q=j+1;q<=n;q++){
						for(ll w=q+1;w<=n;w++){
							for(ll e=w+1;e<=n;e++){
								for(ll r=e+1;r<=n;r++){
									for(ll t=r+1;t<=n;t++){
										for(ll y=t+1;y<=n;y++){
											for(ll s=y+1;s<=n;s++){
												for(ll d=s+1;d<=n;d++){
													for(ll c=d+1;c<=n;c++){
														for(ll a1=c+1;a1<=n;a1++){
															for(ll a2=a1+1;a2<=n;a2++){
																for(ll a3=a2+1;a3<=n;a3++){
																	for(ll a4=a3+1;a4<=n;a4++){
																		for(ll g=a4+1;g<=n;g++){
																			for(ll h=g+1;h<=n;h++){
																				for(ll z1=h+1;z1<=n;z1++){
																					for(ll m=z1+1;m<=n;m++){
																						for(ll qw=m+1;qw<=n;qw++){
																							if(a[qw]+a[m]+a[z1]+a[h]+a[g]+a[a4]+a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a4],max(a[g],max(a[a3],max(a[h],max(a[z1],max(a[m],max(a[qw],a[r])))))))))))))))))))){
												sum++;
											}
																						}
																						if(a[m]+a[z1]+a[h]+a[g]+a[a4]+a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a4],max(a[g],max(a[a3],max(a[h],max(a[z1],max(a[m],a[r]))))))))))))))))))){
												sum++;
											}
																					}
																					if(a[z1]+a[h]+a[g]+a[a4]+a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a4],max(a[g],max(a[a3],max(a[h],max(a[z1],a[r])))))))))))))))))){
												sum++;
											}
																				}
																				if(a[h]+a[g]+a[a4]+a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a4],max(a[g],max(a[a3],max(a[h],a[r]))))))))))))))))){
												sum++;
											}
																			}
																			if(a[g]+a[a4]+a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a4],max(a[g],max(a[a3],a[r])))))))))))))))){
												sum++;
											}
																		}
																		if(a[a4]+a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a4],max(a[a3],a[r]))))))))))))))){
												sum++;
											}
																	}
																	if(a[a3]+a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],max(a[a3],a[r])))))))))))))){
												sum++;
											}
																}
																if(a[a2]+a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],max(a[a2],a[r]))))))))))))){
												sum++;
											}
															}
															if(a[a1]+a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],max(a[a1],a[r])))))))))))){
												sum++;
											}
														}
														if(a[c]+a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],max(a[c],a[r]))))))))))){
												sum++;
											}
													}
													if(a[d]+a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[d],max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],a[r])))))))))){
												sum++;
											}
												}
												if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[s]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],max(a[s],a[r]))))))))){
												sum++;
											}
											}
											if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],max(a[y],a[r])))))))){
												sum++;
											}
										}
										if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]+a[t]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],max(a[t],a[r]))))))){
										sum++;
									}
									}
									if(a[i]+a[j]+a[q]+a[w]+a[e]+a[r]>2*max(a[i],max(a[j],max(a[q],max(a[w],max(a[e],a[r])))))){
										sum++;
									}
								}
								if(a[i]+a[j]+a[q]+a[w]+a[e]>2*max(a[i],max(a[j],max(a[q],max(a[w],a[e]))))){
										sum++;
								}
							}
							if(a[i]+a[j]+a[q]+a[w]>2*max(a[i],max(a[j],max(a[q],a[w])))){
										sum++;
							}
						}
						if(a[i]+a[j]+a[q]>2*max(a[i],max(a[j],a[q]))){
										sum++;
							}
					}
				}
			}
			cout<<sum;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

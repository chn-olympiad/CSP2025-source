#include<bits/stdc++.h>
using namespace std;
int a,b,c,dclub1[500001],dclub2[500001],dclub3[500001],d=0,e=0,f=0,g=0,club[500001],ans=0;
int h;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		if(a==1){
			cin>>b;
			c = 3*b;
			h = b/2;
			for(int k=1;k<=b;k++){
				cin>>dclub1[k];
				club[++d]=dclub1[k];
				cin>>dclub2[k];
				club[++d]=dclub2[k];
				cin>>dclub3[k];
				club[++d]=dclub3[k];
			}
			sort(club+1,club+c+1);
			for(int k =1;k<=c;k++){
				for(int l=k+1;l<=c;l++){
					if(club[k] == club[l]){
						club[l] = 0;
					}
				}
			}
			for(int k=c;k>0;k--){
				for(int l=1;l<=b;l++){
					if(dclub1[l] == club[k] and club[k] != 0){
						e++;
						dclub2[l] =0;
						dclub3[l] =0;
						if(e > h){
							sort(dclub1+1,dclub1+b+1);
							for(int m = b-2;m>0;m--){
								dclub1[m]=0;
							}
						}
					}
					if(dclub2[l] == club[k] and club[k] !=0){
						f++;
						dclub1[l] =0;
						dclub3[l] =0;
						if(f > h){
							sort(dclub2+1,dclub2+b+1);
							for(int m = b-2;m>0;m--){
								dclub2[m]=0;
							}
						}
					}
					if(dclub3[l] == club[k] and club[k] !=0){
						g++;
						dclub1[l] =0;
						dclub2[l] =0;
						if(g > h){
							sort(dclub3+1,dclub3+b+1);
							for(int m = b-2;m>0;m--){
								dclub3[m]=0;
							}
						}
					}
				}
			}
			/*for(int k = 1;k<=b;k++){
				cout<<dclub1[k];
			}
			cout<<endl;
			for(int k = 1;k<=b;k++){
				cout<<dclub2[k];
			}
			cout<<endl;
			for(int k = 1;k<=b;k++){
				cout<<dclub3[k];
			}*/
			for(int k=1;k<=b;k++){
				ans+=dclub1[k];
				ans+=dclub2[k];
				ans+=dclub3[k];
			}
			cout<<ans;
		}
		if(a==2){
			if(i==0){
				cin>>b;
				c = 3*b;
				h = b/2;
				for(int k=1;k<=b;k++){
					cin>>dclub1[k];
					club[++d]=dclub1[k];
					cin>>dclub2[k];
					club[++d]=dclub2[k];
					cin>>dclub3[k];
					club[++d]=dclub3[k];
				}
				sort(club+1,club+c+1);
				for(int k =1;k<=c;k++){
					for(int l=k+1;l<=c;l++){
						if(club[k] == club[l]){
							club[l] = 0;
						}
					}
				}
				for(int k=c;k>0;k--){
					for(int l=1;l<=b;l++){
						if(dclub1[l] == club[k] and club[k] != 0){
							e++;
							dclub2[l] =0;
							dclub3[l] =0;
							if(e > h){
								sort(dclub1+1,dclub1+b+1);
								for(int m = b-2;m>0;m--){
									dclub1[m]=0;
								}
							}
						}
						if(dclub2[l] == club[k] and club[k] !=0){
							f++;
							dclub1[l] =0;
							dclub3[l] =0;
							if(f > h){
								sort(dclub2+1,dclub2+b+1);
								for(int m = b-2;m>0;m--){
									dclub2[m]=0;
								}
							}
						}
						if(dclub3[l] == club[k] and club[k] !=0){
							g++;
							dclub1[l] =0;
							dclub2[l] =0;
							if(g > h){
								sort(dclub3+1,dclub3+b+1);
								for(int m = b-2;m>0;m--){
									dclub3[m]=0;
								}
							}
						}
					}
				}
				/*for(int k = 1;k<=b;k++){
					cout<<dclub1[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub2[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub3[k];
				}*/
				for(int k=1;k<=b;k++){
					ans+=dclub1[k];
					ans+=dclub2[k];
					ans+=dclub3[k];
				}
				cout<<ans<<endl;
				ans=0;
				d=0;
			}
			if(i==1){
				cin>>b;
				c = 3*b;
				h = b/2;
				for(int k=1;k<=b;k++){
					cin>>dclub1[k];
					club[++d]=dclub1[k];
					cin>>dclub2[k];
					club[++d]=dclub2[k];
					cin>>dclub3[k];
					club[++d]=dclub3[k];
				}
				sort(club+1,club+c+1);
				for(int k =1;k<=c;k++){
					for(int l=k+1;l<=c;l++){
						if(club[k] == club[l]){
							club[l] = 0;
						}
					}
				}
				for(int k=c;k>0;k--){
					for(int l=1;l<=b;l++){
						if(dclub1[l] == club[k] and club[k] != 0){
							e++;
							dclub2[l] =0;
							dclub3[l] =0;
							if(e > h){
								sort(dclub1+1,dclub1+b+1);
								for(int m = b-2;m>0;m--){
									dclub1[m]=0;
								}
							}
						}
						if(dclub2[l] == club[k] and club[k] !=0){
							f++;
							dclub1[l] =0;
							dclub3[l] =0;
							if(f > h){
								sort(dclub2+1,dclub2+b+1);
								for(int m = b-2;m>0;m--){
									dclub2[m]=0;
								}
							}
						}
						if(dclub3[l] == club[k] and club[k] !=0){
							g++;
							dclub1[l] =0;
							dclub2[l] =0;
							if(g > h){
								sort(dclub3+1,dclub3+b+1);
								for(int m = b-2;m>0;m--){
									dclub3[m]=0;
								}
							}
						}
					}
				}
				/*for(int k = 1;k<=b;k++){
					cout<<dclub1[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub2[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub3[k];
				}*/
				for(int k=1;k<=b;k++){
					ans+=dclub1[k];
					ans+=dclub2[k];
					ans+=dclub3[k];
				}
				cout<<ans;
				ans=0;
				d=0;
			}
		}
		if(a==3){
			if(i==0){
				cin>>b;
				c = 3*b;
				h = b/2;
				for(int k=1;k<=b;k++){
					cin>>dclub1[k];
					club[++d]=dclub1[k];
					cin>>dclub2[k];
					club[++d]=dclub2[k];
					cin>>dclub3[k];
					club[++d]=dclub3[k];
				}
				sort(club+1,club+c+1);
				for(int k =1;k<=c;k++){
					for(int l=k+1;l<=c;l++){
						if(club[k] == club[l]){
							club[l] = 0;
						}
					}
				}
				for(int k=c;k>0;k--){
					for(int l=1;l<=b;l++){
						if(dclub1[l] == club[k] and club[k] != 0){
							e++;
							dclub2[l] =0;
							dclub3[l] =0;
							if(e > h){
								sort(dclub1+1,dclub1+b+1);
								for(int m = b-2;m>0;m--){
									dclub1[m]=0;
								}
							}
						}
						if(dclub2[l] == club[k] and club[k] !=0){
							f++;
							dclub1[l] =0;
							dclub3[l] =0;
							if(f > h){
								sort(dclub2+1,dclub2+b+1);
								for(int m = b-2;m>0;m--){
									dclub2[m]=0;
								}
							}
						}
						if(dclub3[l] == club[k] and club[k] !=0){
							g++;
							dclub1[l] =0;
							dclub2[l] =0;
							if(g > h){
								sort(dclub3+1,dclub3+b+1);
								for(int m = b-2;m>0;m--){
									dclub3[m]=0;
								}
							}
						}
					}
				}
				/*for(int k = 1;k<=b;k++){
					cout<<dclub1[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub2[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub3[k];
				}*/
				for(int k=1;k<=b;k++){
					ans+=dclub1[k];
					ans+=dclub2[k];
					ans+=dclub3[k];
				}
				cout<<ans<<endl;
				ans=0;
				d=0;
			}
			if(i==1){
				cin>>b;
				c = 3*b;
				h = b/2;
				for(int k=1;k<=b;k++){
					cin>>dclub1[k];
					club[++d]=dclub1[k];
					cin>>dclub2[k];
					club[++d]=dclub2[k];
					cin>>dclub3[k];
					club[++d]=dclub3[k];
				}
				sort(club+1,club+c+1);
				for(int k =1;k<=c;k++){
					for(int l=k+1;l<=c;l++){
						if(club[k] == club[l]){
							club[l] = 0;
						}
					}
				}
				for(int k=c;k>0;k--){
					for(int l=1;l<=b;l++){
						if(dclub1[l] == club[k] and club[k] != 0){
							e++;
							dclub2[l] =0;
							dclub3[l] =0;
							if(e > h){
								sort(dclub1+1,dclub1+b+1);
								for(int m = b-2;m>0;m--){
									dclub1[m]=0;
								}
							}
						}
						if(dclub2[l] == club[k] and club[k] !=0){
							f++;
							dclub1[l] =0;
							dclub3[l] =0;
							if(f > h){
								sort(dclub2+1,dclub2+b+1);
								for(int m = b-2;m>0;m--){
									dclub2[m]=0;
								}
							}
						}
						if(dclub3[l] == club[k] and club[k] !=0){
							g++;
							dclub1[l] =0;
							dclub2[l] =0;
							if(g > h){
								sort(dclub3+1,dclub3+b+1);
								for(int m = b-2;m>0;m--){
									dclub3[m]=0;
								}
							}
						}
					}
				}
				/*for(int k = 1;k<=b;k++){
					cout<<dclub1[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub2[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub3[k];
				}*/
				for(int k=1;k<=b;k++){
					ans+=dclub1[k];
					ans+=dclub2[k];
					ans+=dclub3[k];
				}
				cout<<ans<<endl;
				ans=0;
				d=0;
			}
			if(i==2){
				cin>>b;
				c = 3*b;
				h = b/2;
				for(int k=1;k<=b;k++){
					cin>>dclub1[k];
					club[++d]=dclub1[k];
					cin>>dclub2[k];
					club[++d]=dclub2[k];
					cin>>dclub3[k];
					club[++d]=dclub3[k];
				}
				sort(club+1,club+c+1);
				for(int k =1;k<=c;k++){
					for(int l=k+1;l<=c;l++){
						if(club[k] == club[l]){
							club[l] = 0;
						}
					}
				}
				for(int k=c;k>0;k--){
					for(int l=1;l<=b;l++){
						if(dclub1[l] == club[k] and club[k] != 0){
							e++;
							dclub2[l] =0;
							dclub3[l] =0;
							if(e > h){
								sort(dclub1+1,dclub1+b+1);
								for(int m = b-2;m>0;m--){
									dclub1[m]=0;
								}
							}
						}
						if(dclub2[l] == club[k] and club[k] !=0){
							f++;
							dclub1[l] =0;
							dclub3[l] =0;
							if(f > h){
								sort(dclub2+1,dclub2+b+1);
								for(int m = b-2;m>0;m--){
									dclub2[m]=0;
								}
							}
						}
						if(dclub3[l] == club[k] and club[k] !=0){
							g++;
							dclub1[l] =0;
							dclub2[l] =0;
							if(g > h){
								sort(dclub3+1,dclub3+b+1);
								for(int m = b-2;m>0;m--){
									dclub3[m]=0;
								}
							}
						}
					}
				}
				/*for(int k = 1;k<=b;k++){
					cout<<dclub1[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub2[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub3[k];
				}*/
				for(int k=1;k<=b;k++){
					ans+=dclub1[k];
					ans+=dclub2[k];
					ans+=dclub3[k];
				}
				cout<<ans;
				ans=0;
				d=0;
			}
		}
		if(a==4){
			if(i==0){
				cin>>b;
				c = 3*b;
				h = b/2;
				for(int k=1;k<=b;k++){
					cin>>dclub1[k];
					club[++d]=dclub1[k];
					cin>>dclub2[k];
					club[++d]=dclub2[k];
					cin>>dclub3[k];
					club[++d]=dclub3[k];
				}
				sort(club+1,club+c+1);
				for(int k =1;k<=c;k++){
					for(int l=k+1;l<=c;l++){
						if(club[k] == club[l]){
							club[l] = 0;
						}
					}
				}
				for(int k=c;k>0;k--){
					for(int l=1;l<=b;l++){
						if(dclub1[l] == club[k] and club[k] != 0){
							e++;
							dclub2[l] =0;
							dclub3[l] =0;
							if(e > h){
								sort(dclub1+1,dclub1+b+1);
								for(int m = b-2;m>0;m--){
									dclub1[m]=0;
								}
							}
						}
						if(dclub2[l] == club[k] and club[k] !=0){
							f++;
							dclub1[l] =0;
							dclub3[l] =0;
							if(f > h){
								sort(dclub2+1,dclub2+b+1);
								for(int m = b-2;m>0;m--){
									dclub2[m]=0;
								}
							}
						}
						if(dclub3[l] == club[k] and club[k] !=0){
							g++;
							dclub1[l] =0;
							dclub2[l] =0;
							if(g > h){
								sort(dclub3+1,dclub3+b+1);
								for(int m = b-2;m>0;m--){
									dclub3[m]=0;
								}
							}
						}
					}
				}
				/*for(int k = 1;k<=b;k++){
					cout<<dclub1[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub2[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub3[k];
				}*/
				for(int k=1;k<=b;k++){
					ans+=dclub1[k];
					ans+=dclub2[k];
					ans+=dclub3[k];
				}
				cout<<ans<<endl;
				ans=0;
				d=0;
			}
			if(i==1){
				cin>>b;
				c = 3*b;
				h = b/2;
				for(int k=1;k<=b;k++){
					cin>>dclub1[k];
					club[++d]=dclub1[k];
					cin>>dclub2[k];
					club[++d]=dclub2[k];
					cin>>dclub3[k];
					club[++d]=dclub3[k];
				}
				sort(club+1,club+c+1);
				for(int k =1;k<=c;k++){
					for(int l=k+1;l<=c;l++){
						if(club[k] == club[l]){
							club[l] = 0;
						}
					}
				}
				for(int k=c;k>0;k--){
					for(int l=1;l<=b;l++){
						if(dclub1[l] == club[k] and club[k] != 0){
							e++;
							dclub2[l] =0;
							dclub3[l] =0;
							if(e > h){
								sort(dclub1+1,dclub1+b+1);
								for(int m = b-2;m>0;m--){
									dclub1[m]=0;
								}
							}
						}
						if(dclub2[l] == club[k] and club[k] !=0){
							f++;
							dclub1[l] =0;
							dclub3[l] =0;
							if(f > h){
								sort(dclub2+1,dclub2+b+1);
								for(int m = b-2;m>0;m--){
									dclub2[m]=0;
								}
							}
						}
						if(dclub3[l] == club[k] and club[k] !=0){
							g++;
							dclub1[l] =0;
							dclub2[l] =0;
							if(g > h){
								sort(dclub3+1,dclub3+b+1);
								for(int m = b-2;m>0;m--){
									dclub3[m]=0;
								}
							}
						}
					}
				}
				/*for(int k = 1;k<=b;k++){
					cout<<dclub1[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub2[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub3[k];
				}*/
				for(int k=1;k<=b;k++){
					ans+=dclub1[k];
					ans+=dclub2[k];
					ans+=dclub3[k];
				}
				cout<<ans<<endl;
				ans=0;
				d=0;
			}
			if(i==2){
				cin>>b;
				c = 3*b;
				h = b/2;
				for(int k=1;k<=b;k++){
					cin>>dclub1[k];
					club[++d]=dclub1[k];
					cin>>dclub2[k];
					club[++d]=dclub2[k];
					cin>>dclub3[k];
					club[++d]=dclub3[k];
				}
				sort(club+1,club+c+1);
				for(int k =1;k<=c;k++){
					for(int l=k+1;l<=c;l++){
						if(club[k] == club[l]){
							club[l] = 0;
						}
					}
				}
				for(int k=c;k>0;k--){
					for(int l=1;l<=b;l++){
						if(dclub1[l] == club[k] and club[k] != 0){
							e++;
							dclub2[l] =0;
							dclub3[l] =0;
							if(e > h){
								sort(dclub1+1,dclub1+b+1);
								for(int m = b-2;m>0;m--){
									dclub1[m]=0;
								}
							}
						}
						if(dclub2[l] == club[k] and club[k] !=0){
							f++;
							dclub1[l] =0;
							dclub3[l] =0;
							if(f > h){
								sort(dclub2+1,dclub2+b+1);
								for(int m = b-2;m>0;m--){
									dclub2[m]=0;
								}
							}
						}
						if(dclub3[l] == club[k] and club[k] !=0){
							g++;
							dclub1[l] =0;
							dclub2[l] =0;
							if(g > h){
								sort(dclub3+1,dclub3+b+1);
								for(int m = b-2;m>0;m--){
									dclub3[m]=0;
								}
							}
						}
					}
				}
				/*for(int k = 1;k<=b;k++){
					cout<<dclub1[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub2[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub3[k];
				}*/
				for(int k=1;k<=b;k++){
					ans+=dclub1[k];
					ans+=dclub2[k];
					ans+=dclub3[k];
				}
				cout<<ans<<endl;
				ans=0;
				d=0;
			}
			if(i==3){
				cin>>b;
				c = 3*b;
				h = b/2;
				for(int k=1;k<=b;k++){
					cin>>dclub1[k];
					club[++d]=dclub1[k];
					cin>>dclub2[k];
					club[++d]=dclub2[k];
					cin>>dclub3[k];
					club[++d]=dclub3[k];
				}
				sort(club+1,club+c+1);
				for(int k =1;k<=c;k++){
					for(int l=k+1;l<=c;l++){
						if(club[k] == club[l]){
							club[l] = 0;
						}
					}
				}
				for(int k=c;k>0;k--){
					for(int l=1;l<=b;l++){
						if(dclub1[l] == club[k] and club[k] != 0){
							e++;
							dclub2[l] =0;
							dclub3[l] =0;
							if(e > h){
								sort(dclub1+1,dclub1+b+1);
								for(int m = b-2;m>0;m--){
									dclub1[m]=0;
								}
							}
						}
						if(dclub2[l] == club[k] and club[k] !=0){
							f++;
							dclub1[l] =0;
							dclub3[l] =0;
							if(f > h){
								sort(dclub2+1,dclub2+b+1);
								for(int m = b-2;m>0;m--){
									dclub2[m]=0;
								}
							}
						}
						if(dclub3[l] == club[k] and club[k] !=0){
							g++;
							dclub1[l] =0;
							dclub2[l] =0;
							if(g > h){
								sort(dclub3+1,dclub3+b+1);
								for(int m = b-2;m>0;m--){
									dclub3[m]=0;
								}
							}
						}
					}
				}
				/*for(int k = 1;k<=b;k++){
					cout<<dclub1[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub2[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub3[k];
				}*/
				for(int k=1;k<=b;k++){
					ans+=dclub1[k];
					ans+=dclub2[k];
					ans+=dclub3[k];
				}
				cout<<ans<<endl;
				ans=0;
				d=0;
			}
		}
		if(a==5){
			if(i==0){
				cin>>b;
				c = 3*b;
				h = b/2;
				for(int k=1;k<=b;k++){
					cin>>dclub1[k];
					club[++d]=dclub1[k];
					cin>>dclub2[k];
					club[++d]=dclub2[k];
					cin>>dclub3[k];
					club[++d]=dclub3[k];
				}
				sort(club+1,club+c+1);
				for(int k =1;k<=c;k++){
					for(int l=k+1;l<=c;l++){
						if(club[k] == club[l]){
							club[l] = 0;
						}
					}
				}
				for(int k=c;k>0;k--){
					for(int l=1;l<=b;l++){
						if(dclub1[l] == club[k] and club[k] != 0){
							e++;
							dclub2[l] =0;
							dclub3[l] =0;
							if(e > h){
								sort(dclub1+1,dclub1+b+1);
								for(int m = b-2;m>0;m--){
									dclub1[m]=0;
								}
							}
						}
						if(dclub2[l] == club[k] and club[k] !=0){
							f++;
							dclub1[l] =0;
							dclub3[l] =0;
							if(f > h){
								sort(dclub2+1,dclub2+b+1);
								for(int m = b-2;m>0;m--){
									dclub2[m]=0;
								}
							}
						}
						if(dclub3[l] == club[k] and club[k] !=0){
							g++;
							dclub1[l] =0;
							dclub2[l] =0;
							if(g > h){
								sort(dclub3+1,dclub3+b+1);
								for(int m = b-2;m>0;m--){
									dclub3[m]=0;
								}
							}
						}
					}
				}
				/*for(int k = 1;k<=b;k++){
					cout<<dclub1[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub2[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub3[k];
				}*/
				for(int k=1;k<=b;k++){
					ans+=dclub1[k];
					ans+=dclub2[k];
					ans+=dclub3[k];
				}
				cout<<ans<<endl;
				ans=0;
				d=0;
			}
			if(i==1){
				cin>>b;
				c = 3*b;
				h = b/2;
				for(int k=1;k<=b;k++){
					cin>>dclub1[k];
					club[++d]=dclub1[k];
					cin>>dclub2[k];
					club[++d]=dclub2[k];
					cin>>dclub3[k];
					club[++d]=dclub3[k];
				}
				sort(club+1,club+c+1);
				for(int k =1;k<=c;k++){
					for(int l=k+1;l<=c;l++){
						if(club[k] == club[l]){
							club[l] = 0;
						}
					}
				}
				for(int k=c;k>0;k--){
					for(int l=1;l<=b;l++){
						if(dclub1[l] == club[k] and club[k] != 0){
							e++;
							dclub2[l] =0;
							dclub3[l] =0;
							if(e > h){
								sort(dclub1+1,dclub1+b+1);
								for(int m = b-2;m>0;m--){
									dclub1[m]=0;
								}
							}
						}
						if(dclub2[l] == club[k] and club[k] !=0){
							f++;
							dclub1[l] =0;
							dclub3[l] =0;
							if(f > h){
								sort(dclub2+1,dclub2+b+1);
								for(int m = b-2;m>0;m--){
									dclub2[m]=0;
								}
							}
						}
						if(dclub3[l] == club[k] and club[k] !=0){
							g++;
							dclub1[l] =0;
							dclub2[l] =0;
							if(g > h){
								sort(dclub3+1,dclub3+b+1);
								for(int m = b-2;m>0;m--){
									dclub3[m]=0;
								}
							}
						}
					}
				}
				/*for(int k = 1;k<=b;k++){
					cout<<dclub1[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub2[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub3[k];
				}*/
				for(int k=1;k<=b;k++){
					ans+=dclub1[k];
					ans+=dclub2[k];
					ans+=dclub3[k];
				}
				cout<<ans<<endl;
				ans=0;
				d=0;
			}
			if(i==2){
				cin>>b;
				c = 3*b;
				h = b/2;
				for(int k=1;k<=b;k++){
					cin>>dclub1[k];
					club[++d]=dclub1[k];
					cin>>dclub2[k];
					club[++d]=dclub2[k];
					cin>>dclub3[k];
					club[++d]=dclub3[k];
				}
				sort(club+1,club+c+1);
				for(int k =1;k<=c;k++){
					for(int l=k+1;l<=c;l++){
						if(club[k] == club[l]){
							club[l] = 0;
						}
					}
				}
				for(int k=c;k>0;k--){
					for(int l=1;l<=b;l++){
						if(dclub1[l] == club[k] and club[k] != 0){
							e++;
							dclub2[l] =0;
							dclub3[l] =0;
							if(e > h){
								sort(dclub1+1,dclub1+b+1);
								for(int m = b-2;m>0;m--){
									dclub1[m]=0;
								}
							}
						}
						if(dclub2[l] == club[k] and club[k] !=0){
							f++;
							dclub1[l] =0;
							dclub3[l] =0;
							if(f > h){
								sort(dclub2+1,dclub2+b+1);
								for(int m = b-2;m>0;m--){
									dclub2[m]=0;
								}
							}
						}
						if(dclub3[l] == club[k] and club[k] !=0){
							g++;
							dclub1[l] =0;
							dclub2[l] =0;
							if(g > h){
								sort(dclub3+1,dclub3+b+1);
								for(int m = b-2;m>0;m--){
									dclub3[m]=0;
								}
							}
						}
					}
				}
				/*for(int k = 1;k<=b;k++){
					cout<<dclub1[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub2[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub3[k];
				}*/
				for(int k=1;k<=b;k++){
					ans+=dclub1[k];
					ans+=dclub2[k];
					ans+=dclub3[k];
				}
				cout<<ans<<endl;
				ans=0;
				d=0;
			}
			if(i==3){
				cin>>b;
				c = 3*b;
				h = b/2;
				for(int k=1;k<=b;k++){
					cin>>dclub1[k];
					club[++d]=dclub1[k];
					cin>>dclub2[k];
					club[++d]=dclub2[k];
					cin>>dclub3[k];
					club[++d]=dclub3[k];
				}
				sort(club+1,club+c+1);
				for(int k =1;k<=c;k++){
					for(int l=k+1;l<=c;l++){
						if(club[k] == club[l]){
							club[l] = 0;
						}
					}
				}
				for(int k=c;k>0;k--){
					for(int l=1;l<=b;l++){
						if(dclub1[l] == club[k] and club[k] != 0){
							e++;
							dclub2[l] =0;
							dclub3[l] =0;
							if(e > h){
								sort(dclub1+1,dclub1+b+1);
								for(int m = b-2;m>0;m--){
									dclub1[m]=0;
								}
							}
						}
						if(dclub2[l] == club[k] and club[k] !=0){
							f++;
							dclub1[l] =0;
							dclub3[l] =0;
							if(f > h){
								sort(dclub2+1,dclub2+b+1);
								for(int m = b-2;m>0;m--){
									dclub2[m]=0;
								}
							}
						}
						if(dclub3[l] == club[k] and club[k] !=0){
							g++;
							dclub1[l] =0;
							dclub2[l] =0;
							if(g > h){
								sort(dclub3+1,dclub3+b+1);
								for(int m = b-2;m>0;m--){
									dclub3[m]=0;
								}
							}
						}
					}
				}
				/*for(int k = 1;k<=b;k++){
					cout<<dclub1[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub2[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub3[k];
				}*/
				for(int k=1;k<=b;k++){
					ans+=dclub1[k];
					ans+=dclub2[k];
					ans+=dclub3[k];
				}
				cout<<ans<<endl;
				ans=0;
				d=0;
			}
			if(i==4){
				cin>>b;
				c = 3*b;
				h = b/2;
				for(int k=1;k<=b;k++){
					cin>>dclub1[k];
					club[++d]=dclub1[k];
					cin>>dclub2[k];
					club[++d]=dclub2[k];
					cin>>dclub3[k];
					club[++d]=dclub3[k];
				}
				sort(club+1,club+c+1);
				for(int k =1;k<=c;k++){
					for(int l=k+1;l<=c;l++){
						if(club[k] == club[l]){
							club[l] = 0;
						}
					}
				}
				for(int k=c;k>0;k--){
					for(int l=1;l<=b;l++){
						if(dclub1[l] == club[k] and club[k] != 0){
							e++;
							dclub2[l] =0;
							dclub3[l] =0;
							if(e > h){
								sort(dclub1+1,dclub1+b+1);
								for(int m = b-2;m>0;m--){
									dclub1[m]=0;
								}
							}
						}
						if(dclub2[l] == club[k] and club[k] !=0){
							f++;
							dclub1[l] =0;
							dclub3[l] =0;
							if(f > h){
								sort(dclub2+1,dclub2+b+1);
								for(int m = b-2;m>0;m--){
									dclub2[m]=0;
								}
							}
						}
						if(dclub3[l] == club[k] and club[k] !=0){
							g++;
							dclub1[l] =0;
							dclub2[l] =0;
							if(g > h){
								sort(dclub3+1,dclub3+b+1);
								for(int m = b-2;m>0;m--){
									dclub3[m]=0;
								}
							}
						}
					}
				}
				/*for(int k = 1;k<=b;k++){
					cout<<dclub1[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub2[k];
				}
				cout<<endl;
				for(int k = 1;k<=b;k++){
					cout<<dclub3[k];
				}*/
				for(int k=1;k<=b;k++){
					ans+=dclub1[k];
					ans+=dclub2[k];
					ans+=dclub3[k];
				}
				cout<<ans<<endl;
				ans=0;
				d=0;
			}
		}
	}
}

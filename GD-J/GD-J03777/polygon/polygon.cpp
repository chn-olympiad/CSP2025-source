#include<bits/stdc++.h>
using namespace std;
int n;
int a[10000];

long long cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygob.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]+a[k]>2*max(a[k],max(a[i],a[j]))){
					cnt++;
					//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<endl;
				}
			}
		}
	}
	}
	if(n==4){
			for(int i=1;i<=n;i++){
	 		for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*max(a[k],max(a[i],a[j]))){
						cnt++;
					//	cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<endl;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
	 		for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int o=k+1;o<=n;o++){
					
						if(a[i]+a[j]+a[k]+a[o]>2*max(a[o],max(a[k],max(a[i],a[j])))){
							cnt++;
						//	cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<endl;
						}
					}
				}
			}
		}
	}
	if(n==5){
		for(int i=1;i<=n;i++){
	 		for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*max(a[k],max(a[i],a[j]))){
						cnt++;
						//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<endl;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
	 		for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int o=k+1;o<=n;o++){
					
						if(a[i]+a[j]+a[k]+a[o]>2*max(a[o],max(a[k],max(a[i],a[j])))){
							cnt++;
							//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<endl;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
	 		for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int o=k+1;o<=n;o++){
						for(int b=o+1;b<=n;b++){
						
							if(a[i]+a[j]+a[k]+a[o]+a[b]>2*max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))){
								cnt++;
							//	cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<endl;
							}
						}
					}
				}
			}
		}
	}
	if(n==6){
	
 	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]+a[k]>2*max(a[k],max(a[i],a[j]))){
					cnt++;
					//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<endl;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int o=k+1;o<=n;o++){
				
					if(a[i]+a[j]+a[k]+a[o]>2*max(a[o],max(a[k],max(a[i],a[j])))){
						cnt++;
						//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<endl;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
					
						if(a[i]+a[j]+a[k]+a[o]+a[b]>2*max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))){
							cnt++;
							//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<endl;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
						
							if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]>2*max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j])))))){
								cnt++;
								//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
							}
						}
					}
				}
			}
		}
	}
	}
		if(n==7){
	
 	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]+a[k]>2*max(a[k],max(a[i],a[j]))){
					cnt++;
					//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<endl;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int o=k+1;o<=n;o++){
				
					if(a[i]+a[j]+a[k]+a[o]>2*max(a[o],max(a[k],max(a[i],a[j])))){
						cnt++;
						//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<endl;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
					
						if(a[i]+a[j]+a[k]+a[o]+a[b]>2*max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))){
							cnt++;
							//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<endl;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
						
							if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]>2*max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j])))))){
								cnt++;
								//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
							
								if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]>2*max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))))){
									cnt++;
									//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
								}
							}
						}
					}
				}
			}
		}
	}
	}
		if(n==8){
	
 	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]+a[k]>2*max(a[k],max(a[i],a[j]))){
					cnt++;
					//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<endl;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int o=k+1;o<=n;o++){
				
					if(a[i]+a[j]+a[k]+a[o]>2*max(a[o],max(a[k],max(a[i],a[j])))){
						cnt++;
						//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<endl;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
					
						if(a[i]+a[j]+a[k]+a[o]+a[b]>2*max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))){
							cnt++;
							//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<endl;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
						
							if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]>2*max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j])))))){
								cnt++;
								//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
							
								if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]>2*max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))))){
									cnt++;
									//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
								for(int b8=b7+1;b8<=n;b8++){
								
									if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]+a[b8]>2*max(a[b8],max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j])))))))){
										cnt++;
										//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	}
		if(n==9){
	
 	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]+a[k]>2*max(a[k],max(a[i],a[j]))){
					cnt++;
					//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<endl;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int o=k+1;o<=n;o++){
				
					if(a[i]+a[j]+a[k]+a[o]>2*max(a[o],max(a[k],max(a[i],a[j])))){
						cnt++;
						//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<endl;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
					
						if(a[i]+a[j]+a[k]+a[o]+a[b]>2*max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))){
							cnt++;
							//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<endl;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
						
							if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]>2*max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j])))))){
								cnt++;
								//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
							
								if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]>2*max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))))){
									cnt++;
									//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
								for(int b8=b7+1;b8<=n;b8++){
								
									if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]+a[b8]>2*max(a[b8],max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j])))))))){
										cnt++;
										//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
								for(int b8=b7+1;b8<=n;b8++){
								for(int b9=b8+1;b9<=n;b9++){
								
									if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]+a[b8]+a[b9]>2*max(a[b9],max(a[b8],max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))))))){
										cnt++;
										//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
									}
								}
								}
							}
						}
					}
				}
			}
		}
	}
	}
	if(n==10){
	
 	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]+a[k]>2*max(a[k],max(a[i],a[j]))){
					cnt++;
					//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<endl;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int o=k+1;o<=n;o++){
				
					if(a[i]+a[j]+a[k]+a[o]>2*max(a[o],max(a[k],max(a[i],a[j])))){
						cnt++;
						//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<endl;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
					
						if(a[i]+a[j]+a[k]+a[o]+a[b]>2*max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))){
							cnt++;
							//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<endl;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
						
							if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]>2*max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j])))))){
								cnt++;
								//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
							
								if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]>2*max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))))){
									cnt++;
									//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
								for(int b8=b7+1;b8<=n;b8++){
								
									if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]+a[b8]>2*max(a[b8],max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j])))))))){
										cnt++;
										//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
								for(int b8=b7+1;b8<=n;b8++){
									for(int b9=b8+1;b9<=n;b9++){
									
										if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]+a[b8]+a[b9]>2*max(a[b9],max(a[b8],max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))))))){
											cnt++;
											//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
										}
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
								for(int b8=b7+1;b8<=n;b8++){
									for(int b9=b8+1;b9<=n;b9++){
										for(int b10=b9+1;b10<=n;b10++){
										
											if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]+a[b8]+a[b9]+a[b10]>2*max(a[b10],max(a[b9],max(a[b8],max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j])))))))))){
												cnt++;
												//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
											}
										}
									}
								}	
							}
						}
					}
				}
			}
		}
	}
	}
	if(n==11){
	
 	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]+a[k]>2*max(a[k],max(a[i],a[j]))){
					cnt++;
					//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<endl;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int o=k+1;o<=n;o++){
				
					if(a[i]+a[j]+a[k]+a[o]>2*max(a[o],max(a[k],max(a[i],a[j])))){
						cnt++;
						//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<endl;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
					
						if(a[i]+a[j]+a[k]+a[o]+a[b]>2*max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))){
							cnt++;
							//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<endl;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
						
							if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]>2*max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j])))))){
								cnt++;
								//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
							
								if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]>2*max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))))){
									cnt++;
									//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
								for(int b8=b7+1;b8<=n;b8++){
								
									if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]+a[b8]>2*max(a[b8],max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j])))))))){
										cnt++;
										//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
								for(int b8=b7+1;b8<=n;b8++){
									for(int b9=b8+1;b9<=n;b9++){
									
										if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]+a[b8]+a[b9]>2*max(a[b9],max(a[b8],max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))))))){
											cnt++;
											//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
										}
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
								for(int b8=b7+1;b8<=n;b8++){
									for(int b9=b8+1;b9<=n;b9++){
										for(int b10=b9+1;b10<=n;b10++){
										
											if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]+a[b8]+a[b9]+a[b10]>2*max(a[b10],max(a[b9],max(a[b8],max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j])))))))))){
												cnt++;
												//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
											}
										}
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
								for(int b8=b7+1;b8<=n;b8++){
									for(int b9=b8+1;b9<=n;b9++){
										for(int b10=b9+1;b10<=n;b10++){
											for(int b11=b10+1;b11<=n;b11++){
											
												if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]+a[b8]+a[b9]+a[b10]+a[b11]>2*max(a[b11],max(a[b10],max(a[b9],max(a[b8],max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))))))))){
													cnt++;
													//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
												}
											}
										}
									}
								}	
							}
						}
					}
				}
			}
		}
	}
	}
		if(n==12){
	
 	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]+a[k]>2*max(a[k],max(a[i],a[j]))){
					cnt++;
					//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<endl;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int o=k+1;o<=n;o++){
				
					if(a[i]+a[j]+a[k]+a[o]>2*max(a[o],max(a[k],max(a[i],a[j])))){
						cnt++;
						//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<endl;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
					
						if(a[i]+a[j]+a[k]+a[o]+a[b]>2*max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))){
							cnt++;
							//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<endl;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
						
							if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]>2*max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j])))))){
								cnt++;
								//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
							
								if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]>2*max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))))){
									cnt++;
									//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
								for(int b8=b7+1;b8<=n;b8++){
								
									if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]+a[b8]>2*max(a[b8],max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j])))))))){
										cnt++;
										//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
								for(int b8=b7+1;b8<=n;b8++){
									for(int b9=b8+1;b9<=n;b9++){
									
										if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]+a[b8]+a[b9]>2*max(a[b9],max(a[b8],max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))))))){
											cnt++;
											//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
										}
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
								for(int b8=b7+1;b8<=n;b8++){
									for(int b9=b8+1;b9<=n;b9++){
										for(int b10=b9+1;b10<=n;b10++){
										
											if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]+a[b8]+a[b9]+a[b10]>2*max(a[b10],max(a[b9],max(a[b8],max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j])))))))))){
												cnt++;
												//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
											}
										}
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
								for(int b8=b7+1;b8<=n;b8++){
									for(int b9=b8+1;b9<=n;b9++){
										for(int b10=b9+1;b10<=n;b10++){
											for(int b11=b10+1;b11<=n;b11++){
											
												if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]+a[b8]+a[b9]+a[b10]+a[b11]>2*max(a[b11],max(a[b10],max(a[b9],max(a[b8],max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))))))))){
													cnt++;
													//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
												}
											}
										}
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
								for(int b8=b7+1;b8<=n;b8++){
									for(int b9=b8+1;b9<=n;b9++){
										for(int b10=b9+1;b10<=n;b10++){
											for(int b11=b10+1;b11<=n;b11++){
												for(int b12=b11+1;b12<=n;b12++){
												
													if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]+a[b8]+a[b9]+a[b10]+a[b11]+a[b12]>2*max(a[b12],max(a[b11],max(a[b10],max(a[b9],max(a[b8],max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j])))))))))))){
														cnt++;
														//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
													}
												}
											}
										}
									}
								}	
							}
						}
					}
				}
			}
		}
	}
	}
	else{
		
	
 	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]+a[k]>2*max(a[k],max(a[i],a[j]))){
					cnt++;
					//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<endl;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int o=k+1;o<=n;o++){
				
					if(a[i]+a[j]+a[k]+a[o]>2*max(a[o],max(a[k],max(a[i],a[j])))){
						cnt++;
						//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<endl;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
					
						if(a[i]+a[j]+a[k]+a[o]+a[b]>2*max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))){
							cnt++;
							//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<endl;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
						
							if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]>2*max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j])))))){
								cnt++;
								//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
							
								if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]>2*max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))))){
									cnt++;
									//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
								for(int b8=b7+1;b8<=n;b8++){
								
									if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]+a[b8]>2*max(a[b8],max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j])))))))){
										cnt++;
										//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
								for(int b8=b7+1;b8<=n;b8++){
									for(int b9=b8+1;b9<=n;b9++){
									
										if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]+a[b8]+a[b9]>2*max(a[b9],max(a[b8],max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))))))){
											cnt++;
											//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
										}
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
								for(int b8=b7+1;b8<=n;b8++){
									for(int b9=b8+1;b9<=n;b9++){
										for(int b10=b9+1;b10<=n;b10++){
										
											if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]+a[b8]+a[b9]+a[b10]>2*max(a[b10],max(a[b9],max(a[b8],max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j])))))))))){
												cnt++;
												//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
											}
										}
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
								for(int b8=b7+1;b8<=n;b8++){
									for(int b9=b8+1;b9<=n;b9++){
										for(int b10=b9+1;b10<=n;b10++){
											for(int b11=b10+1;b11<=n;b11++){
											
												if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]+a[b8]+a[b9]+a[b10]+a[b11]>2*max(a[b11],max(a[b10],max(a[b9],max(a[b8],max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))))))))){
													cnt++;
													//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
												}
											}
										}
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
								for(int b8=b7+1;b8<=n;b8++){
									for(int b9=b8+1;b9<=n;b9++){
										for(int b10=b9+1;b10<=n;b10++){
											for(int b11=b10+1;b11<=n;b11++){
												for(int b12=b11+1;b12<=n;b12++){
												
													if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]+a[b8]+a[b9]+a[b10]+a[b11]+a[b12]>2*max(a[b12],max(a[b11],max(a[b10],max(a[b9],max(a[b8],max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j])))))))))))){
														cnt++;
														//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
													}
												}
											}
										}
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
								for(int b8=b7+1;b8<=n;b8++){
									for(int b9=b8+1;b9<=n;b9++){
										for(int b10=b9+1;b10<=n;b10++){
											for(int b11=b10+1;b11<=n;b11++){
												for(int b12=b11+1;b12<=n;b12++){
													for(int b13=b12+1;b13<=n;b13++){
													
														if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]+a[b8]+a[b9]+a[b10]+a[b11]+a[b12]+a[b13]>2*max(a[b13],max(a[b12],max(a[b11],max(a[b10],max(a[b9],max(a[b8],max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j]))))))))))))){
															cnt++;
															//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
														}
													}
												}
											}
										}
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
				for(int o=k+1;o<=n;o++){
					for(int b=o+1;b<=n;b++){
						for(int b6=o+1;b6<=n;b6++){
							for(int b7=b6+1;b7<=n;b7++){
								for(int b8=b7+1;b8<=n;b8++){
									for(int b9=b8+1;b9<=n;b9++){
										for(int b10=b9+1;b10<=n;b10++){
											for(int b11=b10+1;b11<=n;b11++){
												for(int b12=b11+1;b12<=n;b12++){
													for(int b13=b12+1;b13<=n;b13++){
														for(int b14=b13+1;b14<=n;b14++){
														
															if(a[i]+a[j]+a[k]+a[o]+a[b]+a[b6]+a[b7]+a[b8]+a[b9]+a[b10]+a[b11]+a[b12]+a[b13]+a[b14]>2*max(a[b14],max(a[b13],max(a[b12],max(a[b11],max(a[b10],max(a[b9],max(a[b8],max(a[b7],max(a[b6],max(a[b],max(a[o],max(a[k],max(a[i],a[j])))))))))))))){
																cnt++;
																//cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[o]<<" "<<a[b]<<" "<<a[b6]<<" "<<endl;
															}
														}
													}
												}
											}
										}
									}
								}	
							}
						}
					}
				}
			}
		}
	}
	} 
	cout<<cnt%998244353;
	
	/*
	5
	2 2 3 8 10
	
	20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1
	*/
	return 0;
} 

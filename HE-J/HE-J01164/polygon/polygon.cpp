#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int cnt=0;
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n>=3){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int zuida=max(a[i],a[j]);
				for(int k=j+1;k<n;k++){
					if(a[i]+a[j]+a[k]>max(zuida,a[k])*2){
						cnt++;
					}
				}
			}
		}
	}
	if(n>=4){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int zuida=max(a[i],a[j]);
				for(int k=j+1;k<n;k++){
					zuida=max(zuida,a[k]);
					for(int h=k+1;h<n;h++){
						if(a[i]+a[j]+a[k]+a[h]>2*max(zuida,a[h])){
							cnt++;
						}
					}
					
				}
			}
		}
	}
	if(n>=5){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int zuida=max(a[i],a[j]);
				for(int k=j+1;k<n;k++){
					zuida=max(zuida,a[k]);
					for(int h=k+1;h<n;h++){
						zuida=max(zuida,a[h]);
						for(int g=h+1;g<n;g++){
							if(a[i]+a[j]+a[k]+a[h]+a[g]>max(zuida,a[g])*2){
							cnt++;
							}
						}
						
					}
					
				}
			}
		}
	}
	if(n>=6){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int zuida=max(a[i],a[j]);
				for(int k=j+1;k<n;k++){
					zuida=max(zuida,a[k]);
					for(int h=k+1;h<n;h++){
						zuida=max(zuida,a[h]);
						for(int g=h+1;g<n;g++){
							zuida=max(zuida,a[g]);
							for(int x=0;x<n;x++){
								if(a[i]+a[j]+a[k]+a[h]+a[g]+a[x]>max(zuida,a[x])*2){
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
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int zuida=max(a[i],a[j]);
				for(int k=j+1;k<n;k++){
					zuida=max(zuida,a[k]);
					for(int h=k+1;h<n;h++){
						zuida=max(zuida,a[h]);
						for(int g=h+1;g<n;g++){
							zuida=max(zuida,a[g]);
							for(int x=0;x<n;x++){
								zuida=max(zuida,a[x]);
								for(int y=0;y<n;y++){
									if(a[i]+a[j]+a[k]+a[h]+a[g]+a[x]>max(zuida,a[x])*2){
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
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int zuida=max(a[i],a[j]);
				for(int k=j+1;k<n;k++){
					zuida=max(zuida,a[k]);
					for(int h=k+1;h<n;h++){
						zuida=max(zuida,a[h]);
						for(int g=h+1;g<n;g++){
							zuida=max(zuida,a[g]);
							for(int x=0;x<n;x++){
								zuida=max(zuida,a[x]);
								for(int y=0;y<n;y++){
									zuida=max(zuida,a[y]);
									for(int z=0;z<n;z++){
										if(a[i]+a[j]+a[k]+a[h]+a[g]+a[x]+a[y]+a[z]>max(zuida,a[z])*2){
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
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int zuida=max(a[i],a[j]);
				for(int k=j+1;k<n;k++){
					zuida=max(zuida,a[k]);
					for(int h=k+1;h<n;h++){
						zuida=max(zuida,a[h]);
						for(int g=h+1;g<n;g++){
							zuida=max(zuida,a[g]);
							for(int x=0;x<n;x++){
								zuida=max(zuida,a[x]);
								for(int y=0;y<n;y++){
									zuida=max(zuida,a[y]);
									for(int z=0;z<n;z++){
										zuida=max(zuida,a[z]);
										for(int t=0;t<n;t++){
											if(a[i]+a[j]+a[k]+a[h]+a[g]+a[x]+a[z]+a[y]+a[t]>max(zuida,a[t])*2){
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
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int zuida=max(a[i],a[j]);
				for(int k=j+1;k<n;k++){
					zuida=max(zuida,a[k]);
					for(int h=k+1;h<n;h++){
						zuida=max(zuida,a[h]);
						for(int g=h+1;g<n;g++){
							zuida=max(zuida,a[g]);
							for(int x=0;x<n;x++){
								zuida=max(zuida,a[x]);
								for(int y=0;y<n;y++){
									zuida=max(zuida,a[y]);
									for(int z=0;z<n;z++){
										zuida=max(zuida,a[z]);
										for(int t=0;t<n;t++){
											zuida=max(zuida,t);
											for(int v=0;v<n;v++){
												if(a[i]+a[j]+a[k]+a[h]+a[g]+a[x]+a[z]+a[y]+a[t]>max(zuida,a[t])*2){
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
	}
	cout<<cnt;
	return 0;
}



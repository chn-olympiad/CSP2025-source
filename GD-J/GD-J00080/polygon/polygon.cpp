#include<bits/stdc++.h>
using namespace std;
long long n,a[1000010],s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(3<=n){
		for(int i=1;i<=n;i++){
		    for(int j=i+1;j<=n;j++){
			    for(int k=j+1;k<=n;k++){
			        if(a[i]+a[j]+a[k]>a[k]*2){
			            s++;
					}
		        }
		    } 
	    }
	}
    if(4<=n){
		for(int i=1;i<=n;i++){
		    for(int j=i+1;j<=n;j++){
			    for(int k=j+1;k<=n;k++){
			        for(int z=k+1;z<=n;z++){
			            if(a[i]+a[j]+a[k]+a[z]>a[z]*2){
			                s++;
						}
		            }
		        }
		    } 
	    }
	}
	if(5<=n){
		for(int i=1;i<=n;i++){
		    for(int j=i+1;j<=n;j++){
			    for(int k=j+1;k<=n;k++){
			        for(int z=k+1;z<=n;z++){
			            for(int q=z+1;q<=n;q++){
			                if(a[i]+a[j]+a[k]+a[z]+a[q]>a[q]*2)s++;
		                }
		            }
		        }
		    } 
	    }
	}
	if(6<=n){
		for(int i=1;i<=n;i++){
		    for(int j=i+1;j<=n;j++){
			    for(int k=j+1;k<=n;k++){
			        for(int z=k+1;z<=n;z++){
			            for(int q=z+1;q<=n;q++){
			                for(int w=q+1;w<=n;w++){
			                    if(a[i]+a[j]+a[k]+a[z]+a[q]+a[w]>a[w]*2)s++;
		                    }
		                }
		            }
		        }
		    } 
	    }
	}
	if(7<=n){
		for(int i=1;i<=n;i++){
		    for(int j=i+1;j<=n;j++){
			    for(int k=j+1;k<=n;k++){
			        for(int z=k+1;z<=n;z++){
			            for(int q=z+1;q<=n;q++){
			                for(int w=q+1;w<=n;w++){
			                    for(int e=w+1;e<=n;e++){
			                        if(a[i]+a[j]+a[k]+a[z]+a[q]+a[w]+a[e]>a[e]*2)s++;
		                        }
		                    }
		                }
		            }
		        }
		    } 
	    }
	}
	if(8<=n){
		for(int i=1;i<=n;i++){
		    for(int j=i+1;j<=n;j++){
			    for(int k=j+1;k<=n;k++){
			        for(int z=k+1;z<=n;z++){
			            for(int q=z+1;q<=n;q++){
			                for(int w=q+1;w<=n;w++){
			                    for(int e=w+1;e<=n;e++){
			                        for(int r=e+1;r<=n;r++){
			                            if(a[i]+a[j]+a[k]+a[z]+a[q]+a[w]+a[e]+a[r]>a[r]*2)s++;
		                            }
		                        }
		                    }
		                }
		            }
		        }
		    } 
	    }
	}
	if(9<=n){
		for(int i=1;i<=n;i++){
		    for(int j=i+1;j<=n;j++){
			    for(int k=j+1;k<=n;k++){
			        for(int z=k+1;z<=n;z++){
			            for(int q=z+1;q<=n;q++){
			                for(int w=q+1;w<=n;w++){
			                    for(int e=w+1;e<=n;e++){
			                        for(int r=e+1;r<=n;r++){
			                            for(int t=r+1;t<=n;t++){
			                                if(a[i]+a[j]+a[k]+a[z]+a[q]+a[w]+a[e]+a[r]+a[t]>a[t]*2)s++;
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
	if(10<=n){
		for(int i=1;i<=n;i++){
		    for(int j=i+1;j<=n;j++){
			    for(int k=j+1;k<=n;k++){
			        for(int z=k+1;z<=n;z++){
			            for(int q=z+1;q<=n;q++){
			                for(int w=q+1;w<=n;w++){
			                    for(int e=w+1;e<=n;e++){
			                        for(int r=e+1;r<=n;r++){
			                            for(int t=r+1;t<=n;t++){
			                                for(int o=t+1;o<=n;o++){
			                                    if(a[i]+a[j]+a[k]+a[z]+a[q]+a[w]+a[e]+a[r]+a[t]+a[o]>a[o]*2)s++;
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
	cout<<s;
	return 0;
}

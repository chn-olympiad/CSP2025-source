#include<bits/stdc++.h>
using namespace std;
int a[5001];
int m=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long ans=0,z=1,c=1,b=1;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n>10){
		for(int i=1;i<=n;i++){
		    z*=i;
		    z%=m;
		}
		for(int i=3;i<=n;i++){
		    for(int j=1;j<=n-i;j++){
		        c*=j;
		        c%=m;
		    }
		    for(int j=1;j<=i;j++){
		        b*=j;
		        b%=m;
		    }
		    
		    ans+=(z/c)/b;
		    ans%=m;
			c=1;
		    b=1;
		}
		cout<<ans;
		return 0;
	}
	if(n==1||n==2){
		cout<<"0";
		return 0;
	}
	else if(n>=3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
		        for(int k=j+1;k<=n;k++){
		            if((a[i]+a[j]+a[k])>2*a[k]){
		            	ans++;
					}
	            }
	        }
	    }
	}
	if(n>=4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
		        for(int k=j+1;k<=n;k++){
		        	for(int q=k+1;q<=n;q++){
		        		if((a[i]+a[j]+a[k]+a[q])>2*a[q]){
		            	    ans++;
					    }
	                }
	            }
	        }
	    }
	}
	else{
		cout<<ans;
		return 0;
	}
	if(n>=5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
		        for(int k=j+1;k<=n;k++){
		        	for(int q=k+1;q<=n;q++){
		        		for(int w=q+1;w<=n;w++){
		        		    if((a[i]+a[j]+a[k]+a[q]+a[w])>2*a[w]){
		            	        ans++;
					        }
	                    }
	                }
	            }
	        }
	    }
	}
	else{
		cout<<ans;
		return 0;
	}
	if(n>=6){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
		        for(int k=j+1;k<=n;k++){
		        	for(int q=k+1;q<=n;q++){
		        		for(int w=q+1;w<=n;w++){
		        		    for(int e=w+1;e<=n;e++){
		        		        if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e])>2*a[e]){
		            	            ans++;
					            }
	                        }
	                    }
	                }
	            }
	        }
	    }
	}
	else{
		cout<<ans;
		return 0;
	}
	if(n>=7){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
		        for(int k=j+1;k<=n;k++){
		        	for(int q=k+1;q<=n;q++){
		        		for(int w=q+1;w<=n;w++){
		        		    for(int e=w+1;e<=n;e++){
		        		        for(int r=e+1;r<=n;r++){
		        		            if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r])>2*a[r]){
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
	else{
		cout<<ans;
		return 0;
	}
	if(n>=8){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
		        for(int k=j+1;k<=n;k++){
		        	for(int q=k+1;q<=n;q++){
		        		for(int w=q+1;w<=n;w++){
		        		    for(int e=w+1;e<=n;e++){
		        		        for(int r=e+1;r<=n;r++){
		        		            for(int t=r+1;t<=n;t++){
		        		                if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t])>2*a[t]){
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
	else{
		cout<<ans;
		return 0;
	}
	if(n>=9){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
		        for(int k=j+1;k<=n;k++){
		        	for(int q=k+1;q<=n;q++){
		        		for(int w=q+1;w<=n;w++){
		        		    for(int e=w+1;e<=n;e++){
		        		        for(int r=e+1;r<=n;r++){
		        		            for(int t=r+1;t<=n;t++){
		        		                for(int y=t+1;y<=n;y++){
		        		                    if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y])>2*a[y]){
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
	else{
		cout<<ans;
		return 0;
	}
	if(n==10){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
		        for(int k=j+1;k<=n;k++){
		        	for(int q=k+1;q<=n;q++){
		        		for(int w=q+1;w<=n;w++){
		        		    for(int e=w+1;e<=n;e++){
		        		        for(int r=e+1;r<=n;r++){
		        		            for(int t=r+1;t<=n;t++){
		        		                for(int y=t+1;y<=n;y++){
		        		                    for(int u=y+1;u<=n;u++){
		        		                        if((a[i]+a[j]+a[k]+a[q]+a[w]+a[e]+a[r]+a[t]+a[y]+a[u])>2*a[u]){
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
	cout<<ans;
	return 0;
}

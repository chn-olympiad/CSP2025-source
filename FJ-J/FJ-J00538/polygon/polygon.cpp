#include <bits/stdc++.h>
using namespace std;
int n,a[5100],ans;

int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int c=3;c<=n;c++){
		if(c==3){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					if(a[i]+a[j]>a[k] && a[i]+a[k]>a[j] && a[j]+a[k]>a[i]){
						ans++;
					}
				}
			}
		}
	}else if(c==4){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int x=k;x<=n;x++){
						if(2*(a[i]+a[j]+a[k]+a[x])>2*(max(a[i],max(a[j],max(a[k],a[x])))){
							ans++;
						}
					}
				}
			}
		}
	}else if(c==5){
			for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int x=k;x<=n;x++){
						for(int y=x;y<=n;y++){
								if(2*(a[i]+a[j]+a[k]+a[x]+a[y])>2*(max(a[i],max(a[j],max(a[k],max(a[x],a[y]))))){
									ans++;
							}
						}
					}
				}
			}
		}
	}else if(c==6){
			for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int x=k;x<=n;x++){
						for(int y=x;y<=n;y++){
							for(int z=y;z<=n;z++){
								if(2*(a[i]+a[j]+a[k]+a[x]+a[y]+a[z])>2*(max(a[i],max(a[j],max(a[k],max(a[x],max(a[y],a[z])))))){
									ans++;
							}
							}
								
						}
					}
				}
			}
		}
	}else if(c==7){
			for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int x=k;x<=n;x++){
						for(int y=x;y<=n;y++){
							for(int z=y;z<=n;z++){
								for(int q=z;q<=n;q++){
									if(2*(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]+a[q])>2*(max(a[i],max(a[j],max(a[k],max(a[x],max(a[y],max(a[z],a[q]))))))){
									ans++;
							}
								}
								
							}
								
						}
					}
				}
			}
		}
	}else if(c==8){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int x=k;x<=n;x++){
						for(int y=x;y<=n;y++){
							for(int z=y;z<=n;z++){
								for(int q=z;q<=n;q++){
									for(int p=q;p<=n;p++){
											if(2*(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]+a[q]+a[p])>2*(max(a[i],max(a[j],max(a[k],max(a[x],max(a[y],max(a[z],max(a[q],a[p])))))))){
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
	}else if(c==9){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int x=k;x<=n;x++){
						for(int y=x;y<=n;y++){
							for(int z=y;z<=n;z++){
								for(int q=z;q<=n;q++){
									for(int p=q;p<=n;p++){
										for(int d=p;d<=p;d++){
											if(2*(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]+a[q]+a[p]+a[d])>2*(max(a[i],max(a[j],max(a[k],max(a[x],max(a[y],max(a[z],max(a[q],max(a[p],a[d]))))))))){
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
	}else if(c==10){
			for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					for(int x=k;x<=n;x++){
						for(int y=x;y<=n;y++){
							for(int z=y;z<=n;z++){
								for(int q=z;q<=n;q++){
									for(int p=q;p<=n;p++){
										for(int d=p;d<=p;d++){
											for(int f=d;f<=n;f++){
													if(2*(a[i]+a[j]+a[k]+a[x]+a[y]+a[z]+a[q]+a[p]+a[d]+a[f])>2*(max(a[i],max(a[j],max(a[k],max(a[x],max(a[y],max(a[z],max(a[q],max(a[p],max(a[d],a[f])))))))))){
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
} 

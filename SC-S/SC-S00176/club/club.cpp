#include<bits/stdc++.h>
using namespace std;
int t;
int n[10];
int tx[10];
int ma(int x,int y,int z){
	if(x>=y){
		if(x>=z){
			return x;
		}else{
			return z;
		}
	}else{
		if(y>=z){
			return y;
		}else{
			return z;
		}
	}
}
int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		long long a[10005],b[10005],c[10005];
		long long ax[10005],bx[10005],cx[10005];
		long long cnta,cntb,cntc;
		for(int j=1;j<=n[i];j++){
			cin>>a[j]>>b[j]>>c[j];
			ax[j]=a[j];
			bx[j]=b[j];
			cx[j]=c[j];
		}
		for(int j=1;j<=n[i];j++){
			int o=ma(a[j],b[j],c[j]);
			if(o==a[j]){
				cnta++;
			}
			if(o==b[j]){
				cntb++;
			}
			if(o==c[j]){
				cntc++;
			}
		}
		sort(ax+1,ax+n[i]+1);
		sort(bx+1,bx+n[i]+1);
		sort(cx+1,cx+n[i]+1);
		for(int j=1;j<=n[i];j++){
			int o=ma(a[j],b[j],c[j]);
			if(o==a[j]){
				if(cnta<=n[i]/2){
					tx[i]+=a[j];
				}else{
					if(a[j]>=ax[n[i]/2+1]){
						tx[i]+=a[j];
					}
				}
			}else{
				if(o==b[j]){
					if(cntb<=n[i]/2){
						tx[i]+=b[j];
					}else{
						if(b[j]>=bx[n[i]/2+1]){
							tx[i]+=b[j];
						}
					}
				}else{
					if(o==c[j]){
						if(cntc<=n[i]/2){
							tx[i]+=c[j];
						}else{
							if(c[j]>=cx[n[i]/2+1]){
								tx[i]+=c[j];
							}
						}
					}else{
						for(int k=1;k<=n[i];k++){
							int m=ma(a[k],b[k],c[k]);
							if(o==a[j]&&m==a[k]){
								int y=max(b[k],c[k]);
								int z=max(b[j],c[j]);
								if(m-y<o-z){
									tx[i]+=a[j];
									tx[i]-=a[k];
									tx[i]+=y;
								}else{
									if(z==b[j]){
										if(cntb+1<=n[i]/2||z>=bx[n[i]/2+1]){
											tx[i]+=z;
										}else{
											tx[i]+=c[j];
										}
									}
								}
							}
							if(o==b[j]&&m==b[j]){
								int y=max(a[k],c[k]);
								int z=max(a[j],c[j]);
								if(m-y<o-z){
									tx[i]+=b[j];
									tx[i]-=b[k];
									tx[i]+=y;
								}else{
									if(z==a[j]){
										if(cntb+1<=n[i]/2||z>=ax[n[i]/2+1]){
											tx[i]+=z;
										}else{
											tx[i]+=c[j];
										}
									}
								}
							}
							if(o==c[j]&&m==c[j]){
								int y=max(a[k],b[k]);
								int z=max(a[j],b[j]);
								if(m-y<o-z){
									tx[i]+=c[j];
									tx[i]-=c[k];
									tx[i]+=y;
								}else{
									if(z==a[j]){
										if(cntb+1<=n[i]/2||z>=ax[n[i]/2+1]){
											tx[i]+=z;
										}else{
											tx[i]+=c[j];
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
	for(int i=1;i<=t;i++){
		cout<<tx[i]<<endl;
	}
	return 0;
}
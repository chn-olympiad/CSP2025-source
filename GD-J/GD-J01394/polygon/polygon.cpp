#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5010;
const int mod=998244353;
int n;
int a[N];
int ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		int sum=0,maxn=0;
		for(int i=1;i<=n;i++){
			sum+=a[i],maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn){
			ans++;
		}
		cout<<ans;
		return 0;
	}
	if(n==4){
		int sum=0,maxn=0;
		for(int i=1;i<=n;i++){
			sum=0,maxn=0;
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				sum+=a[j],maxn=max(maxn,a[j]);
			}
			if(sum>2*maxn) ans++;
		}
		sum=0,maxn=0;
		for(int i=1;i<=n;i++){
			sum+=a[i],maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn) ans++;
		cout<<ans;
		return 0;
	}
	if(n==5){
		int sum=0,maxn=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=a[i]+a[j]+a[k];
					maxn=max({a[i],a[j],a[k]});
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			sum=0,maxn=0;
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				sum+=a[j],maxn=max(maxn,a[j]);
			}
			if(sum>2*maxn) ans++;
		}
		sum=0,maxn=0;
		for(int i=1;i<=n;i++){
			sum+=a[i],maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn) ans++;
		cout<<ans%mod;
		return 0;
	}
	if(n==6){
		int sum=0,maxn=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=a[i]+a[j]+a[k];
					maxn=max({a[i],a[j],a[k]});
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				sum=0,maxn=0;
				for(int k=1;k<=n;k++){
					if(k==i||k==j) continue;
					sum+=a[k],maxn=max(maxn,a[k]);
				}
				if(sum>2*maxn) ans++;
			}
		}
		for(int i=1;i<=n;i++){
			sum=0,maxn=0;
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				sum+=a[j],maxn=max(maxn,a[j]);
			}
			if(sum>2*maxn) ans++;
		}
		sum=0,maxn=0;
		for(int i=1;i<=n;i++){
			sum+=a[i],maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn) ans++;
		cout<<ans%mod;
		return 0;
	}
	if(n==7){
		int sum=0,maxn=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=a[i]+a[j]+a[k];
					maxn=max({a[i],a[j],a[k]});
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=a[i]+a[j]+a[k]+a[l];
						maxn=max({a[i],a[j],a[k],a[l]});
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				sum=0,maxn=0;
				for(int k=1;k<=n;k++){
					if(k==i||k==j) continue;
					sum+=a[k],maxn=max(maxn,a[k]);
				}
				if(sum>2*maxn) ans++;
			}
		}
		for(int i=1;i<=n;i++){
			sum=0,maxn=0;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				sum+=a[j],maxn=max(maxn,a[j]);
			}
			if(sum>2*maxn) ans++;
		}
		sum=0,maxn=0;
		for(int i=1;i<=n;i++){
			sum+=a[i],maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn) ans++;
		cout<<ans%mod;
		return 0;
	}
	if(n==8){
		int sum=0,maxn=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=a[i]+a[j]+a[k];
					maxn=max({a[i],a[j],a[k]});
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=a[i]+a[j]+a[k]+a[l];
						maxn=max({a[i],a[j],a[k],a[l]});
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=0,maxn=0;
					for(int l=1;l<=n;l++){
						if(l==i||l==j||l==k) continue;
						sum+=a[l],maxn=max(maxn,a[l]);
					}
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				sum=0,maxn=0;
				for(int k=1;k<=n;k++){
					if(k==i||k==j) continue;
					sum+=a[k],maxn=max(maxn,a[k]);
				}
				if(sum>2*maxn) ans++;
			}
		}
		for(int i=1;i<=n;i++){
			sum=0,maxn=0;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				sum+=a[j],maxn=max(maxn,a[j]);
			}
			if(sum>2*maxn) ans++;
		}
		sum=0,maxn=0;
		for(int i=1;i<=n;i++){
			sum+=a[i],maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn) ans++;
		cout<<ans%mod;
		return 0;
	}
	if(n==9){
		int sum=0,maxn=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=a[i]+a[j]+a[k];
					maxn=max({a[i],a[j],a[k]});
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=a[i]+a[j]+a[k]+a[l];
						maxn=max({a[i],a[j],a[k],a[l]});
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-4;i++){
			for(int j=i+1;j<=n-3;j++){
				for(int k=j+1;k<=n-2;k++){
					for(int l=k+1;l<=n-1;l++){
						for(int o=l+1;o<=n;o++){
							sum=a[i]+a[j]+a[k]+a[l]+a[o];
							maxn=max({a[i],a[j],a[k],a[l],a[o]});
							if(sum>2*maxn) ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=0,maxn=0;
					for(int l=1;l<=n;l++){
						if(l==i||l==j||l==k) continue;
						sum+=a[l],maxn=max(maxn,a[l]);
					}
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				sum=0,maxn=0;
				for(int k=1;k<=n;k++){
					if(k==i||k==j) continue;
					sum+=a[k],maxn=max(maxn,a[k]);
				}
				if(sum>2*maxn) ans++;
			}
		}
		for(int i=1;i<=n;i++){
			sum=0,maxn=0;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				sum+=a[j],maxn=max(maxn,a[j]);
			}
			if(sum>2*maxn) ans++;
		}
		sum=0,maxn=0;
		for(int i=1;i<=n;i++){
			sum+=a[i],maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn) ans++;
		cout<<ans%mod;
		return 0;
	}
	if(n==10){
		int sum=0,maxn=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=a[i]+a[j]+a[k];
					maxn=max({a[i],a[j],a[k]});
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=a[i]+a[j]+a[k]+a[l];
						maxn=max({a[i],a[j],a[k],a[l]});
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-4;i++){
			for(int j=i+1;j<=n-3;j++){
				for(int k=j+1;k<=n-2;k++){
					for(int l=k+1;l<=n-1;l++){
						for(int o=l+1;o<=n;o++){
							sum=a[i]+a[j]+a[k]+a[l]+a[o];
							maxn=max({a[i],a[j],a[k],a[l],a[o]});
							if(sum>2*maxn) ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=0,maxn=0;
						for(int o=1;o<=n;o++){
							if(o==i||o==j||o==k||o==l) continue;
							sum+=a[o],maxn=max(maxn,a[o]);
						}
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=0,maxn=0;
					for(int l=1;l<=n;l++){
						if(l==i||l==j||l==k) continue;
						sum+=a[l],maxn=max(maxn,a[l]);
					}
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				sum=0,maxn=0;
				for(int k=1;k<=n;k++){
					if(k==i||k==j) continue;
					sum+=a[k],maxn=max(maxn,a[k]);
				}
				if(sum>2*maxn) ans++;
			}
		}
		for(int i=1;i<=n;i++){
			sum=0,maxn=0;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				sum+=a[j],maxn=max(maxn,a[j]);
			}
			if(sum>2*maxn) ans++;
		}
		sum=0,maxn=0;
		for(int i=1;i<=n;i++){
			sum+=a[i],maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn) ans++;
		cout<<ans%mod;
		return 0;
	}
	if(n==11){
		int sum=0,maxn=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=a[i]+a[j]+a[k];
					maxn=max({a[i],a[j],a[k]});
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=a[i]+a[j]+a[k]+a[l];
						maxn=max({a[i],a[j],a[k],a[l]});
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-4;i++){
			for(int j=i+1;j<=n-3;j++){
				for(int k=j+1;k<=n-2;k++){
					for(int l=k+1;l<=n-1;l++){
						for(int o=l+1;o<=n;o++){
							sum=a[i]+a[j]+a[k]+a[l]+a[o];
							maxn=max({a[i],a[j],a[k],a[l],a[o]});
							if(sum>2*maxn) ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n-5;i++){
			for(int j=i+1;j<=n-4;j++){
				for(int k=j+1;k<=n-3;k++){
					for(int l=k+1;l<=n-2;l++){
						for(int o=l+1;o<=n-1;o++){
							for(int p=o+1;p>=n;p++){
								sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p];
								maxn=max({a[i],a[j],a[k],a[l],a[o],a[p]});
								if(sum>2*maxn) ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=0,maxn=0;
						for(int o=1;o<=n;o++){
							if(o==i||o==j||o==k||o==l) continue;
							sum+=a[o],maxn=max(maxn,a[o]);
						}
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=0,maxn=0;
					for(int l=1;l<=n;l++){
						if(l==i||l==j||l==k) continue;
						sum+=a[l],maxn=max(maxn,a[l]);
					}
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				sum=0,maxn=0;
				for(int k=1;k<=n;k++){
					if(k==i||k==j) continue;
					sum+=a[k],maxn=max(maxn,a[k]);
				}
				if(sum>2*maxn) ans++;
			}
		}
		for(int i=1;i<=n;i++){
			sum=0,maxn=0;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				sum+=a[j],maxn=max(maxn,a[j]);
			}
			if(sum>2*maxn) ans++;
		}
		sum=0,maxn=0;
		for(int i=1;i<=n;i++){
			sum+=a[i],maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn) ans++;
		cout<<ans%mod;
		return 0;
	}
	if(n==12){
		int sum=0,maxn=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=a[i]+a[j]+a[k];
					maxn=max({a[i],a[j],a[k]});
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=a[i]+a[j]+a[k]+a[l];
						maxn=max({a[i],a[j],a[k],a[l]});
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-4;i++){
			for(int j=i+1;j<=n-3;j++){
				for(int k=j+1;k<=n-2;k++){
					for(int l=k+1;l<=n-1;l++){
						for(int o=l+1;o<=n;o++){
							sum=a[i]+a[j]+a[k]+a[l]+a[o];
							maxn=max({a[i],a[j],a[k],a[l],a[o]});
							if(sum>2*maxn) ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n-5;i++){
			for(int j=i+1;j<=n-4;j++){
				for(int k=j+1;k<=n-3;k++){
					for(int l=k+1;l<=n-2;l++){
						for(int o=l+1;o<=n-1;o++){
							for(int p=o+1;p>=n;p++){
								sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p];
								maxn=max({a[i],a[j],a[k],a[l],a[o],a[p]});
								if(sum>2*maxn) ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-4;i++){
			for(int j=i+1;j<=n-3;j++){
				for(int k=j+1;k<=n-2;k++){
					for(int l=k+1;l<=n-1;l++){
						for(int o=l+1;o<=n;o++){
							sum=0,maxn=0;
							for(int p=1;p<=n;p++){
								if(p==i||p==j||p==k||p==l||p==o) continue;
								sum+=a[p],maxn=max(maxn,a[p]);
							}
							if(sum>2*maxn) ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=0,maxn=0;
						for(int o=1;o<=n;o++){
							if(o==i||o==j||o==k||o==l) continue;
							sum+=a[o],maxn=max(maxn,a[o]);
						}
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=0,maxn=0;
					for(int l=1;l<=n;l++){
						if(l==i||l==j||l==k) continue;
						sum+=a[l],maxn=max(maxn,a[l]);
					}
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				sum=0,maxn=0;
				for(int k=1;k<=n;k++){
					if(k==i||k==j) continue;
					sum+=a[k],maxn=max(maxn,a[k]);
				}
				if(sum>2*maxn) ans++;
			}
		}
		for(int i=1;i<=n;i++){
			sum=0,maxn=0;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				sum+=a[j],maxn=max(maxn,a[j]);
			}
			if(sum>2*maxn) ans++;
		}
		sum=0,maxn=0;
		for(int i=1;i<=n;i++){
			sum+=a[i],maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn) ans++;
		cout<<ans%mod;
		return 0;
	}
	if(n==13){
		int sum=0,maxn=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=a[i]+a[j]+a[k];
					maxn=max({a[i],a[j],a[k]});
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=a[i]+a[j]+a[k]+a[l];
						maxn=max({a[i],a[j],a[k],a[l]});
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-4;i++){
			for(int j=i+1;j<=n-3;j++){
				for(int k=j+1;k<=n-2;k++){
					for(int l=k+1;l<=n-1;l++){
						for(int o=l+1;o<=n;o++){
							sum=a[i]+a[j]+a[k]+a[l]+a[o];
							maxn=max({a[i],a[j],a[k],a[l],a[o]});
							if(sum>2*maxn) ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n-5;i++){
			for(int j=i+1;j<=n-4;j++){
				for(int k=j+1;k<=n-3;k++){
					for(int l=k+1;l<=n-2;l++){
						for(int o=l+1;o<=n-1;o++){
							for(int p=o+1;p>=n;p++){
								sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p];
								maxn=max({a[i],a[j],a[k],a[l],a[o],a[p]});
								if(sum>2*maxn) ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-6;i++){
			for(int j=i+1;j<=n-5;j++){
				for(int k=j+1;k<=n-4;k++){
					for(int l=k+1;l<=n-3;l++){
						for(int o=l+1;o<=n-2;o++){
							for(int p=o+1;p>=n-1;p++){
								for(int q=p+1;q<=n;q++){
									sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q];
									maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q]});
									if(sum>2*maxn) ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-7;i++){
			for(int j=i+1;j<=n-6;j++){
				for(int k=j+1;k<=n-5;k++){
					for(int l=k+1;l<=n-4;l++){
						for(int o=l+1;o<=n-3;o++){
							for(int p=o+1;p>=n-2;p++){
								for(int q=p+1;q<=n-1;q++){
									for(int r=q+1;r<=n;r++){
										sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r];
										maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r]});
										if(sum>2*maxn) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=0,maxn=0;
						for(int o=1;o<=n;o++){
							if(o==i||o==j||o==k||o==l) continue;
							sum+=a[o],maxn=max(maxn,a[o]);
						}
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=0,maxn=0;
					for(int l=1;l<=n;l++){
						if(l==i||l==j||l==k) continue;
						sum+=a[l],maxn=max(maxn,a[l]);
					}
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				sum=0,maxn=0;
				for(int k=1;k<=n;k++){
					if(k==i||k==j) continue;
					sum+=a[k],maxn=max(maxn,a[k]);
				}
				if(sum>2*maxn) ans++;
			}
		}
		for(int i=1;i<=n;i++){
			sum=0,maxn=0;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				sum+=a[j],maxn=max(maxn,a[j]);
			}
			if(sum>2*maxn) ans++;
		}
		sum=0,maxn=0;
		for(int i=1;i<=n;i++){
			sum+=a[i],maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn) ans++;
		cout<<ans%mod;
		return 0;
	}
	if(n==14){
		int sum=0,maxn=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=a[i]+a[j]+a[k];
					maxn=max({a[i],a[j],a[k]});
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=a[i]+a[j]+a[k]+a[l];
						maxn=max({a[i],a[j],a[k],a[l]});
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-4;i++){
			for(int j=i+1;j<=n-3;j++){
				for(int k=j+1;k<=n-2;k++){
					for(int l=k+1;l<=n-1;l++){
						for(int o=l+1;o<=n;o++){
							sum=a[i]+a[j]+a[k]+a[l]+a[o];
							maxn=max({a[i],a[j],a[k],a[l],a[o]});
							if(sum>2*maxn) ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n-5;i++){
			for(int j=i+1;j<=n-4;j++){
				for(int k=j+1;k<=n-3;k++){
					for(int l=k+1;l<=n-2;l++){
						for(int o=l+1;o<=n-1;o++){
							for(int p=o+1;p>=n;p++){
								sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p];
								maxn=max({a[i],a[j],a[k],a[l],a[o],a[p]});
								if(sum>2*maxn) ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-6;i++){
			for(int j=i+1;j<=n-5;j++){
				for(int k=j+1;k<=n-4;k++){
					for(int l=k+1;l<=n-3;l++){
						for(int o=l+1;o<=n-2;o++){
							for(int p=o+1;p>=n-1;p++){
								for(int q=p+1;q<=n;q++){
									sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q];
									maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q]});
									if(sum>2*maxn) ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-7;i++){
			for(int j=i+1;j<=n-6;j++){
				for(int k=j+1;k<=n-5;k++){
					for(int l=k+1;l<=n-4;l++){
						for(int o=l+1;o<=n-3;o++){
							for(int p=o+1;p>=n-2;p++){
								for(int q=p+1;q<=n-1;q++){
									for(int r=q+1;r<=n;r++){
										sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r];
										maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r]});
										if(sum>2*maxn) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-8;i++){
			for(int j=i+1;j<=n-7;j++){
				for(int k=j+1;k<=n-6;k++){
					for(int l=k+1;l<=n-5;l++){
						for(int o=l+1;o<=n-4;o++){
							for(int p=o+1;p>=n-3;p++){
								for(int q=p+1;q<=n-2;q++){
									for(int r=q+1;r<=n-1;r++){
										for(int s=r+1;s<=n;s++){
											sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s];
											maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s]});
											if(sum>2*maxn) ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=0,maxn=0;
						for(int o=1;o<=n;o++){
							if(o==i||o==j||o==k||o==l) continue;
							sum+=a[o],maxn=max(maxn,a[o]);
						}
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=0,maxn=0;
					for(int l=1;l<=n;l++){
						if(l==i||l==j||l==k) continue;
						sum+=a[l],maxn=max(maxn,a[l]);
					}
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				sum=0,maxn=0;
				for(int k=1;k<=n;k++){
					if(k==i||k==j) continue;
					sum+=a[k],maxn=max(maxn,a[k]);
				}
				if(sum>2*maxn) ans++;
			}
		}
		for(int i=1;i<=n;i++){
			sum=0,maxn=0;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				sum+=a[j],maxn=max(maxn,a[j]);
			}
			if(sum>2*maxn) ans++;
		}
		sum=0,maxn=0;
		for(int i=1;i<=n;i++){
			sum+=a[i],maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn) ans++;
		cout<<ans%mod;
		return 0;
	}
	if(n==15){
		int sum=0,maxn=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=a[i]+a[j]+a[k];
					maxn=max({a[i],a[j],a[k]});
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=a[i]+a[j]+a[k]+a[l];
						maxn=max({a[i],a[j],a[k],a[l]});
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-4;i++){
			for(int j=i+1;j<=n-3;j++){
				for(int k=j+1;k<=n-2;k++){
					for(int l=k+1;l<=n-1;l++){
						for(int o=l+1;o<=n;o++){
							sum=a[i]+a[j]+a[k]+a[l]+a[o];
							maxn=max({a[i],a[j],a[k],a[l],a[o]});
							if(sum>2*maxn) ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n-5;i++){
			for(int j=i+1;j<=n-4;j++){
				for(int k=j+1;k<=n-3;k++){
					for(int l=k+1;l<=n-2;l++){
						for(int o=l+1;o<=n-1;o++){
							for(int p=o+1;p>=n;p++){
								sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p];
								maxn=max({a[i],a[j],a[k],a[l],a[o],a[p]});
								if(sum>2*maxn) ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-6;i++){
			for(int j=i+1;j<=n-5;j++){
				for(int k=j+1;k<=n-4;k++){
					for(int l=k+1;l<=n-3;l++){
						for(int o=l+1;o<=n-2;o++){
							for(int p=o+1;p>=n-1;p++){
								for(int q=p+1;q<=n;q++){
									sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q];
									maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q]});
									if(sum>2*maxn) ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-7;i++){
			for(int j=i+1;j<=n-6;j++){
				for(int k=j+1;k<=n-5;k++){
					for(int l=k+1;l<=n-4;l++){
						for(int o=l+1;o<=n-3;o++){
							for(int p=o+1;p>=n-2;p++){
								for(int q=p+1;q<=n-1;q++){
									for(int r=q+1;r<=n;r++){
										sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r];
										maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r]});
										if(sum>2*maxn) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-8;i++){
			for(int j=i+1;j<=n-7;j++){
				for(int k=j+1;k<=n-6;k++){
					for(int l=k+1;l<=n-5;l++){
						for(int o=l+1;o<=n-4;o++){
							for(int p=o+1;p>=n-3;p++){
								for(int q=p+1;q<=n-2;q++){
									for(int r=q+1;r<=n-1;r++){
										for(int s=r+1;s<=n;s++){
											sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s];
											maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s]});
											if(sum>2*maxn) ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-9;i++){
			for(int j=i+1;j<=n-8;j++){
				for(int k=j+1;k<=n-7;k++){
					for(int l=k+1;l<=n-6;l++){
						for(int o=l+1;o<=n-5;o++){
							for(int p=o+1;p>=n-4;p++){
								for(int q=p+1;q<=n-3;q++){
									for(int r=q+1;r<=n-2;r++){
										for(int s=r+1;s<=n-1;s++){
											for(int t=s+1;t<=n;t++){
												sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t];
												maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s],a[t]});
												if(sum>2*maxn) ans++;
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
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=0,maxn=0;
						for(int o=1;o<=n;o++){
							if(o==i||o==j||o==k||o==l) continue;
							sum+=a[o],maxn=max(maxn,a[o]);
						}
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=0,maxn=0;
					for(int l=1;l<=n;l++){
						if(l==i||l==j||l==k) continue;
						sum+=a[l],maxn=max(maxn,a[l]);
					}
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				sum=0,maxn=0;
				for(int k=1;k<=n;k++){
					if(k==i||k==j) continue;
					sum+=a[k],maxn=max(maxn,a[k]);
				}
				if(sum>2*maxn) ans++;
			}
		}
		for(int i=1;i<=n;i++){
			sum=0,maxn=0;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				sum+=a[j],maxn=max(maxn,a[j]);
			}
			if(sum>2*maxn) ans++;
		}
		sum=0,maxn=0;
		for(int i=1;i<=n;i++){
			sum+=a[i],maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn) ans++;
		cout<<ans%mod;
		return 0;
	}
	if(n==16){
		int sum=0,maxn=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=a[i]+a[j]+a[k];
					maxn=max({a[i],a[j],a[k]});
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=a[i]+a[j]+a[k]+a[l];
						maxn=max({a[i],a[j],a[k],a[l]});
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-4;i++){
			for(int j=i+1;j<=n-3;j++){
				for(int k=j+1;k<=n-2;k++){
					for(int l=k+1;l<=n-1;l++){
						for(int o=l+1;o<=n;o++){
							sum=a[i]+a[j]+a[k]+a[l]+a[o];
							maxn=max({a[i],a[j],a[k],a[l],a[o]});
							if(sum>2*maxn) ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n-5;i++){
			for(int j=i+1;j<=n-4;j++){
				for(int k=j+1;k<=n-3;k++){
					for(int l=k+1;l<=n-2;l++){
						for(int o=l+1;o<=n-1;o++){
							for(int p=o+1;p>=n;p++){
								sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p];
								maxn=max({a[i],a[j],a[k],a[l],a[o],a[p]});
								if(sum>2*maxn) ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-6;i++){
			for(int j=i+1;j<=n-5;j++){
				for(int k=j+1;k<=n-4;k++){
					for(int l=k+1;l<=n-3;l++){
						for(int o=l+1;o<=n-2;o++){
							for(int p=o+1;p>=n-1;p++){
								for(int q=p+1;q<=n;q++){
									sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q];
									maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q]});
									if(sum>2*maxn) ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-7;i++){
			for(int j=i+1;j<=n-6;j++){
				for(int k=j+1;k<=n-5;k++){
					for(int l=k+1;l<=n-4;l++){
						for(int o=l+1;o<=n-3;o++){
							for(int p=o+1;p>=n-2;p++){
								for(int q=p+1;q<=n-1;q++){
									for(int r=q+1;r<=n;r++){
										sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r];
										maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r]});
										if(sum>2*maxn) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-8;i++){
			for(int j=i+1;j<=n-7;j++){
				for(int k=j+1;k<=n-6;k++){
					for(int l=k+1;l<=n-5;l++){
						for(int o=l+1;o<=n-4;o++){
							for(int p=o+1;p>=n-3;p++){
								for(int q=p+1;q<=n-2;q++){
									for(int r=q+1;r<=n-1;r++){
										for(int s=r+1;s<=n;s++){
											sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s];
											maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s]});
											if(sum>2*maxn) ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-9;i++){
			for(int j=i+1;j<=n-8;j++){
				for(int k=j+1;k<=n-7;k++){
					for(int l=k+1;l<=n-6;l++){
						for(int o=l+1;o<=n-5;o++){
							for(int p=o+1;p>=n-4;p++){
								for(int q=p+1;q<=n-3;q++){
									for(int r=q+1;r<=n-2;r++){
										for(int s=r+1;s<=n-1;s++){
											for(int t=s+1;t<=n;t++){
												sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t];
												maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s],a[t]});
												if(sum>2*maxn) ans++;
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
		for(int i=1;i<=n-10;i++){
			for(int j=i+1;j<=n-9;j++){
				for(int k=j+1;k<=n-8;k++){
					for(int l=k+1;l<=n-7;l++){
						for(int o=l+1;o<=n-6;o++){
							for(int p=o+1;p>=n-5;p++){
								for(int q=p+1;q<=n-4;q++){
									for(int r=q+1;r<=n-3;r++){
										for(int s=r+1;s<=n-2;s++){
											for(int t=s+1;t<=n-1;t++){
												for(int u=t+1;u<=n;u++){
													sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u];
													maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s],a[t],a[u]});
													if(sum>2*maxn) ans++;
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
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=0,maxn=0;
						for(int o=1;o<=n;o++){
							if(o==i||o==j||o==k||o==l) continue;
							sum+=a[o],maxn=max(maxn,a[o]);
						}
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=0,maxn=0;
					for(int l=1;l<=n;l++){
						if(l==i||l==j||l==k) continue;
						sum+=a[l],maxn=max(maxn,a[l]);
					}
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				sum=0,maxn=0;
				for(int k=1;k<=n;k++){
					if(k==i||k==j) continue;
					sum+=a[k],maxn=max(maxn,a[k]);
				}
				if(sum>2*maxn) ans++;
			}
		}
		for(int i=1;i<=n;i++){
			sum=0,maxn=0;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				sum+=a[j],maxn=max(maxn,a[j]);
			}
			if(sum>2*maxn) ans++;
		}
		sum=0,maxn=0;
		for(int i=1;i<=n;i++){
			sum+=a[i],maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn) ans++;
		cout<<ans%mod;
		return 0;
	}
	if(n==17){
		int sum=0,maxn=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=a[i]+a[j]+a[k];
					maxn=max({a[i],a[j],a[k]});
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=a[i]+a[j]+a[k]+a[l];
						maxn=max({a[i],a[j],a[k],a[l]});
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-4;i++){
			for(int j=i+1;j<=n-3;j++){
				for(int k=j+1;k<=n-2;k++){
					for(int l=k+1;l<=n-1;l++){
						for(int o=l+1;o<=n;o++){
							sum=a[i]+a[j]+a[k]+a[l]+a[o];
							maxn=max({a[i],a[j],a[k],a[l],a[o]});
							if(sum>2*maxn) ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n-5;i++){
			for(int j=i+1;j<=n-4;j++){
				for(int k=j+1;k<=n-3;k++){
					for(int l=k+1;l<=n-2;l++){
						for(int o=l+1;o<=n-1;o++){
							for(int p=o+1;p>=n;p++){
								sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p];
								maxn=max({a[i],a[j],a[k],a[l],a[o],a[p]});
								if(sum>2*maxn) ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-6;i++){
			for(int j=i+1;j<=n-5;j++){
				for(int k=j+1;k<=n-4;k++){
					for(int l=k+1;l<=n-3;l++){
						for(int o=l+1;o<=n-2;o++){
							for(int p=o+1;p>=n-1;p++){
								for(int q=p+1;q<=n;q++){
									sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q];
									maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q]});
									if(sum>2*maxn) ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-7;i++){
			for(int j=i+1;j<=n-6;j++){
				for(int k=j+1;k<=n-5;k++){
					for(int l=k+1;l<=n-4;l++){
						for(int o=l+1;o<=n-3;o++){
							for(int p=o+1;p>=n-2;p++){
								for(int q=p+1;q<=n-1;q++){
									for(int r=q+1;r<=n;r++){
										sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r];
										maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r]});
										if(sum>2*maxn) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-8;i++){
			for(int j=i+1;j<=n-7;j++){
				for(int k=j+1;k<=n-6;k++){
					for(int l=k+1;l<=n-5;l++){
						for(int o=l+1;o<=n-4;o++){
							for(int p=o+1;p>=n-3;p++){
								for(int q=p+1;q<=n-2;q++){
									for(int r=q+1;r<=n-1;r++){
										for(int s=r+1;s<=n;s++){
											sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s];
											maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s]});
											if(sum>2*maxn) ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-9;i++){
			for(int j=i+1;j<=n-8;j++){
				for(int k=j+1;k<=n-7;k++){
					for(int l=k+1;l<=n-6;l++){
						for(int o=l+1;o<=n-5;o++){
							for(int p=o+1;p>=n-4;p++){
								for(int q=p+1;q<=n-3;q++){
									for(int r=q+1;r<=n-2;r++){
										for(int s=r+1;s<=n-1;s++){
											for(int t=s+1;t<=n;t++){
												sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t];
												maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s],a[t]});
												if(sum>2*maxn) ans++;
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
		for(int i=1;i<=n-10;i++){
			for(int j=i+1;j<=n-9;j++){
				for(int k=j+1;k<=n-8;k++){
					for(int l=k+1;l<=n-7;l++){
						for(int o=l+1;o<=n-6;o++){
							for(int p=o+1;p>=n-5;p++){
								for(int q=p+1;q<=n-4;q++){
									for(int r=q+1;r<=n-3;r++){
										for(int s=r+1;s<=n-2;s++){
											for(int t=s+1;t<=n-1;t++){
												for(int u=t+1;u<=n;u++){
													sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u];
													maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s],a[t],a[u]});
													if(sum>2*maxn) ans++;
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
		for(int i=1;i<=n-11;i++){
			for(int j=i+1;j<=n-10;j++){
				for(int k=j+1;k<=n-9;k++){
					for(int l=k+1;l<=n-8;l++){
						for(int o=l+1;o<=n-7;o++){
							for(int p=o+1;p>=n-6;p++){
								for(int q=p+1;q<=n-5;q++){
									for(int r=q+1;r<=n-4;r++){
										for(int s=r+1;s<=n-3;s++){
											for(int t=s+1;t<=n-2;t++){
												for(int u=t+1;u<=n-1;u++){
													for(int v=u+1;v<=n;v++){
														sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v];
														maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s],a[t],a[u],a[v]});
														if(sum>2*maxn) ans++;
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
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=0,maxn=0;
						for(int o=1;o<=n;o++){
							if(o==i||o==j||o==k||o==l) continue;
							sum+=a[o],maxn=max(maxn,a[o]);
						}
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=0,maxn=0;
					for(int l=1;l<=n;l++){
						if(l==i||l==j||l==k) continue;
						sum+=a[l],maxn=max(maxn,a[l]);
					}
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				sum=0,maxn=0;
				for(int k=1;k<=n;k++){
					if(k==i||k==j) continue;
					sum+=a[k],maxn=max(maxn,a[k]);
				}
				if(sum>2*maxn) ans++;
			}
		}
		for(int i=1;i<=n;i++){
			sum=0,maxn=0;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				sum+=a[j],maxn=max(maxn,a[j]);
			}
			if(sum>2*maxn) ans++;
		}
		sum=0,maxn=0;
		for(int i=1;i<=n;i++){
			sum+=a[i],maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn) ans++;
		cout<<ans%mod;
		return 0;
	}
	if(n==18){
		int sum=0,maxn=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=a[i]+a[j]+a[k];
					maxn=max({a[i],a[j],a[k]});
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=a[i]+a[j]+a[k]+a[l];
						maxn=max({a[i],a[j],a[k],a[l]});
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-4;i++){
			for(int j=i+1;j<=n-3;j++){
				for(int k=j+1;k<=n-2;k++){
					for(int l=k+1;l<=n-1;l++){
						for(int o=l+1;o<=n;o++){
							sum=a[i]+a[j]+a[k]+a[l]+a[o];
							maxn=max({a[i],a[j],a[k],a[l],a[o]});
							if(sum>2*maxn) ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n-5;i++){
			for(int j=i+1;j<=n-4;j++){
				for(int k=j+1;k<=n-3;k++){
					for(int l=k+1;l<=n-2;l++){
						for(int o=l+1;o<=n-1;o++){
							for(int p=o+1;p>=n;p++){
								sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p];
								maxn=max({a[i],a[j],a[k],a[l],a[o],a[p]});
								if(sum>2*maxn) ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-6;i++){
			for(int j=i+1;j<=n-5;j++){
				for(int k=j+1;k<=n-4;k++){
					for(int l=k+1;l<=n-3;l++){
						for(int o=l+1;o<=n-2;o++){
							for(int p=o+1;p>=n-1;p++){
								for(int q=p+1;q<=n;q++){
									sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q];
									maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q]});
									if(sum>2*maxn) ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-7;i++){
			for(int j=i+1;j<=n-6;j++){
				for(int k=j+1;k<=n-5;k++){
					for(int l=k+1;l<=n-4;l++){
						for(int o=l+1;o<=n-3;o++){
							for(int p=o+1;p>=n-2;p++){
								for(int q=p+1;q<=n-1;q++){
									for(int r=q+1;r<=n;r++){
										sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r];
										maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r]});
										if(sum>2*maxn) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-8;i++){
			for(int j=i+1;j<=n-7;j++){
				for(int k=j+1;k<=n-6;k++){
					for(int l=k+1;l<=n-5;l++){
						for(int o=l+1;o<=n-4;o++){
							for(int p=o+1;p>=n-3;p++){
								for(int q=p+1;q<=n-2;q++){
									for(int r=q+1;r<=n-1;r++){
										for(int s=r+1;s<=n;s++){
											sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s];
											maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s]});
											if(sum>2*maxn) ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-9;i++){
			for(int j=i+1;j<=n-8;j++){
				for(int k=j+1;k<=n-7;k++){
					for(int l=k+1;l<=n-6;l++){
						for(int o=l+1;o<=n-5;o++){
							for(int p=o+1;p>=n-4;p++){
								for(int q=p+1;q<=n-3;q++){
									for(int r=q+1;r<=n-2;r++){
										for(int s=r+1;s<=n-1;s++){
											for(int t=s+1;t<=n;t++){
												sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t];
												maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s],a[t]});
												if(sum>2*maxn) ans++;
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
		for(int i=1;i<=n-10;i++){
			for(int j=i+1;j<=n-9;j++){
				for(int k=j+1;k<=n-8;k++){
					for(int l=k+1;l<=n-7;l++){
						for(int o=l+1;o<=n-6;o++){
							for(int p=o+1;p>=n-5;p++){
								for(int q=p+1;q<=n-4;q++){
									for(int r=q+1;r<=n-3;r++){
										for(int s=r+1;s<=n-2;s++){
											for(int t=s+1;t<=n-1;t++){
												for(int u=t+1;u<=n;u++){
													sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u];
													maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s],a[t],a[u]});
													if(sum>2*maxn) ans++;
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
		for(int i=1;i<=n-11;i++){
			for(int j=i+1;j<=n-10;j++){
				for(int k=j+1;k<=n-9;k++){
					for(int l=k+1;l<=n-8;l++){
						for(int o=l+1;o<=n-7;o++){
							for(int p=o+1;p>=n-6;p++){
								for(int q=p+1;q<=n-5;q++){
									for(int r=q+1;r<=n-4;r++){
										for(int s=r+1;s<=n-3;s++){
											for(int t=s+1;t<=n-2;t++){
												for(int u=t+1;u<=n-1;u++){
													for(int v=u+1;v<=n;v++){
														sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v];
														maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s],a[t],a[u],a[v]});
														if(sum>2*maxn) ans++;
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
		for(int i=1;i<=n-12;i++){
			for(int j=i+1;j<=n-11;j++){
				for(int k=j+1;k<=n-10;k++){
					for(int l=k+1;l<=n-9;l++){
						for(int o=l+1;o<=n-8;o++){
							for(int p=o+1;p>=n-7;p++){
								for(int q=p+1;q<=n-6;q++){
									for(int r=q+1;r<=n-5;r++){
										for(int s=r+1;s<=n-4;s++){
											for(int t=s+1;t<=n-3;t++){
												for(int u=t+1;u<=n-2;u++){
													for(int v=u+1;v<=n-1;v++){
														for(int w=v+1;w<=n;w++){
															sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w];
															maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s],a[t],a[u],a[v],a[w]});
															if(sum>2*maxn) ans++;
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
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=0,maxn=0;
						for(int o=1;o<=n;o++){
							if(o==i||o==j||o==k||o==l) continue;
							sum+=a[o],maxn=max(maxn,a[o]);
						}
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=0,maxn=0;
					for(int l=1;l<=n;l++){
						if(l==i||l==j||l==k) continue;
						sum+=a[l],maxn=max(maxn,a[l]);
					}
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				sum=0,maxn=0;
				for(int k=1;k<=n;k++){
					if(k==i||k==j) continue;
					sum+=a[k],maxn=max(maxn,a[k]);
				}
				if(sum>2*maxn) ans++;
			}
		}
		for(int i=1;i<=n;i++){
			sum=0,maxn=0;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				sum+=a[j],maxn=max(maxn,a[j]);
			}
			if(sum>2*maxn) ans++;
		}
		sum=0,maxn=0;
		for(int i=1;i<=n;i++){
			sum+=a[i],maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn) ans++;
		cout<<ans%mod;
		return 0;
	}
	if(n==19){
		int sum=0,maxn=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=a[i]+a[j]+a[k];
					maxn=max({a[i],a[j],a[k]});
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=a[i]+a[j]+a[k]+a[l];
						maxn=max({a[i],a[j],a[k],a[l]});
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-4;i++){
			for(int j=i+1;j<=n-3;j++){
				for(int k=j+1;k<=n-2;k++){
					for(int l=k+1;l<=n-1;l++){
						for(int o=l+1;o<=n;o++){
							sum=a[i]+a[j]+a[k]+a[l]+a[o];
							maxn=max({a[i],a[j],a[k],a[l],a[o]});
							if(sum>2*maxn) ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n-5;i++){
			for(int j=i+1;j<=n-4;j++){
				for(int k=j+1;k<=n-3;k++){
					for(int l=k+1;l<=n-2;l++){
						for(int o=l+1;o<=n-1;o++){
							for(int p=o+1;p>=n;p++){
								sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p];
								maxn=max({a[i],a[j],a[k],a[l],a[o],a[p]});
								if(sum>2*maxn) ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-6;i++){
			for(int j=i+1;j<=n-5;j++){
				for(int k=j+1;k<=n-4;k++){
					for(int l=k+1;l<=n-3;l++){
						for(int o=l+1;o<=n-2;o++){
							for(int p=o+1;p>=n-1;p++){
								for(int q=p+1;q<=n;q++){
									sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q];
									maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q]});
									if(sum>2*maxn) ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-7;i++){
			for(int j=i+1;j<=n-6;j++){
				for(int k=j+1;k<=n-5;k++){
					for(int l=k+1;l<=n-4;l++){
						for(int o=l+1;o<=n-3;o++){
							for(int p=o+1;p>=n-2;p++){
								for(int q=p+1;q<=n-1;q++){
									for(int r=q+1;r<=n;r++){
										sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r];
										maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r]});
										if(sum>2*maxn) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-8;i++){
			for(int j=i+1;j<=n-7;j++){
				for(int k=j+1;k<=n-6;k++){
					for(int l=k+1;l<=n-5;l++){
						for(int o=l+1;o<=n-4;o++){
							for(int p=o+1;p>=n-3;p++){
								for(int q=p+1;q<=n-2;q++){
									for(int r=q+1;r<=n-1;r++){
										for(int s=r+1;s<=n;s++){
											sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s];
											maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s]});
											if(sum>2*maxn) ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-9;i++){
			for(int j=i+1;j<=n-8;j++){
				for(int k=j+1;k<=n-7;k++){
					for(int l=k+1;l<=n-6;l++){
						for(int o=l+1;o<=n-5;o++){
							for(int p=o+1;p>=n-4;p++){
								for(int q=p+1;q<=n-3;q++){
									for(int r=q+1;r<=n-2;r++){
										for(int s=r+1;s<=n-1;s++){
											for(int t=s+1;t<=n;t++){
												sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t];
												maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s],a[t]});
												if(sum>2*maxn) ans++;
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
		for(int i=1;i<=n-10;i++){
			for(int j=i+1;j<=n-9;j++){
				for(int k=j+1;k<=n-8;k++){
					for(int l=k+1;l<=n-7;l++){
						for(int o=l+1;o<=n-6;o++){
							for(int p=o+1;p>=n-5;p++){
								for(int q=p+1;q<=n-4;q++){
									for(int r=q+1;r<=n-3;r++){
										for(int s=r+1;s<=n-2;s++){
											for(int t=s+1;t<=n-1;t++){
												for(int u=t+1;u<=n;u++){
													sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u];
													maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s],a[t],a[u]});
													if(sum>2*maxn) ans++;
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
		for(int i=1;i<=n-11;i++){
			for(int j=i+1;j<=n-10;j++){
				for(int k=j+1;k<=n-9;k++){
					for(int l=k+1;l<=n-8;l++){
						for(int o=l+1;o<=n-7;o++){
							for(int p=o+1;p>=n-6;p++){
								for(int q=p+1;q<=n-5;q++){
									for(int r=q+1;r<=n-4;r++){
										for(int s=r+1;s<=n-3;s++){
											for(int t=s+1;t<=n-2;t++){
												for(int u=t+1;u<=n-1;u++){
													for(int v=u+1;v<=n;v++){
														sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v];
														maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s],a[t],a[u],a[v]});
														if(sum>2*maxn) ans++;
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
		for(int i=1;i<=n-12;i++){
			for(int j=i+1;j<=n-11;j++){
				for(int k=j+1;k<=n-10;k++){
					for(int l=k+1;l<=n-9;l++){
						for(int o=l+1;o<=n-8;o++){
							for(int p=o+1;p>=n-7;p++){
								for(int q=p+1;q<=n-6;q++){
									for(int r=q+1;r<=n-5;r++){
										for(int s=r+1;s<=n-4;s++){
											for(int t=s+1;t<=n-3;t++){
												for(int u=t+1;u<=n-2;u++){
													for(int v=u+1;v<=n-1;v++){
														for(int w=v+1;w<=n;w++){
															sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w];
															maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s],a[t],a[u],a[v],a[w]});
															if(sum>2*maxn) ans++;
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
		for(int i=1;i<=n-13;i++){
			for(int j=i+1;j<=n-12;j++){
				for(int k=j+1;k<=n-11;k++){
					for(int l=k+1;l<=n-10;l++){
						for(int o=l+1;o<=n-9;o++){
							for(int p=o+1;p>=n-8;p++){
								for(int q=p+1;q<=n-7;q++){
									for(int r=q+1;r<=n-6;r++){
										for(int s=r+1;s<=n-5;s++){
											for(int t=s+1;t<=n-4;t++){
												for(int u=t+1;u<=n-3;u++){
													for(int v=u+1;v<=n-2;v++){
														for(int w=v+1;w<=n-1;w++){
															for(int x=w+1;x<=n;x++){
																sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x];
																maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s],a[t],a[u],a[v],a[w],a[x]});
																if(sum>2*maxn) ans++;
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
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=0,maxn=0;
						for(int o=1;o<=n;o++){
							if(o==i||o==j||o==k||o==l) continue;
							sum+=a[o],maxn=max(maxn,a[o]);
						}
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=0,maxn=0;
					for(int l=1;l<=n;l++){
						if(l==i||l==j||l==k) continue;
						sum+=a[l],maxn=max(maxn,a[l]);
					}
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				sum=0,maxn=0;
				for(int k=1;k<=n;k++){
					if(k==i||k==j) continue;
					sum+=a[k],maxn=max(maxn,a[k]);
				}
				if(sum>2*maxn) ans++;
			}
		}
		for(int i=1;i<=n;i++){
			sum=0,maxn=0;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				sum+=a[j],maxn=max(maxn,a[j]);
			}
			if(sum>2*maxn) ans++;
		}
		sum=0,maxn=0;
		for(int i=1;i<=n;i++){
			sum+=a[i],maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn) ans++;
		cout<<ans%mod;
		return 0;
	}
	if(n==20){
		int sum=0,maxn=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=a[i]+a[j]+a[k];
					maxn=max({a[i],a[j],a[k]});
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=a[i]+a[j]+a[k]+a[l];
						maxn=max({a[i],a[j],a[k],a[l]});
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-4;i++){
			for(int j=i+1;j<=n-3;j++){
				for(int k=j+1;k<=n-2;k++){
					for(int l=k+1;l<=n-1;l++){
						for(int o=l+1;o<=n;o++){
							sum=a[i]+a[j]+a[k]+a[l]+a[o];
							maxn=max({a[i],a[j],a[k],a[l],a[o]});
							if(sum>2*maxn) ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n-5;i++){
			for(int j=i+1;j<=n-4;j++){
				for(int k=j+1;k<=n-3;k++){
					for(int l=k+1;l<=n-2;l++){
						for(int o=l+1;o<=n-1;o++){
							for(int p=o+1;p>=n;p++){
								sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p];
								maxn=max({a[i],a[j],a[k],a[l],a[o],a[p]});
								if(sum>2*maxn) ans++;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-6;i++){
			for(int j=i+1;j<=n-5;j++){
				for(int k=j+1;k<=n-4;k++){
					for(int l=k+1;l<=n-3;l++){
						for(int o=l+1;o<=n-2;o++){
							for(int p=o+1;p>=n-1;p++){
								for(int q=p+1;q<=n;q++){
									sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q];
									maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q]});
									if(sum>2*maxn) ans++;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-7;i++){
			for(int j=i+1;j<=n-6;j++){
				for(int k=j+1;k<=n-5;k++){
					for(int l=k+1;l<=n-4;l++){
						for(int o=l+1;o<=n-3;o++){
							for(int p=o+1;p>=n-2;p++){
								for(int q=p+1;q<=n-1;q++){
									for(int r=q+1;r<=n;r++){
										sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r];
										maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r]});
										if(sum>2*maxn) ans++;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-8;i++){
			for(int j=i+1;j<=n-7;j++){
				for(int k=j+1;k<=n-6;k++){
					for(int l=k+1;l<=n-5;l++){
						for(int o=l+1;o<=n-4;o++){
							for(int p=o+1;p>=n-3;p++){
								for(int q=p+1;q<=n-2;q++){
									for(int r=q+1;r<=n-1;r++){
										for(int s=r+1;s<=n;s++){
											sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s];
											maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s]});
											if(sum>2*maxn) ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n-9;i++){
			for(int j=i+1;j<=n-8;j++){
				for(int k=j+1;k<=n-7;k++){
					for(int l=k+1;l<=n-6;l++){
						for(int o=l+1;o<=n-5;o++){
							for(int p=o+1;p>=n-4;p++){
								for(int q=p+1;q<=n-3;q++){
									for(int r=q+1;r<=n-2;r++){
										for(int s=r+1;s<=n-1;s++){
											for(int t=s+1;t<=n;t++){
												sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t];
												maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s],a[t]});
												if(sum>2*maxn) ans++;
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
		for(int i=1;i<=n-10;i++){
			for(int j=i+1;j<=n-9;j++){
				for(int k=j+1;k<=n-8;k++){
					for(int l=k+1;l<=n-7;l++){
						for(int o=l+1;o<=n-6;o++){
							for(int p=o+1;p>=n-5;p++){
								for(int q=p+1;q<=n-4;q++){
									for(int r=q+1;r<=n-3;r++){
										for(int s=r+1;s<=n-2;s++){
											for(int t=s+1;t<=n-1;t++){
												for(int u=t+1;u<=n;u++){
													sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u];
													maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s],a[t],a[u]});
													if(sum>2*maxn) ans++;
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
		for(int i=1;i<=n-11;i++){
			for(int j=i+1;j<=n-10;j++){
				for(int k=j+1;k<=n-9;k++){
					for(int l=k+1;l<=n-8;l++){
						for(int o=l+1;o<=n-7;o++){
							for(int p=o+1;p>=n-6;p++){
								for(int q=p+1;q<=n-5;q++){
									for(int r=q+1;r<=n-4;r++){
										for(int s=r+1;s<=n-3;s++){
											for(int t=s+1;t<=n-2;t++){
												for(int u=t+1;u<=n-1;u++){
													for(int v=u+1;v<=n;v++){
														sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v];
														maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s],a[t],a[u],a[v]});
														if(sum>2*maxn) ans++;
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
		for(int i=1;i<=n-12;i++){
			for(int j=i+1;j<=n-11;j++){
				for(int k=j+1;k<=n-10;k++){
					for(int l=k+1;l<=n-9;l++){
						for(int o=l+1;o<=n-8;o++){
							for(int p=o+1;p>=n-7;p++){
								for(int q=p+1;q<=n-6;q++){
									for(int r=q+1;r<=n-5;r++){
										for(int s=r+1;s<=n-4;s++){
											for(int t=s+1;t<=n-3;t++){
												for(int u=t+1;u<=n-2;u++){
													for(int v=u+1;v<=n-1;v++){
														for(int w=v+1;w<=n;w++){
															sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w];
															maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s],a[t],a[u],a[v],a[w]});
															if(sum>2*maxn) ans++;
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
		for(int i=1;i<=n-13;i++){
			for(int j=i+1;j<=n-12;j++){
				for(int k=j+1;k<=n-11;k++){
					for(int l=k+1;l<=n-10;l++){
						for(int o=l+1;o<=n-9;o++){
							for(int p=o+1;p>=n-8;p++){
								for(int q=p+1;q<=n-7;q++){
									for(int r=q+1;r<=n-6;r++){
										for(int s=r+1;s<=n-5;s++){
											for(int t=s+1;t<=n-4;t++){
												for(int u=t+1;u<=n-3;u++){
													for(int v=u+1;v<=n-2;v++){
														for(int w=v+1;w<=n-1;w++){
															for(int x=w+1;x<=n;x++){
																sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x];
																maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s],a[t],a[u],a[v],a[w],a[x]});
																if(sum>2*maxn) ans++;
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
		for(int i=1;i<=n-14;i++){
			for(int j=i+1;j<=n-13;j++){
				for(int k=j+1;k<=n-12;k++){
					for(int l=k+1;l<=n-11;l++){
						for(int o=l+1;o<=n-10;o++){
							for(int p=o+1;p>=n-9;p++){
								for(int q=p+1;q<=n-8;q++){
									for(int r=q+1;r<=n-7;r++){
										for(int s=r+1;s<=n-6;s++){
											for(int t=s+1;t<=n-5;t++){
												for(int u=t+1;u<=n-4;u++){
													for(int v=u+1;v<=n-3;v++){
														for(int w=v+1;w<=n-2;w++){
															for(int x=w+1;x<=n-1;x++){
																for(int y=x+1;y<=n;y++){
																	sum=a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v]+a[w]+a[x]+a[y];
																	maxn=max({a[i],a[j],a[k],a[l],a[o],a[p],a[q],a[r],a[s],a[t],a[u],a[v],a[w],a[x],a[y]});
																	if(sum>2*maxn) ans++;
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
		for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int l=k+1;l<=n;l++){
						sum=0,maxn=0;
						for(int o=1;o<=n;o++){
							if(o==i||o==j||o==k||o==l) continue;
							sum+=a[o],maxn=max(maxn,a[o]);
						}
						if(sum>2*maxn) ans++;
					}
				}
			}
		}
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					sum=0,maxn=0;
					for(int l=1;l<=n;l++){
						if(l==i||l==j||l==k) continue;
						sum+=a[l],maxn=max(maxn,a[l]);
					}
					if(sum>2*maxn) ans++;
				}
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				sum=0,maxn=0;
				for(int k=1;k<=n;k++){
					if(k==i||k==j) continue;
					sum+=a[k],maxn=max(maxn,a[k]);
				}
				if(sum>2*maxn) ans++;
			}
		}
		for(int i=1;i<=n;i++){
			sum=0,maxn=0;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				sum+=a[j],maxn=max(maxn,a[j]);
			}
			if(sum>2*maxn) ans++;
		}
		sum=0,maxn=0;
		for(int i=1;i<=n;i++){
			sum+=a[i],maxn=max(maxn,a[i]);
		}
		if(sum>2*maxn) ans++;
		cout<<ans%mod;
		return 0;
	}
	return 0;
}

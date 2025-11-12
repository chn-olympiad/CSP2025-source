#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ans=0;
int a[10005],s[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//ios::std::sync_with_stdio
	cin.tie(0);
	scanf("%d",&n);
	int flag=1;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]!=1) flag=0;
	}
	sort(a+1,a+1+n);
	if (flag){
		int s=0;
		for (int i=1;i<=n-2;i++){
			s+=i;
		}
		cout<<s;
		return 0;
	}
	else if (n==3){
		if (a[1]+a[2]+a[3]>a[3]*2){
			cout<<1;
			return 0;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			for (int z=j+1;z<=n;z++){
				if (a[i]+a[j]+a[z]>a[z]*2){
					ans++;
				}
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			for (int z=j+1;z<=n;z++){
				for (int o=z+1;o<=n;o++){
					if (a[i]+a[j]+a[z]+a[o]>a[o]*2){
						ans++;
					}
				}
			}
		}
	}
	if (n<5){
		cout<<ans;
		return 0;
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			for (int z=j+1;z<=n;z++){
				for (int o=z+1;o<=n;o++){
					for (int p=o+1;p<=n;p++){
						if (a[i]+a[j]+a[z]+a[o]+a[p]>a[p]*2) ans++;
					}
				}
				
			}
		}
	}
	if (n<6){
		cout<<ans;
		return 0;
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			for (int z=j+1;z<=n;z++){
				for (int o=z+1;o<=n;o++){
					for (int p=o+1;p<=n;p++){
						for (int m=p+1;m<=n;m++){
							if (a[i]+a[j]+a[z]+a[o]+a[p]+a[m]>a[m]*2) ans++;
						}
					}
				}
				
			}
		}
	}
	if (n<7){
		cout<<ans;
		return 0;
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			for (int z=j+1;z<=n;z++){
				for (int o=z+1;o<=n;o++){
					for (int p=o+1;p<=n;p++){
						for (int m=p+1;m<=n;m++){
							for (int u=m+1;u<=n;u++){
								if (a[i]+a[j]+a[z]+a[o]+a[p]+a[m]+a[u]>a[u]*2) ans++;
							}
						}
					}
				}
				
			}
		}
	}
	if (n<8){
		cout<<ans;
		return 0;
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			for (int z=j+1;z<=n;z++){
				for (int o=z+1;o<=n;o++){
					for (int p=o+1;p<=n;p++){
						for (int m=p+1;m<=n;m++){
							for (int u=m+1;u<=n;u++){
								for (int d=u+1;d<=n;d++){
									if (a[i]+a[j]+a[z]+a[o]+a[p]+a[m]+a[u]+a[d]>a[d]*2) ans++;
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


#include<bits/stdc++.h>
using namespace std;
const int N=5005,INF=0x7f7f7f7f;
int a[N];
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,zd=-INF,zh=0;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		zh+=a[i];
		zd=max(zd,a[i]);
	}
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		if(zh>(2*zd))cout<<1;
		else cout<<0;
		return 0;
	}
	else if(n==4){
		if(zh>(2*zd))ans++;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int b=j+1;b<=n;b++){
					if((a[i]+a[j]+a[b])>=(2*b))ans++;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	else if(n==5){
		if(zh>(2*zd))ans++;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int b=j+1;b<=n;b++){
					if(a[i]+a[j]+a[b]>=(2*b))ans++;
					for(int c=b+1;c<=n;c++){
						if((a[i]+a[j]+a[b]+a[c])>=(2*c))ans++;
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	else if(n==6){
		if(zh>(2*zd))ans++;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int b=j+1;b<=n;b++){
					if(a[i]+a[j]+a[b]>=(2*b))ans++;
					for(int c=b+1;c<=n;c++){
						if((a[i]+a[j]+a[b]+a[c])>=(2*c))ans++;
						for(int d=c+1;d<=n;d++){
							if((a[i]+a[j]+a[b]+a[c]+a[d])>=(2*d))ans++;
						}
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	else if(n==7){
		if(zh>(2*zd))ans++;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int b=j+1;b<=n;b++){
					if(a[i]+a[j]+a[b]>=(2*b))ans++;
					for(int c=b+1;c<=n;c++){
						if((a[i]+a[j]+a[b]+a[c])>=(2*c))ans++;
						for(int d=c+1;d<=n;d++){
							if((a[i]+a[j]+a[b]+a[c]+a[d])>=(2*d))ans++;
							for(int e=d+1;e<=n;e++){
								if((a[i]+a[j]+a[b]+a[c]+a[d]+a[e])>=(2*e))ans++;
							}
						}
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}


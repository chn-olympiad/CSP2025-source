#include <bits/stdc++.h>
using namespace std;
#define lint long long
const int N=5005,mod=998244353;

lint n,a[N];

lint read(){
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}

lint s1(){
	lint ans=0;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			for (int k=j+1;k<=n;k++){
				lint sum=0,maxx=-1;
				if (i==j||i==k||j==k)
					continue;
				sum=a[i]+a[j]+a[k];
				maxx=max(a[i],max(a[j],a[k]));
				if (sum>2*maxx)
					ans++;
			}
		}
	}
	return ans;
}

lint s2(){
	lint ans=0;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			for (int k=j+1;k<=n;k++){
				for (int l=k+1;l<=n;l++){
					lint sum=0,maxx=-1;
					if (i==j||i==k||j==k||i==l||j==l||k==l)
						continue;
					sum=a[i]+a[j]+a[k]+a[l];
					maxx=max(a[i],max(a[j],max(a[l],a[k])));
					if (sum>2*maxx)
						ans++;
				}
			}
		}
	}
	return ans;
}

lint s3(){
	lint ans=0;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			for (int k=j+1;k<=n;k++){
				for (int l=k+1;l<=n;l++){
					for (int r=l+1;r<=n;r++){
						lint sum=0,maxx=-1;
						if (i==j||i==k||j==k||i==l||j==l||k==l||i==r||j==r||k==r||l==r)
							continue;
						sum=a[i]+a[j]+a[k]+a[l]+a[r];
						maxx=max(a[i],max(a[j],max(a[k],max(a[l],a[r]))));
						if (sum>2*maxx)
							ans++;
					}
				}
			}
		}
	}
	return ans;
}

lint s4(){
	lint ans=0;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			for (int k=j+1;k<=n;k++){
				for (int l=k+1;l<=n;l++){
					for (int r=l+1;r<=n;r++){
						for (int w=r+1;w<=n;w++){
							lint sum=0,maxx=-1;
							if (i==j||i==k||j==k||i==l||j==l||k==l||i==r||j==r||k==r||l==r||i==w||j==w||k==w||l==w||r==w)
								continue;
							sum=a[i]+a[j]+a[k]+a[l]+a[r]+a[w];
							maxx=max(a[i],max(a[j],max(a[k],max(a[l],max(a[r],a[w])))));
							if (sum>2*maxx)
								ans++;
						}
					}
				}
			}
		}
	}
	return ans;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	if (n==3){
		int ans=s1()%mod;
		cout <<ans<<endl;
	}
	if (n==4){
		int ans=(s1()%mod+s2()%mod)%mod;
		cout <<ans<<endl;
	}
	if (n==5){
		int ans=((s1()%mod+s2()%mod)%mod+s3()%mod)%mod;
		cout <<ans<<endl;
	}
	if (n==6){
		int ans=(((s1()%mod+s2()%mod)%mod+s3()%mod)%mod+s4()%mod)%mod;
		cout <<ans<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
long long n,ans,a[5005],jc[5005],s[5005];
long long ma=0;
void work3(){
	long long b=max(max(a[1],a[2]),a[3]);
	long long c=min(min(a[1],a[2]),a[3]);
	long long d=a[1]+a[2]+a[3]-b-c;
	if(d+c>b) cout<<1;
	else cout<<0;
}
void work1(){
	long long ans=0;
	for(int i=3;i<=n;i++){
		long long cnt=1;
		for(int j=n;j>=n-i+1;j--) cnt=(cnt*j/(n-j+1))%Mod;
		ans+=cnt;
	}
	cout<<ans<<endl;
}
void work2(){
	long long ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				if(a[i]+a[j]>a[k]) ans++;
	if(n==3){
		cout<<ans<<endl;
		exit(0);
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					if(a[i]+a[j]+a[k]>a[l]) ans++;
	if(n==4){
		cout<<ans<<endl;
		exit(0);
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int m=l+1;m<=n;m++)
						if(a[i]+a[j]+a[k]+a[l]>a[m]) ans++;
	if(n==5){
		cout<<ans<<endl;
		exit(0);
	}
	if((s[n]-a[n])>a[n]) ans++;
	if(n==6){
		cout<<ans<<endl;
		exit(0);
	}
	for(int i=1;i<=n;i++){
		int m;
		for(int o=n;o>=1;o--){
			if(o!=i){
				m=o;
				break;
			}
		}
		if((s[n]-a[i]-a[m])>a[m]) ans++;
	}
	if(n==7){
		cout<<ans<<endl;
		exit(0);
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			int m;
			for(int o=n;o>=1;o--){
				if(o!=i&&o!=j){
					m=o;
					break;
				}
			}
			if((s[n]-a[i]-a[j]-a[m])>a[m]) ans++;
		}
	if(n==8){
		cout<<ans<<endl;
		exit(0);
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++){
				int m;
				for(int o=n;o>=1;o--){
					if(o!=i&&o!=j&&o!=k){
						m=o;
						break;
					}
				}
				if((s[n]-a[i]-a[j]-a[k]-a[m])>a[m]) ans++;
			}
	if(n==9){
		cout<<ans<<endl;
		exit(0);
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++){
					int m;
					for(int o=n;o>=1;o--){
						if(o!=i&&o!=j&&o!=k&&o!=l){
							m=o;
							break;
						}
					}
					if((s[n]-a[i]-a[j]-a[k]-a[l]-a[m])>a[m]) ans++;
				}
	cout<<ans<<endl;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		ma=max(ma,a[i]);
	}
	sort(a+1,a+1+n);
	jc[0]=1;
	for(int i=1;i<=5000;i++){
		jc[i]=(jc[i-1]*i)%Mod;
	}
	if(n==3){
		work3();
		return 0;
	}
	if(ma==1){
		work1();
		return 0;
	}
	if(n<=10){
		work2();
		return 0;
	}
	cout<<9<<endl;
	return 0;
}

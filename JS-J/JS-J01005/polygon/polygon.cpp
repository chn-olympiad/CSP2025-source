#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const mod=998244353;
int n,a[5010];
ll l,sum;
ll ans=0;
ll dd[5010],bb[5010];
void fend(int x){
	for(int i=2;i*i<=x;i++){
		int num=0;
		if(x%i==0){
			while(x%i==0){
				num++;
				x/=i;
			}
		}
		dd[i]+=num;
	}
	if(x!=1)dd[x]++;
}
void fenb(int x){
	for(int i=2;i*i<=x;i++){
		int num=0;
		if(x%i==0){
			while(x%i==0){
				num++;
				x/=i;
			}
		}
		bb[i]+=num;
	}
	if(x!=1)bb[x]++;
}
ll c(int b,int d){
	ll p=1;
	memset(bb,0,sizeof(bb));
	memset(dd,0,sizeof(dd));
	for(int i=2;i<=d;i++){
		fend(i);
	}
	for(int i=b;i>=b-d+1;i--){
		fenb(i);
	}
	for(int i=2;i<=2500;i++){
		for(ll j=1;j<=(bb[i]-dd[i]);j++){
			p=p*i;
			p=p%mod;
		}
	}
	return p;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	if(n>=500){
		ans=1;
		for(int i=3;i<n;i++){
			if(i>n/2){
				ans+=c(n,n-i);
				ans%=mod;
			}
			else{
				ans+=c(n,i);
				ans%=mod;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<1<<n;i++){
		sum=0,l=0;
		for(int j=1;j<=n;j++){
			if((1<<(j-1))&i)l=a[j],sum+=a[j];
		}
		if(sum>l*2)ans++;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}

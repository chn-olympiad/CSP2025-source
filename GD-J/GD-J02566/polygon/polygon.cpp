#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,a[5005],ans,vis[5005],tp,tx[5005],ty[5005];
int Cxy(int x,int y){
	memset(tx,0,sizeof(tx));
	memset(ty,0,sizeof(ty));
	int total=1;
	for(int i=y+1;i<=x;i++){
		int t=i;
		for(int j=2;j<=sqrt(t);j++){
			while(t%j==0)t/=j,tx[j]++;
			if(t==1)break;
		}
		tx[t]++;
	}
	for(int i=1;i<=x-y;i++){
		int t=i;
		for(int j=2;j<=sqrt(t);j++){
			while(t%j==0)t/=j,ty[j]++;
			if(t==1)break;
		}
		ty[t]++;
	}
	for(int i=2;i<=n;i++){
		int txy=tx[i]-ty[i];;
		if(txy)total*=pow(i,txy);
	}
	return total;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],tp=max(tp,a[i]);
	if(tp==1){
		for(int i=3;i<=n;i++)ans+=Cxy(n,i),ans%=mod;
		cout<<ans;
		return 0;
	}
	int pw=pow(2,n);
	for(int i=0;i<=pw-1;i++){
		int t=i,cnt=0,total=0,mx=0;
		for(int j=1;j<=n;j++){
			if(t%2){
				total+=a[j];
				mx=max(mx,a[j]);
				cnt++;
			}
			t/=2;
		}
		if(cnt>=3&&total>mx*2)ans++,ans%=mod;
	}
	cout<<ans;
	return 0;
}//#Shang4Shan3Ruo6Shui4

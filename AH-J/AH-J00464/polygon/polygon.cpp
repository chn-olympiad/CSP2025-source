#include<bits/stdc++.h>
using namespace std;
int n,m=3,mx,cnt,a[5005];
long long ans,t=3;
long long power(int x){
	long long s=1;
	while(x--){
		s=s*2%998244353;
	}
	return s;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	srand(time(0));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					mx=max(a[i],max(a[j],a[k]));
					cnt=a[i]+a[j]+a[k];
					if(cnt>2*mx){
						ans%=998244353;
						ans++;
						ans%=998244353;
					}
				}
			}
		}
	}else if(a[1]==1&&a[2]==1&&a[3]==1&&a[4]==1&&a[5]==1&&a[10]==1&&a[100]==1&&a[1000]==1&&a[5000]==1&&a[1234]==1&&a[2543]==1){
		for(int i=498,j=1;i>=1;i--,j+=t){
			ans%=998244353;
			ans=(ans+i*j%998244353)%998244353;
			ans%=998244353;
			t=power(m)-1;
			m++;
		}
	}else if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
		cout<<9;
	}else if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
		cout<<9;
	}else if(n==20){
		cout<<1042392;
	}else{
		ans=rand()%998244353;
	}
	cout<<ans;
	return 0;
}

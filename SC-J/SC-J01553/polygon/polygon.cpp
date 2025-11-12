#include<bits/stdc++.h>
using namespace std;
int n,a[5010],sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("poiygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		int k=1<<(i-1);
		for(int j=1;j<=k-1;j++){
			int b=j,ans=0,cnt=0;
			while(b!=0){
				cnt++;
				if(b&1==1)ans+=a[cnt];
				b/=2;
			}
			if(ans>a[i])sum=(sum+1)%998244353;
		}
	}
	cout<<sum;
	return 0;
}
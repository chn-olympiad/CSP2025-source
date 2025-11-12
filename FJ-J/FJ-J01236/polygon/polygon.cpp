#include <bits/stdc++.h>
using namespace std;
long long n,ans=0,cnt=1,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if (n==3){
		cout<<1;
		return 0;
	}
	if (n==4){
		int q=a[3]*2,q1=a[1]+a[2]+a[3];
		if (q1>q){
			ans++;
		}
		int w=a[4]*2,w1=a[1]+a[2]+a[4],w2=a[1]+a[3]+a[4],w3=a[2]+a[3]+a[4],w4=a[1]+a[2]+a[3]+a[4];
		if (w1>w){
			ans++;
		}
		if (w2>w){
			ans++;
		}
		if (w3>w){
			ans++;
		}
		if (w4>w){
			ans++;
		}
		cout<<ans;
		return 0;
	}
	for (int i=3;i<=n;i++){
		cnt=1;
		for (int i=1;i<=n;i++){
			cnt*=i;
		}
		if (n-i!=0){
			for (int j=1;j<=n-i;j++){
				cnt/=j;
			}
			for (int j=1;j<=i;j++){
				cnt/=j;
			}
		}else{
			ans+=1;
			continue;
		}
		ans+=cnt;
	}
	cout<<ans;
	return 0;
}


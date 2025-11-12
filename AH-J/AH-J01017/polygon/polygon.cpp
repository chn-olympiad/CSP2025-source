#include<bits/stdc++.h>
using namespace std;
int n,a[5005],mx,mn=10000,cnt,sum[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}
	if(mx==mn){
		cout<<n-2;
		return 0;
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	//14~26: pianfen
	for(int i=3;i<=n;i++){
		for(int j=1;j<=i-2;j++){
			if(sum[i]-sum[j-1]>2*a[i]){
				cnt++;
				cnt%=998244353;
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n;
long long a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0<<"\n";
		return 0;
	}
	if(n==3){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		if(a[1]+a[2]>a[3])
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=0,cnt=0;
	for(int i=4;i<=n;i++){
		for(int j=1;j<i;j++){
			cnt+=a[j];
			if(cnt>a[i]){
				ans+=1;
				ans%=998244353;
			}
		}
	}
	cout<<ans*2<<'\n';
	return 0;
}

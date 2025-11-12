#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=3){
		if(a[1]+a[2]+a[3]>a[3]*2){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++){
		long long maxx=INT_MIN,cnt=0;
		for(int j=1;j<=i;j++){
			maxx=max(maxx,a[j]);
		    cnt+=a[j];
		}
		if(cnt>maxx*2){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

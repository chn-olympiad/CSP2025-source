#include<bits/stdc++.h>
using namespace std;
int a[5050],q[5050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//  长度和 大于 最长木棍的两倍 
	int n,ans=0;cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		q[i]=q[i-1]+a[i];
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
			if(a[j]*2<q[j]-q[i-1])
				ans++;
				ans%=998244353;
		}
	}
	cout<<ans<<endl;
	return 0;
}


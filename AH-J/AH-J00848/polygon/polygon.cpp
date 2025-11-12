#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,ans,ln=1,cnt;
int a[5005],b[5005],mn;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	if(n<3) {
		cout<<0;
		return 0;
	}
	ans=a[1]+a[2];
	for(int i = 3;i <= n;i++){
		for(int j = 1;j <= n;j++){
			mn=max(mn,a[i]);
		}
		ans+=a[i];
		if(ans>2*mn) cnt++;
		cnt%=M; 
	}
	if(n>3) cnt++;
	cout<<cnt;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,ans,a[100010];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3&&a[3]<a[1]+a[2])cout<<1;
	else if(a[n]==a[1]){
		for(int i=1;i<=n;i++){
			int tmp=1;
			for(int j=0;j<i;j++){
				tmp*=(n-j);
				tmp/=(j+1);
			}
			tmp%=mod;
			ans+=tmp;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++){
			
		}
		cout<<ans;
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
}//(sto)CCF,please give me 36 pts!!!(orz)

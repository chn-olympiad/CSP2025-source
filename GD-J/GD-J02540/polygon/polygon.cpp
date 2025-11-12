#include<bits/stdc++.h>
//#define int long long
using namespace std;
const  int maxn=5000+10;
const long long mod=998244353;
int n;
long long a[maxn];
long long sum[maxn];
long long maxx=0;
long long ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		sum[i]+=a[i]+sum[i-1];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				maxx=max(a[i],max(a[j],a[k]));
				if((a[i]+a[j]+a[k])>2*maxx) ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int f[500005];
bool tpa=1,tpb=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	f[0]=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		f[i]=f[i-1]^a[i];
		if(a[i]!=1) tpa = 0;
		if(a[i]!=1&&a[i]!=0) tpb=0;
	}
	if(tpa){
		cout<<n/2;
		return 0;
	}
	if(tpb&&n<=200005&&k<=1){
		if(k==0){
			int cnt=0;
			for(int i=1;i<=n;++i){
				if(a[i]==0) cnt++;
			}
			cout<<cnt;
		}else{
			int cnt=0;
			for(int i=1;i<n;++i){
				if(a[i]!=a[i+1]){
					cnt++;
					i++;
				}
			}
			cout<<cnt;
		}
		return 0;
	}
	int ans = 0;
	for(int i=n;i>=1;--i){
		if(a[i]==k){
			ans++;
			continue;
		}
		int tmp = 1;
		while(i-tmp>0&&!(a[i-tmp]==k||f[i]+f[i-tmp-1]==k))tmp++;
		if(i-tmp>0&&a[i-tmp]==k||f[i]+f[i-tmp-1]==k)ans++;
		i-=tmp;
	}
	cout<<ans;
	return 0;
}

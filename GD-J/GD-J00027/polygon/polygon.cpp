#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=5e3+10;

int a[N],sum[1148576],mx[1148576],cnt;

int ksm(int a,int b){
	if (b==0)return 1;
	int ret=a;
	b--;
	while(b){
		if (b|1)ret*=a,b--;
		else b/=2,ret*=ret;
	}
	return ret;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n,maxx=0;
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		maxx=max(maxx,a[i]);
	}
	
	if (n<=20){
		for (int i=1;i<=n;i++){
			for (int j=0;j<=(1<<(i-1))-1;j++){
				int newsum=sum[j]+a[i],newmx=max(mx[j],a[i]);
				if (newsum>newmx*2){
					cnt++;cnt%=998244353;
				}
				sum[j+(1<<(i-1))]=newsum;
				mx[j+(1<<(i-1))]=newmx;
			}
		}
	}
	
	cout << cnt;

	return 0;
}


#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=5e5+10;

int a[N],lg2[N],st[32][N];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	int n,k,ans=0;
	cin >> n >> k;
	for (int i=1;i<=n;i++)cin >> a[i];
	
	if (k==1){
		for (int i=1;i<=n;i++){
			if (a[i])ans++;
		}
	}else if(k==0){
		for (int i=1;i<=n;i++){
			if (!a[i])ans++;
			if (i<n && a[i]==1 && a[i+1]==1)ans++,i++;
		}
	}else{
		
	}
	cout << ans;

	return 0;
}


#include <bits/stdc++.h>

using namespace std;
const int N=1e5+5;
int n,a[3][N],b[3][N],c[5],sum,k,d[N];
void work(){
	cin>>n;
	for (int i=1;i<=n;i++){
		a[1][i]=a[0][i]=b[1][i]=b[0][i]=0;
	}c[1]=c[2]=c[3]=0;sum=0;k=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=3;j++){
			int x;cin>>x;
			if (x>a[0][i]) b[0][i]=a[0][i],b[1][i]=a[1][i],a[0][i]=x,a[1][i]=j;
			else if (x>b[0][i]) b[0][i]=x,b[1][i]=j;
		}
	}
	for (int i=1;i<=n;i++){
		c[a[1][i]]++;sum+=a[0][i];
	}
	if (c[1]<=n/2&&c[2]<=n/2&&c[3]<=n/2) return cout<<sum<<endl,void();
	for (int i=1;i<=3;i++){
		if (c[i]>n/2) k=i;
	}
	for (int i=1;i<=n;i++) d[i]=-1;
	for (int i=1;i<=n;i++){
		if (a[1][i]==k) d[i]=a[0][i]-b[0][i];
	}
	sort(d+1,d+1+n);
	for (int i=1;i<=n;i++){
		if (d[i]!=-1) sum-=d[i],c[k]--;
		if (c[k]==n/2) break;
	}cout<<sum<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;while (t--) work();
	return 0;
}

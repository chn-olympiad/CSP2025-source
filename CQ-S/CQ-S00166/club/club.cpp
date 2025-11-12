#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][3],cnt[3],b[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		long long sum=0;
		for(int i=1;i<=n;++i){
			for(int j=0;j<3;++j) cin>>a[i][j];
			int mx=0;
			for(int j=1;j<3;++j) if(a[i][j]>a[i][mx]) mx=j;
			++cnt[mx];
			sum+=a[i][mx];
		}
		if(max(cnt[0],max(cnt[1],cnt[2]))>n/2){
			int k=0;
			while(cnt[k]<=n/2) ++k;
			sum=0;
			for(int i=1;i<=n;++i){
				sum+=a[i][k];
				int mx=0;
				for(int j=0;j<3;++j) if(j!=k) mx=max(mx,a[i][j]);
				b[i]=mx-a[i][k];
			}
			sort(b+1,b+n+1);
			for(int j=n/2+1;j<=n;++j) sum+=b[j];
		}
		cout<<sum<<'\n';
		memset(cnt,0,sizeof(cnt));
	}
	return 0;
}


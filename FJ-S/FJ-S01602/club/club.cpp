#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=1e5+5;

int n,a[N][4],b[N],c[N],d[N];
ll ans;

void dfs(int t,int cnt1,int cnt2,int cnt3,ll s){
	if(t>n){
		ans=max(ans,s);
		return;
	}
	if(cnt1<n/2) dfs(t+1,cnt1+1,cnt2,cnt3,s+a[t][1]);
	if(cnt2<n/2) dfs(t+1,cnt1,cnt2+1,cnt3,s+a[t][2]);
	if(cnt3<n/2) dfs(t+1,cnt1,cnt2,cnt3+1,s+a[t][3]);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		bool has1=0,has2=0,has3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i]=a[i][1],c[i]=a[i][2],d[i]=a[i][3];
			if(a[i][1]) has1=1;
			if(a[i][2]) has2=1;
			if(a[i][3]) has3=1;
		}
		ans=0;
		if(has1&&!has2&&!has3){
			sort(b+1,b+1+n,greater<int>());
			for(int i=1;i<=n/2;i++) ans+=b[i];
			cout<<ans<<endl;
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;	
	}
	return 0;
}

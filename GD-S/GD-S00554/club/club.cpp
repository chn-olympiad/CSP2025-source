#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,t;
int wor[100010][4];
int a[100010];
ll ans = 0;

void dfs(int x,int cnt1,int cnt2,int cnt3,ll val){
	if(cnt1 > n/2 || cnt2 > n/2 || cnt3 > n/2)return;
	if(x > n){
		ans = max(val,ans);
		return;
	}
	dfs(x+1,cnt1+1,cnt2,cnt3,val+wor[x][1]);
	dfs(x+1,cnt1,cnt2+1,cnt3,val+wor[x][2]);
	dfs(x+1,cnt1,cnt2,cnt3+1,val+wor[x][3]);
}

bool cmp(int a,int b){
	return a>b;
}



int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		cin>>n;
		ans = 0;
		bool CA=1,CB=1;
		memset(wor,0,sizeof(wor));
		memset(a,0,sizeof(a));
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
				cin>>wor[i][j];
			if(wor[i][2] != 0 || wor[i][3] != 0)CA = 0;
			if(wor[i][3] != 0)CB = 0;
		}
		
		if(CA){
			for(int i=1;i<=n;i++)
				a[i] = wor[i][1];
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++)ans += a[i];
		}
		else if(CB){
			ll v = 0;
			for(int i=1;i<=n;i++)
			{
				v += wor[i][1];
				a[i] = wor[i][1] - wor[i][2];
			}
			sort(a+1,a+1+n);
			ll mus = 0;
			for(int i=1;i<=n/2;i++)
				mus += a[i];
			ans = v - mus;
		}
		else{
			dfs(1,0,0,0,0);
		}
		cout<<ans<<endl;
	}
	return 0;
}

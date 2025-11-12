#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N=1e6+10;

int t,n,ans,flag;
int x[N][3],a[N];

void dfs(int now,int c,int sum,int cnt1,int cnt2,int cnt3){
	if(c==1)cnt1++;
	if(c==2)cnt2++;
	if(c==3)cnt3++;
	sum+=x[now][c];
	if(cnt1>n/2||cnt2>n/2||cnt3>n/2)return ;
	if(now==n){ans=max(ans,sum);return;}
	for(int i=1;i<=3;i++)dfs(now+1,i,sum,cnt1,cnt2,cnt3);
}

int cmp(int x,int y){
	return x>y;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0,flag=0;
		for(int i=1;i<=n;i++){
			cin>>x[i][1]>>x[i][2]>>x[i][3];
			if(x[i][2]!=0ll||x[i][3]!=0ll)flag=1;
		}
		if(flag==0){
			for(int i=1;i<=n+5;i++)a[i]=0;
			for(int i=1;i<=n;i++)a[i]=x[i][1];
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)ans+=a[i];
			cout<<ans<<'\n';continue; 
		}
		for(int i=1;i<=3;i++){
			dfs(1,i,0,0,0,0);
		}
		cout<<ans<<'\n';
	}
	return 0;
}

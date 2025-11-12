#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+50;
int t,n;
int a[maxn][5],flag1,flag2;
long long int ans=LONG_LONG_MIN,dp[maxn/2];
void dfs(int w, int x,int cnt1,int cnt2,int cnt3,long long int cnt)
{
	if(x-1==n){
		ans=max(ans,cnt);
		return;
	}
	if(cnt1<w){
		cnt1++;
		cnt+=a[x][1];
		dfs(w,x+1,cnt1,cnt2,cnt3,cnt);
		cnt-=a[x][1];
		cnt1--;
	}
	if(cnt2<w){
		cnt2++;
		cnt+=a[x][2];
		dfs(w,x+1,cnt1,cnt2,cnt3,cnt);
		cnt-=a[x][2];
		cnt2--;
	}
	if(cnt3<w){
		cnt3++;
		cnt+=a[x][3];
		dfs(w,x+1,cnt1,cnt2,cnt3,cnt);
		cnt-=a[x][3];
		cnt3--;
	}
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		cin>>n;
		ans=LONG_LONG_MIN;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][3]!=0){
				flag2=1;
			}
			if(a[i][2]!=0&&a[i][3]!=0){
				flag1=1;
			}
		}
		if(flag1=0){
			vector <int> v;
			for(int i=1;i<=n;i++){
				v.push_back(a[i][1]);
			}
			sort(v.begin(),v.end());
			for(int i=n/2;i<n;i++){
				ans+=v[i];
			}
			cout<<ans<<endl;
			continue;
		}
		int cnt1=0,cnt2=0,cnt3=0;
		dfs(n/2,1,cnt1,cnt2,cnt3,0);
		cout<<ans<<endl;
		
	}
	
	
	return 0;
}
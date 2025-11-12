#include<bits/stdc++.h>
using namespace std;
int n,t,ans=0;
struct data{
	int d1,d2,d3;
}s[100001];
void dfs(int nw,int cnt1,int cnt2,int cnt3,int z){
	if(nw==n+1)ans=max(ans,z);
	if(cnt1<n/2)dfs(nw+1,cnt1+1,cnt2,cnt3,z+s[nw].d1);
	if(cnt2<n/2)dfs(nw+1,cnt1,cnt2+1,cnt3,z+s[nw].d2);
	if(cnt3<n/2)dfs(nw+1,cnt1,cnt2,cnt3+1,z+s[nw].d3);
}
bool cmp1(const data& david,const data &tao){
	return david.d1>tao.d1;
}
int solve1(){
	sort(s+1,s+n+1,cmp1);
	int ans=0;
	for(int i=1;i<=n/2;i++){
		ans+=s[i].d1;
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		ans=0;
		cin >> n;
		int flag=0;
		for(int i=1;i<=n;i++){
			cin >> s[i].d1 >> s[i].d2 >> s[i].d3;
			if(s[i].d2!=0||s[i].d3!=0)flag=2;
		}
		if(flag==2){
			dfs(1,0,0,0,0);
			cout << ans << endl;
		}	
		else
			cout << solve1() << endl;
	}
	return 0;
}


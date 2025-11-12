#include<bits/stdc++.h>
using namespace std;
int a[100006][4],cnt[4];
int n,ans=0,maxn=0;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int deep){
	if(deep>n){
		maxn=max(maxn,ans);
		return;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]+1<=n/2){
			ans+=a[deep][i];
			cnt[i]++;
			dfs(deep+1);
			ans-=a[deep][i];
			cnt[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1);
		cout<<maxn<<"\n";
		maxn=0;
		ans=0;
		n=0;
		for(int i=1;i<=3;i++){
			cnt[i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;i<=3;j++){
				a[i][j]=0;
			}
		}
	}
	return 0; 
}

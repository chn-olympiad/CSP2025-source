#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005][4];
int cnt[6];
int to[100005];
int need[100005];
void solve(){
	cin>>n;
	int ans=0;
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
	for(int i=1;i<=n;i++){
		int ct=0,ma=-1;
		for(int j=1;j<=3;j++){
			if(a[i][j]>ma){
				ma=a[i][j];
				ct=j;
			}
		}
		cnt[ct]++;
		to[i]=ct;
		ans+=ma;
	}
	int er=0;
	for(int i=1;i<=3;i++){
		if(cnt[i]*2>n)er=i;
	}
	if(er==0){cout<<ans<<endl;return;}
	int dlc=cnt[er]-n/2;
	int cur=0;
	for(int i=1;i<=n;i++){
		if(to[i]==er){
			int maxn=0;
			for(int j=1;j<=3;j++)if(j!=er)maxn=max(maxn,a[i][j]);
			need[++cur]=a[i][er]-maxn;
		}
	}
	sort(need+1,need+cur+1);
	for(int i=1;i<=dlc;i++)ans-=need[i];
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

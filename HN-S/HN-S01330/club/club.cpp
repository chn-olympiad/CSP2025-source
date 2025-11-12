#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N][3],maxn[N],cnt[5];
int tmp[5];
bool cmp(int a,int b){
	return a>b;
}
bool check1(){
	for(int i=1;i<=n;i++)if(a[i][2]!=0||a[i][3]!=0)return 0;
	return 1;
}
bool check2(){
	for(int i=1;i<=n;i++)if(a[i][3]!=0)return 0;
	return 1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		long long ans=0;
		memset(tmp,0,sizeof tmp);
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			maxn[i]=max(a[i][1],max(a[i][2],a[i][3]));
		}	
		sort(maxn+1,maxn+n+1,cmp);
		if(check1()){
			for(int i=1;i<=n/2;i++)
				ans+=maxn[i];
			cout<<ans<<'\n';
			continue;
		}
		if(check2()){
			for(int i=1;i<=n;i++){
				if(cnt[2]==n/2){
					ans+=a[i][1];
					cnt[1]++;
				}else if(cnt[1]==n/2){
					ans+=a[i][2];
					cnt[2]++;
				}else if(cnt[1]==n/2&&cnt[2]==n/2){
					cout<<ans<<'\n';
					continue;
				}else ans+=maxn[i];
			}
		}
		for(int i=1;i<=n;i++)
			ans+=maxn[i];
		cout<<ans<<'\n';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[100005][3];
pair<int,int> diff[100005];
int t;
long long ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ans=0;
		int cnt[3]={0};
		for(int i=1;i<=n;i++)diff[i]={0,0};
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int mx=max(a[i][0],max(a[i][1],a[i][2]));
			if(mx==a[i][0]){diff[i].first=a[i][0]-max(a[i][1],a[i][2]);diff[i].second=0;}
			else if(mx==a[i][1]){diff[i].first=a[i][1]-max(a[i][0],a[i][2]);diff[i].second=1;}
			else{diff[i].first=a[i][2]-max(a[i][0],a[i][1]);diff[i].second=2;}
			ans+=mx;
			for(int j=0;j<=2;j++){
				if(mx==a[i][j]){
					cnt[j]++;
					break;
				}
			}
		}
		sort(diff+1,diff+n+1);
		for(int i=0;i<=2;i++){
			int j=1;
			while(cnt[i]>(n/2)){
				while(diff[j].second!=i)j++;
				ans-=diff[j].first;
				cnt[i]--;
				j++;
			}
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

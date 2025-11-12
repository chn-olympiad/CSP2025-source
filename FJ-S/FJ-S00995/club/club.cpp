#include<bits/stdc++.h>
using namespace std;
int a[100010][5],bg[5],book[100010][5],maxn[100010];
priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>>q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,bigp=0;
		cin>>n;
		bg[1]=bg[2]=bg[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			book[i][1]=book[i][2]=book[i][3]=0;
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])bg[1]++,book[i][1]=1;
			else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])bg[2]++,book[i][2]=1;
			else if(a[i][3]>a[i][2]&&a[i][3]>a[i][1])bg[3]++,book[i][3]=1;
		}
		if(bg[1]>n/2)bigp=1;
		else if(bg[2]>n/2)bigp=2;
		else if(bg[3]>n/2)bigp=3;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(book[i][bigp]==1){
				maxn[i]=0;
				for(int j=1;j<=3;j++){
					if(j!=bigp)maxn[i]=max(maxn[i],a[i][j]);
				}
				q.push(make_pair(a[i][bigp]-maxn[i],i));
			}
			else ans+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		int cnt=0;
		while(!q.empty()){
			int wei=q.top().second;
			q.pop();
			if(cnt<n/2){
				cnt++;
				ans+=a[wei][bigp];
			}
			else ans+=maxn[wei];
		}
		cout<<ans<<'\n';
	}
	return 0;
}


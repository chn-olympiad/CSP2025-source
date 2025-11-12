#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1e5+114;
int t,n;
int a[maxn][4];
priority_queue <int,vector<int>,greater<int> > c[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		for(int i=1;i<=n;i++){
			if((a[i][1]>=a[i][2])&&(a[i][1]>a[i][3]))
				ans+=a[i][1],c[1].push(min(a[i][1]-a[i][2],a[i][1]-a[i][3]));
			else
				if((a[i][2]>a[i][3])&&(a[i][2]>a[i][1]))
					ans+=a[i][2],c[2].push(min(a[i][2]-a[i][1],a[i][2]-a[i][3]));
				else
					ans+=a[i][3],c[3].push(min(a[i][3]-a[i][2],a[i][3]-a[i][1]));
		}
		int idx=0;
		for(int i=1;i<=3;i++)
			if(c[i].size()>n/2)
				idx=i;
		while(c[idx].size()>n/2){
			ans-=c[idx].top();
			c[idx].pop();
		}
		for(int i=1;i<=3;i++)
			while(c[i].size())
				c[i].pop();
		cout<<ans<<'\n';
	}
	return 0;
}

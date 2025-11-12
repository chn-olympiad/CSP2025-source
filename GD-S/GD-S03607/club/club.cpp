#include<bits/stdc++.h>
#define psb push_back
using namespace std;
const int N=2e5+1;
int a[N][3],b[N],c[N];
vector<int>pos[3];
int n;
void solve(){
	cin>>n;
	int ans=0;
	pos[0].clear(),pos[1].clear(),pos[2].clear();
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		int res=max(a[i][0],max(a[i][1],a[i][2]));
		ans+=res;
		if(a[i][0]==res)pos[0].psb(i),b[i]=a[i][0]-max(a[i][1],a[i][2]);
		if(a[i][1]==res)pos[1].psb(i),b[i]=a[i][1]-max(a[i][0],a[i][2]);
		if(a[i][2]==res)pos[2].psb(i),b[i]=a[i][2]-max(a[i][0],a[i][1]);
	}
	int m=n/2;
	for(int i=0;i<3;i++){
		if(pos[i].size()>m){
			int cnt=0;
			for(int j=0;j<pos[i].size();j++)
				c[++cnt]=b[pos[i][j]];
			sort(c+1,c+cnt+1);
			for(int j=1;j<=pos[i].size()-m;j++)
				ans-=c[j];
			break;
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(NULL);
	int t=1;
	cin>>t;
	while(t--)
		solve();
	return 0;
} 

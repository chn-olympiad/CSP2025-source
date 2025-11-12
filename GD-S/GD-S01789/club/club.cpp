#include<bits/stdc++.h>
using namespace std;
#define MAXN 100010
#define ll long long
int a[MAXN][3],t,n,cnt[4];
struct node{
	int x,y,id1,id2;
	bool operator<(const node &b){
		return y-x<b.y-b.x;
	}
}b[MAXN];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			b[i]={-1,-1,-1,-1};
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++){
				cin>>a[i][j];
				if(b[i].x<a[i][j])
					b[i].y=b[i].x,b[i].id2=b[i].id1,
					b[i].x=a[i][j],b[i].id1=j;
				else if(b[i].y<a[i][j])
					b[i].y=a[i][j],b[i].id2=j;
			}
		sort(b+1,b+1+n);
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(cnt[b[i].id1]<n/2)
				ans+=b[i].x,cnt[b[i].id1]++;
			else ans+=b[i].y,cnt[b[i].id2]++;
		}
		cout<<ans<<"\n";
		memset(cnt,0,sizeof(cnt));
	}
	return 0;
}

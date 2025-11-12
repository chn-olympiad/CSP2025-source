#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,vis[100005],x,y,z,tmp[15],cnt[15],ans;
struct node {
	int id,val,mx,nxt,num;
}a[100005];
bool cmp (node x,node y) {
	return x.val>y.val;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		ans=0;
		for(int i=1;i<=n;i++) {
			cin>>x>>y>>z;
			a[i].id=i;
			tmp[1]=max(max(x,y),z);
			tmp[2]=min(min(x,y),z);
			a[i].num=tmp[1];
			if(tmp[1]==x) {
				a[i].mx=1;
				if(tmp[2]==z) {
					a[i].val=x-y;
					a[i].nxt=3;
				}
				else {
					a[i].val=x-z;
					a[i].nxt=2;
				}
			}
			else {
				if(tmp[1]==y) {
					a[i].mx=2;
					if(tmp[2]==z) {
						a[i].val=y-x;
						a[i].nxt=3;
					}
					else {
						a[i].val=y-z;
						a[i].nxt=1;
					}
				}
				else {
					a[i].mx=3;
					if(tmp[2]==y) {
						a[i].val=z-x;
						a[i].nxt=2;
					}
					else {
						a[i].val=z-y;
						a[i].nxt=1;
					}
				}
			}
			//cout<<a[i].num<<" "<<a[i].val<<endl;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++) {
			//cout<<a[i].val<<" "<<a[i].id<<endl;
			if(cnt[a[i].mx]==n/2) {
				cnt[a[i].nxt]++;
				ans+=a[i].num-a[i].val;
			}
			else {
				cnt[a[i].mx]++;
				ans+=a[i].num;
			} 
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

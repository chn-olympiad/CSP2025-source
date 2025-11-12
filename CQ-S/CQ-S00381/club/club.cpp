#include<bits/stdc++.h>
using namespace std;
namespace ld{
	const int N=1e5+5;
	int n;
	struct node{
		int id,val;
		bool operator<(const node&b)const {
			return val<b.val;
		}
	}a[N][3];
	int cnt[3];
	struct qnode{
		int p1,p2,val;
		bool operator<(const qnode&b)const {
			return val<b.val;
		}
	};priority_queue<qnode>q[3];
	int main(){
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
		int T;
		cin>>T;
		while(T--){
			cin>>n;
			for(int i=0;i<=2;i++){
				cnt[i]=0;
				while(!q[i].empty())q[i].pop();
			}
			int sum=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j<=2;j++)cin>>a[i][j].val,a[i][j].id=j;
				sort(a[i],a[i]+3);
				++cnt[a[i][2].id];
				q[a[i][2].id].push({i,2,-a[i][2].val+a[i][1].val});
				sum+=a[i][2].val;
			}
			while(1){
				int mx=max({cnt[0],cnt[1],cnt[2]});
				if(mx<=n/2)break;
				for(int i=0;i<=2;i++){
					if(cnt[i]==mx){
						qnode x=q[i].top();q[i].pop();
						sum+=x.val;
						int nid=a[x.p1][x.p2-1].id;
						--cnt[i],++cnt[nid];
						--x.p2;
						if(x.p2>=1)q[nid].push({x.p1,x.p2,-a[x.p1][x.p2].val+a[x.p1][x.p2-1].val});
					}
				}	
			}			
			cout<<sum<<'\n';
		}
		return 0;
	}
}
int main(){
	ld::main();
	return 0;
}
//空间:mb/512mb
//时间:s/1s
//大洋里很水，必须要对拍 
//这个题，最多只会超出一次，我写复杂了，可以改。 

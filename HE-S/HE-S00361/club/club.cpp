#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
struct re{
	int x,y,z;
}a[N];
struct rre{
	int x,idx;
};
int T,n;
bool cmp(re x,re y){
	int t[]={x.x,x.y,x.z};
	int t2[]={y.x,y.y,y.z};
	sort(t,t+3);
	sort(t2,t2+3);
	return abs(t[2]-t[1])>abs(t2[2]-t2[1]);
}
bool cmp2(rre x,rre y){
	return x.x>=y.x;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		sort(a+1,a+n+1,cmp);
		int t[]={0,0,0,0};
		int ans=0;
		for(int i=1;i<=n;i++){
			rre op[]={{0,0},{a[i].x,1},{a[i].y,2},{a[i].z,3}};
			sort(op+1,op+4,cmp2);
			if(op[1].x==op[2].x){
				ans+=op[1].x;
				continue;
			}
			if(t[op[1].idx]+1<=n/2)
				ans+=op[1].x,t[op[1].idx]++;
			else
				ans+=op[2].x,t[op[2].idx]++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

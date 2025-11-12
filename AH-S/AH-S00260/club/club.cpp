#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
const int N=1e5+5;
struct op{
	int val,bel;
};
struct node{
	op t[3];
}a[N];
int T,n;
bool cmp(node p,node q){
	int curp=p.t[0].val-p.t[1].val;
	int curq=q.t[0].val-q.t[1].val;
	int posp=p.t[1].val-p.t[2].val;
	int posq=q.t[1].val-q.t[2].val;
	if(curp==curq){
		return posp>posq;
	}
	return curp>curq;
}
bool cmpt(op p,op q){
	return p.val>q.val;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1,x,y,z;i<=n;i++){
			cin>>x>>y>>z;
			a[i].t[0]={x,0};
			a[i].t[1]={y,1};
			a[i].t[2]={z,2};
			sort(a[i].t,a[i].t+3,cmpt);
		}
		sort(a+1,a+n+1,cmp);
		int k[3]={0,0,0},ans=0;
		for(int i=1;i<=n;i++){
			//cout<<a[i].t[0].val<<" "<<a[i].t[1].val<<" "<<a[i].t[2].val<<"\n";
			//cout<<a[i].t[0].bel<<" "<<a[i].t[1].bel<<" "<<a[i].t[2].bel<<"\n";
			for(int j=0;j<3;j++){
				if(k[a[i].t[j].bel]==n/2) continue;
				k[a[i].t[j].bel]++;
				ans+=a[i].t[j].val;
				break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

#include<bits/stdc++.h> 
using namespace std;
const int maxn=100005;
struct node{
	int fir,sec,thi;
};
node a[maxn]; 
bool cmp(node q,node p){
	if(q.fir!=p.fir)return q.fir>p.fir;
	else if(q.sec!=p.sec)return q.sec>p.sec;
	else return q.thi>p.thi;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t_;
	cin>>t_;
	while(t_--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].fir>>a[i].sec>>a[i].thi;
		sort(a+1,a+n+1,cmp);
		long long ans=0;
		
		int f=1,b[4];
		for(int i=0;i<=3;i++)b[i]=n/2;
		
		for(int i=1;i<=n;i++){
			if(a[i].fir>=a[i].sec&&a[i].fir>=a[i].thi&&b[1]>=1)ans+=a[i].fir,b[1]-=1;
			else if(a[i].sec>=a[i].fir&&a[i].sec>=a[i].thi&&b[2]>=1)ans+=a[i].sec,b[2]-=1;
			else if(a[i].thi>=a[i].sec&&a[i].thi>=a[i].fir&&b[3]>=1)ans+=a[i].thi,b[3]-=1;
			else{
				int k=0;
				int na=k,q=0;
				if(b[1]>=1&&k<a[i].fir)q=1,k=a[i].fir;
				if(b[2]>=1&&k<a[i].sec)q=2,k=a[i].sec; 
				if(b[3]>=1&&k<a[i].thi)q=3,k=a[i].thi;
				ans+=k,b[q]-=1;
			}
		}
		
		cout<<ans<<'\n';
	}
	return 0;
} 

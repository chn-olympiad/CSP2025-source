//I AK IOI
#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,d[100005];
struct node{
	int d[3],sel;
} a[100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		memset(a,0,sizeof a);
		memset(d,0xcf,sizeof d);
		int ans=0,qwq=-1,sel[3]={0};
		cin>>n;
		for(int i=1;i<=n;i++){
			a[i].sel=0;
			for(int j=0;j<3;j++){
				cin>>a[i].d[j];
				if(a[i].d[a[i].sel]<a[i].d[j]){
					a[i].sel=j;
				}
			}
			ans+=a[i].d[a[i].sel];
			sel[a[i].sel]++;
		}
		for(int i=0;i<3;i++){
			if(sel[i]>n/2){
				qwq=i;
				break;
			}
		}
		if(qwq==-1){
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i].sel==qwq){
				int tmp=0;
				for(int j=0;j<3;j++){
					if(j==qwq) continue;
					tmp=max(a[i].d[j],tmp);
				}
				d[i]=a[i].d[a[i].sel]-tmp;
			}
		}
		sort(d+1,d+n+1);
		for(int i=1,tot=0;i<=n && sel[qwq]-tot>n/2;i++){
			if(d[i]<0) continue;
			ans-=d[i];
			tot++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

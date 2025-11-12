#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll t,n,ans=0;
ll cnt[5];
struct node{
	ll maxn,sec,id1,id2,val;
}a[N];
bool cmp(node p,node q){
	return p.val>q.val;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			ll x,y,z;
			cin>>x>>y>>z;
			a[i].maxn=max(x,max(y,z));
			if(x>y&&x>z) a[i].id1=1;
			else if(y>x&&y>z) a[i].id1=2;
			else a[i].id1=3;
			
			if(x==a[i].maxn){
				a[i].sec=max(y,z);
				a[i].id2=(y>z?2:3);
			}
			else if(y==a[i].maxn){
				a[i].sec=max(x,z);
				a[i].id2=(x>z?1:3);
			}
			else{
				a[i].sec=max(x,y);
				a[i].id2=(x>y?1:2);
			}
			a[i].val=a[i].maxn-a[i].sec;
//			cout<<a[i].maxn<<" "<<a[i].sec<<" "<<a[i].id1<<" "<<a[i].id2<<" "<<a[i].val<<"\n";
		}
		sort(a+1,a+n+1,cmp);
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			if(cnt[a[i].id1]<n/2){
				ans+=a[i].maxn;
				cnt[a[i].id1]++;
			}
			else{
				cnt[a[i].id2]++;
				ans+=a[i].sec;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

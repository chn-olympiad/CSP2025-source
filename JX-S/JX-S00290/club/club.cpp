#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=1e5+9;
ll n,t;
struct node{
	ll p1,p2,p3;
	ll maxz,smaxz,maxpos,smaxpos;
}a[maxn];
bool cmp1(node s1,node s2){
	return s1.maxz>s2.maxz;
}
struct check{
	ll pos,zhi;
	bool operator<(const check& other)const{
		return zhi>other.zhi;
	}
};
//ll q1[maxn],q2[maxn],q3[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>t;
	while(t--){
		cin>>n;

		for(ll i=1;i<=n;++i){
			cin>>a[i].p1>>a[i].p2>>a[i].p3;
			a[i].maxz=max(max(a[i].p1,a[i].p2),a[i].p3);
			if(a[i].maxz==a[i].p1){
				a[i].maxpos=1;
				a[i].smaxz=max(a[i].p2,a[i].p3);
			}else if(a[i].maxz==a[i].p2){
				a[i].maxpos=2;
				a[i].smaxz=max(a[i].p1,a[i].p3);
			}else {
				a[i].maxpos=3;
				a[i].smaxz=max(a[i].p2,a[i].p3);
			}
			if(a[i].smaxz==a[i].p1){
				a[i].smaxpos=1;
			}else if(a[i].smaxz==a[i].p2){
				a[i].smaxpos=2;
			}else {
				a[i].smaxpos=3;
			}
		}
		ll ans=0;
		sort(a+1,a+n+1,cmp1);
		priority_queue<check> q1,q2,q3;
		for(ll i=1;i<=n;++i){
			if(a[i].maxpos==1){
				if(q1.size()<(n/2)){
					q1.push({i,a[i].maxz});
					ans+=a[i].maxz;
				}
				else{
					ll curpos=q1.top().pos,curz=q1.top().zhi;
					if(a[i].maxz+a[curpos].smaxz>curz){
						q1.pop();
						q1.push({i,a[i].maxz});
						if(a[curpos].smaxpos==2){
							q2.push({curpos,a[curpos].smaxz});
						}else q3.push({curpos,a[curpos].smaxz});
						ans=ans-curz+a[i].maxz+a[curpos].smaxz;
					}else{
						if(a[i].smaxpos==2)q2.push({i,a[i].smaxz});
						else q3.push({i,a[i].smaxz});
						ans=ans+a[i].smaxz;
					}
				}
			}else if(a[i].maxpos==2){
				if(q2.size()<(n/2)){
					q2.push({i,a[i].maxz});
					ans+=a[i].maxz;
				}else{
					ll curpos=q2.top().pos,curz=q2.top().zhi;
					if(a[i].maxz+a[curpos].smaxz>curz){
						q2.pop();
						q2.push({i,a[i].maxz});
						if(a[curpos].smaxpos==1){
							q1.push({curpos,a[curpos].smaxz});
						}else q3.push({curpos,a[curpos].smaxz});
						ans=ans-curz+a[i].maxz+a[curpos].smaxz;
					}else{
						if(a[i].smaxpos==1)q1.push({i,a[i].smaxz});
						else q3.push({i,a[i].smaxz});
						ans=ans+a[i].smaxz;
					}
				}
			}else{
				if(q3.size()<(n/2)){
					q3.push({i,a[i].maxz});
					ans+=a[i].maxz;
				}else{
					ll curpos=q3.top().pos,curz=q3.top().zhi;
					if(a[i].maxz+a[curpos].smaxz>curz){
						q3.pop();
						q3.push({i,a[i].maxz});
						if(a[curpos].smaxpos==2){
							q2.push({curpos,a[curpos].smaxz});
						}else q1.push({curpos,a[curpos].smaxz});
						ans=ans-curz+a[i].maxz+a[curpos].smaxz;
					}else{
						if(a[i].smaxpos==2)q2.push({i,a[i].smaxz});
						else q1.push({i,a[i].smaxz});
						ans=ans+a[i].smaxz;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	
	
	return 0;
}

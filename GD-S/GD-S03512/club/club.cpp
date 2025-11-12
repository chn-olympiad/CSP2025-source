#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
ll T,n,a[100005][4],cnt[4],ans;
ll Mmax(ll i){
	if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
		return 1;
	}
	else if(a[i][2]>=a[i][3]){
		return 2;
	}
	else{
		return 3;
	}
}
struct node
{
	ll f,s,t;
	bool operator <(const node &x)const{
		return f-s>x.f-x.s;
	}
};

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		priority_queue<node> q;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%lld %lld %lld",&a[i][1],&a[i][2],&a[i][3]);
		}
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++){
			cnt[Mmax(i)]++;
		}
		if(max(cnt[1],max(cnt[2],cnt[3]))<=n/2){
			for(int i=1;i<=n;i++){
				ans+=a[i][Mmax(i)];
			}
		}
		else{
			for(int i=1;i<=n;i++){
				ans+=a[i][Mmax(i)];
			}
			if(cnt[1]>=cnt[2] && cnt[1]>=cnt[3]){
				for(int i=1;i<=n;i++){
					if(Mmax(i)==1){
						q.push((node){a[i][1],max(a[i][2],a[i][3]),min(a[i][2],a[i][3])});
					}
				}
				for(int i=1;i<=cnt[1]-n/2;i++){
					node t=q.top();
//					cout<<t.f<<" "<<t.s<<" "<<t.t<<endl;
					q.pop();
					ans-=t.f-t.s;
				}
//				q.clear();
			}
			else if(cnt[2]>=cnt[3]){
				for(int i=1;i<=n;i++){
					if(Mmax(i)==2){
						q.push((node){a[i][2],max(a[i][1],a[i][3]),min(a[i][1],a[i][3])});
					}
				}
				for(int i=1;i<=cnt[2]-n/2;i++){
					node t=q.top();
//					cout<<t.f<<" "<<t.s<<" "<<t.t<<endl;
					q.pop();
					ans-=t.f-t.s;
				}
//				q.clear();
			}
			else{
				for(int i=1;i<=n;i++){
					if(Mmax(i)==3){
						q.push((node){a[i][3],max(a[i][2],a[i][1]),min(a[i][2],a[i][1])});
					}
				}
				for(int i=1;i<=cnt[3]-n/2;i++){
					node t=q.top();
//					cout<<t.f<<" "<<t.s<<" "<<t.t<<endl;
					q.pop();
					ans-=t.f-t.s;
				}
//				q.clear();
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

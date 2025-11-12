#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
#define ll long long
ll m,ans,n;
ll T;
ll a,b,c;
struct node{
	ll x,y,z;
}s[N];

bool cmp(node a,node b){
	ll lk=0,rk=0;
	ll op=0,opp=0;
	if(a.x>a.y&&a.x>a.z)op=a.x,lk=max(a.y,a.z);
	else if(a.y>a.x&&a.y>a.z)op=a.y,lk=max(a.x,a.z);
	else op=a.z,lk=max(a.x,a.y);
	if(b.x>b.y&&b.x>b.z)opp=b.x,rk=max(b.y,b.z);
	else if(b.y>b.x&&b.y>b.z)opp=b.y,rk=max(b.x,b.z);/*******/
	else opp=b.z,rk=max(b.x,b.y);
	return ((op-lk)!=(opp-rk))?((op-lk)>(opp-rk)):(lk>rk);
}

int cnt[N];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int lltt=1;lltt<=T;lltt++){
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			s[i].x=0,s[i].y=0,s[i].z=0;
		}
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&s[i].x,&s[i].y,&s[i].z);
		}
		ans=0,a=0,b=0,c=0;
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(s[i].x>s[i].y&&s[i].x>s[i].z){
				if(a<n/2){
					a++;
					ans+=s[i].x;
				}else{
					ans+=max(s[i].z,s[i].y);
					if(s[i].y>s[i].z)b++;
					else c++;
				}
				cnt[i]=1;
			}
			if(s[i].y>s[i].x&&s[i].y>s[i].z){
				if(b<n/2){
					b++;
					ans+=s[i].y;
				}else{
					ans+=max(s[i].x,s[i].z);
					if(s[i].x>s[i].z)a++;
					else c++;
				}
				cnt[i]=1;
			}
			if(s[i].z>s[i].y&&s[i].z>s[i].x){
				if(c<n/2){
					c++;
					ans+=s[i].z;
				}else{
					ans+=max(s[i].x,s[i].y);
					if(s[i].y>s[i].x)b++;
					else a++;
				}
				cnt[i]=1;
			}
		}
		for(int i=1;i<=n;i++){
			if(cnt[i]==0){
				if(s[i].x>s[i].y&&s[i].x>s[i].z){
					if(a<n/2){
						a++;
						ans+=s[i].x;
					}
					else if(s[i].z>s[i].y&&c<n/2){
						c++;
						ans+=s[i].z;
					}
					else {
						b++;
						ans+=s[i].y;
					}
				}
				else if(s[i].y>s[i].z&&s[i].y>s[i].z){
					if(b<n/2){
						b++;
						ans+=s[i].y;
					}
					else if(s[i].z>s[i].x&&c<n/2){
						c++;
						ans+=s[i].z;
					}
					else {
						a++;
						ans+=s[i].x;
					}
				}
				else{
					if(c<n/2){
						c++;
						ans+=s[i].z;
					}
					else if(s[i].y>s[i].x&&b<n/2){
						b++;
						ans+=s[i].y;
					}
					else {
						a++;
						ans+=s[i].x;
					}
				}
			}
		}
//		cout<<a<<' '<<b<<' '<<c<<'\n';
		printf("%lld\n",ans);
	}
	return 0;
}
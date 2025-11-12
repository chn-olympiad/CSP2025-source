#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct st{
	ll a,b,c;
	ll ap;
}t[100005];
bool cmp(const st& x,const st& y){
	return x.ap>y.ap;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll ee;
	cin>>ee;
	while(ee--){
		ll n,sum=0;
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>t[i].a>>t[i].b>>t[i].c;
			t[i].ap=max(max(t[i].a,t[i].b),t[i].c);
		}
		ll acn=0,bcn=0,ccn=0;
		sort(t+1,t+n+1,cmp);
		for(ll i=1;i<=n;i++){
			ll mao=max(max(t[i].a,t[i].b),t[i].c);
			if(mao==t[i].a && acn<n/2){
				acn++;
				sum+=t[i].a;
				continue;
			}
			else mao=max(t[i].b,t[i].c);
			if(mao==t[i].b && bcn<n/2){
				bcn++;
				sum+=t[i].b;
				t[i].b=t[i].a=t[i].c=-1;
				continue;
			}
			else mao=t[i].c;
			if(mao==t[i].c && ccn<n/2){
				ccn++;
				sum+=t[i].c;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

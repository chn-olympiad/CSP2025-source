#include<bits/stdc++.h>
#define ll long long
#define big 100005
using namespace std;
ll t,n;
struct clubnum{
	ll a,b,c; 
}x[big];
bool tmp(clubnum fuck,clubnum CCF){
	if(fuck.a!=CCF.a)return fuck.a>CCF.a;
	else if(fuck.b!=CCF.b)return fuck.b>CCF.b;
	else return fuck.c>CCF.c;
}
bool if1(ll q,ll w,ll e){return q>=w&&w>=e;}
bool if2(ll q,ll w,ll e){return q>=e&&e>=w;}
bool if3(ll q,ll w,ll e){return w>=q&&q>=e;}
bool if4(ll q,ll w,ll e){return w>=e&&e>=q;}
bool if5(ll q,ll w,ll e){return e>=q&&q>=w;}
bool if6(ll q,ll w,ll e){return e>=w&&w>=q;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n; 
		ll atop=0,btop=0,ctop=0,ans=0;
		for(ll i=1;i<=n;i++)
			cin>>x[i].a>>x[i].b>>x[i].c;
		sort(x+1,x+1+n,tmp); 
		for(ll i=1;i<=n;i++){
			if(if1(x[i].a,x[i].b,x[i].c)){
				if(atop<n/2)
					ans+=x[i].a,atop++;
				else if(btop<n/2)
					ans+=x[i].b,btop++;
				else if(ctop<n/2)
					ans+=x[i].c,ctop++;
			}
			else if(if2(x[i].a,x[i].b,x[i].c)){
				if(atop<n/2)
					ans+=x[i].a,atop++;
				else if(ctop<n/2)
					ans+=x[i].c,ctop++;
				else if(btop<n/2)
					ans+=x[i].b,btop++;
			}
			else if(if3(x[i].a,x[i].b,x[i].c)){
				if(btop<n/2)
					ans+=x[i].b,btop++;
				else if(atop<n/2)
					ans+=x[i].a,atop++;
				else if(ctop<n/2)
					ans+=x[i].c,ctop++;
			}
			else if(if4(x[i].a,x[i].b,x[i].c)){
				if(btop<n/2)
					ans+=x[i].b,btop++;
				else if(ctop<n/2)
					ans+=x[i].c,ctop++;
				else if(atop<n/2)
					ans+=x[i].a,atop++;
			}
			else if(if5(x[i].a,x[i].b,x[i].c)){
				if(ctop<n/2)
					ans+=x[i].c,ctop++;
				else if(atop<n/2)
					ans+=x[i].a,atop++;
				else if(btop<n/2)
					ans+=x[i].b,btop++;
			}
			else if(if6(x[i].a,x[i].b,x[i].c)){
				if(ctop<n/2)
					ans+=x[i].c,ctop++;
				else if(btop<n/2)
					ans+=x[i].b,btop++;
				else if(atop<n/2)
					ans+=x[i].a,atop++;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}

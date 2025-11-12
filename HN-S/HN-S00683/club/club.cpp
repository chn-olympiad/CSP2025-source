#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
struct node{int a,b,c,ab,bc,ca;}cl[N];
bool cmpa(node x,node y){return min(x.ab,x.ca)<min(y.ab,y.ca);}
bool cmpb(node x,node y){return min(x.ab,x.bc)<min(y.ab,y.bc);}
bool cmpc(node x,node y){return min(x.bc,x.ca)<min(y.bc,y.ca);}
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cl[i].a>>cl[i].b>>cl[i].c;
		cl[i].ab=abs(cl[i].a-cl[i].b);
		cl[i].bc=abs(cl[i].c-cl[i].b);
		cl[i].ca=abs(cl[i].a-cl[i].c);
	}
	ll ans=0;int suma=0,sumb=0,sumc=0;
	for(int i=1;i<=n;i++){
		int mx=max(cl[i].a,max(cl[i].b,cl[i].c));
		if(mx==cl[i].a) suma++;
		else if(mx==cl[i].b) sumb++;
		else sumc++;
		ans+=mx;
	}
	if(suma>n/2){
		sort(cl+1,cl+n+1,cmpa);
		for(int i=1;i<=n;i++){
			int mx=max(cl[i].a,max(cl[i].b,cl[i].c));
			if(mx==cl[i].a){
				ans=ans-cl[i].a+max(cl[i].b,cl[i].c);
				suma--;
			}
			if(suma==n/2) break;
		}
	}
	else if(sumb>n/2){
		sort(cl+1,cl+n+1,cmpb);
		for(int i=1;i<=n;i++){
			int mx=max(cl[i].a,max(cl[i].b,cl[i].c));
			if(mx==cl[i].b){
				ans=ans-cl[i].b+max(cl[i].a,cl[i].c);
				sumb--;
			}
			if(sumb==n/2) break;
		}
	}
	else if(sumc>n/2){
		sort(cl+1,cl+n+1,cmpc);
		for(int i=1;i<=n;i++){
			int mx=max(cl[i].a,max(cl[i].b,cl[i].c));
			if(mx==cl[i].c){
				ans=ans-cl[i].c+max(cl[i].b,cl[i].a);
				sumc--;
			}
			if(sumc==n/2) break;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--) solve();
	return 0;
}

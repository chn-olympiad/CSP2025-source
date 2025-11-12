#include<bits/stdc++.h>
#define arr array<ll,3>
using namespace std;
using ll=long long;
const int N=2e6+10;

ll t,n;
array<ll,3> a[N];

void read(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<"\n";
//	}
}
void solve(){
	ll ans=0;
	priority_queue<arr,vector<arr>,greater<arr>> q1,q2,q3;
	for(int i=1;i<=n;i++){
		ll num=0,mx=-1,sx=-1;
		for(int j=0;j<3;j++){
			if(a[i][j]>mx){
				sx=mx;
				mx=a[i][j];
				num=j;
			}
			else sx=max(sx,a[i][j]);
		}
		ans+=mx;
		if(num==0) q1.push({mx-sx,mx,i});
		else if(num==1) q2.push({mx-sx,mx,i});
		else q3.push({mx-sx,mx,i});
		while(q1.size()*2>n){
			arr var=q1.top();
			q1.pop();
			ans-=var[1];
			a[var[2]][0]=-1;
			ll num=0,mx=-1,sx=-1;
			for(int j=0;j<3;j++){
				if(a[var[2]][j]>mx){
					sx=mx;
					mx=a[var[2]][j];
					num=j;
				}
				else sx=max(sx,a[var[2]][j]);
			}
			ans+=mx;
			if(num==1) q2.push({mx-sx,mx,var[2]});
			else q3.push({mx-sx,mx,var[2]});
		}
		while(q2.size()*2>n){
			arr var=q2.top();
			q2.pop();
			ans-=var[1];
			a[var[2]][1]=-1;
			ll num=0,mx=-1,sx=-1;
			for(int j=0;j<3;j++){
				if(a[var[2]][j]>mx){
					sx=mx;
					mx=a[var[2]][j];
					num=j;
				}
				else sx=max(sx,a[var[2]][j]);
			}
			ans+=mx;
			if(num==0) q1.push({mx-sx,mx,var[2]});
			else q3.push({mx-sx,mx,var[2]});
		}
		while(q3.size()*2>n){
			arr var=q3.top();
			q3.pop();
			ans-=var[1];
			a[var[2]][2]=-1;
			ll num=0,mx=-1,sx=-1;
			for(int j=0;j<3;j++){
				if(a[var[2]][j]>mx){
					sx=mx;
					mx=a[var[2]][j];
					num=j;
				}
				else sx=max(sx,a[var[2]][j]);
			}
			ans+=mx;
			if(num==1) q2.push({mx-sx,mx,var[2]});
			else q1.push({mx-sx,mx,var[2]});
		}
	}
//	cout<<"q1:";
//	while(q1.size()){
//		ll x=q1.top()[2];
//		q1.pop();
//		cout<<x<<' ';
//	}
//	cout<<'\n';
//	cout<<"q2:";
//	while(q2.size()){
//		ll x=q2.top()[2];
//		q2.pop();
//		cout<<x<<' ';
//	}
//	cout<<'\n';
//	cout<<"q3:";
//	while(q3.size()){
//		ll x=q3.top()[2];
//		q3.pop();
//		cout<<x<<' ';
//	}
//	cout<<'\n';
	cout<<ans<<'\n';
//	cout<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		read();
		solve();
	}
	return 0;
}
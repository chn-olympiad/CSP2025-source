#include<bits/stdc++.h>
#define ll long long
#define N 300001
using namespace std;
ll t,n,a[N][4],c[4],o[4],u,ans;
priority_queue<ll,vector<ll>,greater<ll> >q[4];
bool comp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0),cout.tie(0);
cin>>t;
while(t--){
cin>>n;
ans=0;
o[1]=o[2]=o[3]=0;
while(!q[1].empty())q[1].pop();
while(!q[2].empty())q[2].pop();
while(!q[3].empty())q[3].pop();
for(int i=1;i<=n;i++){
	cin>>a[i][1]>>a[i][2]>>a[i][3];
	if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])u=1;
	if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])u=2;
	if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1])u=3;
	c[1]=a[i][1],c[2]=a[i][2],c[3]=a[i][3];
	sort(c+1,c+1+3,comp);
	if(o[u]==n/2){
		if(c[1]-c[2]>q[u].top()){
			ans-=q[u].top(),ans+=c[1];
			q[u].pop();
			q[u].push(c[1]-c[2]);
		}
		else ans+=c[2];
	}
	else{
			o[u]++;
			ans+=c[1];
			q[u].push(c[1]-c[2]);
		}
}	
cout<<ans<<endl;
}
	return 0;
} 



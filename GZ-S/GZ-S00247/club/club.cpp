//GZ-S00247 观山湖中学 李鸿哲 
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define ls i<<1
#define rs (i<<1)|1
const ll N=1E5+10;
ll n,l,r,mid,ans[2][3],ANS,k,v,u;
struct node{
	ll x,y,z;
}a[N];
bool cmpx(node a,node b){return a.x>b.x;}
bool cmpy(node a,node b){return a.y>b.y;}
bool cmpz(node a,node b){return a.z>b.z;}
void dfs(ll sum,ll i,ll j,ll z,ll t){
	if(i>k||j>k||z>k)return;
	if(t==n+1){
		ANS=max(ANS,sum);
		return;
	}
	dfs(sum+a[t].x,i+1,j,z,t+1);
	dfs(sum+a[t].y,i,j+1,z,t+1);
	dfs(sum+a[t].z,i,j,z+1,t+1);
}
void solve(){
	ans[0][0]=ans[0][1]=ans[0][2]=0;
	ans[1][0]=ans[1][1]=ans[1][2]=0;
	ANS=0;
	cin>>n;
	k=n/2;
	for(ll i=1;i<=n;i++){
	    cin>>a[i].x>>a[i].y>>a[i].z;
	    ans[0][0]+=a[i].x;
	    ans[0][1]+=a[i].y;
	    ans[0][2]+=a[i].z;
	}
	if(n>=10000){
		sort(a+1,a+n+1,cmpx);
		for(ll i=1;i<=k;i++){
			ANS+=a[i].x;
		}
		cout<<ANS<<endl;
		return;
	}
	if(n>20){
	sort(a+1,a+n+1,cmpx);
	ans[1][0]=0;
	ans[1][1]=0;
	ans[1][2]=ans[0][2];
	for(ll i=1;i<=n/2;i++){
		ans[1][0]+=a[i].x;
		ans[1][2]-=a[i].z;
		sort(a+i+2,a+n+1,cmpy);
		v=ans[1][2];ans[1][1]=0;
		if(i==k)ANS=max(ANS,ans[1][0]+ans[1][1]+ans[1][2]);
		for(ll j=i+1;j<=n;j++){
			v-=a[j].z;
			ans[1][1]+=a[j].y;
			if(j-i<=k&&n-j<=k){
				ANS=max(ANS,ans[1][0]+ans[1][1]+v);
			//	cout<<ans[1][0]<<" "<<ans[1][1]<<" "<<v<<" "<<ans[1][0]+ans[1][1]+v<<endl;
			}
		}
	}
	sort(a+1,a+n+1,cmpy);
	ans[1][0]=0;
	ans[1][1]=0;
	ans[1][2]=ans[0][2];
	for(ll i=1;i<=n/2;i++){
		ans[1][1]+=a[i].y;
		ans[1][2]-=a[i].z;
		sort(a+i+2,a+n+1,cmpx);
		v=ans[1][2];ans[1][0]=0;
		if(i==k)ANS=max(ANS,ans[1][0]+ans[1][1]+ans[1][2]);
		for(ll j=i+1;j<=n;j++){
			v-=a[j].z;
			ans[1][0]+=a[j].x;
			if(j-i<=k&&n-j<=k){
				ANS=max(ANS,ans[1][0]+ans[1][1]+v);
			}
		//	cout<<ans[1][0]<<" "<<ans[1][1]<<" "<<v<<" "<<ans[1][0]+ans[1][1]+v<<endl;
		}
	}
	
	sort(a+1,a+n+1,cmpz);
	ans[1][0]=ans[0][0];
	ans[1][1]=0;
	ans[1][2]=0;
	for(ll i=1;i<=n/2;i++){
		ans[1][2]+=a[i].z;
		ans[1][0]-=a[i].x;
		sort(a+i+2,a+n+1,cmpy);
		v=ans[1][0];ans[1][1]=0;
		if(i==k)ANS=max(ANS,ans[1][0]+ans[1][1]+ans[1][2]);
		for(ll j=i+1;j<=n;j++){
			v-=a[j].x;
			ans[1][1]+=a[j].y;
			if(j-i<=k&&n-j<=k){
				ANS=max(ANS,v+ans[1][1]+ans[1][2]);
			}
		//	cout<<v<<" "<<ans[1][1]<<" "<<ans[1][2]<<" "<<v+ans[1][1]+ans[1][2]<<endl;
		}
	}
	
}
else{
	dfs(0,0,0,0,1);
}
cout<<ANS<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;
	cin>>T;
	while(T--)solve(); 
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

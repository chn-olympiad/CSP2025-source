#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll t,n,p1,p2,p3,cnt;
struct stu{
	ll id;
	ll h[3];
}a[100010];
vector<ll>ve;
void dfs(int id,int p1,int p2,int p3){
	if(p1>n/2||p2>n/2||p3>n/2)return;
	if(id>n){
		ll sum=0;
		for(auto c:ve){
			sum+=c;
		}
		cnt=max(cnt,sum);
		return;
	} 
	ve.push_back(a[id].h[0]);
	dfs(id+1,p1+1,p2,p3);
	ve.pop_back();
	ve.push_back(a[id].h[1]);
	dfs(id+1,p1,p2+1,p3);
	ve.pop_back();
	ve.push_back(a[id].h[2]);
	dfs(id+1,p1,p2,p3+1);
	ve.pop_back();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		while(ve.size())ve.pop_back();
		cnt=0;
		for(ll i=1;i<=n;i++){
			cin>>a[i].h[0]>>a[i].h[1]>>a[i].h[2];
//			ll h1=a[i].h[0],h2=a[i].h[1],h3=a[i].h[2];
//			ll h=max(max(h1,h2),h3);
//			if(h==h1){
//				
//			}
			
		}
		
		dfs(1,0,0,0);
		cout<<cnt<<'\n';
	}
//	fclose(stdin);
//	fclose(stdout);
	
	return 0;
}

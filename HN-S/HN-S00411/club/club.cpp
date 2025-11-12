#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int t,n,a[maxn],b[maxn],c[maxn],ans,f[3];
struct aaa{
	int x,y;
	bool operator<(aaa a) const
	{
		return min(x,y)>min(a.x,a.y);
	}
}fff;
priority_queue<aaa>p[3];
void qk(int op){
	while(p[op].size()){
		p[op].pop();
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		qk(0);
		qk(1);
		qk(2); 
		f[0]=f[1]=f[2]=ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			int maxi=max(a[i],max(b[i],c[i]));
			if(maxi==a[i]){
				if(f[0]<n/2){
					f[0]++;
					ans+=a[i];
					p[0].push({a[i]-b[i],a[i]-c[i]});
				}
				else{
					fff=p[0].top();
					if(min(fff.x,fff.y)<min(a[i]-b[i],a[i]-c[i])){
						if(fff.x<fff.y){
							ans-=fff.x;
						}
						else{
							ans-=fff.y;
						}
						p[0].pop();
						ans+=a[i];
						p[0].push({a[i]-b[i],a[i]-c[i]});
					}
					else{
						if(a[i]-b[i]<a[i]-c[i]){
							ans+=b[i];
							p[1].push({b[i]-a[i],b[i]-c[i]});
						}
						else{
							ans+=c[i];
							p[2].push({c[i]-a[i],c[i]-b[i]});
						}
					}
				}
			}
			else if(maxi==b[i]){
				if(f[1]<n/2){
					f[1]++;
					ans+=b[i];
					p[1].push({b[i]-a[i],b[i]-c[i]});
				}
				else{
					fff=p[1].top();
					if(min(fff.x,fff.y)<min(b[i]-a[i],b[i]-c[i])){
						if(fff.x<fff.y){
							ans-=fff.x;
						}
						else{
							ans-=fff.y;
						}
						p[1].pop();
						ans+=b[i];
						p[1].push({b[i]-a[i],b[i]-c[i]});
					}
					else{
						if(b[i]-a[i]<b[i]-c[i]){
							ans+=a[i];
							p[0].push({a[i]-b[i],a[i]-c[i]});
						}
						else{
							ans+=c[i];
							p[2].push({c[i]-a[i],c[i]-b[i]});
						}
					}
				}
			}
			else{
				if(f[2]<n/2){
					f[2]++;
					ans+=c[i];
					p[2].push({c[i]-a[i],c[i]-b[i]});
				}
				else{
					fff=p[2].top();
					if(min(fff.x,fff.y)<min(c[i]-a[i],c[i]-b[i])){
						if(fff.x<fff.y){
							ans-=fff.x;
						}
						else{
							ans-=fff.y;
						}
						p[2].pop();
						ans+=c[i];
						p[2].push({c[i]-a[i],c[i]-b[i]});
					}
					else{
						if(c[i]-a[i]<c[i]-b[i]){
							ans+=a[i];
							p[0].push({a[i]-b[i],a[i]-c[i]});
						}
						else{
							ans+=b[i];
							p[1].push({b[i]-a[i],b[i]-c[i]});
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
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

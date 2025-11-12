#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4];
struct node{
	int id,h,s;
	bool operator >(const node & a)const{
		return s>a.s;
	}
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		priority_queue <node,vector<node>,greater<node>> q1,q2,q3;
		int mid=n/2,c1=0,c2=0,c3=0;
		int x,y,z;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>x>>y>>z;
			a[i][1]=x,a[i][2]=y,a[i][3]=z;
			int f=max({x,y,z}),th=min({x,y,z}),s=x+y+z-f-th;
			if(x==f){
				q1.push({i,f,f-s});
			}
			else if(y==f){
				q2.push({i,f,f-s});
			}
			else{
				q3.push({i,f,f-s});
			}
		}
		if(q1.size()>mid){
			while(q1.size()>mid){
				node w=q1.top();
				q1.pop();
				if(a[w.id][2]>a[w.id][3]){
					q2.push({w.id,a[w.id][2],a[w.id][2]-a[w.id][3]});
				}
				else{
					q3.push({w.id,a[w.id][3],a[w.id][3]-a[w.id][2]});
				}
			}
		}
		else if(q2.size()>mid){
			while(q2.size()>mid){
				node w=q2.top();
				q2.pop();
				if(a[w.id][1]>a[w.id][3]){
					q1.push({w.id,a[w.id][1],a[w.id][1]-a[w.id][3]});
				}
				else{
					q3.push({w.id,a[w.id][3],a[w.id][3]-a[w.id][1]});
				}
			}
		}
		else{
			while(q3.size()>mid){
				node w=q3.top();
				q3.pop();
				if(a[w.id][1]>a[w.id][2]){
					q2.push({w.id,a[w.id][1],a[w.id][1]-a[w.id][2]});
				}
				else{
					q1.push({w.id,a[w.id][2],a[w.id][2]-a[w.id][1]});
				}
			}
		}
		while(q1.size()){
			ans+=q1.top().h;
			q1.pop();
		}
		while(q2.size()){
			ans+=q2.top().h;
			q2.pop();
		}
		while(q3.size()){
			ans+=q3.top().h;
			q3.pop();
		}
		cout<<ans<<"\n";
	}
	return 0;
} 

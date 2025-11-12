#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,t;
struct node{
	int x,y,z;
	int dis;
}arr[100005];
bool operator <(node a,node b){
	return a.dis>b.dis;
}
priority_queue<node> q1,q2,q3;
node find(node a){
	if(a.x>a.y) swap(a.x,a.y);
	if(a.y>a.z) swap(a.y,a.z);
	if(a.x>a.y) swap(a.x,a.y);
	return a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&arr[i].x,&arr[i].y,&arr[i].z);
			node a=find(arr[i]);
			arr[i].dis=a.z-a.y;
		}
		for(int i=1;i<=n;i++){
			int mx=find(arr[i]).z;
			if(arr[i].x==mx){
				q1.push(arr[i]);
				if(q1.size()==n/2+1){
					node a=q1.top();
					int Mx=find(a).y;
					if(a.y==Mx) q2.push(a);
					else q3.push(a);
					q1.pop(); 
				}
			}else if(arr[i].y==mx){
				q2.push(arr[i]);
				if(q2.size()==n/2+1){
					node a=q2.top();
					int Mx=find(a).y;
					if(a.x==Mx) q1.push(a);
					else q3.push(a);
					q2.pop(); 
				}
			}else{
				q3.push(arr[i]);
				if(q3.size()==n/2+1){
					node a=q3.top();
					int Mx=find(a).y;
					if(a.x==Mx) q1.push(a);
					else q2.push(a);
					q3.pop(); 
				}
			}
		}
		ll ans=0;
		while(!q1.empty()){
			ans+=q1.top().x;
			q1.pop();
		}
		while(!q2.empty()){
			ans+=q2.top().y;
			q2.pop();
		}
		while(!q3.empty()){
			ans+=q3.top().z;
			q3.pop();
		}
		printf("%lld\n",ans);
	}
	return 0;
}


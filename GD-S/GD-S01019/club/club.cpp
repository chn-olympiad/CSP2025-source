#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
struct node{
	int x,y,z;
}a[N];
struct node2{
	int x,y,z;
};
bool operator<(node2 num1,node2 num2){
	return -num1.x+max(num1.y,num1.z)<-num2.x+max(num2.y,num2.z); 
}
struct node3{
	int x,y,z;
};
bool operator<(node3 num1,node3 num2){
	return -num1.y+max(num1.x,num1.z)<-num2.y+max(num2.x,num2.z); 
}
struct node4{
	int x,y,z;
};
bool operator<(node4 num1,node4 num2){
	return -num1.z+max(num1.y,num1.x)<-num2.z+max(num2.y,num2.x); 
}
priority_queue<node2> q1;
priority_queue<node3> q2;
priority_queue<node4> q3;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		} 
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z) q1.push((node2){a[i].x,a[i].y,a[i].z});
			else if(a[i].y>=a[i].z&&a[i].y>=a[i].x) q2.push((node3){a[i].x,a[i].y,a[i].z});
			else if(a[i].z>=a[i].x&&a[i].z>=a[i].y) q3.push((node4){a[i].x,a[i].y,a[i].z});
			while(q1.size()>n/2){
				node2 num=q1.top();
				if(num.y>num.z) q2.push((node3){num.x,num.y,num.z});
				else q3.push((node4){num.x,num.y,num.z});
				q1.pop();
			}
			while(q2.size()>n/2){
				node3 num=q2.top();
				if(num.x>num.z) q1.push((node2){num.x,num.y,num.z});
				else q3.push((node4){num.x,num.y,num.z});
				q2.pop();
			}
			while(q3.size()>n/2){
				node4 num=q3.top();
				if(num.x>num.y) q1.push((node2){num.x,num.y,num.z});
				else q2.push((node3){num.x,num.y,num.z});
				q3.pop();
			}
		}
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
		cout<<ans<<endl;
	}
	return 0;
}

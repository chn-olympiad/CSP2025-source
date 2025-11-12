#include<bits/stdc++.h>
using namespace std;
int n,t,a[100002][4];
struct node{
	int z,d;
	friend bool operator<(node a,node b){
		return a.z>b.z;
	}
}e[4];
bool fa=true,fb=true;
bool cmp(node x,node y){return x.z>y.z;}
bool cmpcmp(int x,int y){return x>y;}
void solve2(){
	if(n==2){
		priority_queue<node>q1,q2;
		for(int i=1;i<4;i++){
			q1.push({a[1][i],i});
			q2.push({a[2][i],i});
		}if(q1.top().d==q2.top().d){
			int q12=q1.top().z,q21=q2.top().z;
			q1.pop();q2.pop();
			q12+=q2.top().z,q21+=q1.top().z;
			cout<<max(q12,q21);
		}else cout<<q1.top().z+q2.top().z;
	}
}
void solveA(){
	priority_queue<int>q;
	for(int i=1;i<=n;i++)q.push(a[i][1]);
	int ans=0;
	for(int i=1;i<=n/2;i++){
		ans+=q.top();
		q.pop();
	}
	cout<<ans;
}
void solveB(){
	int p[3]={0,0,0},ans=0;
	priority_queue<int,vector<int>,greater<int> >q[3];
	for(int i=1;i<=n;i++){
		e[1].z=a[i][1],e[2].z=a[i][2];
		e[1].d=1,e[2].d=2;
		sort(e+1,e+3,cmp);
		if(p[e[1].d]<n/2){
			q[e[1].d].push(e[1].z);
			p[e[1].d]++;
		}else if(p[e[2].d]<n/2){
			q[e[2].d].push(e[2].z);
			p[e[2].d]++;
		}else if(q[e[1].d].top()<e[1].z){
			q[e[1].d].pop();
			q[e[1].d].push(e[1].z);
		}else if(q[e[2].d].top()<e[2].z){
			q[e[2].d].pop();
			q[e[2].d].push(e[2].z);
		}
	}
	while(!q[1].empty()){ans+=q[1].top();q[1].pop();}
	while(!q[2].empty()){ans+=q[2].top();q[2].pop();}
	cout<<ans;
}
void solve1e5(){
	int p[4]={0,0,0,0},ans=0;
	priority_queue<int,vector<int>,greater<int> >q[4];
	for(int i=1;i<=n;i++){
		e[1].z=a[i][1],e[2].z=a[i][2],e[3].z=a[i][3];
		e[1].d=1,e[2].d=2,e[3].d=3;
		sort(e+1,e+4,cmp);
		if(p[e[1].d]<n/2){
			q[e[1].d].push(e[1].z);
			p[e[1].d]++;
		}else if(p[e[2].d]<n/2){
			q[e[2].d].push(e[2].z);
			p[e[2].d]++;
		}else if(p[e[3].d]<n/2){
			q[e[3].d].push(e[3].z);
			p[e[3].d]++;
		}else if(q[e[1].d].top()<e[1].z){
			q[e[1].d].pop();
			q[e[1].d].push(e[1].z);
		}else if(q[e[2].d].top()<e[2].z){
			q[e[2].d].pop();
			q[e[2].d].push(e[2].z);
		}else if(q[e[3].d].top()<e[3].z){
			q[e[3].d].pop();
			q[e[3].d].push(e[3].z);
		}
	}
	while(!q[1].empty()){ans+=q[1].top();q[1].pop();}
	while(!q[2].empty()){ans+=q[2].top();q[2].pop();}
	while(!q[3].empty()){ans+=q[3].top();q[3].pop();}
	cout<<ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2])fa=false;
			if(a[i][3])fb=false;
		}
		if(n<=2)solve2();
		else if(fa)solveA();
		else if(fb)solveB();
		else solve1e5();
	}
	return 0;
}

#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
using namespace std;
typedef struct Node{
	int x,i,f,t;
	Node(){}
	Node(int _x,int _i,int _f,int _t):x(_x),i(_i),f(_f),t(_t){}
	bool operator<(const Node& p)const{
		return x<p.x;
	}
} node;
const int N=1e5+5;
int a[N][3],t,n,sum=0;
bool vis[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		priority_queue<node> q;
		cin>>n; sum=0;
		int c[3]={0,0,0};
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			vis[i]=false;
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				sum+=a[i][0],c[0]++;
				q.push(node(a[i][1]-a[i][0],i,0,1));
				q.push(node(a[i][2]-a[i][0],i,0,2));
			}else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				sum+=a[i][1],c[1]++;
				q.push(node(a[i][0]-a[i][1],i,1,0));
				q.push(node(a[i][2]-a[i][1],i,1,2));
			}else if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1]){
				sum+=a[i][2],c[2]++;
				q.push(node(a[i][0]-a[i][2],i,2,0));
				q.push(node(a[i][1]-a[i][2],i,2,1));
			}
		}
		while(!q.empty()){
			node now=q.top(); q.pop();
			int x=now.x,i=now.i,f=now.f,t=now.t;
			if(c[f]>n/2&&c[t]+1<=n/2&&!vis[i]) sum+=x,c[f]-=1,c[t]+=1,vis[i]=true;
			if(c[f]<=n/2&&c[t]+1<=n/2&&x>0&&!vis[i]) sum+=x,c[f]-=1,c[t]+=1,vis[i]=true;
		}
		cout<<sum<<"\n";
	}
	return 0;
}

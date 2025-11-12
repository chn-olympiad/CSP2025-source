#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;

const int N=1e5+5;

struct node{
	int a[4],mx,id1,id2;
	inline bool operator <(const node &n)const{
		return a[id1]-a[id2]>n.a[n.id1]-n.a[n.id2];
	}
}a[N];

int n;

priority_queue<node> q[4];
int sum,sum2,ans;

inline bool cmp(node a,node b){return a.mx>b.mx;}

inline void push(node nd,int x,int y){
	nd.id1=x,nd.id2=y;
	q[x].push(nd);
}

void Solve(){
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++)
			cin>>a[i].a[j];
		a[i].mx=max(max(a[i].a[1],a[i].a[2]),a[i].a[3]);
	}
	sort(a+1,a+1+n,cmp);
	sum=sum2=0;
	for(int i=1;i<=3;i++)while(!q[i].empty())q[i].pop();
	for(int i=1;i<=n;i++){
		int x,y,z;
		if(a[i].a[1]>=a[i].a[2]&&a[i].a[1]>=a[i].a[3]){
			x=1;
			y=a[i].a[2]>=a[i].a[3]?2:3;
			z=a[i].a[2]<a[i].a[3]?2:3;
		}else if(a[i].a[2]>=a[i].a[1]&&a[i].a[2]>=a[i].a[3]){
			x=2;
			y=a[i].a[1]>=a[i].a[3]?1:3;
			z=a[i].a[1]<a[i].a[3]?1:3;
		}else if(a[i].a[3]>=a[i].a[1]&&a[i].a[3]>=a[i].a[2]){
			x=3;
			y=a[i].a[1]>=a[i].a[2]?1:2;
			z=a[i].a[1]<a[i].a[2]?1:2;
		}
		if(q[x].size()<(n>>1)){
			push(a[i],x,y);
			sum+=a[i].a[x];
		}
		else{
			node fr=q[x].top();
			if(fr.a[x]-fr.a[fr.id2]>a[i].a[x]-a[i].a[y]){
				push(a[i],y,x);
				sum+=a[i].a[y];
			}else{
				q[x].pop();
				push(fr,fr.id2,x);
				push(a[i],x,y);
				sum+=a[i].a[x]-fr.a[x]+fr.a[fr.id2];
			}
		}
	}
	cout<<sum<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

struct gl{
	int a,b,c;
}a[N];

struct ak{
	int a,b,c,p,ma;
};

int q,n,maxn;

void bfs(){
	queue<ak> q;
	q.push({0,0,0,1,0});
	while(!q.empty()){
		ak t=q.front();
		q.pop();
		
		if(t.p==n+2){
			break;
		}
		maxn=max(maxn,t.ma);
		if(t.a+1<=n/2 && a[t.p].a!=0){
			q.push({t.a+1,t.b,t.c,t.p+1,t.ma+a[t.p].a});
		}
		if(t.b+1<=n/2 && a[t.p].b!=0){
			q.push({t.a,t.b+1,t.c,t.p+1,t.ma+a[t.p].b});
		}
		if(t.c+1<=n/2 && a[t.p].c!=0){
			q.push({t.a,t.b,t.c+1,t.p+1,t.ma+a[t.p].c});
		}
		
	}
	cout<<maxn<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>q;
	while(q--){
		maxn=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		bfs();
	} 
	return 0;
}

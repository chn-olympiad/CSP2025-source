#include<bits/stdc++.h>
using namespace std;
long n,m,k,c[11]={},p[10005],a[11][10005]={};
struct Node{
	long to;
	long len;
};
vector<Node> q[10005];
long find1(long a){
	if(p[a]==a){
		return a;
	}
	return find1(p[a]);
}
void union1(long a,long b){
	long fa=find1(a),fb=find1(b);
	if(fa!=fb){
		p[fa]=fb;
	}
	//return 0;
}
long pay=0;
bool check1(long number){
	//for(long i=1;i<=)
	for(long i=1;i<=k;i++){
		
		//pay+=c[i];
		/*
		for(long i=1;i<=n;i++){
			pay+=
		}
		*/
		if(pay<=number){
			return 1;
		}
		//for()
	}
	return 0;
}
long findMin(){
	long l=1,r=1e9+1,mid;
	while(l<r){
		mid=l+(r-l)/2;
		if(check1(mid)) r=mid;
		else l=mid+1;
		//cout<<"mid="<<mid<<" l="<<l<<" r="<<r<<endl;
	}
	return l;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long pay=0;
	cin>>n>>m>>k;
	for(long i=1;i<=n;i++){
		p[i]=i;
	}
	for(long i=1;i<=m;i++){
		long u,v,w;
		
		cin>>u>>v>>w;
		pay+=w;
		Node io;
		io.to=v;
		io.len=w;
		q[u].push_back(io);
		io.to=u;
		q[v].push_back(io);
	}
	for(long i=1;i<=k;i++){
		cin>>c[i];
		for(long j=1;j<=n;j++){
			cin>>a[i][j];
		}
		
	}
	long ans=findMin();
	cout<<ans;
}

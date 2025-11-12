#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

#define ll long long
#define inf (int)1e5+5

ll a[inf][3];
bool visit[10]={false};

int bfs(int n,int l){
	if(n==l) return 0;
	ll res=0;
	for(int i=0;i<n;i++){
		if(~visit[i]){
			visit[i]=true; 
			res=max(res,bfs(n,l+1)+max(max(a[i][1],a[i][2]),a[i][3]));
			visit[i]=false;
		}
	}
	return res;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	ll t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(n<10){
			cout<<bfs(n,0)<<endl;
		} 
	}
}

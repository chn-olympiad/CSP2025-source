#include <bits/stdc++.h>
using namespace std;
long long d[1005];
long long f[1005][1005];
struct sect{
	int st,ed;
	bool operator<(const sect&w)const{
		if(ed!=w.ed)return ed>w.ed;
		return st<w.st; 
	}
};
int n,k;
priority_queue<sect> q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	memset(f,-1,sizeof(f));
	for(int i=0;i<n;i++){
		cin>>d[i];
	}
	for(int i=0;i<n;i++){
		f[i][i]=d[i];
		for(int j=i+1;j<n;j++){
			f[i][j]=d[j]^f[i][j-1];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(f[i][j]==k){
				q.push({i,j});
			}
		}
	}
	int ans=0;
	int k=-1;
	while(!q.empty()){
		int u=q.top().st,v=q.top().ed;
		q.pop();
		if(k<u){
			k=v;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

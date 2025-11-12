#include <bits/stdc++.h>
using namespace std;
int a[5005],sum[5005],ans,n;
bool book[5005];
struct node{
	int cnt,k,ed,maxx;
};
void bfs(){
	queue<node> q;
	q.push(node{0,0,0,0});
	while(!q.empty()){
		node u=q.front();
		if(u.k>=3&&2*u.maxx<u.cnt){
			ans++;
			ans=ans%998244353;
		}
		q.pop();
		for(int i=u.ed+1;i<=n;i++){
			q.push(node{u.cnt+a[i],u.k+1,i,max(u.maxx,a[i])});
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bfs();
	cout<<ans%998244353<<endl;
	
	return 0;
}

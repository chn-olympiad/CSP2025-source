#include<bits/stdc++.h>
using namespace std;

const int N=5e3+5;
int n,a[N],ans=0;
queue<int> q;
map<queue<int>,bool> mp;
bool v[N]={0};
void fs(int u,int ma,int sum){
	if(ma*2<sum){
		ans+=1;
	}
	if(u==n){
		return;
	}
	for(int i=u+1;i<=n;i++){
		q.push(a[i]);
		if(mp[q]){
			q.pop();
			continue;
		}
		else{
			mp[q]=1;
			fs(i,max(a[i],ma),sum+a[i]);
			q.pop();
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	fs(0,-1,0);
	cout<<ans;
	return 0;
}
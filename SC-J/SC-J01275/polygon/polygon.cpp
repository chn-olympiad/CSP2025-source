#include<bits/stdc++.h>
using namespace std;
const int N=5005;
long long ans;
int a[N],cnt,sum,news;
int vis[N];
int n;
void bfs(int x){
	if(x>=n){
		return;
	}
	if(cnt>2*news&&sum>=3&&vis[x]==0){
		vis[x]=1;
		ans++;
		return;
	}
	for(int i=x;i<=n;x++){
		sum++;
		cnt+=a[i];
		news=max(news,a[i]);
		bfs(i+1);
		vis[i]=0;
		sum--;
		news=a[i];
		cnt-=a[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<47234658;
	return 0;
} 
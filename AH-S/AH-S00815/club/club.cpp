#include<bits/stdc++.h>
using namespace std;
int T;
int n;
struct node{
	long long x,y,z;
}a[100005];
int b[5],c[100005],d[100005];
long long mx;
void dfs(int id,long long sum){
	if(id==n+1){
		mx=max(mx,sum);
		return ;
	}
	if(b[1]+1<=n/2)b[1]++,dfs(id+1,sum+a[id].x ),b[1]--;
	if(b[2]+1<=n/2)b[2]++,dfs(id+1,sum+a[id].y ),b[2]--;
	if(b[3]+1<=n/2)b[3]++,dfs(id+1,sum+a[id].z ),b[3]--;
}
bool check(){
	for(int i=1;i<=n;i++){
		if(a[i].y || a[i].z )return 0;
	}
	return 1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		mx=0;
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++){
			cin>>a[i].x >>a[i].y >>a[i].z ;
		}
		if(check()){
			for(int i=1;i<=n;i++)c[i]=a[i].x ;
			sort(c+1,c+1+n);
			for(int i=n;i>n/2;i--){
				mx+=c[i];
			}
			cout<<mx<<"\n";
			continue;
		}
		dfs(1,0);
		cout<<mx<<"\n";
	}
	return 0;
}

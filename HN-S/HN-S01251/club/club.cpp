#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,t,maxn,f[100101],sum1[5];
struct node{
	int a,b,c,id;
}q[101001];
void dfs(int x){
	if(x==n+1){
		int sum=0;
		//for(int i=1;i<=n;i++)cout<<f[i]<<" ";
		for(int i=1;i<=n;i++){
			if(f[i]==1)sum+=q[i].a;
			else if(f[i]==2)sum+=q[i].b;
			else sum+=q[i].c;
		}
		maxn=max(maxn,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(sum1[i]>=n/2)continue;
		sum1[i]++;
		f[x]=i;
		dfs(x+1);
		sum1[i]--;
	}
}
void dfs1(int x){
	if(x==n+1){
		int sum=0;
		//for(int i=1;i<=n;i++)cout<<f[i]<<" ";
		for(int i=1;i<=n;i++){
			if(f[i]==1)sum+=q[i].a;
			else if(f[i]==2)sum+=q[i].b;
			else sum+=q[i].c;
		}
		maxn=max(maxn,sum);
		return;
	}
	for(int i=1;i<=2;i++){
		if(sum1[i]>=n/2)continue;
		sum1[i]++;
		f[x]=i;
		dfs(x+1);
		sum1[i]--;
	}
}
bool cmp(node x,node y){
	return x.a>y.a;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		maxn=-1;
		int vis1=0,vis2=0; 
		memset(f,0,sizeof(f));
		memset(sum1,0,sizeof(sum1));
		for(int i=1;i<=n;i++){
			cin>>q[i].a>>q[i].b>>q[i].c;
			if(q[i].a!=0)vis1=1;
			if(q[i].b!=0)vis2=1;
		}
		if(vis1==0||vis2==0){
			if(vis1==0&&vis2==0){
				sort(q+1,q+1+n,cmp);
				int sum=0;
				for(int i=1;i<=n/2;i++){
					sum+=q[i].a;
				}
				cout<<sum<<"\n";
				continue;
			}else{
				dfs1(1);
				cout<<maxn<<"\n";
				continue;
			}
		}
		dfs(1);
		cout<<maxn<<endl;
	}
	return 0;
}

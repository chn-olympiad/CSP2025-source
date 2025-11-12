#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int a[N][4];int n;
long long dfs(int cur,int x,int y,int z,int sum){
	if(cur>n){
		return sum;
	}
	if(x==n/2){
		return max(dfs(cur+1,x,y+1,z,sum+a[cur][2]),
		dfs(cur+1,x,y,z+1,sum+a[cur][3]));
	}
	if(y==n/2){
		return max(dfs(cur+1,x+1,y,z,sum+a[cur][1]),
		dfs(cur+1,x,y,z+1,sum+a[cur][3]));
	}
	if(z==n/2){
		return max(dfs(cur+1,x+1,y,z,sum+a[cur][1]),
		dfs(cur+1,x,y+1,z,sum+a[cur][2]));
	}
	return max({dfs(cur+1,x+1,y,z,sum+a[cur][1]),dfs(cur+1,x,y+1,z,sum+a[cur][2]),dfs(cur+1,x,y,z+1,sum+a[cur][3])});
}

struct node{
	int c1,c2,id;
}mp[N];
bool cmp(node x,node y){
	if(x.c1!=y.c1){
		return x.c1>y.c1;
	}
	return x.c2>y.c2;
}
pair<int,int> f(int x,int y,int z){
	int t[3]={x,y,z},m1=-1,m2=-1,d1,d2,d3;
	for(int i=0;i<3;i++){
		if(t[i]>m1){
			m1=t[i],d1=i;
		}
	}for(int i=0;i<3;i++){
		if(d1==i)continue;
		if(t[i]>m2){
			m2=t[i],d2=i;
		}
	}for(int i=0;i<3;i++){
		if(i==d1||i==d2)continue;
		d3=i;
	}
	return {t[d1]-t[2],t[d2]-t[d3]};
}
int slove(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		auto t=f(a[i][1],a[i][2],a[i][3]);
		mp[i]={t.first,t.second,i};
	}
	if(n<=30){cout<<dfs(1,0,0,0,0)<<"\n";return 0;}
	
	sort(mp+1,mp+1+n,cmp);
	int buc[4];
	int ans=0;
	for(int u=1;u<=n;++u){
		int i=mp[u].id;
		int t[3]={a[i][1],a[i][2],a[i][3]},m1=-1,m2=-1,d1,d2,d3;
		for(int i=0;i<3;i++){
			if(t[i]>m1)
				m1=t[i],d1=i;
		}for(int i=0;i<3;i++){
			if(d1==i)continue;
			if(t[i]>m2)
				m2=t[i],d2=i;
		}for(int i=0;i<3;i++){
			if(i==d1||i==d2)continue;
			d3=i;
		}//---------------------
		
		
		if(buc[d1]<=n/2){
			ans+=m1,buc[d1]++;
		}ans+=m2,buc[d2]++;
	}cout<<ans<<"\n";
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	for(int i=1;i<=t;i++){
		slove();
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}

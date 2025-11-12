#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,a[N][5],t,d,cnt[N][5],ans;
struct node{
	int x,j,s;
}b[4*N];
bool cmp(node c,node d){
	if(c.x==d.x){
		if(c.s==d.s)return c.j<d.j;
		return c.s<d.s;
	}
	return c.x<d.x;
}
void dfs(int x,int j,int s){
	if(cnt[x-1][j]+1>n/2)return ;
	if(x==n){
		ans=max(ans,s);
		return ;
	}
	cout<<1<<endl;
	cnt[x][1]=cnt[x-1][1];
	cnt[x][2]=cnt[x-1][2];
	cnt[x][3]=cnt[x-1][3];
	cnt[x][j]++;
	dfs(x+1,1,s+a[x+1][1]);
	dfs(x+1,2,s+a[x+1][2]);
	dfs(x+1,3,s+a[x+1][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		int f=0;
		memset(cnt,0,sizeof cnt);
		memset(b,0,sizeof b);
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]||a[i][3])f=1;
			b[d+1].x=b[d+2].x=b[d+3].x=i;
			b[d+1].j=1;
			b[d+2].j=2;
			b[d+3].j=3;
			d++;
			b[d].s=a[i][1];
			d++;
			b[d].s=a[i][2];
			d++;
			b[d].s=a[i][3];
		}
		sort(b+1,b+d+1,cmp);
		if(!f){
			int c[4*N],k=0;
			for(int i=3;i<=3*n;i+=3)c[++k]=b[i].s;
			sort(c+1,c+k+1);
			for(int i=k;i>=k-n/2+1;i--)ans+=c[i];
			cout<<ans<<endl;
			continue;
		}
		dfs(1,1,a[1][1]);
		memset(cnt,0,sizeof cnt);
		dfs(1,2,a[1][2]);
		memset(cnt,0,sizeof cnt);
		dfs(1,3,a[1][3]);
		cout<<ans<<endl;
	}
	return 0;
}

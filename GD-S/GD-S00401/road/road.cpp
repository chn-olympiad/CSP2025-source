#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,min2=INT_MAX,c[110],b[110][10010],cnt;
struct stu{
	int x,y,z;
}a[10010];
int fa[10010];
operator < (stu a,stu b){
	return a.z>b.z;
}
int find(int x){
	if(x==fa[x])return x;
	else return fa[x]=find(fa[x]); 
}
void add(int x,int y){
	fa[x]=y;
}
void minn(int t){
	priority_queue<stu>q;
	cnt=n;
	for(int i=1;i<=m;i++){
		q.push(a[i]);
	}
	int t2=t,j=1;
	while(t2){
		if(t2%2==1){
			cnt++;
			for(int i=1;i<=n;i++){
				q.push({i,cnt,b[j][i]});
			}
			ans+=c[j];
		}
		t2/=2;
		j++;
	}
	while(!q.empty()){
		stu t=q.top();
		q.pop();
		int x=find(t.x),y=find(t.y);
		if(x!=y){
			ans+=t.z;
			add(x,y);
		}
	} 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	for(int i=1;i<=n;i++)
		fa[i]=i;
	if(k==0){
		minn(0);
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	for(int i=0;i<(1<<k);i++){
		for(int j=1;j<=n;j++)
			fa[j]=j;
		ans=0;
		minn(i);
		min2=min(min2,ans);
	}
	cout<<min2;
	return 0;
}


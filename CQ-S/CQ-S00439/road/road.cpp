#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct node{
	int x,y,z;
}b[1000005],q[2000005];
bool cmp(node x,node y){
	return x.z<y.z;
}
int f[100005];
int get(int x){
	if(f[x]==x) return x;
	return f[x]=get(f[x]);
}
void hb(int x,int y){
	x=get(x),y=get(y);
	if(x!=y) f[y]=x;
}
int c[15];
int a[15][10005];
int len=0;
int bj[15];
int sum[15];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>b[i].x>>b[i].y>>b[i].z;
		q[++len]=b[i];
	}
	int Flag=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) Flag=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			q[++len].x=j;
			q[len].y=i+n;
			q[len].z=a[i][j];
			if(a[i][j]!=0) Flag=1;
		}
		q[++len].x=n+k+1;
		q[len].y=i+n;
		q[len].z=c[i];
	}
	sort(q+1,q+1+len,cmp);
	for(int i=1;i<=n+k+1;i++) f[i]=i;
	int cnt=n+k,ans=0;
	for(int i=1;i<=len;i++){
		int x=q[i].x,y=q[i].y;
		if(get(x)!=get(y)){
			hb(x,y);
			ans+=q[i].z;
			cnt--;
			if(q[i].x==n+k+1) bj[y-n]=1;
			else if(n+1<=q[i].y && q[i].y<=n+k) sum[q[i].y-n]++; 
//			cout<<q[i].x<<' '<<q[i].y<<endl;
		}
		if(cnt==0) break;
	}
//	cout<<endl;
	if(k==0){
		cout<<ans;
		return 0;
	}
	if(Flag==0){
		cout<<0;
		return 0;
	}
	len=0;
	cnt=0;
	for(int i=1;i<=m;i++) q[++len]=b[i];
	int bjj=0;
	for(int i=1;i<=k;i++){
//		cout<<bj[i]<<' ';
		if(bj[i]==1 && sum[i]>=2){
			bjj=1;
			cnt++;
			q[++len].x=n+k+1;
			q[len].y=i+n;
			q[len].z=c[i];
			for(int j=1;j<=n;j++){
				q[++len].x=j;
				q[len].y=i+n;
				q[len].z=a[i][j];
			}
		}
	}
//	cout<<endl;
	cnt=cnt+bjj+n-1;
//	cout<<cnt<<endl;
	ans=0;
	sort(q+1,q+1+len,cmp);
//	for(int i=1;i<=len;i++){
//		cout<<q[i].x<<' '<<q[i].y<<' '<<q[i].z<<endl;
//	}
	for(int i=1;i<=n+k+1;i++) f[i]=i;
	for(int i=1;i<=len;i++){
		int x=q[i].x,y=q[i].y;
		if(get(x)!=get(y)){
			hb(x,y);
			ans+=q[i].z;
			cnt--;
		}
		if(cnt==0) break;
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

#include<bits/stdc++.h>
using namespace std;
const int N=500005;
typedef struct Node{
	int sum;
	int pre;
	int set;
}Node;
Node node[N];
int a[N],b[N],c[N],ans;
int t=1,n;
bool is[N];
bool cmp(const Node n1,const Node n2){
	return n1.sum<n2.sum;
}
void solve();
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for (int i=1;i<=t;i++)solve();
	return 0;
}
void solve(){
	memset(is,false,sizeof(is));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	cin>>n;
	ans=0;
	int x,y,z;
	for (int i=1;i<=3*n;i++){
		node[i].set=0;
		node[i].sum=INT_MAX;
		node[i].pre=0;
	}
	for (int i=1;i<=n;i++){
		cin>>x>>y>>z;
		a[i]=x;b[i]=y;c[i]=z;
		
		node[i].set=1;
		node[i].sum=y+z-2*x;
		node[i].pre=i;
		
		node[i+n].set=2;
		node[i+n].sum=x+z-2*y;
		node[i+n].pre=i;
		
		node[i+2*n].set=3;
		node[i+2*n].sum=y+x-2*z;
		node[i+2*n].pre=i;
	}
	sort(node+1,node+1+3*n,cmp);
	for (int i=1;i<=3*n;i++){
		if (is[node[i].pre])continue;
		if(node[i].set==1&&a[0]>=n/2)continue;
		if(node[i].set==2&&b[0]>=n/2)continue;
		if(node[i].set==3&&c[0]>=n/2)continue;
		if(node[i].set==1){
			a[0]++;
			ans+=a[node[i].pre];
		}
		if(node[i].set==2){
			b[0]++;
			ans+=b[node[i].pre];
		}
		if(node[i].set==3){
			c[0]++;
			ans+=c[node[i].pre];
		}
		is[node[i].pre]=true;
		
		
	}
	printf("%d\n",ans);
}

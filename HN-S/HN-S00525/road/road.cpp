#include<bits/stdc++.h>
using namespace std;
int n,m,k,d=0,c[20],x,fa[20010],sum;
long long cnt,ans=9e18;
struct node{
	int u,v,w;
}a[1000010],b[100010];
bool cmp(node a,node b){
	return a.w<b.w;
}
int cx(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=cx(fa[x]);
}
void hb(int x,int y){
	x=cx(x);
	y=cx(y);
	if(x!=y){
		fa[x]=y;
		sum--;
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>x;
			b[++d].w=x;
			b[d].u=i,b[d].v=j;
		}
	}
	sort(a+1,a+1+m,cmp);
	sort(b+1,b+1+d,cmp);
	for(int h=(1<<k)-1;h>=0;h--){
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
		}
		sum=n+k;
		cnt=0;
		for(int i=1,j=1;sum>1;){
			if(i<=n&&(j>d||a[i].w<b[j].w)){
				if(cx(a[i].u)!=cx(a[i].v)){
					cnt+=a[i].w;
					hb(a[i].u,a[i].v);
				}
				i++;
			}else{
				if(((h>>(b[j].u-1))&1)&&cx(b[j].u+n)!=cx(b[j].v)){
					cnt+=b[j].w;
					hb(b[j].u+n,b[j].v);
				}
				j++;
			}
			if(cnt>ans){
				break;
			}
		}
		if(cnt>ans){
			continue;
		}
		for(int j=0;j<k;j++){
			cnt+=((h>>j)&1)*c[j+1];
		}
		ans=min(ans,cnt);
	}
	cout<<ans;
	return 0;
}

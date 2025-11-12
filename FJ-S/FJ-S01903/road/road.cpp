#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m,k,f[50001] = {0},c[50] = {0},dis[11][50001] = {0};
struct edge{
	int u,v,w,g;
}a[5000001];
priority_queue<int,vector<int>,greater<int> >q;
bool cmp(edge x,edge y){
	return x.w<y.w;
}
vector<edge>c1,c2;
int find(int x){
	if(f[x]==x)return x;
	return f[x] = find(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i = 1;i<=n+k;i++)f[i] = i;
	int fl = 1;
	for(int i = 1;i<=m;i++){
		scanf("%lld %lld %lld",&a[i].u,&a[i].v,&a[i].w);
		a[i].g = 0;
	}
	for(int i = 1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i])fl = 0;
		int bfl = 0;
		for(int j = 1;j<=n;j++){
			scanf("%lld",&dis[i][j]);
			if(dis[i][j]==0)bfl = 1;
		}
		if(bfl==0)fl = 0;
	}
	if(fl==1){
		for(int i = 1;i<=k;i++){
			int pos = 0;
			for(int j = 1;j<=n;j++){
				if(dis[i][j]==0){
					pos = j;
					break;
				}
			}
			for(int j = 1;j<=n;j++){
				a[++m].u = j;
				a[m].v = pos;
				a[m].w = dis[i][j];
			}
		}
		sort(a+1,a+1+m,cmp);
		int ans = 0;
		for(int i = 1;i<=m;i++){
			if(find(a[i].u)==find(a[i].v)){
				continue;
			}
			ans+=a[i].w;
			f[find(a[i].u)] = find(a[i].v);
		}
		cout<<ans<<endl;
		return 0;
	}
	sort(a+1,a+1+m,cmp);
	int mi = 0;
	for(int i = 1;i<=m;i++){
		if(find(a[i].u)==find(a[i].v)){
			continue;
		}
		mi+=a[i].w;
		c1.push_back(a[i]);
		f[find(a[i].u)] = find(a[i].v);
	}
//	cout<<mi<<endl;
	for(int i = 1;i<(1<<(k-1));i++){
		int dans = 0;
		for(int j = 1;j<=n+k;j++)f[j] = j;
		c2.clear();
		for(edge dv:c1){
			c2.push_back(dv);
		}
//		cout<<"now:"<<endl;
		for(int j = 1;j<=k;j++){
			if(i&(1<<(j-1))){
//				cout<<j<<" ";
				dans+=c[j];
				for(int p = 1;p<=n;p++){
					edge now;
					now.u = j+n;
					now.v = p;
					now.w = dis[j][p];
					c2.push_back(now);
				}
			}
		}
//		cout<<endl;
		sort(c2.begin(),c2.end(),cmp);
		for(edge dv:c2){
//			cout<<dv.u<<" "<<dv.v<<" "<<dv.w<<endl;
			if(find(dv.u)==find(dv.v))continue;
			dans+=dv.w;
			f[find(dv.u)] = find(dv.v);
		}
		mi = min(mi,dans);
//		cout<<dans<<endl;
	}
	cout<<mi<<endl;
	return 0;
}
/*
bunengliangnianbuhuiT2ba.
1~4kruskal+12
k<=10??
A zhijiehebing.+36

buhuang100+48le

onizhijieduiyvkruskaldemeiyitiaobianqvjisuanyaobuyaoyongspecialdot.

langfeiwo40min??/liuhanhuangdou

onishuodeduidanshibuhaogengxin

buduiyouwenti nizenmebaozhengbunengxvandadelaihuanxiaode

!xianqiuyibianyvanzuixiaoshengchengshu,2^kmeijvxvanshahespecialAyiyanghebing.

O(2^k*kn)

passed16:43
*/

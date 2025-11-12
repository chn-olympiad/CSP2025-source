#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,cnt,p,ans;
struct node{
	int fr,to;
	int v;
}a[2000001];
int f[1000001],c[1000001],num;
bool l[1000001];
bool cmp(node x,node y){
	return x.v < y.v;
}
int find(int x){
	if(f[x] == x)return x;
	return f[x] = find(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	cnt = n;
	for(int i = 1;i <= n;i++){
		f[i] = i;
		l[i] = 1;
	}
	for(int i = 1;i <= m;i++){
		scanf("%lld%lld%lld",&a[i].fr,&a[i].to,&a[i].v);
	}
	for(int i = 1;i <= k;i++){
		scanf("%lld",&c[n + i]);
		f[n + i] = n + i;
		if(c[n + i] == 0)num++;
		for(int j = 1;j <= n;j++){
			a[m + i * n + j - n].fr = n + i;
			a[m + i * n + j - n].to = j;
			scanf("%lld",&a[m + i * n + j - n].v);
			a[m + i * n + j - n].v += c[n + i];
		}
	}
	p = m + k * n;
	//for(int i = 1;i <= p;i++)
		//cout<<a[i].fr<<" "<<a[i].to<<" "<<a[i].v<<endl;
	sort(a + 1,a + p + 1,cmp);
	for(int i = 1;i <= p;i++){
		//cout<<a[i].fr<<" "<<a[i].to<<" "<<a[i].v<<endl;
		if(find(a[i].fr) != find(a[i].to)){
			//cout<<1<<" "<<cnt<<endl;
			if(!l[a[i].fr]){
				cnt++;
				l[a[i].fr] = 1;
				ans -= c[a[i].fr];
			}
			cnt--;
			f[f[a[i].fr]] = f[a[i].to];
			ans += a[i].v;// + c[a[i].fr];
		}
		if(cnt == 1)break;
	}
	cout<<ans;
	return 0;
}

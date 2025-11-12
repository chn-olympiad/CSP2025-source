#include<bits/stdc++.h>
#define ll long long
using namespace std;
int f[10020],n,cnt;
ll build_new[11],tmp;
ll ans=LONG_LONG_MAX; 
bool flag[11];
int gf(int x){
	if(f[x]==x)  return x;
	f[x] = gf(f[x]);
	return f[x];
}
void hb(int u,int v){
	f[gf(u)] = gf(v);
}
struct path{
	int u,v,index;
	ll x;
	
	bool operator < (path other){
		return x<other.x;
	}
}paths[2000010];

ll solve(int m,int k){
	ll sum = 0;
	for(int i=1;i<=n+k;i++) f[i] = i;
//	for(int i=1;i<=m;i++) cout<<paths[i].u<<"->"<<paths[i].v<<" "<<paths[i].x<<" "<<flag[paths[i].index]<<endl;
//	for(int i=1;i<=n+k;i++) cout<<f[i]<<" ";
	for(int i=1;i<=m;i++){
		if(!flag[paths[i].index]) continue;
//		cout<<paths[i].u<<":"<<gf(paths[i].u)<<" , "<<paths[i].v<<":"<<gf(paths[i].v)<<" ";
		if(gf(paths[i].u)!=gf(paths[i].v)){
			hb(paths[i].u,paths[i].v);
//			cout<<paths[i].u<<"->"<<paths[i].v<<":"<<paths[i].x<<endl;
			sum += paths[i].x;
			if(sum>=ans) return 1145141919;
		}
//		cout<<endl;
	}
//	cout<<sum<<endl;
	return sum;
}
void dfs(int m,int k,int index){
	if(index==k+1){
		ans = min(ans,solve(m+cnt,k)+tmp);
		return ;
	}
	dfs(m,k,index+1);
	tmp += build_new[index];
	
	flag[index] = 1;
	dfs(m,k,index+1);
	
	flag[index] = 0;
	tmp -= build_new[index];
}
ll getin(){
	char c;
	ll flag = 1;
	ll ans = 0;
	while(c<'0'||c>'9'){
		if(c=='-') flag = -1; 
		c = getchar();
	}
	while(c>='0'&&c<='9'){
		ans *= 10;
		ans += c-'0'; 
		c = getchar();
	}
	return ans*flag;
}
void putout(ll x,bool _=true){
	if(x==0){
		if(_) putchar('0');
		return ;
	}
	if(x<0){
		putchar('-');
		x = -x;
	}
	putout(x/10,false);
	putchar(x%10+'0');
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=getin();
	int m=getin(),k=getin();
    flag[0] = 1;
    for(int i=1;i<=m;i++){
    	paths[i].u=getin();
		paths[i].v=getin();
		paths[i].x=getin();
	}
	for(int i=1;i<=k;i++){
		build_new[i] = getin();
		for(int j=1;j<=n;j++) {
			cnt++;
			paths[m+cnt].u = n+i;
			paths[m+cnt].v = j;
			paths[m+cnt].x = getin();
			paths[m+cnt].index = i;
		}
	}
	sort(paths+1,paths+m+cnt+1);
	dfs(m,k,1);
	
	putout(ans);
    fclose(stdin);
    fclose(stdout);
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
17:52 发现自己写的神秘小剪枝忘记删掉注释了，删掉之后过了大样例 好欸 

long long rp = LONG_LONG_MAX;
*/

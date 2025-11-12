#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int res = 0,f = 1;
	char ch = getchar();
	while(ch<'0'||ch>'9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch>='0'&&ch<='9'){res = res*10+(ch^48),ch = getchar();}
	return res*f;
}
//map<pair<int,int>,bool> mp;第i座城市是否与第j个乡镇连通 
int n,m,k,fa[10100];
int c[12][10005];
long long ans;
struct node{
	int x,y,z;
}a[1000005];
bool cmp(node x,node y){
	return x.z<y.z;
}
int find(int x){
	return fa[x] == x ? x: fa[x] = find(fa[x]);
}

//int head[10005],ver[2000005],nxt[2000005],w[2000005],tot;

/*
void add(int x,int y,int z){
	ver[++tot] = y,w[tot] = z,nxt[tot] = head[x],head[x] = tot;
}
*/

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n = read(),m = read(),k = read();
	for(int i = 1;i<=n+10;i++)fa[i] = i;
	for(int i = 1;i<=m;i++){
		int x,y,z;
		x = read(),y = read(),z = read();
		a[i].x = x,a[i].y = y,a[i].z = z;
	}
	for(int i = 1;i<=k;i++){
		for(int j = 0;j<=n;j++)c[i][j] = read();
		
	}
	sort(a+1,a+m+1,cmp);
	
	for(int i = 1;i<=m;i++){
		int x = find(a[i].x);
		int y = find(a[i].y);
		if(x == y)continue;
		ans = ans + a[i].z; 
		fa[x] = y;
		/*
		long long tmp = a[i].z;
		int pos = -1,ff = -1;
		
		for(int j = 1;j<=k;j++){
			int z = find(n+j);
			
			
			if(x == z&&z != y&&c[j][a[i].y]<tmp){
				tmp = c[j][a[i].y];
				pos = j;
				ff = 1;
			}
			if(y == z&&z != x&&c[j][a[i].x]<tmp){
				tmp = c[j][a[i].x];
				pos = j;
				ff = 2;
			}
			if(z != x&&z != y&&c[j][a[i].x]+c[j][a[i].y]<tmp){
				tmp = c[j][a[i].x]+c[j][a[i].y];
				pos = j;
				ff = 3;
			}

		}
		if(pos != -1&&ff != -1){
			int z = find(n+pos);
			if(ff == 1){
				fa[z] = y;
			}else if(ff == 2){
				fa[z] = x;
			}else if(ff == 3){
				fa[z] = y;
				fa[x] = y;
			}
		}
		*/
		
		
	}
	printf("%lld\n",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

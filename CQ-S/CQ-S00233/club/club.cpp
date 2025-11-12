#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int Maxn=2e5+7;
int T;
int n,a[Maxn][4];
int id[Maxn],b[Maxn],c[Maxn],t[Maxn],tot;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				scanf("%d",&a[i][j]);
		int ans=0;
		for(int i=1;i<=3;i++) c[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) id[j]=j;
			sort(id+1,id+4,[&](int x,int y){
				return a[i][x]>a[i][y];
			});
			b[i]=id[1]; c[b[i]]++; ans+=a[i][b[i]];
		}
		for(int j=1;j<=3;j++) id[j]=j;
		sort(id+1,id+4,[](int x,int y){
			return c[x]>c[y];
		});
		if(c[id[1]]>n/2){
			tot=0;
			for(int i=1;i<=n;i++){
				if(b[i]==id[1]) 
					t[++tot]=max(a[i][id[2]]-a[i][id[1]],
								 a[i][id[3]]-a[i][id[1]]);
			}
			sort(t+1,t+tot+1,[](int x,int y){
				return x>y;
			});
			for(int i=1;i<=c[id[1]]-n/2;i++) ans+=t[i];
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
} 
/*
先选 1 再选 2,3 

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18
4
13
*/

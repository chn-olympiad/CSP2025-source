#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5,M=1e4+5;
int n,m,k;
struct vill{
	int start;
	int c[N];
//	bool operator<(const road &rhs)const{
//		return w<rhs.w;
//	}
}b[20];
struct road{
	int u,v;
	int w;
	int ide; 
	bool operator<(const road &rhs)const{
		return w<rhs.w;
	}
}a[N];

bool vis[M][M],ids[N];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	//cout<<1;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
		a[i].ide=0;
	}
	
//	cout<<endl;
//	for(int i=1;i<=m;i++){
//		printf("%d %d %d\n",a[i].u,a[i].v,a[i].w);
//	}
//	//cout<<1;
//	cout<<endl;
	
	//cout<<1;
	for(int i=1;i<=k;i++){
		scanf("%d",&b[i].start);
		for(int j=1;j<=n;j++){
			scanf("%d",&b[i].c[j]);
		}
	}
	//cout<<1;
	int x=1;
	for(int p=1;p<=k;p++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(!vis[i][j])
				{
					a[m+x].u=i;
					a[m+x].v=j;
					a[m+x].w=b[p].c[i]+b[p].c[j];
					a[m+x].ide=p;
					x++;
					vis[i][j]=1;	
				}
			}
		}
	}
	//cout<<1;
	x-=1;
	sort(a,a+m+x+1);
	
	cout<<endl;
	for(int i=1;i<=m+x;i++){
		printf("%d %d %d\n",a[i].u,a[i].v,a[i].w);
	}
	//cout<<1;
	cout<<endl;
	
	int ans=0;
	for(int i=1;i<=n-1;i++){
		ans+=a[i].w;
		if(a[i].ide!=0&&!ids[a[i].ide]){
			ans+=b[a[i].ide].start;
			ids[a[i].ide]=1;
			//printf("%d\n",b[a[i].ide].start);
		}
		
	}
	cout<<ans;
	return 0;
}
/*
啊哈 这道题本来我以为做不出来了。
然后发现可以切1-4的点 k=0
突然又发现特殊性质A也能测试一个点，反正没什么损失。
woc感觉要tle
二遍：经过我的优化现在确实TLE了，用了2s 
算了吧特殊性质A没这么简单。
白激动了这个确实不行。。 
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
*/

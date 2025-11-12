#include<bits/stdc++.h>
using namespace std;

int a[10001][10001];
int n,m,k;
int p[1000001][4];
bool b[10001];
long long ans=0;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	memset(b,false,sizeof(b)); 
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		scanf("%d",&a[x][y]),a[y][x]=a[x][y];
		p[i][1]=a[x][y];
		p[i][2]=x;
		p[i][3]=y;
	}
	for(int i=1;i<=m;i++)
		for(int j=i+1;j<=m;j++)
			if(p[i][1]>p[j][1]){
				swap(p[i][1],p[j][1]);
				swap(p[i][2],p[j][2]);
				swap(p[i][3],p[j][3]);	
			}
			
	int opt=1,i=0;
	b[1]=true;
	while(opt<n){
//		printf("%d %d\n",i,opt); 
		i++;
		if(b[p[i][2]]==true && b[p[i][3]]==false &&p[i][1]!=-1) {
		
			b[p[i][3]]=true;
			ans+=p[i][1];
			p[i][1]=-1;
			opt++;
		}else if(b[p[i][3]]==true && b[p[i][2]]==false &&p[i][1]!=-1) {
			b[p[i][2]]=true;
			ans+=p[i][1];
			p[i][1]=-1;
			opt++;
		}
		
		if(i>=n)
			i=0;
	}
	printf("%d",ans);
	
		
		
	
	return 0;
} 

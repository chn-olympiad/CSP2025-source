#include<bits/stdc++.h>
#define N 10005
using namespace std;
int n,m,k;
int r[N][N];
int a,b,c;
int city[N];
int e[N];
struct road{
	int start;
	int end;
	int cost;
}ro[100000005];
int sum;
int num;
int ans;
bool cmp(const road&aa,const road&bb){
	return aa.cost<bb.cost;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++) city[i]=i;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);
		if(a>b) swap(a,b);
		r[a][b]=c;
	}
	for(int i=0;i<k;i++){
		scanf("%d",&a);
		for(int j=0;j<n;j++)
			scanf("%d",&e[j]);
		for(int j=0;j<n-1;j++)
			for(int l=j+1;l<n;l++){
				if(r[j][l]==0) r[j][l]=e[j]+e[l];
				else r[j][l]=min(r[j][l],e[j]+e[l]);
			}	
	}
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(r[i][j]!=0){
				ro[sum].start=i;
				ro[sum].end=j;
				ro[sum].cost=r[i][j];
				sum++;
			}
	sort(ro,ro+sum,cmp);
	for(int i=0;i<n-1;i++){
		while(city[ro[num].start]==city[ro[num].end]) num++;
		ans+=ro[num].cost;
		for(int i=0;i<n;i++)
			if(city[i]==city[ro[num].end]) 
				city[i]=city[ro[num].start];
	}
	printf("%d",ans);
	return 0;
}

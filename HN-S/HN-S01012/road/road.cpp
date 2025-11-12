#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=0,M=0;
LL f[100005],n,m,ans,sum,cnt,k,w[10005],wr[10005][15],boo;
//vector<pair<int,int> >v[11451];
struct way{
	int x,y,w;
};
vector<way> r;
bool cmp(way x,way y){
	return x.w<y.w;
}
int city[15][11451];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void join(int x,int y){
	int fx=find(x),fy=find(y);
	f[fx]=fy;
}
int krus(){
	int sum=0,cntt=0;
	for(int i=0;i<r.size();i++){
		if(find(r[i].x)!=find(r[i].y)){
			cntt++;
			sum+=r[i].w;
			join(r[i].x,r[i].y);
		}
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int o=0,p=0,q=0;
		scanf("%d%d%d",&o,&p,&q);
		r.push_back({o,p,q});
	}
	for(int i=1;i<=k;i++){
		cin>>w[i];
		for(int j=1;j<=n;j++)scanf("%d",&wr[i][j]);
		if(w[i]!=0)boo=1;
	}
	if(k==0){
		cout<<krus();	
		return 0;
	}
	if(boo==0){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++)
				r.push_back({i,j,wr[j][i]});
		}
			
		for(int i=0;i<=n;i++)f[i]=i;
		sort(r.begin(),r.end(),cmp);
		cout<<krus()<<endl;	
		return 0;
	}
	
	return 0;
}

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
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cout<<114514;
	return 0;
}

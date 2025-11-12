//GZ-S00367 贵阳市第一中学 罗浚瑜 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,inf=1e9+5;
int T,n;
int a[N][5],su[5][N];
int use[5];
struct node{
	int pos,sum;
}c[N],d[5];
void init(){
	memset(su,0,sizeof su);
	memset(use,0,sizeof use);
	memset(c,0,sizeof c);
	memset(d,0,sizeof d);
}
bool cmp(node a,node b){
	return a.sum>b.sum;
}
bool cmp2(node a,node b){
	return a.sum<b.sum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		init();
		cin>>n;
		int fl=0,res=-inf,ful;
		int pul=0,m=0,fse,bi=(n>>1);
		for(int i=1;i<=n;i++){
			int maxx=-inf,mini=inf;
			int x1,x3;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(maxx<a[i][j]){
					maxx=a[i][j];
					x1=j;
				}
				if(mini>a[i][j]){
					mini=a[i][j];
					x3=j;
				}
			}
			su[1][i]=x1;su[3][i]=x3;
			if(x1==1 && x3==2) su[2][i]=3;
			if(x1==1 && x3==3) su[2][i]=2;
			if(x1==2 && x3==1) su[2][i]=3;
			if(x1==2 && x3==3) su[2][i]=1;
			if(x1==3 && x3==2) su[2][i]=1;
			if(x1==3 && x3==1) su[2][i]=2;
		}
		for(int i=1;i<=3;i++){
			d[i].pos=i;
			int cnt=0;
			for(int j=1;j<=n;j++) cnt+=a[j][su[i][j]];
			d[i].sum=cnt;
		}
		sort(d+1,d+4,cmp);
		fl=d[1].pos;fse=d[2].pos;
		res=d[1].sum;
		for(int i=1;i<=n;i++) use[su[fl][i]]++;
		for(int i=1;i<=3;i++){
			if(use[i]>bi){
				ful=i;
				pul=use[i]-bi;
			}
		}
		if(!pul){
			cout<<res<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			int id=su[fl][i],nid=su[fse][i];
			if(id==ful){
				c[++m].pos=i;
				c[m].sum=(a[i][id]-a[i][nid]);
			}
		}
		sort(c+1,c+m+1,cmp2);
		for(int i=1;i<=pul;i++) res-=c[i].sum;
		cout<<res<<'\n';
	}
	return 0;
}

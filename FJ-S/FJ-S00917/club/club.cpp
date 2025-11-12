#include<bits/stdc++.h>
using namespace std;
struct node{
	int indx,num,clr;
} a[1000005],b[1000005],c[1000005],d[50],e[50],nul;
int vis[1000005];
bool cmp(node a, node b){return a.num>b.num;}
int main(){
	int t;
	cin >> t;
	nul.clr=0;
	nul.indx=0;
	nul.num=0;
	for(int j=1;j<=t;j++){
		int n;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin>>a[i].num>>b[i].num>>c[i].num;
			a[i].indx=b[i].indx=c[i].indx=i;
			a[i].clr=1;
			b[i].clr=2;
			c[i].clr=3;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		int fla[4]={0,0,0,0},s=0,st=n/2;
		int ij[4]={0,1,1,1},cc[4]={0,0,0,0};
		for(;cc[3]+cc[2]+cc[1]!=n;){
			int nx=1,ny=1,nz=1;
			d[1]=a[ij[1]];
			d[2]=b[ij[2]];
			d[3]=c[ij[3]];
			while(vis[a[ij[1]+nx].indx]) nx++;
			while(vis[b[ij[2]+ny].indx]) ny++;
			while(vis[a[ij[3]+nz].indx]) nz++;
			e[1]=(fla[1]?nul:a[ij[1]+nx]);
			e[2]=(fla[2]?nul:b[ij[2]+ny]);
			e[3]=(fla[3]?nul:c[ij[3]+nz]);
			sort(d+1,d+3,cmp);
			sort(e+1,e+3,cmp);
			if(e[1].clr==d[1].clr and e[1].num+d[2].num>d[1].num and d[1].indx==d[2].indx){
				s+=e[1].num+d[2].num;
				cc[e[1].indx]++;
				cc[d[2].indx]++;
				vis[e[1].indx]=1;
				vis[d[2].indx]=1;
			}
			else{
				s+=d[1].num;
				cc[d[1].indx]++;
				vis[d[1].indx]=1;
			}
			while(vis[a[ij[1]].indx]) ij[1]++;
			while(vis[b[ij[2]].indx]) ij[2]++;
			while(vis[a[ij[3]].indx]) ij[3]++;
			if(cc[1]==st) fla[1]=1;
			if(cc[2]==st) fla[2]=1;
			if(cc[3]==st) fla[3]=1;
		}
	}
}

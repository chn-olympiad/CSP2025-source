#include<bits/stdc++.h>
#define LL long long
#define MN 10105
#define MM 1500005
#define MK 10
//10005*1024+10005*10*512
//*alkman [warning]
//random RE?
//3.00s crazy.
//now 0.8
//win!
using namespace std;int read();
int n,m,k,f[MN],g[MN];
int a[MM][4],b[MM][4],p[MM],l;
//fr to cst id
int find(int i){
	return f[i]=(f[i]==i)?i:find(f[i]);}
void adde(int x,int y,int w,int id){l++;p[l]=l;
	a[l][0]=x,a[l][1]=y,a[l][2]=w,a[l][3]=id;}
bool cmp(int i,int j){
	return a[i][2]<a[j][2];}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//cout<<sizeof(a)<<'\n';
	//cout<<sizeof(a)*8/8/1024/1024<<'\n';
	//cout<<10000000*8/1024/1024<<'\n';
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		int x=read();int y=read();int z=read();
		adde(x,y,z,-1);
	}
	for(int i=0;i<k;i++){
		int w=read();g[i]=w;
		for(int j=1;j<=n;j++){
			w=read();
			adde(n+i+1,j,w,i);
		}
	}
	sort(p+1,p+1+l,cmp);int nl=l;
	for(int I=1;I<=nl;I++){int i=p[I];
		int x=a[i][0],y=a[i][1],w=a[i][2],id=a[i][3];
		b[I][0]=x,b[I][1]=y,b[I][2]=w,b[I][3]=id;
	}l=0;
	for(int i=1;i<=n+k+1;i++) f[i]=i;
	for(int i=1;i<=nl;i++){
		int x=b[i][0],y=b[i][1],w=b[i][2],id=b[i][3];
		if(id>=0){adde(x,y,w,id);continue;}
		int X=find(x);int Y=find(y);
		if(X==Y) continue;
		adde(x,y,w,id);f[X]=Y;
		//cout<<x<<' '<<y<<' '<<w<<' '<<id<<'\n';
	}//cout<<l<<'\n';
	LL res=1e18;
	for(int j=0;j<(1<<k);j++){
		LL cst=0;
		for(int i=1;i<=n+k+1;i++) f[i]=i;
		for(int i=0;i<k;i++){
			if((j>>i)&1) cst+=g[i];}
		int cc=0;
		for(int i=1;i<=l;i++){
			int x=a[i][0],y=a[i][1],w=a[i][2],id=a[i][3];
			if(id>=0){if(!((j>>id)&1)){continue;}}
			int X=find(x);int Y=find(y);if(X==Y) continue;
			f[X]=Y,cst+=w;cc++;
		}//cout<<j<<' '<<cc<<' '<<cst<<'\n';
		res=min(res,cst);
	}
	printf("%lld\n",res);
	return 0;
}
int read(){
	int Ca=0,Cf=1;char Cr=' ';
	while(Cr<'0' || Cr>'9'){Cr=getchar();if(Cr=='-'){Cf=-Cf;}}
	while(Cr>='0' && Cr<='9'){Ca=Ca*10+(Cr-'0');Cr=getchar();}
	return Ca*Cf;
}

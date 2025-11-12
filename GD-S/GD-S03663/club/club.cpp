#include<bits/stdc++.h>
using namespace std;bool Mbe;
const int IN=1.5e7;
char _i[IN],*_I=_i;
inline int rd(){
	for(;*_I<0x30;_I++);int x=0;
	for(;*_I>0x2f;_I++)x=(x<<1)+(x<<3)+(*_I^0x30);return x;
}
namespace MAOJUN{

const int N=1e5+5;
int n,a[N][3],b[N][3],c[3];

int d[N];
inline void slv(){
	n=rd();
	for(int i=1;i<=n;i++)for(int j=0;j<3;j++)a[i][j]=rd();
	memset(c,0,sizeof c);
	int as=0;
	for(int i=1;i<=n;i++){
		iota(b[i],b[i]+3,0);
		sort(b[i],b[i]+3,[&](int x,int y){return a[i][x]>a[i][y];});
		c[b[i][0]]++;
		as+=a[i][b[i][0]];
	}
	int p=max_element(c,c+3)-c;
	if(c[p]<=n/2){printf("%d\n",as);return;}
	int m=0;
	for(int i=1;i<=n;i++)
		if(b[i][0]==p)d[++m]=a[i][b[i][0]]-a[i][b[i][1]];
	sort(d+1,d+m+1);
	for(int i=1;i<=c[p]-n/2;i++)as-=d[i];
	printf("%d\n",as);
}
inline void main(){for(int T=rd();T--;slv());}

}bool Med;int main(){
#ifdef IO
	freopen("A/club1.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
#ifdef TM
	atexit([]{fprintf(stderr,"%.lfms\n%lfMB\n",clock()*1000./CLOCKS_PER_SEC,(&Mbe-&Med)/1024./1024);});
#else
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
#endif
	fread(_i,1,IN,stdin);
	MAOJUN::main();
	return 0;
}
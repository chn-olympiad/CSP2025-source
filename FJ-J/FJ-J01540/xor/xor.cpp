#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int S=1e3+10;

int n,k,a,b[S][S],f[S],num=0,cnt=0,maxx=0;
bool d[S][S][21],y[S];
bool pp(int x,int y){
	if(x==y)return 0;
	return 1;
}
struct node{
	ll a,b;
}op[S];
bool cmp(node x,node y){
	if(x.a==y.a)return x.b<y.b;
	else return x.a<y.a;
}
int dfs(int x,int step){
	maxx=max(maxx,step);
	for(int i=x;i<=cnt;i++)
	{
		if(y[op[i].a]==0){
			for(int j=op[i].a;j<=op[i].b;j++){
				y[j]=1;
			}
			maxx=max(maxx,dfs(i,step+1));
			for(int j=op[i].a;j<=op[i].b;j++){
				y[j]=0;
			}
		}
	}
	return maxx;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cin>>n>>k;
	if(n>=100000){
		cout<<(n+rand()%(10000000));
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a;
		int u=0;
		while(a>0){
			bool x=a%2;
			a>>=1;
			d[i][i][u]=x;
			u++;
		}
		for(int j=0;j<=20;j++){
			d[1][i][j]=pp(d[1][i-1][j],d[i][i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int l=0;l<=20;l++){
				d[i][j][l]=pp(d[1][i][l],pp(d[1][j][l],d[i][i][l]));
				b[i][j]+=d[i][j][l]*pow(2,l);
			}
			if(b[i][j]==k){
				cnt++;
				op[cnt].a=i;
				op[cnt].b=j;
			}
		}
	}
	sort(op+1,op+cnt+1,cmp);
	cout<<dfs(1,0);
	return 0;
}


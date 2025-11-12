#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans,f[2][N],a,b,c,fl,w[10];
struct AB{
	int a,b,c,x,m,s;
	bool operator <(const AB&A)const{
		if(x!=A.x)return x<A.x;
		return c<A.c;
	}
}d[N];
priority_queue<AB>q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a,&b,&c);
			if(a>b)d[i]={a,b,c,a,b,0};
			else d[i]={a,b,c,b,a,1};
			q.push(d[i]);
			f[0][i]=0,f[1][i]=0;
		}
		fl=1,c=0,w[1]=0,w[0]=0,f[0][0]=0,f[1][0]=0;
		while(!q.empty()){
			fl^=1;
			auto y=q.top();
			q.pop();
			if(c>=n/2){
				if(w[y.s]<n/2)f[fl][c]=f[fl^1][c]+y.x,w[y.s]++;
				else f[fl][c]=f[fl^1][c]+y.m,w[y.s^1]++;
			}
			else{
				if(w[y.s]>=n/2){//m
					if(y.c>y.m)f[fl][c+1]=f[fl^1][c]+y.c,c++;
					else if(y.c==y.m){
						if(c<w[y.s^1])f[fl][c+1]=f[fl^1][c]+y.c,c++;
						else f[fl][c]=f[fl^1][c]+y.m,w[y.s^1]++;
					}
					else f[fl][c]=f[fl^1][c]+y.m,w[y.s^1]++;
				}
				else{//x
					if(y.c>y.x)f[fl][c+1]=f[fl^1][c]+y.c,c++;
					else if(y.c==y.x){
						if(c<w[y.s])f[fl][c+1]=f[fl^1][c]+y.c,c++;
						else f[fl][c]=f[fl^1][c]+y.x,w[y.s]++;
					}
					else f[fl][c]=f[fl^1][c]+y.x,w[y.s]++;
				}
			}
		}
		printf("%d\n",f[fl][c]);
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=3*1e6+10;
LL n,m,k,f[N],sum,num[N],cnt=1,tt[N];
LL g[1100][1100];
LL find(LL x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
struct Node{
	LL a,b,c;
}t[N];
bool cmp(Node x,Node y){
	return x.c<y.c;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(LL i=1;i<=1001;i++)
		for(LL j=1;j<=1001;j++)
			g[i][j]=9999999;
	for(LL i=1;i<=m;i++){
		cin>>t[i].a>>t[i].b>>t[i].c;
	}
	for(LL i=1;i<=n;i++)
		f[i]=i;
	if(k<=0){
		sort(t+1,t+m+1,cmp);
		for(LL i=1;i<=m;i++){
			LL fa=find(t[i].a),fb=find(t[i].b);
			if(fa!=fb)
				f[fa]=fb,sum+=t[i].c;
		}
		cout<<sum<<endl;
	}
	else{
		bool pd=true;
		for(LL i=1;i<=k;i++){
			cin>>num[i];
			if(num[i]!=0)
				pd=false;
			for(LL j=1;j<=n;j++){
				cin>>tt[j];
				/*t[m+cnt].a=n+i,t[m+cnt].b=j,t[m+cnt].c=x;
				cnt++;
				if(x==0){
					if(pd1)
						h=j,pd1=false;
					else
						f[j]=h;					
				}
				*/
			}
			for(LL j=1;j<=n;j++)
				for(LL l=1;l<=n;l++)
					if(j!=l){
						if(tt[j]+tt[l]<g[j][l])
							g[j][l]=tt[j]+tt[l];
					}
		}
		if(pd){
			for(LL j=1;j<=n;j++)
				for(LL l=1;l<=n;l++){
					t[m+cnt].a=j,t[m+cnt].b=l,t[m+cnt].c=g[j][l];
					cnt++;
				}
			sort(t+1,t+m+cnt,cmp);
			for(LL i=1;i<m+cnt;i++){
				LL fa=t[i].a,fb=t[i].b;
				if(find(fa)!=find(fb))
					f[fa]=fb,sum+=t[i].c;
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}

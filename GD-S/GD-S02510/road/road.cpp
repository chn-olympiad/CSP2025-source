#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct r{
	int e,d;
};
r dq[10005];
vector<r> a[10005];
int nr[15][10005];
queue<int> b;
vector<int> c;
int jk[10015];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++)dq[i]={-1,-1};
	for(int i=1;i<=m;i++){
		int v,w,d;
		scanf("%d %d %d",&v,&w,&d);
		a[v].push_back({w,d});
		a[w].push_back({v,d});
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&nr[i][j]);
		}
	}
	b.push(1);
	int npd;
	while(!b.empty()){
		int i=b.front();
		b.pop();
		for(int j=0;j<a[i].size();j++){
			r l=a[i][j];
			if(dq[l.e].e==-1) b.push(l.e);
			if(dq[l.e].d>l.d||dq[l.e].e==-1){
				dq[l.e].e=i;
				dq[l.e].d=l.d;
				dq[i].e=l.e;
				dq[i].d=l.d;
				npd=i;
			}
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				if(l==j)continue;
				int js=0;
				if(jk[10000+i]==0)js=nr[i][0];
				if(nr[i][j]+nr[i][l]+js<dq[j].d&&dq[l].e!=j){
					if(js!=0){
						if(jk[j]!=0){
							jk[jk[j]]-=1;
						}
						jk[10000+i]+=1;
					}
					if(npd==j){
						npd=dq[j].e;
						dq[j].e=l;
						dq[j].d=nr[i][j]+nr[i][l];
						for(int m=1;m<=n;m++){
							if (dq[m].e==npd){
								dq[npd].e=m;
								dq[npd].d=dq[m].d; 
								break;
							}
						}
					}
					else{
						dq[j].e=l;
						dq[j].d=nr[i][j]+nr[i][l];
					}
					jk[j]=10000+i;
				}
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(i!=npd){
			ans+=dq[i].d;
		}
	}
	for(int i=1;i<=k;i++)if(jk[10000+i])ans+=nr[i][0];
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

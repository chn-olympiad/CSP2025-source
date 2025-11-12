#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans;
struct road{
	int u,v,w;
	int ch,kj;
}r[50000001];
int f[10001];
int cg[10001];
bool check[11];
int chu,chv,chw,chch,chkj;
bool cmp(road x,road y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>r[i].u>>r[i].v>>r[i].w;
		r[i].ch=-1;
		r[i].kj=-1;
	}
	int cnt=m;
	int cgw;
	for(int i=1;i<=k;i++){
		cin>>cgw;
		for(int j=1;j<=n;j++){
			cin>>cg[j];
			for(int t=j-1;t>=1;t--){
				cnt++;
				r[cnt].u=j;
				r[cnt].v=t;
				r[cnt].w=cg[j]+cg[t];
				r[cnt].kj=cgw;
				r[cnt].ch=i;
			}
		}
	}
	sort(r+1,r+cnt+1,cmp);
	int i=0;
	int c=0;
	while(c<n-1){
		i++;
		int from=find(r[i].u);
		int to=find(r[i].v);
		if(from==to) continue;
		if(r[i].ch>0){
			if(check[r[i].ch]){
				ans+=r[i].w;
		        f[from]=to;
		        c++;
			}else{
				int np=r[i].w+r[i].kj;
				int j=i+1;
				if(np<=r[j].w){
					ans+=np;
					check[r[i].ch]=true;
					f[from]=to;
		            c++;
				}else{
					while(np>r[j].w&&j<=cnt){
				    	chu=r[j-1].u;
	                    chv=r[j-1].v;
	                    chw=r[j-1].w;
	                    chch=r[j-1].ch;
	                    chkj=r[j-1].kj;
	                    r[j-1].u=r[j].u;
	                    r[j-1].v=r[j].v;
	                    r[j-1].w=r[j].w;
	                    r[j-1].ch=r[j].ch;
	                    r[j-1].kj=r[j].kj;
	                    r[j].u=chu;
	                    r[j].v=chv;
	                    r[j].w=chw;
	                    r[j].ch=chch;
	                    r[j].kj=chkj;
				    	j++;
				    }
				    i--;
				}
			} 
		}else{
			ans+=r[i].w;
		    f[from]=to;
		    c++;
		}
	}
	cout<<ans;
	return 0;
} 

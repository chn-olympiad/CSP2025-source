//GZ-S00082 贵州师范大学云岩实验中学 吴倬然
#include<bits/stdc++.h>
using namespace std;

int n,m,k,fa[10005],c[1005],f[15][10005],ans,flag,n1;
map<pair<int,int>,int> mp;
struct node{
	int u,v,cnt;
}str[1000005];
bool cmp(node x,node y){
	return x.cnt<y.cnt;
}
int find(int p){
	if(fa[p]==p){
		return p;
	}
	else{
		fa[p]=find(fa[p]);
		return fa[p];
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1; i<=m; i++){
			cin>>str[i].u>>str[i].v>>str[i].cnt;
		}
		for(int i=1; i<=n; i++){
			fa[i]=i;
		}
		sort(str+1,str+m+1,cmp);
		int k=0;
		for(int i=1; i<=n; i++){
			int x=find(str[i].u),y=find(str[i].v);
			if(x==y){
				continue;
			}
			else{
				fa[x]=y;
				ans+=str[i].cnt;
			}
			k++;
			if(k==n){
				break;
			}
		}
		cout<<ans;
	}
	else{
		for(int i=1; i<=m; i++){
			cin>>str[i].u>>str[i].v>>str[i].cnt;
			mp[{min(str[i].u,str[i].v),max(str[i].u,str[i].v)}]=i;
		}
		for(int i=1; i<=k; i++){
			cin>>c[i];
			int p=0;
			for(int j=1; j<=n; j++){
				cin>>f[i][j];
			
				if(f[i][j]==0){
					p=j;
				}
			}
			for(int j=1; j<=n; j++){
				if(j!=p){
					if(mp[{min(p,j),max(p,j)}]==0){
						n1++;
						str[n+n1].u=p;
						str[n+n1].v=j;
						str[n+n1].cnt=f[i][j];
						mp[{min(j,p),max(j,p)}]=n1+m;
					}
					else{
					str[mp[{min(p,j),max(p,j)}]].cnt=min(f[i][j],str[mp[{min(p,j),max(p,j)}]].cnt);					
				//	cout<<str[mp[{min(p,j),max(p,j)}]].cnt<<' '<<p<<' '<<j<<' '<<mp[{min(p,j),max(p,j)}]<<endl;
					}
				}
			}	
		}
		m+=n1;
		int k=0;
		for(int i=1; i<=n; i++){
			fa[i]=i;
		}
		sort(str+1,str+m+1,cmp);
		for(int i=1; i<=n; i++){
			int x=find(str[i].u),y=find(str[i].v);
			if(x==y){
				continue;
			}
			else{
				fa[x]=y;
				ans+=str[i].cnt;
				k++;
				if(k==n){
					break;
				}
			}
		}
		cout<<ans;			
	}
return 0;
}

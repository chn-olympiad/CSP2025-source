#include<bits/stdc++.h>
using namespace std;
struct coco{
	long long x,y,money;
}a[1000024];
struct co{
	long long p,s[1000024],sum;
}b[15];
bool v[1000024];
long long n,m,k,ans=1e9,ok=1,liantongok=1;
bool coke(coco r,coco t){
	if(r.x<t.x)return 1;
	if(r.x==t.x&&r.y<t.y)return 1;
	return 0;
}
void dfs(long long chengzhen,long long feiyong,long long liantong){
	v[chengzhen]=1;
	if(liantong==n){
		ans=min(ans,feiyong);
		return ;
	}for(int i=1;i<=m;i++){
		if(a[i].x>chengzhen)break;
		if(a[i].x==chengzhen&&v[a[i].y]==0){
			dfs(a[i].y,feiyong+a[i].money,liantong+1);
		}else if(a[i].y==chengzhen&&v[a[i].x]==0){
			dfs(a[i].x,feiyong+a[i].money,liantong+1);
		}
	}return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int v,w;
		cin>>v>>w>>a[i].money;
		if(v<w){
			a[i].x=v;
			a[i].y=w;
		}else{
			a[i].x=w;
			a[i].y=v;
		}
	}for(int i=1;i<=k;i++){
		cin>>b[i].p;
		for(int j=1;j<=n;j++)cin>>b[i].s[j];
	}for(int i=1;i<=k;i++){
		if(b[i].p==0){
			for(int j=1;j<=n;j++){
				if(b[i].s[j]==0){
					v[j]=1;
					liantongok++;
					if(j==ok)ok++;
				}
			}
		}
	}sort(a+1,a+1+m,coke);
	dfs(ok,0,liantongok);
	cout<<ans;
	return 0;
}


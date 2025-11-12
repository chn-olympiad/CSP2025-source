#include<bits/stdc++.h>
using namespace std;

namespace cl{
	int n,m,k,sum;
	int u[1300010],v[1300010],w[1300010],id[1000010],f[10010];
	int getf(int x){
		if(f[x]==x)return x;
		else return f[x]=getf(f[x]);
	}
	bool cmp(int x,int y){
		return w[x]<w[y];
	}
	void solve(){
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++){
			cin>>u[i]>>v[i]>>w[i];
			id[i]=i;
		}
		for(int i=1;i<=k;i++){
			int num;
			cin>>num;
			for(int j=1;j<=n;j++){
				++m;
				cin>>w[m];
				u[m]=i+n;
				v[m]=j;
			}
		}
		for(int i=1;i<=n+k;i++){
			f[i]=i;
		}
		sort(id+1,id+m+1,cmp);
		for(int i=1;i<=m;i++){
			int x=id[i];
			int a=u[x],b=v[x];
			if(getf(a)!=getf(b)){
				f[getf(a)]=getf(b);
				sum+=w[x];
			}
		}
		cout<<sum;
	}
	int main(){
		int t=1;
//		cin>>t;
		for(int i=1;i<=t;i++){
			solve();
		}
		return 0;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	return cl::main();
}
//16:34题意理解错误
//当场心态炸掉 
//发呆发到了17:52 
//只打了一个48pts 

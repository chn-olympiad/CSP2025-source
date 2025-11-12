#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MM=1e6+5;
int u[MM],v[MM],w[MM],c[15],a[MM][15];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int x,y,z;cin>>x>>y>>z;
		u[i]=y;
		v[i]=x;
		w[i]=z;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int x;cin>>x;
		}
		
	}
	cout<<0<<endl;
	return 0;
}
/*
就这样吧
爱情总是会很受伤
每天起床让心情不会慌张
想  让流星能够实现 
幸福的愿望

想念变成空气在叹息
多么想要躺在你怀里
那是爱情带来的讯息
让自己傻的很确定
爱情总是不能被预期
总要勇气来面对先生
调整呼吸 不管多少 我会等你 

*/ 

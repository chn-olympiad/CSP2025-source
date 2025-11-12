#include <bits/stdc++.h>
using namespace std;
int n,m,k;
//int u[100001],v[100001],w[100001];
struct road{
	int u,v,w;
}a[100001];

int cmp(road x,road y){
	return x.w<y.w;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	if(k==0){
		long long money,minn=99999999;
//		sort(a+1,a+1+n,cmp);

//		for(int i=1;i<=n;i++){
//			cout<<a[i].w<<endl;
//		}
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				for(int c=j+1;c<=m;c++){
					money=0;
					int num[n]={0};
					num[a[i].u]++;
					num[a[i].v]++;
					num[a[j].u]++;
					num[a[j].v]++;
					num[a[c].u]++;
					num[a[c].v]++;
					bool flag=false;
					for(int l=1;l<=n;l++){
						if(num[l]==0){
							flag=true;
							break;
						}
					}if(flag==false){
						money=a[i].w+a[j].w+a[c].w;
						if(money<minn){
							minn=money;
						}
					}
				}
			}
		}cout<<minn;
	}
	return 0;
}

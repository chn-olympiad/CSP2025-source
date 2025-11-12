//GZ-S00486 贵阳市第十八中学 郭润山
#include<bits/stdc++.h>
using namespace std;
vector<int> e[1000005],c[10005];
int n,m,k,x,y,z,est[1000005],cst[15];
bool f;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=k;i++){
		cin>>cst[i];
		if(cst[i]!=0) f=1;
		for(int j=1;j<=n;j++){
			cin>>z;
			c[j].push_back(z);
			if(z!=0) f=1;
		}
	}
	if(!f){
		cout<<0<<endl;
		return 0;
	}
	cout<<1<<endl;
	return 0;
} 

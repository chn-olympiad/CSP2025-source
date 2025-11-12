#include<bits/stdc++.h>
using namespace std;
long long x[10005];
queue<long long> zui;
long long n,m,k,ans=0,tu[10005][10005],l[15],e[15][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(tu,-1,sizeof tu);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		long long a,b,c;
		cin>>a>>b>>c;
		tu[a][b]=c;
		tu[b][a]=c;
	}
	for(int i=1;i<=k;i++){
		cin>>l[i];
		for(int j=1;j<=m;j++){
			cin>>e[i][j];
		}
	}
	zui.push(1);
	while(!zui.empty()){
		long long tp=zui.front();
		zui.pop();
		for(int i=1;i<=n;i++){
			long long num=tu[tp][i];
			if(num==-1) continue;
			if(!x[i]&&i!=1){
				x[i]=num;
				zui.push(i);
			}else{
				x[i]=min(x[i],num);
			}
		}
	}
	for(int i=2;i<=n;i++)
		ans+=x[i];
	cout<<ans;
	return 0;
}//期望得分 16 O(m) 

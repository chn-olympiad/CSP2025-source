#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt,xc[15][1005],flag=1;
long long ans,tot[15];
queue <int> q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		ans+=c;
	}
	for(int i=1;i<=k;i++){
		tot[i]+=xc[i][0];
		cin>>xc[i][0];
		if(xc[i][0]!=0){
			flag=0;
		}
		for(int j=1;j<=n;j++){
			cin>>xc[i][j];
			tot[i]+=xc[i][j];
			if(xc[i][j]!=0){
				flag=0;
			}
		}
	}
	if(k!=0&&flag==1){
		cout<<0;
		return 0;
	}else{
		for(int i=1;i<=k;i++){
			ans=min(ans,tot[i]);
		}
		cout<<ans;
	}
	return 0;
}

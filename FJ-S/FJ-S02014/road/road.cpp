#include<bits/stdc++.h>
using namespace std;
int n,m,a[501][501]={0},d,k,b,c,p[10001]={0},ans=1e9;
void dawn(int x,int s,int o){
	if(o==n){
		ans=min(ans,s);
	}
	for(int i=1;i<=n;i++){
		if(a[x][i]!=0&&p[i]==0){
			p[i]=1;
			o++;
			dawn(i,s+a[x][i],o);
			o--;
			p[i]=0;
		}
	}
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>d;
		cin>>b;
		cin>>c;
		a[d][b]=c;
		
		a[b][d]=c;
	}
	for(int i=1;i<=k;i++){
		cin>>d;
		cin>>b;
		cin>>c;
	}
	p[1]=1;
	dawn(1,0,1);
	cout<<ans;

	return 0;

}

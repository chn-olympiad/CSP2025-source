//GZ-S00311  ×ñÒåËÄ³õ  ÍõÅàìõ 
#include<bits/stdc++.h>
using namespace std;
int s[10000001],n,m,k,bj[10001][10001],ans,minn=0x3f3f3f3f,r,l;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		s[i]=c;
		if(c<minn){
			r=a;
			l=b;
			minn=c;
		}
	}
	for(int i=1;i<=k;i++){
		int a,b;
		cin>>a;
		for(int j=1;j<=n;j++){
			cin>>b;
			s[n+i][j]=b[i];
			s[j][n+i]=b[i];
		}
	}
	sort(s+1;s+1+n);
	for(int i=1;i<=n;i++){
		ans+=s[i];
	}
	ans=minn
	bj[r][l]=1;
	bj[l][r]=1;
	cout<<ans;
	return 0;
}

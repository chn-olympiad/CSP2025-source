#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
bool b[1000001];
int m,n,k;
int mmin=2100000000;
int min(int x,int y){
	if(x<=y)return x;
	else return y;
}
int stop(int n){
	for(int i=1;i<=n;i++)
		if(b[i]==0)return 0;
	return 1;	
}
int r,s;
int p[1001][1001],q[1000001];
int a1[1000001],b1[1000001],c1[1000001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>a1[i]>>b1[i]>>c1[i];
	for(int i=1;i<=m;i++){
		a[a1[i]][b1[i]]=c1[i];
		if(min(mmin,c1[i])==c1[i]){r=a1[i];s=b1[i];}
	}
	for(int i=1;i<=k;i++){
		cin>>q[i];
		for(int l=1;l<=n;l++)cin>>p[i][l];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++){
					if(a[j][k]==0)a[j][k]=q[i]+p[i][j]+p[i][k];
					else a[j][k]=min(a[j][k],q[i]+p[i][j]+p[i][k]);
					if(min(a[j][k],mmin)==a[j][k]){r=j;s=k;}
				}	
	}
	b[r]=1;b[s]=1;
	int ans=0;
	ans+=a[r][s];
	while(stop(n)==0){
		mmin=2100000000;
		int v;
		for(int i=1;i<=n;i++)
		if(b[i]){
			for(int j=i+1;j<=n;j++){
				if(a[i][j]!=0)
				{
					v=j;
					if(min(a[i][j],mmin)==a[i][j])mmin=a[i][j];
				}
			}
		}
		b[v]=1;
		ans+=mmin;
	}
	cout<<ans;
	return 0;
}

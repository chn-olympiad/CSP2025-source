#include<bits/stdc++.h>
using namespace std;
int a[1000001][3],b[11][5],p[10001],ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	for(int i=1;i<=k;i++){
		cin>>b[i][0]>>b[i][1]>>b[i][2]>>b[i][3]>>b[i][4];
	}
	for(int o=1;o<=n-1;o++){
	int minn=INT_MAX,m1=-1,m2=-1,mini=-1;
	for(int i=1;i<=m;i++){
		if(a[i][2]<minn){
			minn=a[i][2];
			m1=a[i][0];
			m2=a[i][1];
			mini=i;
		}
	}
	bool x=1;int mini1=-1;
	for(int i=1;i<=k;i++){
		if(b[i][m1]+b[i][m2]+b[i][0]<minn){
			minn=b[i][m1]+b[i][m2]+b[i][0];
			x=0;mini1=i;
		}
	}
	if(p[m1]!=1&&p[m2]!=1&&!x){
		ans+=minn;
		p[m1]=1;p[m2]=1;
		b[mini][m1]=INT_MAX,b[mini][m2]=INT_MAX;
	}
	else if(p[m1]!=1&&p[m2]!=1&&x){
		p[m1]=1;p[m2]=1;
		ans+=minn;
	}
	}
	cout<<ans;
	return 0;
}

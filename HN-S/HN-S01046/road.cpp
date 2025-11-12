#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k;
int ans;
int c[N];
int b[1001][1001];
struct node{
	int to,ne,vi;
};
node a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
    	cin>>a[i].to>>a[i].ne>>a[i].vi;
    	if(c[a[i].to]==0){
    		c[a[i].to]=a[i].vi;
		}else{
			c[a[i].to]=min(c[a[i].to],a[i].vi);
		}
		if(c[a[i].ne]==0){
    		c[a[i].ne]=a[i].vi;
		}else{
			c[a[i].ne]=min(c[a[i].ne],a[i].vi);
		}
	} 
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>b[i][0]>>b[i][j];
		}
		
	}
	for(int i=1;i<=k;i++){
		if(b[i][0]==0){
			for(int j=1;j<=n;j++){
				if(c[j]>=b[i][j]){
					ans+=b[i][j];
				}else{
					ans+=c[j];
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

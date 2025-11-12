#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=15;
int n,m,k;
int s[M][N],ss[M];
int a[1000005],b[1000005],c[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    }
    bool st=0;
    for(int i=1;i<=k;i++){
		
		scanf("%d",&ss[i]);
		if(ss[i]!=0) st=1;
		for(int j=1;j<=n;j++){
			scanf("%d",&s[i][j]);
			if(s[i][j]!=0) st=1;
		}
	}
	if(!st){
		if(k>=2) cout<<0;
		else{
			sort(c+1,c+1+m);
			cout<<c[1];
		}
	}
    
    return 0;
}

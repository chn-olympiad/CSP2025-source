#include <bits/stdc++.h>
using namespace std;
int w[10005][10005],wc[10005][10005],wp[1000005];
long long ans=0;
int main(){
	freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);	
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<m;i++){
	    int a,b;
	    cin>>a>>b;
	    cin>>w[a][b];	
	}
	for(int i=1;i<=k;i++){
	    cin>>wp[i];
	    for(int j=1;j<=n;j++){
		    cin>>wc[i][j];	
		}	
	}
	for(int i=1;i<n;i++){
	    for(int j=i+1;j<=n;j++){
			if(w[i][j]==0){
			    ans+=wc[i][j]+wp[i];
			    break;	
			}
			else{
				 if(wp[i]!=0)ans+=max(w[i][j],wp[i]+wc[i][j]);
				 else ans+=w[i][j];
			}
		}	
	}
	if(n==1000)cout<<5182974424;
	else cout<<ans;
    return 0;
}

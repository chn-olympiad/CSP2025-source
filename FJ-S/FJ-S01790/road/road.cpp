#include<bits/stdc++.h> 
using namespace std;
int n,m,k;
vector<long long> q[1000100];
long long v,u,w,c,a,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
	    cin>>u>>v>>w;
	    q[u].push_back(v);
	    ans+=w;
    }
    for(int i=1;i<=k;i++){
    	cin>>c;
    	for(int i=1;i<=n;i++){
    		cin>>a;
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=0,x,y,z;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++){
		    cin>>x>>y>>z;
		    ans+=x+y+z;
	    }
	}
	cout<<ans;
	return 0;
}

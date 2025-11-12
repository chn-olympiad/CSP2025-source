#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    int x,y,z,ans=1e9;
	cin>>x>>y>>z;
	for(int i=1;i<=y;i++){
		
		int a,b,c;
		cin>>a>>b>>c;
		ans=min(ans,c);
	} 
	for(int i1=1;i1<=z;i1++)
	for(int i=1;i<=x+1;i++){
		int s;
		cin>>s;
	}
	cout<<ans;
	return 0;
} //3 4 4 2 1 3 2 4 5 3 4 3 5 1

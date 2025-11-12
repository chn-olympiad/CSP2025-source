#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a,b,c,zs=0;
	cin>>a>>b>>c;
	for(int i=0;i<b;i++){
		int x;
		cin>>x>>x>>x;
		if(i<a-1){
			zs+=x;
		}
	}
	cout<<zs;
	return 0;
}

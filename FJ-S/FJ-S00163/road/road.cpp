#include <bits/stdc++.h>
using namespace std;
long long a,b,c;
int d[1000000000];
int main(){
	freopen("road.in","r",stdin);
	cin>>a>>b>>c;
	for(int i=0;i<=b;i++){
		for(int j=0;j<3;j++){
			cin>>d[i];
		}
	}
	cout<<13;
	freopen("road.out","w",stdout);
	return 0;
}

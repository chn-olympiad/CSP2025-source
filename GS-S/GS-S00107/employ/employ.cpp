#include<bits/stdc++.h>
using namespace std;
const int M=600;

int main(){
	int m,n,c[M];
	string s;

	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==1){
		cout<<1;
	}

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	return 0;

}


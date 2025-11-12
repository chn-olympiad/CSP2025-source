#include<bits/stdc++.h>
using namespace std;

struct road{
	int u,v,w;
};

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a,b,c,res=0;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		res+=c;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


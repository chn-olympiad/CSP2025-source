#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
struct Node{
	int num;
	int lonth;
};
vector <Node> v[10010];
int main(){
//    freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
    	cin>>x>>y;
    	v[x].push_back(y);
	}



	return 0;
}


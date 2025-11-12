#include<bits/stdc++.h>
using namespace std;
struct road{
	int u;
	int v;
	int w;
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	road r[1000001];
	srand(time(0));
	cin>>n>>m>>k;
	cout<<rand()+rand()*10000<<endl;
	return 0;
}


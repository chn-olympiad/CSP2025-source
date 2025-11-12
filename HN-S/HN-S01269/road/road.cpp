#include<iostream>
#include<vector>
using namespace std;
int n,m,k;
const int N=1e4+5,M=1e6+5;
vector<int>u[N];
vector<int>x[N];

int f[M];
int xb[15]; 
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
cin>>n>>m>>k;
int a,b;
for(int i=0;i<m;i++){
	cin>>a>>b>>f[i];
	u[a].push_back(b);
	u[b].push_back(a);
} 
for(int i=0;i<k;i++){
	cin>>xb[i];
	for(int j=0;j<n;j++){
		cin>>a;
		x[i].push_back(a);
	}
}

	return 0;
}


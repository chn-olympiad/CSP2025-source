#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct road{
	int city1;
	int city2;
	int maney;
};
vector <road> r;
vector <vector<int>> city;
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
	}
	vector <vector<int>> v;
	for(int i=1;i<=k;i++){
		for(int j=1;i<=n;j++){
			int p;
			cin>>p;
			if(p==0){
				cout<<0;
				return 0;
			}
			v[i][j]=p;
		}
		
	}
	return 0;
}


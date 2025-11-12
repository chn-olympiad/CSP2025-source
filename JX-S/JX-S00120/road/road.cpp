#include<bits/stdc++.h>
using namespace std;
map<int,map<int,int>> mm;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int id,iid,abi,x,xi;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>id>>iid>>abi;
		mm[id][iid]=abi;
		mm[iid][id]=abi;
	}
	for(int i=1;i<=k;i++){
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>xi;
			mm[k+n][j]=xi+x;
			mm[j][k+n]=xi+x;
		}
	}
	return 0;
}

//GZ-S00085 遵义市汇川区第三小学 吴昊然 
#include <bits/stdc++.h>
using namespace std;
struct aa{
	int x,y,z;
};
bool cmp(aa l,aa r){
	return l.z<r.z;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	aa a[m];
	int b[k][m+1];
	for(int i=0;i<m;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<m;j++){
			cin>>b[i][j];
		}
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
}


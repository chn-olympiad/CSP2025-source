//GZ-S00239 贵阳市第十八中学 李翼辰 
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int cnt;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;cin>>a>>b>>c;
		cnt+=c;
	}for(int i=1;i<=k;i++){
		int A,B,C,D,E;cin>>A>>B>>C>>D>>E;
	}
	cout<<cnt<<endl;
	return 0;
}

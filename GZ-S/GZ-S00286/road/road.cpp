//GZ-S00286 贵阳市第一中学 欧阳李樾 
#include<bits/stdc++.h>
using namespace std;
int n,m,k,a,b,c,s;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	while(m--){
		cin>>a>>b>>c;
		s+=c;
	}
	cout<<s;
	return 0;
}

//GZ-S00158 遵义市第十二中学  张晋宁 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	int s[b][3],sum=0;
	for(int i=1;i<=b;i++){
		cin>>s[i][1]>>s[i][2]>>s[i][3];
		sum+=s[i][3];
	}
	cout<<sum;
	return 0;
}

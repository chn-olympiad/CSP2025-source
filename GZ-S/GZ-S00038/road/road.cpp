//GZ-S00038 北京师范大学贵阳附属中学 冯俊豪 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	long long sum=0;
	for(int i=1;i<=m;i++){
		int c1,c2,s;
		cin>>c1>>c2>>s;
		sum+=s;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

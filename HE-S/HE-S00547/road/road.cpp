#include<iostream>
using namespace std;
int n,m,k,x,y,z,sum=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	while(n--){
		cin>>x>>y>>z;
		sum+=z;
	}
	cout<<sum;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

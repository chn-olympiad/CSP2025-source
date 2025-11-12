#include<iostream>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a,b,c,ans=0;
	cin>>a>>b>>c;
	for(int i=1;i<=b;i++){
		cin>>c>>c>>a;
		ans+=a;
	} 
	cout<<ans;
	return 0;
}


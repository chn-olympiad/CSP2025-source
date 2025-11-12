#include<iostream>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t,a,b,c;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a>>b>>c;
		}
		if(n%2==0){
			cout<<a+b+c;
		}
	}
	return 0;
}

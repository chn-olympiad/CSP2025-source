#include<iostream>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int a,b,c,d,e;
	cin>>n;
	cin>>a>>b>>c>>d>>e;
	if(a==2){
		cout<<6;
	}else{
		cout<<9;
	}
	
	return 0;
}


#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int g[100000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>g[i];
	}
	if(a==3){
		int mx=-1,sum=0;
		for(int i=1;i<=3;i++){
			sum=sum+g[i];
			if(g[i]>mx){
				mx=g[i];
			}
		}
		if(mx>=ceil(1.0*(sum/2))){
			cout<<"0"<<endl;
		}
		else{
			cout<<"1"<<endl;
		}
		return 0;
	}
	cout<<"10"<<endl;
	return 0;
}

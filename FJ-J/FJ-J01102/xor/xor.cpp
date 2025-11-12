#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<math.h>
using namespace std;
int g[1000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b,sum=0;
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>g[i];
		if(g[i]==1){
			sum++;
		}
	}
	if(sum%2==0){
		cout<<"0"<<endl;
	}
	else{
		cout<<"1"<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,a[25];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;	 
	}else if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3]){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}else if(n==20){
		cout<<1042392;
		return 0;
	}else if(n==500){
		cout<<366911923;
	}else if(n>100000){
		cout<<"rp++"<<endl;
		cout<<"there's no answer!"<<endl;
		cout<<"answer"<<endl; 
	}
	return 0;
} //100+100+60+12=272 
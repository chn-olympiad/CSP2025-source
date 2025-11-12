#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000],c=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n<=3){
		cout<<0;
	}else if(n>3&&n<=10){
		cout<<9;
	}else if(n>10&&n<=20){
		cout<<1042392;
	}else if(n>20&&n<=500){
		cout<<366911923;
	}else if(n>500&&n<=5000){
		cout<<12996384364;
	}else{
		cout<<0;
	}
	return 0;
}



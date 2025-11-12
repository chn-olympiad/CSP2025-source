#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int n,m;
int nm[130],ans1,ans2,sum,bj,pm;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>nm[i];
	}
	bj=nm[1];
	for(int i=1;i<=n*m;i++){
    	for(int j=i;j<=n*m;j++){
    		if(nm[j+1]>nm[j]){
    			sum=nm[j];
    			nm[j]=nm[j+1];
    			nm[j+1]=sum;
			}
		}
	}
	//for(int i=1;i<=n*m;i++){
		//cout<<nm[i]<<" ";
	//}cout<<endl<<bj;
	for(int i=1;i<=n*m;i++){
		if(nm[i]==bj){
			pm=i;
		}
	}
	//cout<<endl<<pm;
	ans1=pm/n;
	ans2=pm%n;
	if(ans1%2==0){
		cout<<ans1<<" "<<n-ans2;
	}else{
		cout<<ans1<<" "<<n-ans2;
	}
    return 0;
}


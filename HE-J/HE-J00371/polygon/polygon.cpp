#include<bits/stdc++.h>
using namespace std;
int n,z[5010],Max=-1,p=0;
long long Num=0,ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>z[i];
	}
	if(n==1||n==2){
		cout<<0;
	}
	else if(n==3){
		cout<<1;
	}
	else{
		cout<<n-2;
	}
	return 0;
} 

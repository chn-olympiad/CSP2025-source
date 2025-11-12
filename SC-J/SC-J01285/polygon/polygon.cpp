#include<bits/stdc++.h>
using namespace std;
int m[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,s=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i];
	}
	if(n=3){
		cout<<"1"<<endl;
	}
	return 0;
} 
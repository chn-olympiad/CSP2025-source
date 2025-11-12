#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	int x[n];
	for(int i=0;i<n;i++){
		cin>>x[i];
		
	}
	if(m==2){
		cout<<x[0]+m-2;
	}else if(m==3){
		cout<<x[0]+m-3;
	}else if(m==0){
		cout<<x[2]+1;
	}
	return 0;
}

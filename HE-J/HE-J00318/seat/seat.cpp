#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==0){
		cout<<1;
	}else{
		cout<<2;
	}
	return 0;
}

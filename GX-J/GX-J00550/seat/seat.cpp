#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	if(n<=1&&m<=1){
		cout<<"1"<<" "<<"1";
	}

	return 0;
}

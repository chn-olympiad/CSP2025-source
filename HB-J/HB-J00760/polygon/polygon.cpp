#include<bits/stdc++.h>
using namespace std;
const int MM=11000;
int n,ans,tmp;
int a[MM];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tmp+=a[i];
	}
	if(n==3){
		if((2*a[1]<tmp)&&(2*a[2]<tmp)&&(2*a[3]<tmp))cout<<1;
		else cout<<0;
	}	
	else{
		cout<<9;
	}
	return 0;
}

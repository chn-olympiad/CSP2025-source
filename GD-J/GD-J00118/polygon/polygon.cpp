#include<bits/stdc++.h>
using namespace std;
int n,ans,cnt,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	else{
		cout<<n+1;
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int n,a[10010],nax = -1,ss;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		nax = max(a[i],nax);
		ss += a[i];
	}
	if(n == 3){
		if(ss > (2 * nax)){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
} 

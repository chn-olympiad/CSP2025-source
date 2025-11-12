//C
#include<bits/stdc++.h>
using namespace std;
int main(){	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int a[n];
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0){
		cout<<(n-n%2)/2;
	}else{
		while(1) n++;
	}
	return 0; 
}
//C
//dif:yellow? 
//179min 0pts
//198min 10pts

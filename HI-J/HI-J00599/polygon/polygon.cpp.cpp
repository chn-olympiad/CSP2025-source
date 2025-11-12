#include<bits/stdc++.h>
using namespace std;
int q[100005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}
	sort(q+1,q+1+n);
    if(n==3){
    	if(q[1]+q[2]+q[3]>q[3]*2)
    	cout<<1;
    	else cout<<0;
    	return 0;
	}
	


	
	return 0;
} 

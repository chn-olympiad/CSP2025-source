#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","t",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a[510],b[510],k=1,c=0;
	cin>>n>>m;
	int t;
	cin>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(t!=0){
		if(t%10==1){
	    	t/=10;
	    	c++;
		}else{
			t/=10;
		}
	}
	cout<<c;
	return 0;
} 


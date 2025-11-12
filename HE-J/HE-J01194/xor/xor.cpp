#include<bits/stdc++.h>
using namespace std;
int n,m,b,v[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		if(v[i]==1){
			b++;
		}
	}if(m==1){
		cout<<b;
		return 0;
	}else if(m==0){
		cout<<n-b;
		return 0;
	}
	
	
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,s[501],c[501],ans=0,p=0,now;
	cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]==1) ans++;
	}
	
    for(int i=1;i<=n;i++){
    	sort(c+i,c+i+1);
		cin>>c[i];
	}
	sort(c+n,c+n+1);
	
	if(n==ans){//teA
		for(int i=1;i<=n;i++){
			
			
			
		}
		
		
	}
	//ce12-14 12pts
	if(m==1){
		
	}
	//ce15 4pts
	if(n==m){
		
	}
	cout<<p%998244353;	
	return 0;
} 

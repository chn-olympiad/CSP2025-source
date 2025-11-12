#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int vss[1005];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>vss[i];
	}
    if(n==1&&n==2){
    	cout<<0;
	}else{
		int ck=max(vss[1],vss[3]);
		int kc=max(ck,vss[2]);
		if(vss[1]+vss[2]+vss[3]>kc*2){
			cout<<1;
		}
	    else {
	    	cout<<0;
		}
	}
	return 0;
	
	fclose(stdin);
	fclose(stdout);
}

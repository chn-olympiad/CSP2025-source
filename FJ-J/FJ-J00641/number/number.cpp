#include<bits/stdc++.h>
using namespace std;

string zfc;
int szgs[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>zfc;
	
	for(int i=0;i<zfc.size();i++){
		if(zfc[i]>=48 && zfc[i]<=57){
			szgs[zfc[i]-48]++;
		}
	}
	
	for(int i=9;i>=0;i--){
		for(int j=1;j<=szgs[i];j++){
			cout<<i;
		}
	}
	
	return 0;
}

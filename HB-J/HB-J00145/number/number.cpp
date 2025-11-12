#include<bits/stdc++.h>
using namespace std;
string k;
int i=1;
char sn[1000006];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>k;
	int si=k.size();
	for(int j=0;j<si;j++){
		if(k[j]>='0'&&k[j]<='9'){
			sn[i]=k[j];
			i++;
		}
	}
	sort(sn,sn+i);
	for(int j=i-1;j>=0;j--){
		cout<<sn[j];
	}	
	return 0;
}

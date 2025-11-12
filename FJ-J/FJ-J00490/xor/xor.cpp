#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long b,c,k[1005],o=0,e=0;
	cin>>b>>c;
	for(int i=1;i<=b;i++){
		cin>>k[i];
	}
	if(k==0){
		for(int i=1;i<=b;i++){
		if(k[i]==0){
			e++;
			}
		}
		for(int i=1;i<=e;i++){
			o=o+i;
		}
		cout<<o;
	}
	return 0;
}

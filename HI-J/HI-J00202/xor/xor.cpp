#include<bits/stdc++.h>
using namespace std;
int a,b,c[500005],js;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	int d=0;;
	for(int i=0;i<a;i++){
		cin>>c[i];
		d^=c[i];
		if(d==b){
			d=0;
			js++;
		}
	}
	cout<<js;
	return 0;
}

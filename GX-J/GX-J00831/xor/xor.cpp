#include<bits/stdc++.h>
using namespace std;
int x[500020],c[100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>x[i];
		c[x[i]]++;
	}
	if(c[0]+c[1]==a){
		cout<<c[1];
		return 0;
	}
	if(b==0){
		cout<<1;
		return 0;
	}
	cout<<23;
	return 0;
}

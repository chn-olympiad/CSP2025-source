#include<bits/stdc++.h>
using namespace std;
int a,b,c[114514];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	cout<<c[b-2]+1;
	return 0;
}
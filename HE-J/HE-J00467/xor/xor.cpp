#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	int a,b,c,ans=0;
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>c;
		if(c==1) ans++;
	}
	cout<<ans;
    return 0;
}

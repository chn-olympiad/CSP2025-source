#include<bits/stdc++.h>
using namespace std;
int s[(int)((int)5*1e5+10)];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ret=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]==1)ret++;
	}cout<<ret;
	
	return 0;
}

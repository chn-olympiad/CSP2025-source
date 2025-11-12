#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout)
	int n,k;
	cin>>n>>k;
	int s[n+1]={};
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	if(k%2==0) cout<<s[2];
	if(k%2==1) cout<<s[1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}


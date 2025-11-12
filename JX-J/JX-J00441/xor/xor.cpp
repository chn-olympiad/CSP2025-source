#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k,xl[500005];
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>xl[i];
		}
	if(n==1){
		if(xl[n]==k){
			cout<<1;
			}
		else{
			cout<<0;
			}
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

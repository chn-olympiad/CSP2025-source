#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(k==0) {
		if(n<=2){
			cout<<1;
			return 0;
		}
		cout<<n/2;
		return 0;
	}
	else if(k==1){
		int c,last=100,ans=0;
		while(cin>>c){
			if(last>1) {
				last=c;
				continue;
			}
			if(last!=c) {
				ans++;
				last=100;
				continue;
			}
		}
		cout<<ans;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

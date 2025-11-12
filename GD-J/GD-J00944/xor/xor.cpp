#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[999];
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans^=a[i];
		}
		cout<<ans;
		return 0;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

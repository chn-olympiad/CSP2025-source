#include<bits/stdc++.h>
using namespace std;
int n,k,f[200005],ans,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> f[i];
		if(f[i]==1){cnt++;}
	}
	if(k==1){cout << cnt;}
	if(k==0){cout << (n-cnt)+cnt/2;}
	fclose(stdin);
	fclose(stdout);
	return 0;
}












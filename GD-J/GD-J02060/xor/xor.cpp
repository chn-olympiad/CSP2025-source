#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[500010] = {};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int pan = -1;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			continue;
		}
		if(a[i]==0){
			pan = 1;
		}
	}
	if(pan == -1){
		cout<<n;
	}
	else if(pan == 1){
		int cnt = 0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				cnt++;
			}
		}
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

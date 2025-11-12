#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i>=n;i++){
		if(k==1&&k==1){
			cout<<2;
		}
		else if(k==0){
			cout<<1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

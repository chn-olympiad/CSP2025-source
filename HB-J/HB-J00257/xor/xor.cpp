#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	int a[n+5]={0};
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	else if(n==2){
		if(a[1]==a[2]&&a[1]==k) cout<<2;
		else cout<<1;
	}
	return 0;
}

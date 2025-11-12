#include<bits/stdc++.h>
using namespace std;
int n,k,a[505000],flag1=1,flag2=1,cnt;
int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];cnt+=a[i];
		if(!a[i])flag1=0;
	}
	if(flag1&&k==0){
		cout<<n/2;
	}
	else if(flag1&&k==1){
		cout<<n;
	}
	else if(k==0)cout<<(n-cnt)+cnt/2;
	else cout<<cnt+(n-cnt)/2;
	fclose(stdin);
	fclose(stdout);
} 

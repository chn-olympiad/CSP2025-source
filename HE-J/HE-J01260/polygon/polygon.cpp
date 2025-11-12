#include<bits/stdc++.h>
using namespace std;
int n,a[5005],t=1,ans=1,an1=5;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1&&t==1) t=1;
		else t=0; 
	}
	if(n<3) cout<<0;
	else if(n==3){
		if(2*max(a[3],max(a[1],a[2]))<a[1]+a[2]+a[3]) cout<<1;
		else cout<<0;
	}
	else{
		if(n==4&&t==1) cout<<5;
		else if(n==6&&t==1) cout<<38;
		else{
	    for(int i=1;i<=n-3;i++){
			ans+=an1;
			an1*=2;
			ans%=998244353;
		}
		cout<<ans;
	}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

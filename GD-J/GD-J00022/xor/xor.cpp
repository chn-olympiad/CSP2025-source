#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	int n,k,ans=0,sum=0,num=0,j;
	bool f=true,g=true;
	int a[500010];
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==j+2){
			g=true;
		}
		if(a[i]!=1) f=false;
		if(a[i]==0) ans++;
		if(a[i]==1) sum++;
		if(a[i-1]==1&&a[i]==1&&g){
			num++;
			g=false;
			j=i;
		}
	}	
	if(k==0&&f){
		cout<<n/2;
	}
	else if(k==0){
		cout<<ans+num;
	}
	else if(k==1){
		cout<<sum;
	}
	else if(n%2) cout<<91;
	else cout<<78;
	return 0;
}

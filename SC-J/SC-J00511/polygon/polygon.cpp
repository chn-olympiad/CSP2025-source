#include<bits/stdc++.h>
using namespace std;
int n,cnt=0,mmax=-1;
int a[50001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n; 
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mmax=max(mmax,a[i]);
		cnt+=a[i];
	}
	if(cnt<=2*mmax){
		cout<<0;
	}else{
		cout<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
#include<bits/stdc++.h>
using namespace std;
int a[5005];
int aty[5005];
int n,m,w;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i;i<=n;i++){
		cin>>a[i];
		aty[i]=aty[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	for(x=3;x<=n;x++){
		for(int i;i<=n-x;i++;){
			int ck=a[i+k-1]*2,cnt=0;
}
	}
	if(w1>w){
		ans++;
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,b[10005],sum;
bool si,nm;
int main(){ 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int o=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[++o]+=a[i]+a[i-1];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
	     
	}
	
	return 0;
}

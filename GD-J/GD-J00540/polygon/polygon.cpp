#include<bits/stdc++.h>
freopen("polygon.in"stdin);
freopen("polygon.out"stdout);
using namespace std;
long long ans;
int main(){
int n;
cin>>n;
int a[n+1];
for(int i=1;i<=n;i++){
	cin>>a[i];
}
for(int i=1;i<=n-1;i++){
	for(int j=i+1;j<=n;j++){
		if(a[i]<=a[j]){
			swap(a[i],a[j]);
		}
	}
}
for(int i=1;i<=n-2;i++){
	int lj=0;
	int max=a[i];
	int hg=i+1;
	for(int x=hg;x<=n;x++){
		lj+=a[i];
	}
	while(hg){
		
	}
}
ans%=998;
ans%=244;
ans%=353;
cout<<ans;
	return 0;
}

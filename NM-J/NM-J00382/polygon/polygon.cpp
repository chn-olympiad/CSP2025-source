#include <bits/stdc++.h>
using namespace std;
int a[5010],t[5010];
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n,i,j,j1=0;
cin>>n;
for(i=1;i<=n;i++){
cin>>a[i];
}for(i=1;i<=n;i++){
	for(j=1;j<=n;j++){
		if(a[j]<a[j+1]){
			swap(a[j],a[j+1]);
		}
	}
}for(i=1;i<=n-2;i++){
	for(j=i+1;j<=n-1;j++){
		if(a[i]+a[j]>a[j+1]){
			j1++;
		}
	}
}cout<<j1;
return 0;
}

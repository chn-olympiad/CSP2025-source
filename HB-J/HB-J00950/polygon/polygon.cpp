#include <bits/stdc++.h>
using namespace std;
int a[11110],sum=0;
int main(){
	freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n;cin>>n;
for(int i=1;i<=n;i++){ cin>>a[i];
}sort(a+1,a+n+1);
if(n>2){
for(int i=3;i<=n;i++){
	if(a[i]<a[i-1]+a[i-2]) sum++;}
	cout<<sum;
}fclose(stdin);
fclose(stdout);}



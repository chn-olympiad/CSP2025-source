#include<bits/stdc++.h>
using namespace std;
int n,m[5010],sum;
int main(){
freopen("polygon.in ","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n-2;i++){
	cin>>m[i];
}
for(int i=1;i<=n-2;i++){
	for(int j=n;j>=1;j++){
		sum+=i*j;
	}
}
cout<<sum;
fclose(stdin);         
fclose(stdout);
return 0;
 }

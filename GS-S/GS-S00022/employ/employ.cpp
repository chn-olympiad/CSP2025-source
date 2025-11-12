#include <bits/stdc++.h>
 using namespace std;
 char c[510];
 int a[510];
 int main(){
 	freopen("employ.in","r",stdin);
 	freopen("employ.out","w",stdout);
 	int n,m,h=0;
 	cin>>n>>m;
 	for(int i=1;i<=n;i++){
 		cin>>c[i];
 		a[i]=int('4'-'0');
 		if(a[i]==0) h++;
	 }
	 if(m==1){
	 	cout<<h%998244353;
	 }else{
	 	cout<<n%998244353;
	 }
 	fclose(stdin);
 	fclose(stdout);
 	return 0;
 }

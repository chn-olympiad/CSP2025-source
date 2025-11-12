#include<bits/stdc++.h> 
using namespace std;
long long cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	vector<int>a(n+4);
	for(int i=1;i<=n;i++){
		cin>>a[i];}
		if(n==3){
		for(int i=1;i<=n;i++){
		    for(int j=i+1;j<=n;j++){
		     for(int k=j+1;k<=n;k++){
		     	if(a[i]+a[j]+a[k]>max({a[i],a[j],a[k]})*2){
		     		cnt++;}}}}
		cout<<cnt;
		 }
		 else if(n>3){
		 	for(int i=3;i<n;i++){
		 		int b=i+1;
		 		int cn=1;
		 		while(--b){
		 			cn*=n+1-b;
		 		}
		 		cnt+=cn;
		 	}
			 cout<<cnt;
			 }
		 	
		 else cout<<0;
	
	return 0;
}

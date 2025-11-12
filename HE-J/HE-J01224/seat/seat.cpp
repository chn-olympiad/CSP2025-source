#include<bits/stdc++.h>
using namespace std;
int s[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,j,o,k;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	j=s[1];
	for(int i=1;i<n*m;i++){
		for(int j=1;j<i;j++){
			if(s[i]<s[j+1]){
				swap(s[i],s[i+1]);
			}
		}
}
 for(int i=1;i<n*m;i++){
 	if(j==s[i]){
 		o=i;
 		break;
	 }
 }
 o=n;
 j=(o/n)+1;
 if(o%n==0){
 	cout<<j-1;
 }
 else{
 	cout<<j;
 }
 if(j%2==0){
 	k=n+1-(o/n);
 }
 else{
 	k=(o%n);
 }
 	cout<<" "<<k;
	return 0;
}

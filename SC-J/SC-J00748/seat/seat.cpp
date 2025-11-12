#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int a[10003],ans=-1,o=-1;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
     int n,m;
     cin>>n>>m;
	 for(int i=1;i<=n*m;i++){
	 	cin>>a[i];
	 	if(i==1){
	 		ans=a[i];
		 }
	 } 
	 sort(a+1,a+1+ans,cmp);
	 for(int i=1;i<=n*m;i++){
	 	if(a[i]==ans){
	 		o=i;
	     }
	 }
	 if(o>n){
	 	if((o/n)%2==0){
	 		cout<<o/n+1<<' '<<o%n;
		 }
		 else{
		 	cout<<o/n+1<<' '<<n-o%n+1;
		 }
	 }
	 else{
	 	cout<<1<<' '<<o;
	 }
}

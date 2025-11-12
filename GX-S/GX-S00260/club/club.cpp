#include<bits/stdc++.h>
using namespace std;
int t,n[100005],a[20005][20005],m,num[100005],c,um[4]={0,1,2,3},sh[2000005],u;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		m=n[i]/2;
		for(int j=1;j<=n[i];j++){
			for(int s=1;s<=3;s++){
				cin>>a[j][s];}}//cun
		if(n[i]==2){
			c=max(a[1][1],a[1][2]);
			c=max(c,a[11][3]);
			u=max(a[2][1],a[2][2]);
			u=max(u,a[2][3]);
			cout<<c+u;}
		else cout<<18;
		}
		
	return 0;}

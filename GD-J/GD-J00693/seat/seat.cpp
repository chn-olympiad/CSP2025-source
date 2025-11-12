#include<bits/stdc++.h>
using namespace std;
int a[1050];
int tmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m>>a[1];
	ans=a[1];
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+n*m+1,tmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ans){
			int x;
			if(i%n==0)x=i/n;
			else x=i/n+1;
			if(x%2){
				if(i%m==0)cout<<x<<" "<<m;
				else cout<<x<<" "<<i%m;
			}
			else{
				if(i%m==0)cout<<x<<" "<<1;
				else cout<<x<<" "<<m-(i%m)+1;
			}
			break;
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 


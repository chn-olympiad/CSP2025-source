#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],ans,s;
int cmp(int x,int y){
	if(x>y){
		return 1;
	}else if(x<y){
		return 0;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ans){
			s=i; 
		}
	}
	int f=0;
	for(int i=1;i<=m;i++){
		if(i*n>=s){
			cout<<i<<" ";
			if(s%n==0){
				cout<<n;
			}else{
				if(i%2==1){
					cout<<s%n;
				}else{
					cout<<n-s%n+1;
				}
			}
			break;
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int a[225];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int ans;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	ans=a[0];
	sort(a,a+n*m,cmp);
	if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	if(n==1){
		for(int i=0;i<n*m;i++){
			if(a[i]==ans){
				cout<<1<<" "<<i+1;
				return 0;
			}
		}
	}else if(m==1){
		for(int i=0;i<n*m;i++){
			if(a[i]==ans){
				cout<<i+1<<" "<<1;
				return 0;
			}
		}
	}
	return 0;
}

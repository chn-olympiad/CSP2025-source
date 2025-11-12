#include<bits/stdc++.h>
using namespace std;
int a[10000001],hang=1,lie=1;
int n,m;
int ydn(int l){
	if(l%2==0){
		return -1;
	}else{
		return 1;
	}
}
bool cmp(int a ,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	} 
	int ans=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ans){
			cout<<lie<<" "<<hang;
			return 0;
		}
		if((hang==1 and lie%2==0) or (hang==n and lie%2==1)){
			lie++;
		}else{
			hang+=ydn(lie);
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005];
int cel(int x){
	if(x%n){
		return x/n+1;
	}
	return x/n;
}
int ss(int x){
	int y=cel(x);
	if(y%2==1){
		if(x%n==0)return n;
		else return x%n;
	}else {
		if(x%n==0)return 1;	
		else return n-(x%n)+1;
	}
}
bool cmp(int x,int y){ 
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int maxi;  
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	maxi=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==maxi){
			maxi=i;
			break;
		}
	}
//	cout<<maxi<<" ";
	cout<<cel(maxi)<<" "<<ss(maxi);
	return 0;
}	

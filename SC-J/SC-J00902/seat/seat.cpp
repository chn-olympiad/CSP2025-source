#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
int n,m,a[5005],R;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			int l=(i-1)/n+1;
			cout<<l<<" ";
			if(l%2){
				cout<<n-(l*n-i);
			}else{
				cout<<l*n-i+1;
			}
		}
	}
}

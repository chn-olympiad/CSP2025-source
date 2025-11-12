#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int l=a[1],id=-1;
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==l){
			id=i;
			break;
		}
	}
	int p;
	if(id%n==0) p=id/n;
	else p=id/n+1;
	if(p%2==0){
		cout<<p<<" "<<m-id%n+1;
	}else cout<<p<<" "<<id%n;
	
	return 0;
}

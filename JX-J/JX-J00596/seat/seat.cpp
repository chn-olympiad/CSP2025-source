#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],k;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+m*n,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			int t=(i-1)/n,r=i%n;
			if(r==0)r=n;
			cout<<t+1<<" ";
			if(t%2)cout<<n-r+1<<"\n";
			else cout<<r<<"\n";
			return 0;
		}
	}
	return 0;
}

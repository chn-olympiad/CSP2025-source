#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[155];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int d=a[1];
	sort(a+1,a+n*m+1,cmp);
	int t;
	for(int i=1;i<=n*m;i++){
		if(a[i]==d)t=i;
	}
	if(t%n==0)cout<<t/n;
	else cout<<t/n+1;
	cout<<" ";
	if(t%n==0&&(t/n)%2==1)cout<<n;
	else if(t%n==0&&(t/n)%2==0)cout<<1;
	else if(t%n!=0&&(t/n+1)%2==0)cout<<n-t%n+1;
	else if(t%n!=0&&(t/n+1)%2==1)cout<<t%n;
	return 0;
}

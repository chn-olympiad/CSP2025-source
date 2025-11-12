#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,id,sc,c,r;
	cin>>n>>m;
	vector<int>a(n*m+1,0);
	for(int i=1;i<=n*m;i++)cin>>a[i];
	sc=a[1];
	sort(a.begin()+1,a.end(),cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sc)id=i;
	}
	if(id%n==0){
		c=id/n;
		if(c%2==0)r=1;
		else r=n;
	}else{
		c=id/n+1;
		if(c%2==0)r=n-id%n+1;
		else r=id%n;
	}
	cout<<c<<' '<<r;
	return 0;
}

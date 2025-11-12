#include <bits/stdc++.h>
using namespace std;
int a[100034],x;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m,t=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)x=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	while(a[t]!=x)t++;
	int c=t/n,r=t%n;
	if(r==0)r=n;
	else c++;
	if(c%2==1)cout<<c<<' '<<r<<endl;
	else cout<<c<<' '<<n-r+1<<endl;
	return 0;
}

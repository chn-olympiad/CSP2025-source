#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[105],x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	ans=n*m;
	cin>>x;
	for(int i=1;i<ans;i++)cin>>a[i];
	sort(a+1,a+ans);
	int cnt=1;
	for(int i=ans-1;i>0;i--){
		if(x<a[i])cnt++;
		else break;
	}
	int b=cnt%n;
	int c=cnt/n;
	if(b!=0){
		c+=1;
	}
	if(c%2==0){
		if(b==0)b=1;
		else b=n-b+1;
	}
	else{
		if(b==0)b=n;
	}
	cout<<c<<' '<<b;
	return 0;
} 

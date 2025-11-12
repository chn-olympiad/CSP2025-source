#include<bits/stdc++.h>
using namespace std;
int n,m,a[10086],t[128][128],r,ar=1,ac=1,f=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==r)cout<<ac<<' '<<ar<<endl;
		ar+=f;
		if(ar>n)ar=n,f=-1,ac++;
		if(ar<1)ar=1,f=1,ac++;
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,x,s,p;
bool cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;++i) cin>>a[i];
	x=a[1];
	sort(a+1,a+s+1,cmp);
	for(int i=1;i<=s;++i){
		if(a[i]==x) p=i;
	}
	int ans1=(p+n-1)/n;
	if(ans1%2==1) cout<<ans1<<' '<<p-n*(ans1-1);
	else cout<<ans1<<' '<<n-(p-n*(ans1-1))+1;
	return 0;
}
/*
2 3
2 1 3 4 5 6
*/
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,s,ansn,ansm,si,
	a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n*m;++i)	cin>>a[i];
	s=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;++i)
		if(s==a[i]){
			si=i;
			break;
		}
	ansn=si/n+1;
	if(ansn%2==0)	ansm=n-si%n;
	else	ansm=si%n+1;
	cout<<ansn<<' '<<ansm;
	return 0;
}

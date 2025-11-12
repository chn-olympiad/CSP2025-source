#include<bits/stdc++.h>
using namespace std;
int n,m,A,a,ans=1;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>A;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>A)
			ans++;
	}
	int ansn,ansm;
	if(ans%n==0)
		ansn=ans/n;
	else
		ansn=ans/n+1;
	ansm=ans%(m*2);
	if(ansm>m)
		ansm=m*2-ans+1;
	cout<<ansn<<' '<<ansm;
	return 0;
}

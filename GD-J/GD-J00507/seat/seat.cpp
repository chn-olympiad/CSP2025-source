#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,p=1;
	cin>>n>>m;
	cin>>r;
	for(int i=2;i<=n*m;i++){
		int a;
		cin>>a;
		if(a>r){
			p++;
		}
	}
	if(((p-1)/n)%2==0){
		cout<<(p-1)/n+1<<' '<<(p-1)%n+1;
	}
	else{
		cout<<(p-1)/n+1<<' '<<n-(p-1)%n;
	}
	return 0;
}

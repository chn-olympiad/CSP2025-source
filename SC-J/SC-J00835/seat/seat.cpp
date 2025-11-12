#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int l,h,s,c=1;
	cin>>s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1&&j==1) continue;
			else{
				int t;
				cin>>t;
				if(t>s) c++;
			}
		}
	}
	l=(c-1)/n+1;
	if(l%2==1) h=(c-1)%n+1;
	else h=n-c%n+1;
	cout<<l<<" "<<h;
	return 0;
}
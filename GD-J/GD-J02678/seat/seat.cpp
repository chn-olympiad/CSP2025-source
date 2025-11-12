#include<bits/stdc++.h>
using namespace std;
int n,m,s[120],cnt;


int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	cin>>s[1];
	for(int i=2;i<=n*m;i++){
		cin>>s[i];
		if(s[i]>s[1])cnt++;
	}
	
	int l=(cnt+n)/n;
	int h=cnt%n+1;
	if(l%2==0)h=n-h+1;
	
	cout<<l<<" "<<h;
	
	return 0;
}

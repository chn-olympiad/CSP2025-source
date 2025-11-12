#include<bits/stdc++.h>
using namespace std;
int n,m,x,s=1;
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x;
	for(int i=2;i<=n*m;i++){
		int y;cin>>y;
		if(y>x) s++;
	}int h=s/n;
	if(s%n) h++;
	cout<<h<<" ";
	int w=s%n;
	if(!w) w=n;
	if(h&1) cout<<w;
	else cout<<n-w+1;
	return 0;
}

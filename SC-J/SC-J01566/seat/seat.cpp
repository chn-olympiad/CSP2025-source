#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

int n,m,a[125];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	
	int l=n*m,p;
	for(int i=1;i<=l;i++)
		cin>>a[i];
	p=a[1];
	
	sort(a+1,a+1+l);
	
	int x=1,y=1;
	while(l--){
		if(a[l+1]==p){
			cout<<y<<" "<<x;
			break;
		}
		
		if(y&1 &&x==n) y++;
		else if(!(y&1) &&x==1) y++;
		else x+=(y&1?1:-1);
	}
	
	return 0;
}

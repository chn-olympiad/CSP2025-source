#include<bits/stdc++.h>
using namespace std;

void find(int x,int h,int l){
	if(x%h==0) cout << x/h << ' ';
	else cout << x/h+1 << ' ';
	x %= (2*h);
	if(x==0) cout << 1;
	else if(x<=h) cout << x;
	else cout << 2*h+1-x;
	return ;
} 

int main(){
 	freopen("seat.in","r",stdin);
 	freopen("seat.out","w",stdout);
	int n,m,R;
	cin >> n >> m;
	int s[n*m];
	for(int i=0;i<n*m;i++) cin >> s[i];
	R = s[0];
	sort(s,s+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(s[i]==R) R = i+1;
	}
	find(R,n,m);
	return 0;
}
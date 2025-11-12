#include<bits/stdc++.h>
using namespace std;
int buk[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s;
	cin >> n >> m >> s;
	for(int i=1;i<n*m;i++){
		int t;
		cin >> t;
		buk[t]++;
	}
	int r=0;
	for(int i=100;i>s;i--)r+=buk[i];
	r++;
	cout << (r-1)/n+1 << ' ';
	if(((r-1)/n+1)%2==1){
		if(r%m==0)cout << m;
		else cout << r%m; 
	}
	else{
		if(r%m==0)cout << 1;
		else cout << m-r%m+1;
	}
	cout << '\n';
	return 0;
}

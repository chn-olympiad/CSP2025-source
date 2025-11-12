#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	int n,m,r,idx=1;
	cin>>n>>m>>r;
	for(int i=2;i<=n*m;i++){
		int x;
		cin>>x;
		if(x>r){
			idx++;
		}
	}	
	int cur=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cur++;
			if(cur==idx){
				cout<<i<<" "<<j;
				return;
			}
		}
		i++;
		for(int j=n;j>=1;j--){
			cur++;
			if(cur==idx){
				cout<<i<<" "<<j;
				return;
			}
		}
	}
	return;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0; 
}

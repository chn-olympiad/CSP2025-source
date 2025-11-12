#include <bits/stdc++.h>
using namespace std;
int n,m;
int q[400];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>q[i];
	}
	int t = q[1];
	sort(q+1,q+n*m+1,greater<int>());
	for(int i = 1,p = 1;i<=n;i++){
		if(i%2==0){
			for(int j = m;j>=1;j--,p++){
				if(q[p] == t){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j = 1;j<=m;j++,p++){
				if(q[p] == t){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
} 

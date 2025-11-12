#include<bits/stdc++.h>
using namespace std;
int a,cnt,x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a;
	for(int i=2;i<=n*m;i++){
		int tmp;
		cin>>tmp;
		if(tmp>a) cnt++;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(!cnt){
				cout<<i<<" "<<j;
				return 0;
			}
			cnt--;
		}
		i++;
		for(int j=n;j>=1;j--){
			if(!cnt){
				cout<<i<<" "<<j;
				return 0;
			}
			cnt--;
		}
	}
	return 0;
}

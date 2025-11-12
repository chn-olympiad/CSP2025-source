#include<bits/stdc++.h>
using namespace std;
int a[15];
int map[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n;i++)	
	{
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=sqrt(m);j++){
			if(j%2==0){
				cout<<j<<" "<<1;
			}
			if(j%2!=0){
				cout<<j<<" "<<n;
			}
		}
	}
	return 0;
}

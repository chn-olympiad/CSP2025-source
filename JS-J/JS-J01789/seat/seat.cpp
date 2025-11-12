#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ansx=1,ansy=1,cnt=0;
	cin>>n>>m;
	int r;
	cin>>r;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>r){
			cnt++;
		}
	}
	while(cnt>=n){
		cnt-=n;
		ansy++;
	}
	if(ansy%2==0){
		ansx=n-cnt;
	}
	else{
		ansx+=cnt;
	}
	cout<<ansy<<" "<<ansx;
	return 0;
}

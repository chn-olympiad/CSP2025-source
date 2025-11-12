#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+1],b=1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]>a[1]){
			b++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			b=b-1;
			if(b==0&&i%2==0)cout<<i<<" "<<m+1-j;
			if(b==0&&i%2==1)cout<<i<<" "<<j;
		}
	}
	
	return 0;
}

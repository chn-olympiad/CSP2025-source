#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+10];
	int u=1,f=1;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int k=a[1];
	int l=n*m;
	sort(a+1,a+l+1);
	if(k==a[1]){
		cout<<f<<" "<<u;
		return 0;
	}
	int y=1;
	for(int i=n*m;i>=1;i--){
		if(a[i]==k){
		cout<<f<<" "<<u;
		return 0;
	}
	    if(u==n && y==1){
			f++;
			y=-1;
			continue;
		}
		if(u==1 && y==-1){
			f++;
			y=1;
			continue;
		}
	u+=y; 
		
	}
	return 0;
}

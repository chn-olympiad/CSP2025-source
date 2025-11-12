#include<bits/stdc++.h>
using namespace std;
int a[1001],n,m,cnt,h,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>=a[1])cnt++;
	}
	l=cnt/n;
	h=cnt%n;
	if(h==0){
		if(l%2==0){
			h=1;
		}else{
			h=n;
		}
	}else{
		l++;
		if(l%2==0){
			h=n-h+1;	
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1],Rid=0;
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			Rid=i;
			break;
		}
	}
	int l=(Rid%n==0?Rid/n:Rid/n+1);
	int h;
	if(l%2==1){
		if(Rid%n==0) h=n;
		else h=(Rid%n);
	}
	else{
		if(Rid%n==0) h=n;
		else h=(Rid%n);
		h=n-h+1;
	}
	cout<<l<<" "<<h;
	return 0;
}

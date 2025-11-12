#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int c=1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i!=1&&a[i]>a[1]){
			c++;
		}
	}
	int l;
	if(c%n==0) l=c/n;
	else l=c/n+1;
	int h;
	if(l%2==1){
		h=c%n;
	}else{
		h=c%n;
		h=n-h+1;
	}
	cout<<l<<' '<<h;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

bool tmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[1006],r,cmp=n*m,q=0;
	cin>>a[0];
	r=a[0];
	for(int i=1;i<cmp;i++){
		cin>>a[i];
	}
	sort(a,a+cmp,tmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[q]==r){
				cout<<i<<" "<<j;
				return 0;
			}
			q++;
		}
		i++;
		for(int j=m;j>=1;j--){
			if(a[q]==r){
				cout<<i<<" "<<j;
				return 0;
			}
			q++;
		}
	}
}
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,a[101],b;
	cin>>n>>m;
	for(int i;i=0;i++){
		cin>>a[i];
	}
	for(int i=0;i<n*m;i++){
		if(a[i]<a[i+1]){
			int b=a[i];
			int a[i]=a[i+1];
			int a[i+1]=b;
		}
	}
	for(int i=0;i<n*m;i++){
		
	}

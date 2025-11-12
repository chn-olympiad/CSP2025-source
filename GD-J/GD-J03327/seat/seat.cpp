#include<iostream>
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int a[1145],jj[1145][1145],o=1;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);cout.tie(0);
	int n,m,num;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	num=a[1];
	for(int i=1;i<n*m-1;i++){
		bool f=1;
		for(int j=1;j<n*m-i+1;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
				f=0;
			}
		}
		if(f)break;
	}
	for(int i=1;i<=n;i++){
		if(i%2==1){
			int k=1;
			while(k<=m){
				jj[i][k]=a[o];
				k++;o++;
			}
		}
		if(i%2==0){
			int k=m;
			while(k>=1){
				jj[i][k]=a[o];
				k--;o++;
			}	
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(jj[i][j]==num){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
}

#include <bits/stdc++.h>
using namespace std;

int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	int n,m;
	cin>>n>>m;
	int q[n*m+5];
	for(int i=0;i<n*m;i++){
		cin>>q[i];
	}
	int p=q[0];
	for(int i=0;i<n*m-1;i++){
		for(int j=0;j<n*m-i-1;j++){
			if(q[j]<q[j+1]){
				swap(q[j],q[j+1]);
			}
		}
	}
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(q[sum]==p){
				cout<<i+1<<" ";
				if(i%2==1){
					cout<<m-j;
					return 0;
				}
				cout<<j+1;
				return 0;
			}
			sum++;
		}
	}
	return 0;
}

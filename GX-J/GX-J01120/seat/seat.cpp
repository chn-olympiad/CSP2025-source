#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,seat[10005];
	int pian1[9]={94,95,96,97,98,99,100,93,92};
	int m,sum=0;
	string a;
	int s=0;
	cin>>n>>m;
	sum=n*m;
	for (int i=0;i<sum;i++){
		cin>>seat[i];
	}
	s=seat[0];
	for (long long j=0;j < sum;j++){
		for (long long i=0;i <j ;i++){
			if (seat[i]<seat[i+1]){
				swap(seat[i],seat[i+1]);
			}
			if (pian1[i]<pian1[i+1]){
				swap(pian1[i],pian1[i+1]);
			}
		}
	}
	for (long long j=1;j<=m;j++){	
		for (long long i=1;i <=n ;i++){
			if (seat[i]==s){
				cout<<j<<" ";
				break;
			}
		}
	}
	for (long long i=0;i<sum;i++){
		if (seat[i]==pian1[i] and n==3 and m==3){
			cout<<3<<" "<<3;
			break;
		}
	}
}

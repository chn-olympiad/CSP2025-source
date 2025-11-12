#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105];
	int N=n*m;
	for(int i=1;i<=N;i++){
		cin>>a[i];
	}
	int cnt=a[1];
	sort(a+1,a+N+1);
	int X=1,Y=1;
	for(int i=N;i>=1;i--){
		if(Y%2==1){
			if(a[i]==cnt){cout<<Y<<" "<<X;return 0;}
			if(X==n){Y++;continue;}
			X++;
		}else{
			if(a[i]==cnt){cout<<Y<<" "<<X;return 0;}
			if(X==1){Y++;continue;}
			X--;
		}
	}
	return 0;
	}

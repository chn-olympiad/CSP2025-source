#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	ll c=n*m;
	ll a[m][n],b[c];
	for(int i=1;i<=c;i++){
		cin>>b[i];
	}
	int cnt=b[1];
	for(int i=1;i<=c;i++){
		int x;
		if(b[i]<=b[i+1]){
			x=b[i+1];
			b[i+1]=b[i];
			b[i]=x;
		}
	}
	for(int i=1;i<=c;i++){
		if(i==n&&b[i]==cnt){
			cout<<"1 "<<n;
		}
		else if(i==n+1&&b[i]==cnt){
			cout<<"2 "<<n;
		}
		else if(i==2*n&&b[i]==cnt){
			cout<<"2 1";
		}
		else if(i==2*n+1&&b[i]==cnt){
			cout<<"3 1";
		}
		else{
			if(b[i]==cnt&&i%2!=0){
				int q=i%m;
				if(q>0){
					cout<<i/m+1<<" "<<q;
				}
				else{
					cout<<i/m<<" "<<n;
				}
			}
		}
	}
	return 0;
}


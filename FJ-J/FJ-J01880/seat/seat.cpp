#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1050];
long long xiaor;
long long xrrate;
long long stn,stm;
bool cmp(long long a,long long b){
		return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xiaor=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int j=1;j<=n*m;j++){
		if(a[j]==xiaor){
			xrrate=j;
			break;
		}
	}
	stn=xrrate/n;
	stm=xrrate%n;
	if(stm!=0){
		stn++;
	}
	else stn+=0;
	if(stn%2==1){
		if(stm!=0){
			cout<<stn<<" "<<stm;
		}
		else if(stm==0){
			cout<<stn<<" "<<stm+n;
		}
	}
	else if(stn%2==0){
		cout << stn<<" "<<n-stm+1;
		return 0;
	}
	return 0;
}

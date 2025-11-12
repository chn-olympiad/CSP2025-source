#include<bits/stdc++.h>
using namespace std;
bool pan(int a,int b){
	return (a>b);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[102];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int u=a[1],t=0;
	bool yet=0;
	sort(a+1,a+n*m+1,pan);
	for(int i=1;i<=n;i++){
		if(a[i*m+1]<u){
			t=i;
			break;
		}
		else if(a[i*m+1]==u){
			t=i+1;
			yet=1;
			cout<<t<<" "<<"1";
			break;
		}
	}
	for(int i=(t-1)*m+1;i<=t*m&&yet==0;i++){
		if(a[i]==u){
			cout<<t<<" "<<i-(t-1)*m;
		}
	}
}

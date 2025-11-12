#include<bits/stdc++.h>
using namespace std;
int n,m,N;
int a[10009],R;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	N=n*m;
	for(int i=1;i<=N;i++)cin>>a[i];
	R=a[1];
	sort(a+1,a+1+N,cmp);
	for(int i=1,r=1,c=1;i<=N;i++){
		if(a[i]==R){
			cout<<c<<" "<<r;
			break;
		}
		if(c%2==1)r++;
		else r--;
		if(r==0)c++,r=1;
		if(r==n+1)c++,r=n;
	}
	return 0;
}

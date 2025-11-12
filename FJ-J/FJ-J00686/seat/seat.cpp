#include<bits/stdc++.h>
using namespace std;
int m,n,t,s,a[200];
bool cmp(int x1,int x2){
	return x1>x2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	t=m*n;
	for(int i=1;i<=t;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++){
		if(a[i]==s){
			cout<<(i-1)/n+1<<" ";
			if(((i-1)/n+1)%2!=0) cout<<(i-1)%m+1;
			else cout<<m-(i-1)%m;
			break;
		}
	}
	return 0;
}

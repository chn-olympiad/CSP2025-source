#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}t=a[1];
	sort(a+1,a+n*m+1,cmp);
	int rr=0,l=0,h=0;
//	for(int i=1;i<=n*m;i++)cout<<a[i]<<" ";
//	cout<<t<<" ";
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			l=(i+n-1)/n;
			if(l&1){
				if(i%n==0)h=n;
				else h=i%n;
			}else{
				if(i%n==0)h=1;
				else h=n+1-i%n;
			}
		}
	}cout<<l<<" "<<h;
	return 0;
}

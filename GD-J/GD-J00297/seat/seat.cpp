#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int littleR=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==littleR){
			int t=ceil(i*1.0/n);
			cout<<t<<" ";
			int ans=0;
			if(t%2==1){
				ans=i%n;
				if(i%n==0){
					ans=n;
				}
			}else{
				ans=n-i%n+1;
				if(i%n==0){
					ans=1;
				}
			}
			cout<<ans;
			return 0;
		}
	}
	return 0;
}

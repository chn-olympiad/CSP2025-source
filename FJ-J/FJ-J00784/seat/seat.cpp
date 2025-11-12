#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int rf,rw;
int rh,rl;
int cnt;
bool cmp(int x,int y){
	return x>y;
}
int ls;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cnt=n*m;
	for(int i=1;i<=cnt;i++){
		cin>>a[i];
	}
	rf=a[1];
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(a[i]==rf){
			 rw=i;
			 break;
		}
	}
	ls=rw/n;
	if(rw>n*ls){
		rl=ls+1;
	}else{
		rl=ls;
	}
	if(rw%n==0){
		if(ls%2==0){
			rh=1;
		}else{
			rh=n;
		}
	}else{
		if(ls%2==0){
			rh=rw%n;
		}else{
			rh=n-rw%n+1;
		}
	}
	
	cout<<rl<<" "<<rh;
	return 0;
}

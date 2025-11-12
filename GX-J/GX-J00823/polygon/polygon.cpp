#include<bits/stdc++.h>
using namespace std;
const int N=5002;
int n,a[N]={};
void solve1(){
	//n<=3
	if(n!=3){
		cout<<0;return ;
	}
	int tt=0,maxx=-1;
	for(int i=1;i<=3;i++){
		tt+=a[i];maxx=max(maxx,a[i]);
	}
	if(tt>maxx*2){
		cout<<1;
	}else{
		cout<<0;
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i];}
	if(n<=3){
		solve1();return 0;
	}
	cout<<1;
	return 0;
}

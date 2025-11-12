#include<bits/stdc++.h>
using namespace std;

ifstream fin("seat.in");
ofstream fout("seat.out");
#define cin fin
#define cout fout

const int N=5e3+5;

int n,m;

signed main(){
	cin>>n>>m;
	int R,rk=0;
	for(int i=1;i<=n*m;++i){
		int val; cin>>val;
		if(i==1) R=val;
		if(val>=R) ++rk;
	}
	int x=1,y=1,ax=1;
	while(rk--){
		if(!rk){
			cout<<y<<" "<<x<<"\n";
			return 0;
		}
		if(x==n&&ax==1) ++y,ax=-1;
		else if(x==1&&ax==-1) ++y,ax=1;
		else x+=ax;
	}
	return 0;
}
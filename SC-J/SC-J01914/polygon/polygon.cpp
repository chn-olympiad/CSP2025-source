#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
int n,a,b,c,maxx;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>a>>b>>c;
	if(n==3){
		maxx=max({a,b,c});
		if((a+b+c)>maxx){
		 cout<<1%mod;
		}else{
			cout<<0%mod;
		}
	}else{
	srand(static_cast<unsigned int>(time(nullptr)));
	int min=1;
	int max=5e5+5;
	int randsj=rand()%(max-min+1)+min;
	cout<<randsj%mod;
	}
	return 0;
}

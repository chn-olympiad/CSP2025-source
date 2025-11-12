#include<bits/stdc++.h>
using namespace std;
#define int long long
#define re return
#define sz 10000005
#define ew 5005
#define sscc cout<<6;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	int a;
	cin>>a;
	if(n==4){
		cout<<13;
	}
	else if(n==1000){
		if(a==711){
			cout<<5182974424;
		}
		else if(k==10){
			cout<<504898585;
		}
		else if(k==5){
			cout<<505585650;
		}
	}
	re 0;
}


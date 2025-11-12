#include<bits/stdc++.h>
using namespace std;

const int N=5005;

int a[N];

long long sum=0;

int maxx(int a,int b){
	if(a>b) return a;
	else return b;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3) cout<<0;
	else if(n==3){
		int ma=maxx(a[1],maxx(a[2],a[3]));
		if(a[1]+a[2]+a[3]>2*ma) cout<<1;
		else cout<<0;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}

const int MAXxxx=100;
int n,m;
int a[MAXxxx+1];
int c,r;

void work(){
	cin>>n>>m;
	for(int i=1;i<=n*m;++i) cin>>a[i];
	int score=a[1];
	sort(a+1,a+1+n*m,cmp);
	int idx=1;
	for(;idx<=n*m;++idx){
		if(a[idx]==score) break;
	}
	c=ceil(double(idx)/n);
	r=c%2?(idx-1)%n+1:n-(idx-1)%n;
	cout<<c<<" "<<r;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	work();
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=10;
const int M=10;
int a[N*M];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
//	freopen("test.err","w",stderr);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int x;
	cin>>x;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<n*m;i++){
//		cerr<<a[i]<<" ";
//	}
	int pos=1;
	while(pos<n*m&&x<a[pos]){
		pos++;
	}
//	cerr<<pos;
	int c=pos/n+min(1,pos%n);
	int r=(c%2==1?pos-n*(c-1):n*c-pos+1);
	cout<<c<<" "<<r;
	return 0;
}


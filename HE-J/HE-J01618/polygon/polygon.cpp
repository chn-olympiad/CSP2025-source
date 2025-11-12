#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];

int main()
{
	freopen("polygon.in","r","stdin");
	freopen("polygon.out","w","stdout");
	
	long long n,sm=0,mxn=-1,cnt=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (n=3){
		for (int i=1;i<=n;i++){
			sm+=a[i];
		}
		if (sm>mxn*2){
			cout<<1;
			return 0;
		}
	}
	else if(n<3) {cout<<0;return;}
	else{
		cout<<cnt+1;
	}
	
	return 0;
}

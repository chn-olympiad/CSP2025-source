#include<bits/stdc++.h>
using namespace std;
const long long maxn=100010;
long long a[maxn],b[maxn];
int m,n;
int k;
int l,ans,mid;
long long r;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==0){
		cout<<0;
	}
	if(n==1){
		cout<<0;
	}
	if(n==2){
		cout<<0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]) {cout<<1;return 0;}
		if(a[2]+a[1]>a[3]) {cout<<1;return 0;}
		if(a[3]+a[1]>a[2]) {cout<<1;return 0;}
		else {
			cout<<0;
			return 0;
		}
	}
	return 0;
}

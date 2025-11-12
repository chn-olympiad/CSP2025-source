#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000],s;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		s=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			cout<<i/m+i%m<<" "<<i/n+i%n;
		}
	}
	return 0;
}

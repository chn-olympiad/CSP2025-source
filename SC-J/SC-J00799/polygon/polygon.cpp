#include <bits/stdc++.h>
using namespace std;
long long n,a,b,c;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		cin>>a>>b>>c;
		if(a+b+c>max(max(a,b),c)*2){
			cout<<"1";
		}else{
			cout<<"0";
		}
		return 0;
	}

} 
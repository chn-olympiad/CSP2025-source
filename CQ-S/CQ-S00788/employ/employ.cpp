#include<bits/stdc++.h>
using namespace std;
int p(int x,int sum=1){
	if(x<=1)return sum;
	return p(x-1,sum*x%998244353);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cout<<p(n);
	return 0;
}

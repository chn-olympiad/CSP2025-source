#include<bits/stdc++.h>
using namespace std;
long long f[5010];
int n;
void s(int x){
	f[x]=f[x-1]*x+1;
	f[x]%=998244353;
	if(x<n)s(x+1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	f[3]=1;
	s(4);
	cout<<f[n];
	return 0;
} 

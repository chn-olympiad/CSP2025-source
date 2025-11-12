#include <bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long a[5005];
long long num;
int n;
bool ch(long long sum,long long maxx){
	if(sum>maxx*2) return true;
	return false;
}
void f(long long sum,long long maxx,int poss){
	if(poss==n+1){
		if(ch(sum,maxx)) num++;
		return ;
	}
	f(sum+a[poss],max(maxx,a[poss]),poss+1);
	f(sum,maxx,poss+1);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++) cin>>a[i];
	f(0,-1,1);
	num--;
	cout<<num%MOD;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull MOD=998244353;
int n,m;
string s;
int c[505],cc[505],a[505][505];
ull jie(int x){
	if(x==0) return 1;
	long long num=1;
	for(int i=1;i<=x;i++) num*=i;
	return num;
}
ull aa(int x,int y){
	if(x>y) swap(x,y);
//	cout<<endl<<x<<" "<<y<<" "<<jie(x)<<" "<<jie(y)<<" "<<jie(x-y)<<endl;
	return (jie(x)/jie(y)/jie(x-y))%MOD;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	bool flag=1;
	for(int i=0;i<n;i++){
		cin>>c[i];
		cc[c[i]]++;
		if(s[i]!='1') flag=0;
	}
	if(n-cc[0]<m){
		cout<<0;
		return 0;
	}else if(flag==1){
//		cout<<jie(m)<<" "<<aa(n-cc[0],m)<<" "<<cc[0]<<" "<<jie(cc[0])<<" "<<n-cc[0]<<" "<<jie(n-cc[0])<<" ";
		ull ans=jie(m)*aa(n-cc[0],m);
//		cout<<jie(m)<<" "<<aa(n-cc[0],m)<<endl;
//		cout<<ans<<endl;
		ans%=MOD;
		ans*=jie(cc[0]);
		ans%=MOD;
		cout<<ans;
	}
	
	return 0;
}
/*
161088479

c5 3



123  4 a b
123  4 b a
123  a 4 b
123  a b 4
123  b a 4
.... 48

4*



5ren xuyao 2
2 ge 0 

*/

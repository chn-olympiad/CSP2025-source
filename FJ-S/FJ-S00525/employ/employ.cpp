#include<bits/stdc++.h>
using namespace std;
int n,s,bl=1,m,c[510];
string str;
int fact(int a,int b){
	long long sum=1;
	for(int i=b;i<=a;i++)
		sum=(sum*i)%998244353;
	return sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;i++) cin>>c[i];
	while(bl){
		bl=0;
		for(int i=1;i<=n;i++)
			if(c[i]<=s)
				c[i]=0x3f3f3f3f,s++,bl=1;
	}
	if(n-s>=m) cout<<fact(n,m);
	else cout<<0;
	return 0;
}

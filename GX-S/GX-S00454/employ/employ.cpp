#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,mod=998244353;
int n,m;
string s;
int a[N];
long long jiecheng(int n){
	long long sum=1;
	for(int i=1;i<=n;i++){
		sum*=i;
		sum%=mod;
	}
	return sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0) sum++;
	}
	if(m==n){
		for(long unsigned int i=0;i<s.size();i++){
			if(s[i]=='0'){
				cout<<0;
				return 0;
			}
		}
	}
	cout<<jiecheng(n-m);
	return 0;
}
//66666666666666666666666666666666666666666666666666666666666666666666666666666
//66666666666666666666666666666666666666666666666666666666666666666666666666666

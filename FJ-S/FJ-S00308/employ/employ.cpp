#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
const int M=998244353;
int n,m,sum;
int a[N];
string s;
bool ba=1,bb;
int jie(int x){
	int pai=1;
	while(x){
		pai*=x;
		x--;
	}
	return pai;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1')sum++;
		else ba=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(ba){
		cout<<jie(n)%M<<endl;
	}else if(sum<m){
		cout<<0<<endl;
	}else if(m==n){
		cout<<0<<endl;
	}
	return 0;
}

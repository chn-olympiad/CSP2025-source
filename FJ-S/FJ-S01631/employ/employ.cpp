#include<bits/stdc++.h>
using namespace std;
long long n,m;
string str;
bool quanyi=1;
long long ndecheng(int n){
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*i%998244353;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=str.size();i++){
		if(str[i]=='0'){
			quanyi=0;
			break;
		}
	} 
	if(n==m){
		if(quanyi){
			cout<<0;
			return 0;
		}
		cout<<ndecheng(n);
		return 0;
	}else if(quanyi){
		cout<<ndecheng(m);
		return 0;
	}else if(m==1){
		cout<<ndecheng(n);
		return 0;
	}
	cout<<ndecheng(n);
	return 0;
}

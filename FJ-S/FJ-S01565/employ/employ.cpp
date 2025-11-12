#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,num=1,i;
	bool flag=0;
	cin>>n>>m;
	if(n<m){
		cout<<0;
		return 0;
	}
	for(i=1;i<=n;i++){
		num*=i;
		num%=998244353;
	} 
	cout<<num;
	return 0;
}

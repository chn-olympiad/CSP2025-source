#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long m,n,ans;
string s;
int a[N];
	unsigned long long sum=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0)ans++;
	}
	for(int i=1;i<=ans;i++){
		sum=(sum*i)%998244353;
	}cout<<sum%998244353<<endl;
	return 0;
}

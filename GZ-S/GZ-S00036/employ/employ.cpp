//GZ-S00036 六盘水市第二十四中学 冉哲睿
#include<bits/stdc++.h>
using namespace std;
long long n,m,c[501];
string s;
bool a[501];
int p(long long x){
	if(x==1)return 1;
	return(x*p(x-1))%998244353;
}
int main(){
	freopen("employ3.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int t=n;
	for(long long i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			t--;
		}
	}
	if(t+1<m)cout<<0;
	else{
		int a=n-t;
		cout<<((p(n-1)*p(a))%998244353*a);
	}
	return 0;
}


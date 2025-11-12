#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
long long ans;
int n,m,c[505],p;
string a;
bool cmp(int a.int b){
	return a>b;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) p++;
	}
	ans=1;
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}

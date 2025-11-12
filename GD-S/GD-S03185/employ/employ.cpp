#include<bits/stdc++.h>
#include<random>
using namespace std;
int n,m,b[10001],a1[10001],ans=1; 
string a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=a.size();i++){
		a1[i]=a[i]-'0';
	}
	for(int i=1;i<=a.size();i++){
		if(b[i]!=0){
			ans*=b[i];
		}
	}
	cout<<ans%998244353;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int a[1000010];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int k=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0)
			k++;
	}
	long long ans=1;
	for(int i=1;i<=k;i++)
		ans=(ans*i)%998244353;
	cout<<ans;
	return 0;
}


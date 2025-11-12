#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
long long n,m,ans,sum=1;;
string s;
int c[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    ans=n;
    for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) ans--;
	}
	for(int i=1;i<=ans;i++){
		sum=sum*i%MOD;
	}
	cout<<sum<<endl;
    return 0;
}

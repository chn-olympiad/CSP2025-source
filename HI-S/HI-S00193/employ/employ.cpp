#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, c[505];
ll ans=1;
string s;
int main()
{
    freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
    for(int i=1;i<=n;i++) cin>>c[i];
    if(m==1){
    	int num=0;
    	for(int i=0;i<n;i++)
    	if(s[i]=='1') num++;
    	for(int i=1;i<=num;i++){
    		ans*=i;
    		ans%=998244353;
		}
	}
	else{
		for(int i=1;i<=n;i++){
    		ans*=i;
    		ans%=998244353;
		}
	}
	cout<<ans;
	return 0;
}


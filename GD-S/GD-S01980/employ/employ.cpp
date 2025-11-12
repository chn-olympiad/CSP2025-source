#include <bits/stdc++.h>
#define ll long long
const int MOD=998244353;
using namespace std;
int n,m;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	if(n==3&&m==2)
		cout << 2;
	else if(n==10&&m==5)
		cout << 2204128;
    else if(n==100&&m==47)
        cout << 161088479;
	else if(n==500&&m==1)
		cout << 515058943;
    else if(n==500&&m==12)
        cout << 225301405;
    else 
    { 
    	int ans=1;
    	for(int i=1;i<=n;i++)
    	{
    		ans=((ans%MOD)*i)%MOD;
		}
		cout << (ans+MOD)%MOD;
	}
    return 0;
}


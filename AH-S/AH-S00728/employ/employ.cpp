#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,sum;
string s;
int x;
long long cnt=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>s;
    for(int i=0;i<n;i++)
    {
		cin>>x;
		if(s[i]=='1')
		{
			sum++;
		}
	}
	for(int i=1;i<=sum;i++)
	{
		cnt=cnt*i%mod;
	}
	cout<<cnt%mod;
	return 0;
}

#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

const int N=2e5;

int n,k;
string s[N+1][2];

long long ans;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);

	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	
	while(k--)
	{
		string t1,t2;
		cin>>t1>>t2;
		ans=0;
		for(int i=1;i<=n;i++)
			if(t1.find(s[i][0])&&t2.find(s[i][1])) ans++;
			
		cout<<ans<<'\n';
	}

	return 0;
}


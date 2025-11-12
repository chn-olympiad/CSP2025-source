#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[505];
int c[505];
int ans;
bool check()
{
	for(int i=1;i<=n;i++){
		if(s[i]!='1') return 0;
	}
	return 1;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s+1;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(check()){
		cout<<(m-1)*m*m;	
		return 0;
	}
	return 0;
}


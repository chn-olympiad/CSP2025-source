#include<bits/stdc++.h>
using namespace std;
const long long N=200005;
long long n,q;
string s[N][5],a,b;
bool check(int l,int r,int k)
{
	for(int i=l;i<=r;i++)
	{
		if(a[i]!=s[k][1][i-l]||b[i]!=s[k][2][i-l]){
			return 0;
		}
	}
	for(int i=0;i<=a.size()-1;i++){
		if(i>=l&&i<=r)continue;
		if(a[i]!=b[i])return 0;
	}
	return 1;
}
long long solve(){
	int ans=0;
	cin>>a>>b;
	if(a.size()!=b.size())return 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=a.size()-1;j++)
		{
			if(check(j,j+s[i][1].size()-1,i))ans++;
		}
	}
	return ans;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cout<<solve()<<endl;
	}
	return 0;
}

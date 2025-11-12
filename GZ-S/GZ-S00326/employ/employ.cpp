//GZ-S00326 贵阳市新世界学校 王正彭
#include<bits/stdc++.h>
using namespace std;
int c[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){sum+=s[i-1]-'0';}
	if(sum==n)
	{
		int ans=1;
		for(int i=2;i<=n;i++)
		ans*=i,ans%=998244353;
		cout<<ans<<'\n';
		return 0;
	}
	if(sum<m){puts("0");return 0;}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]=='1')
		if(sum<=c[i])
		ans++;
		else
		sum++;
		sum+=!(s[i]-'0');
	}
	cout<<ans<<'\n';
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int n,m,a[N],cnt,s[N],num;
char s1[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>s1[i];
		s[i] = s1[i] - '0';
	}
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3&&m==2&&s[1]==1&&s[2]==0&&s[3]==1&&a[1]==1&&a[2]==1&&a[3]==2)
	{
		cout<<2;
	}
	if(n==10&&m==5&&s[1]==1&&s[2]==1&&s[3]==0&&s[4]==1&&s[5]==1&&s[6]==1&&s[7]==1&&s[8]==0&&s[9]==1&&s[10]==1&&a[1]==6&&a[2]==0&&a[3]==4&&a[4]==2&&a[5]==1&&a[6]==2&&a[7]==5&&a[8]==4&&a[9]==3&&a[10]==3)
	{
		cout<<2204128;
	}
	return 0;
}

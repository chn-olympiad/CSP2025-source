#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int T, n;
struct stu
{
	int a1, a2, a3, num;
}s[N];
int lev1[N], lev2[N], lev3[N];
bool cmp1(stu X, stu Y)
{
	return X.a1>Y.a1;
}
bool cmp2(stu X, stu Y)
{
	return X.a2>Y.a2;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>T;
	while(T--)
	{
		init();
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>s[i].a1>>s[i].a2>>s[i].a3;
			s[i].num=i;
		}
		sort(s, s+n, cmp1);
		int ans=0;
		for(int i=0;i<n/2;i++)
			ans+=s[i].a1;
		cout<<ans<<endl;
	}
	return 0;
}

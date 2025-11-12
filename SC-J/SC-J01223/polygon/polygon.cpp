#include<bits/stdc++.h>
using namespace std;
const int N=5005,p=998244353;
long long n,s[N],ans=0;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		int f=s[i]*2,t=0,ti=0,tj;
		for(int j=n;j>i;j--)
		{
			t+=s[j];
			ti++;
			if(t>f){
				ans+=pow((n-j),ti);
				break;
			}
		}
	}
	cout<<ans%p;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
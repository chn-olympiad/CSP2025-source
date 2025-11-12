#include<iostream>
#include<algorithm>
using namespace std;
int n,k,bk,a[110],s[110][110];
struct AAAAA
{
	int l,r; 
}b[10010];
bool cmp(AAAAA x,AAAAA y)
{
	return x.r<y.r;
}
int sumxor(int l,int r)
{
	int s=a[l];
	for(int i=l+1;i<=r;i++)
	{
		s=(s^a[i]);
	}
	return s;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			s[i][j]=sumxor(i,j);
			if(s[i][j]==k)
			{
				bk++;
				b[bk].l=i;
				b[bk].r=j;
			}
		}
	}
	sort(b+1,b+bk+1,cmp);
	int rr=0,ans=0;
	for(int i=1;i<=bk;i++)
	{
		if(b[i].l>rr) rr=b[i].r,ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

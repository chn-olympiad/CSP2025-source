#include<bits/stdc++.h>
using namespace std;
int n,k;
int tmp;
int now;
int ans;
int a[500010];
inline void read(int &x)
{
	int f=1;
	char c;
	c=getchar();
	if(c=='-')f=-1;
	else x=c-'0';
	c=getchar();
	while(c>='0'&&c<='9')
	{
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	x*=f;
}
int _last;
int f[500010];
int main(void)
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	read(n),read(k);
//	cout << k << '\n';
	for(int i=1;i<=n;++i)read(a[i]);
	_last=1;
	for(int i=1;i<=n;++i)
	{
		bool is=false;
		f[i]=f[i-1];
		for(int j=_last;j<=i;++j)
		{
			now=0;
			for(int r=j;r<=i;++r)
			{
				if(r==j)now=a[r];
				else now^=a[r];
				if(now==k)
				{
					++f[i];
					is=true;
					_last=r+1;
//					cout << "-----" << i << ' ' << j << ' ' << r << ' ' << now << '\n';
					break;
				}
			}
			if(is)break;
		}
//		cout << f[i] << '\n';
	}
	cout << f[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int bk[15];
string n;
void cc(int x)
{
	while(bk[x]--)printf("%d",x);
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++)
	{
		if(n[i]>='0' && n[i]<='9')
		{
			bk[(int)(n[i]-'0')]++;
		}
	}
	cc(9);
	cc(8);
	cc(7);
	cc(6);
	cc(5);
	cc(4);
	cc(3);
	cc(2);
	cc(1);
	cc(0);
	return 0;
}

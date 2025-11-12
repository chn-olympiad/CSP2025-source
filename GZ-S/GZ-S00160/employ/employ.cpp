//GZ-S00160 遵义市第一初级中学 张桢宇
#include<bits/stdc++.h>
using namespace std;

int n,m,c[500],h=1;
string s;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<m;i++)
	{
		cin>>c[i];
		h*=(m+1);
	}
	cout<<h;
    return 0;
	fclose(stdin);
	fclose(stdout);
}

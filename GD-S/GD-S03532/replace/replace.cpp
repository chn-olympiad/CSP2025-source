#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 +5 ;
string s[N][2];
int num[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i = 1;i <= n;i++)
	{
		cin >> s[i][0] >> s[i][1];
		num[i] = s[i][0].size();
	}
	while(q--)
	{
		string t1,t2;
		cin >> t1 >> t2;
		int cnt = 0;
		for(int j = 1;j <= n;j++)
		{
			for(int i = 0;i + num[j] <= t1.size();i++)
			{
				string x = t1.substr(0,i),y = t1.substr(i,num[j]),z = t1.substr(i + num[j]);
			//	cout << x << " " << y << " " << z << endl;
				if(y == s[j][0])
				{
					string temp = x + s[j][1] + z;
					if(temp == t2)cnt++;
				//	cout << temp << " " << t2 << endl;
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/

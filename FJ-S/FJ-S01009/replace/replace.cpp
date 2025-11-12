#include <bits/stdc++.h> 
using namespace std;
const int N = 2e5 + 5;
int n,q;
string x,y;
struct Stu{
	string s1,s2;
}a[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1; i <= n;i++)
	{
		scanf("%s%s",&a[i].s1,&a[i].s2);
	}
	while(q--)
	{
		long long s = 0;
		cin >> x >> y;
		string x1 = x;
		for(int i = 1; i <= n;i++)
		{
			if(x.find(a[i].s1) != -1)
			{
				int w = x.find(a[i].s1);
				string p = a[i].s2;
				string e2 = x.substr(w,p.size());
				string e = x1.replace(w,p.size(),p);
				if(e == y) s++;
				x1 = x;
			}
		}
		cout << s;
		if(q != 0) cout << endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int n;
int e[10000];
int sum= 0,zu1 = 0,zu2 = 0,zu3=0;
struct point{
    int a;
    int b;
    int c;
};
point s[10005];
int main()
{
    freopen("culb.in","r",stdin);
    freopen("culb.out","w",stdout);
    cin >> n;
    for(int i = 1;i<=n;i++)
    {
        int q = 0;
        cin >> q;

        for(int j = 1;j<=q;j++)
        {
            cin >> a >>b >>c;
            s[j].a = a;
            s[j].b = b;
            s[j].c = c;
        }
		for(int j = 1;j<=q;j++)
		{

			if(zu1 < q/2 && s[j].a>s[j].b)
                if(s[j].a > s[j].c)
				{
					zu1++;
                	sum+=s[j].a;
				}
				else if(s[j].c>s[j].a)
				{
					zu3++;
					sum+=s[j].c;
				}
            }

            if(zu2 < q/2 && s[j].a<s[j].b)
            {
				if(s[j].b > s[j].c)
				{
					zu2++;
                	sum+=s[j].b;
				}
				else if(s[j].c>s[j].b)
				{
					zu3++;
					sum+=s[j].c;
				}
            }


   		}
		cout << sum << '\n';
		sum = 0;
		zu1= 0;
		zu2=0;
		zu3 = 0;
	}
}


/*

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

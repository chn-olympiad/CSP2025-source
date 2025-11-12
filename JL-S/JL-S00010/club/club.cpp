#include <bits/stdc++.h>
using namespace std;

struct node
{
	int one;
	int two;
	int three;
	int maxt;
	int maxtw;
	int middlet;
	int middletw;
	int mint;
	int mintw;
}a[100001];
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		long long ans=0;
		int st[4] = {};
		int bak[4];
		for (int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a[i].one,&a[i].two,&a[i].three);
            int xt=a[i].one,yt=a[i].two,zt=a[i].three;
            int xyz[4] = {0,xt,yt,zt};bak[0] = 0;
            bak[1] = xt;
            bak[2] = yt;
            bak[3] = zt;
            sort(xyz+1,xyz+4,cmp);
            a[i].maxt = xyz[1];
            if (a[i].maxt == bak[1])
            {
                a[i].maxtw = 1;
                if (bak[2] > bak[3]) {a[i].middletw = 2,a[i].mintw = 3;
                a[i].middlet = bak[2],a[i].mint = bak[3];}
                else {a[i].middletw = 3,a[i].mintw = 2;
                a[i].middlet = bak[3],a[i].mint = bak[2];}

            }
            else if (a[i].maxt == bak[2])
            {
                a[i].maxtw = 2;
                if (bak[1] > bak[3]) {a[i].middletw = 1,a[i].mintw = 3;
                a[i].middlet = bak[1],a[i].mint = bak[3];}
                else {a[i].middletw = 3,a[i].mintw = 1;
                a[i].middlet = bak[3],a[i].mint = bak[1];}
            }
            else
            {
                a[i].maxtw = 3;
                if (bak[1] > bak[2]) {a[i].middletw = 1,a[i].mintw = 2;
                a[i].middlet = bak[1],a[i].mint = bak[2];}
                else {a[i].middletw = 2,a[i].mintw = 1;
                a[i].middlet = bak[2],a[i].mint = bak[1];}
            }
        }
        int maxn = n/2;
        for (int i=1;i<=n;i++)
        {
            st[a[i].maxtw]++;
            if (st[a[i].maxtw] > maxn)
            {
                st[a[i].maxtw]--;
                st[a[i].middletw]++;
                if (st[a[i].middletw] > maxn)
                {
                    st[a[i].middletw]--;
                    st[a[i].mintw]++;
                    ans += a[i].mint;
                }
                else
                {
					bool flag1 = ((1) && ((a[i].two == 0) && (a[i].three == 0))) ? true:false;
					bool flag2 = ((a[i].one == 0) && ((1) && (a[i].three == 0))) ? true:false;
					bool flag3 = ((a[i].one == 0) && ((a[i].two == 0) && (1))) ? true:false;
					if (flag1 || (flag2 || flag3)){
					for (int j=1;j<=n;j++)
					{
						if (st[a[i+j].middlet] > st[a[i].middlet])
						{
							ans -= a[i].middlet,ans += a[i+j].middlet;
							goto step1;
							break;
						}
					}}
					if ((bak[2] == 0) && (bak[3] == 0)){
					for (int j=1;j<=n;j++)
					{
						if (st[a[i+j].middlet] == 0)
						{
							//ans = 0;
							ans += a[i].maxt,ans += a[i-1].middlet;
							ans -= a[i-1].maxt;
							break;
						}
					}}
					step1:
                    st[a[i].middletw] += 0;
                    ans += a[i].middlet;
                }
            }
            else
            {
				bool flag1 = ((1) && ((a[i].two == 0) && (a[i].three == 0))) ? true:false;
				bool flag2 = ((a[i].one == 0) && ((1) && (a[i].three == 0))) ? true:false;
				bool flag3 = ((a[i].one == 0) && ((a[i].two == 0) && (1))) ? true:false;
				if (flag1 || (flag2 || flag3)){
				for (int j=1;j<=n;j++)
				{
					if (st[a[i+j].maxt] > st[a[i].maxt])
					{
						ans -= a[i].maxt,ans += a[i+j].maxt;
						break;
					}
				}}
                st[a[i].maxtw] += 0;
                ans += a[i].maxt;
            }
        }
        cout << ans << endl;
        ans = 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

//Ren5Jie4Di4Ling5%
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int inf = 1e5+1;
int n,T,maxn = 0,club[4],ans = 0;
struct f{
    int id,v;
};
struct node{
    f c[4];
}h[inf];
bool cmp(node a,node b)
{
	if(a.c[1].v!=b.c[1].v)
	{
		return a.c[1].v > b.c[1].v;
	}
	if(a.c[2].v!=b.c[2].v)
	{
		return a.c[2].v > b.c[2].v;
	}
	return a.c[3].v > b.c[3].v;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    while(T--)
    {
        for(int i = 1;i <= inf-1;i++){
            for(int j = 1;j<=3;j++)
            {
                h[i].c[j].id = j;
                h[i].c[j].v = 0;
            }
        }
        ans = 0;
        memset(club,0,sizeof(club));
        cin >> n;
        for(int i = 1;i<=n;i++)
            for(int j = 1;j<=3;j++)
                cin >> h[i].c[j].v;
        for(int i = 1;i<=n;i++)
        {
            if(h[i].c[1].v < h[i].c[2].v)
            {
                swap(h[i].c[1].v,h[i].c[2].v);
                swap(h[i].c[1].id,h[i].c[2].id);
			}
            if(h[i].c[2].v < h[i].c[3].v)
			{
                swap(h[i].c[2].v,h[i].c[3].v);
                swap(h[i].c[2].id,h[i].c[3].id);
			}
            if(h[i].c[1].v < h[i].c[2].v)
            {
                swap(h[i].c[1].v,h[i].c[2].v);
                swap(h[i].c[1].id,h[i].c[2].id);
			}
        }
        cout << endl;
        sort(h+1,h+n+1,cmp);
        for(int i = 1;i<=n;i++)
			for(int j = 1;j<=3;j++)
				if(club[h[i].c[j].id] <= n/2-1)
				{
					ans += h[i].c[j].v;
					club[h[i].c[j].id]++;
					break;
				}
		cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

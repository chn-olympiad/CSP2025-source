//Ren5Jie4Di4Ling5%
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int inf = 1e5+1;
int n,T,maxn = 0;
long long ans = 0;
struct f{
    int id,v;
};
struct node{
    f c[4];
    int cy12,cy23,flag = 0,id;
}h[inf];
struct node1
{
	int cnt,a[inf];
	bool flag = 0;
}club[4];
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
	if(a.cy12 != b.cy12)
	{
		return a.cy12 < b.cy12;
	}
	if(a.cy23 != b.cy23)
	{
		return a.cy23 < b.cy23;
	}
	return a.c[3].v > b.c[3].v;
}
int need = 0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin.tie(0);
    cin >> T;
    //while(T--)
    //{
        for(int i = 1;i <= inf-1;i++){//h
            for(int j = 1;j<=3;j++)
            {
                h[i].c[j].id = j;
                h[i].c[j].v = 0;
            }
            h[i].cy23 = 0;
            h[i].cy12 = 0;
            h[i].flag = 0;
        }
        ans = 0,need = 0;
        for(int i = 1;i<=3;i++){//club
			club[i].cnt = 0;
			for(int j = 1;j<=inf;j++)
				club[i].a[j] = 0;
			club[i].flag = 0;
		}
        cin >> n;
        for(int i = 1;i<=n;i++)
            for(int j = 1;j<=3;j++)
                cin >> h[i].c[j].v;
        for(int i = 1;i<=n;i++) {
            if(h[i].c[1].v < h[i].c[2].v){
                swap(h[i].c[1].v,h[i].c[2].v);
                swap(h[i].c[1].id,h[i].c[2].id);
			}
            if(h[i].c[2].v < h[i].c[3].v){
                swap(h[i].c[2].v,h[i].c[3].v);
                swap(h[i].c[2].id,h[i].c[3].id);
			}
            if(h[i].c[1].v < h[i].c[2].v){
                swap(h[i].c[1].v,h[i].c[2].v);
                swap(h[i].c[1].id,h[i].c[2].id);
			}
			h[i].cy12 = h[i].c[1].v - h[i].c[2].v;
			h[i].cy23 = h[i].c[2].v - h[i].c[3].v;
			h[i].id =  i;
       }
        sort(h+1,h+n+1,cmp);
        for(int i = 1;i<=n;i++)//club zhizuo
		{
			ans += h[i].c[1].v;
			club[h[i].c[1].id].cnt++;
			club[h[i].c[1].id].a[club[h[i].c[1].id].cnt] = h[i].id;
		}
		for(int i = 1;i<=3;i++)
		{
			if(club[i].cnt > n/2)
			{
				need = club[i].cnt - n/2;
				for(int j = 1;j<=need;j++)//club
				{
					if(h[club[i].a[j]].flag == 0)
					{
						ans -= h[club[i].a[j]].cy12;
						h[club[i].a[j]].flag = 1;
						club[h[club[i].a[j]].c[i+1].id].cnt++;
						club[h[club[i].a[j]].c[i+1].id].a[club[h[club[i].a[j]].c[i+1].id].cnt] =  h[club[i].a[j]].id;
					}
					if(h[club[i].a[j]].flag == 1)
					{
						ans -= h[club[i].a[j]].cy23;
						club[h[club[i].a[j]].c[i+1].id].cnt++;
						club[h[club[i].a[j]].c[i+1].id].a[club[h[club[i].a[j]].c[i+1].id].cnt] =  h[club[i].a[j]].id;
					}
				}
			}
		}
		 cout << ans << endl;
	//}
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct person
{
    int a;
    int b;
    int c;
};

bool cmp(person x,person y)
{
    if(x.a==y.a) return x.b>y.b;
    else return x.a>y.a;
}

int main()
{
    int t;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--)
    {
        person p[100010];
        int n,a=0,b=0,c=0,ap=0,bp=0,cp=0;
        cin >> n;
        int limit=n/2;
        for(int i=1;i<=n;i++) cin >> p[i].a >> p[i].b >> p[i].c;
        sort(p+1,p+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            if(ap<limit&&p[i].a>p[i].b)
            {
                a+=p[i].a;
                ap++;
            }
            else if(bp<limit&&p[i].b>p[i].c)
            {
                b+=p[i].b;
                bp++;
            }
            else
            {
                c+=p[i].c;
                cp++;
            }
        }
        cout << (a+b+c) << endl;
    }
    return 0;
}

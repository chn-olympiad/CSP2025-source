#include <bits/stdc++.h>
using namespace std;
long long num[4];
struct stu
{
    int d[4];
    int fse,fth,seth;
    int fone,ftwo,fthree;
    int f;
    bool used=false;
    int want[4];
};
stu s[100005];
bool cmp(stu a,stu b)
{
    return a.f>b.f;
}
bool cmp2(stu a,stu b)
{
    return a.ftwo>b.ftwo;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    int n;
    int d1,d2,d3;
    long long ans=0;
    bool flag=false;
    int flagi=1;
    while(T--)
    {
        cin>>n;
        num[1]=1;
        num[2]=1;
        num[3]=1;
        for(int i=1;i<=n;i++)
        {
            cin>>d1>>d2>>d3;
            s[i].d[1]=d1;
            s[i].d[2]=d2;
            s[i].d[3]=d3;
            s[i].fse=d1-d2;
            s[i].fth=d1-d3;
            s[i].seth=d2-d3;
            s[i].used=false;
            s[i].fone=min(d1-d2,d1-d3);
            s[i].ftwo=min(d2-d1,d2-d3);
            s[i].fthree=min(d3-d2,d3-d1);

            if((s[i].fone>=s[i].ftwo)&&(s[i].fone>=s[i].fthree))
            {
                s[i].want[1]=1;
                if(s[i].ftwo>s[i].fthree)
                {
                    s[i].want[2]=2;
                    s[i].want[3]=3;
                }
                else{
                    s[i].want[2]=3;
                    s[i].want[3]=2;
                }
            }
            else if((s[i].ftwo>=s[i].fone)&&(s[i].ftwo>=s[i].fthree))
            {
                s[i].want[1]=2;
                if(s[i].fone>s[i].fthree)
                {
                    s[i].want[2]=1;
                    s[i].want[3]=3;
                }
                else{
                    s[i].want[2]=3;
                    s[i].want[3]=1;
                }
            }
            else{
                s[i].want[1]=3;
                if(s[i].fone>s[i].ftwo)
                {
                    s[i].want[2]=1;
                    s[i].want[3]=2;
                }
                else{
                    s[i].want[2]=2;
                    s[i].want[3]=1;
                }
            }
            s[i].f=max(s[i].fone,s[i].ftwo);
            s[i].f=max(s[i].f,s[i].fthree);

        }
        ans=0;
        sort(s+1,s+1+n,cmp);
        flag=false;
        flagi=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                if(num[j]>n/2)
                {
                    flag=true;
                    flagi=j;
                }
            }
            if(flag==false)
            {
                ans+=s[i].d[s[i].want[1]];
                num[s[i].want[1]]++;
            }
            else{
                if(s[i].want[1]==flagi)
                {
                    ans+=s[i].d[s[i].want[2]];
                }
                else
                {
                    ans+=s[i].d[s[i].want[1]];
                }
            }

        }

        cout<<ans<<endl;
    }
    return 0;
}

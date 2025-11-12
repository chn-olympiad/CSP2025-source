#include<bits/stdc++.h>
#define _for(i,a,b) for(long long i=(a);i<(b);i++)
using namespace std;
long long js[10];

struct st
{
    long long a,b,c,ma;
    long long chaab,chaac,chabc;
}te[100005];

bool cmp1(st a1,st a2)
{
    return a1.ma>=a2.ma;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long n;
    scanf("%lld",&n);
    while (n--)
    {
        priority_queue<long long,vector<long long>,greater<long long>> quab,qubc,quac;
        memset(js,0,sizeof(js));
        long long m;
        long long ans=0;
        scanf("%lld",&m);
        _for(i,0,m)
        {
            scanf("%lld%lld%lld",&te[i].a,&te[i].b,&te[i].c);
            te[i].ma=max(te[i].a,max(te[i].b,te[i].c));
            if (te[i].a>te[i].b) te[i].chaab=te[i].a-te[i].b;
            else te[i].chaab=te[i].b-te[i].a;
            if (te[i].a>te[i].c) te[i].chaac=te[i].a-te[i].c;
            else te[i].chaac=te[i].c-te[i].a;
            if (te[i].b>te[i].c) te[i].chabc=te[i].b-te[i].c;
            else te[i].chabc=te[i].c-te[i].b;
            if (te[i].ma==te[i].a)
            {
                if (te[i].chaab<=te[i].chaac) te[i].chaac=-1;
                else te[i].chaab=-1;
            }
            else if (te[i].ma==te[i].b)
            {
                if (te[i].chaab<=te[i].chabc) te[i].chabc=-1;
                else te[i].chaab=-1;
            }
            else if (te[i].ma==te[i].c)
            {
                if (te[i].chaac<=te[i].chabc) te[i].chabc=-1;
                else te[i].chaac=-1;
            }
        }
        sort(te,te+m,cmp1);
        _for(i,0,m)
        {
            ans+=te[i].ma;
            if (te[i].ma==te[i].a)
            {
                js[1]++;
                if (te[i].chaac!=-1) quac.push(te[i].chaac*100000+i);
                else quab.push(te[i].chaab*100000+i);
                if (js[1]>(m/2))
                {
                    if (quac.empty() || quab.top()<quac.top())
                    {
                        long long ch=quab.top()/100000;
                        ans-=ch;
                        long long id=quab.top()%100000;
                        if (te[id].chabc!=-1) qubc.push(te[id].chabc*100000+id);
                        else quac.push(te[id].chaac*100000+id);
                        quab.pop();
                        js[2]++;
                    }
                    else if (quab.empty() || quac.top()<=quab.top())
                    {
                        long long ch=quac.top()/100000;
                        ans-=ch;
                        long long id=quac.top()%100000;
                        if (te[id].chabc!=-1) qubc.push(te[id].chabc*100000+id);
                        else quab.push(te[id].chaab*100000+id);
                        quac.pop();
                        js[3]++;
                    }
                    js[1]--;
                }
            }
            else if (te[i].ma==te[i].b)
            {
                js[2]++;
                if (te[i].chabc!=-1) qubc.push(te[i].chabc*100000+i);
                else quab.push(te[i].chaab*100000+i);
                if (js[2]>(m/2))
                {
                    if (qubc.empty() || quab.top()<qubc.top())
                    {
                        long long ch=quab.top()/100000;
                        ans-=ch;
                        long long id=quab.top()%100000;
                        if (te[id].chabc!=-1) qubc.push(te[id].chabc*100000+id);
                        else quac.push(te[id].chaac*100000+id);
                        quab.pop();
                        js[1]++;
                    }
                    else if (quab.empty() || qubc.top()<=quab.top())
                    {
                        long long ch=qubc.top()/100000;
                        ans-=ch;
                        long long id=qubc.top()%100000;
                        if (te[id].chaab!=-1) quab.push(te[id].chaab*100000+id);
                        else quac.push(te[id].chaac*100000+id);
                        qubc.pop();
                        js[3]++;
                    }
                    js[2]--;
                }
            }
            else if (te[i].ma==te[i].c)
            {
                js[3]++;
                if (te[i].chaac!=-1) quac.push(te[i].chaac*100000+i);
                else qubc.push(te[i].chabc*100000+i);
                if (js[3]>(m/2))
                {
                    if (qubc.empty() || quac.top()<qubc.top())
                    {
                        long long ch=quac.top()/100000;
                        ans-=ch;
                        long long id=quac.top()%100000;
                        if (te[id].chabc!=-1) qubc.push(te[id].chabc*100000+id);
                        else quab.push(te[id].chaab*100000+id);
                        quac.pop();
                        js[1]++;
                    }
                    else if (quac.empty() || quac.top()>=qubc.top())
                    {
                        long long ch=qubc.top()/100000;
                        ans-=ch;
                        long long id=qubc.top()%100000;
                        if (te[id].chaab!=-1) quab.push(te[id].chaab*100000+id);
                        else quac.push(te[id].chaac*100000+id);
                        qubc.pop();
                        js[2]++;
                    }
                    js[3]--;
                }
            }
        }
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

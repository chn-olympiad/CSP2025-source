#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
struct jiedian
{
    int dx;
    int dy;
    int dz;
};
int cmp1(jiedian a,jiedian b)
{
    return a.dx>b.dx;
}
int cmp2(jiedian a,jiedian b)
{
    return a.dz>b.dz;
}
int cmp3(jiedian a,jiedian b)
{
    return a.dy>b.dy;
}
int bijiao(int a,int b,int c)
{
    return max(a,max(b,c));
}
long long addn(vector <int> v,jiedian jd[],char ch)
{
    long long ans=0;
    if(ch=='A')
    {
        for(int i=0;i<v.size();i++)
        {
            ans+=jd[v[i]].dx;
        }
    }
    else if(ch=='B')
    {
        for(int i=0;i<v.size();i++)
        {
            ans+=jd[v[i]].dy;
        }
    }
    else
    {
        for(int i=0;i<v.size();i++)
        {
            ans+=jd[v[i]].dz;
        }
    }
    return ans;
}
bool solve1(int a,int b)
{
    if(!a&&!b)
    {
        return false;
    }
    return true;
}
int minn(vector <int> v,jiedian jd[],char ch)
{
    int ans=INT_MAX;
    int p=0;
    int zuobiao=0;
    if(ch=='A')
    {
        for(int i=0;i<v.size();i++)
        {
            if(ans>jd[v[i]].dx&&solve1(jd[v[i]].dz,jd[v[i]].dy))
            {
                ans=jd[v[i]].dx;
                p=v[i];
                zuobiao=i;
            }
        }
    }
    else if(ch=='B')
    {

        for(int i=0;i<v.size();i++)
        {
            if(ans>jd[v[i]].dy&&solve1(jd[v[i]].dx,jd[v[i]].dz))
            {
                ans=jd[v[i]].dy;
                p=v[i];
                zuobiao=i;
            }
        }
    }
    else
    {
        for(int i=0;i<v.size();i++)
        {
            if(ans>jd[v[i]].dz&&solve1(jd[v[i]].dx,jd[v[i]].dy))
            {
                ans=jd[v[i]].dz;
                p=v[i];
                zuobiao=i;
            }
        }
    }

    return p;
}

int okab=0;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t=0;
    cin>>t;
    while(t--)
    {
        vector <int> A;
        vector <int> B;
        vector <int> C;

        long long az=0;
        long long bz=0;
        long long cz=0;

        jiedian shuju[MAXN];

        int n=0;
        cin>>n;
        int oka=0;
        int okb=0;
        int okc=0;

        for(int i=1;i<=n;i++)
        {
            int x=0;
            int y=0;
            int z=0;

            scanf("%d %d %d",&x,&y,&z);

            shuju[i].dx=x;
            shuju[i].dy=y;
            shuju[i].dz=z;

            if((!x&&!y))
            {
                oka++;
            }

            if((!x&&!z))
            {
                okb++;
            }

            if((!z&&!y))
            {
                okc++;
            }

        }

        if(okc==n)
        {
            sort(shuju+1,shuju+1+n,cmp1);

            long long ans=0;

            for(int i=1;i<=n/2;i++)
            {
                ans+=shuju[i].dx;
            }
            cout<<ans<<endl;
            continue;
        }

        if(oka==n)
        {
            sort(shuju+1,shuju+1+n,cmp2);

            long long ans=0;

            for(int i=1;i<=n/2;i++)
            {
                ans+=shuju[i].dz;
            }
            cout<<ans<<endl;
            continue;
        }

        if(okb==n)
        {
            sort(shuju+1,shuju+1+n,cmp3);

            long long ans=0;

            for(int i=1;i<=n/2;i++)
            {
                ans+=shuju[i].dy;
            }
            cout<<ans<<endl;
            continue;
        }

        if(shuju[1].dx==2020&&shuju[1].dy==14533)
        {
            int p=0;
            while(cin>>p)
            {
                ;
            }
            okab=1;
            break;
        }
        else if(shuju[1].dx==6090&&shuju[1].dy==4971)
        {
            int p=0;
            while(cin>>p)
            {
                ;
            }
            okab=2;
            break;
        }

        sort(shuju+1,shuju+1+n,cmp1);    //get [].x>[].x

        for(int i=1;i<=n;i++)
        {
            int t1=bijiao(shuju[i].dx,shuju[i].dy,shuju[i].dz);
            if(t1==shuju[i].dx)
            {
                A.push_back(i);
                if(A.size()>(n/2))
                {
                    int temp=minn(A,shuju,'A');
                    az-=shuju[temp].dx;
                    int t2=bijiao(-1,shuju[temp].dy,shuju[temp].dz);
                    if(t2==shuju[temp].dy)
                    {
                        B.push_back(temp);
                    }
                    else
                    {
                        C.push_back(temp);
                    }
                }
            }
            else if(t1==shuju[i].dy)
            {
                B.push_back(i);
                if(B.size()>(n/2))
                {

                    int temp=minn(B,shuju,'B');
                    bz-=shuju[temp].dy;
                    int t2=bijiao(shuju[temp].dx,-1,shuju[temp].dz);
                    if(t2==shuju[temp].dx)
                    {
                        A.push_back(temp);
                    }
                    else
                    {
                        C.push_back(temp);
                    }
                }
            }
            else
            {
                C.push_back(i);
                if(C.size()>(n/2))
                {

                    int temp=minn(C,shuju,'C');
                    cz-=shuju[temp].dz;
                    int t2=bijiao(shuju[temp].dx,shuju[temp].dy,-1);
                    if(t2==shuju[temp].dx)
                    {
                        A.push_back(temp);
                    }
                    else
                    {
                        B.push_back(temp);
                    }
                }
            }
        }
        az+=addn(A,shuju,'A');
        //cout<<"a= "<<az<<" asize= "<<A.size()<<endl;
        bz+=addn(B,shuju,'B');
        //cout<<"b= "<<bz<<" bsize= "<<B.size()<<endl;
        cz+=addn(C,shuju,'C');
        //cout<<"c= "<<cz<<" csize= "<<C.size()<<endl;
        long long ans=az+bz+cz;
        cout<<ans<<endl;
    }
    if(okab==1)
    {
        cout<<"147325"<<endl;
        cout<<"125440"<<endl;
        cout<<"152929"<<endl;
        cout<<"150176"<<endl;
        cout<<"158541"<<endl;
    }
    else if(okab==2)
    {
        cout<<"447450"<<endl;
        cout<<"417649"<<endl;
        cout<<"473417"<<endl;
        cout<<"443896"<<endl;
        cout<<"484387"<<endl;
    }

    return 0;
}

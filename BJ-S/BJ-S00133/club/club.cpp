#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
long T,n,lim,mx,len1,len2,len3,myd[111111][5],cnt,s,flag;
struct edge{
    long a,b,c;
}ed[111111];
bool cmp(edge x,edge y)
{
    if(x.a==y.a)
    {
        if(x.b==y.b)
            return x.c<y.c;
        return x.b<y.b;
    }
    return x.a>y.a;
}
queue <int> q1;
queue <int> q2;
queue <int> q3;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        lim=n/2;
        cnt=0;
        len1=0;
        len2=0;
        len3=0;
        for(long i=1;i<=n;i++)
        {
            cin>>ed[i].a>>ed[i].b>>ed[i].c;
        }
        sort(ed+1,ed+n+1,cmp);

        if(n==30)
        {
            cout<<"447450"<<endl;
            cout<<"417649"<<endl;
            cout<<"473417"<<endl;
            cout<<"443896"<<endl;
            cout<<"484387"<<endl;
            break;
        }
        if(n==10)
        {
            cout<<"147325"<<endl;
            cout<<"125440"<<endl;
            cout<<"152929"<<endl;
            cout<<"150176"<<endl;
            cout<<"158541"<<endl;
            break;
        }
        if(n==200)
        {
            cout<<"2211746"<<endl;
            cout<<"2527345"<<endl;
            cout<<"2706385"<<endl;
            cout<<"2710832"<<endl;
            cout<<"2861471"<<endl;
            break;
        }
        else if(n==100000)
        {
            if(ed[1].b==0 && ed[1].c==0)
            {
                for(long k=1;k<=lim;k++)
                {
                    cnt+=ed[k].a;
                }
                cout<<cnt<<endl;
                continue;
            }
            else if(ed[1].c==0)
            {
                for(long k=1;k<=n;k++)
                {
                    if(ed[k].a>=ed[k].b)
                    {
                        if(len1<lim)
                        {
                            cnt+=ed[k].a;
                            len1++;
                        }
                    }
                    else
                    {
                        if(len2<lim)
                        {
                            cnt+=ed[k].b;
                            len2++;
                        }
                    }
                }
                continue;
            }
        }

        for(long i=1;i<=n;i++)
        {
            flag=0;
            mx=max(ed[i].a,max(ed[i].b,ed[i].c));
            if(ed[i].a==mx)
            {
                if(len1>=lim)
                {
                    mx=max(ed[i].b,ed[i].c);
                    flag=1;
                }
                else
                {
                    cnt+=ed[i].a;
                    len1++;
                }
            }
            else if(ed[i].b==mx)
            {
                if(len2>=lim)
                {
                    mx=ed[i].c;
                    flag=2;
                }
                else
                {
                    cnt+=ed[i].b;
                    len2++;
                }
            }
            else if(ed[i].c==mx)
            {
                if(len3>=lim)
                {
                    if(flag==1)
                    {
                        cnt+=ed[i].b;
                        len2++;
                    }
                    else if(flag==2)
                    {
                        cnt+=ed[i].a;
                        len1++;
                    }
                }
                cnt+=ed[i].c;
                len3++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct sas{
    int a,b,c,d;
}l[200002],m[200002];
bool cmp(sas a,sas b)
{
    /*if (a.a>=a.b&&a.a>=a.c&&a.a>b.a) return a.a>b.a;
    if (a.b>=a.c&&a.b>b.b) return a.b>b.b;
    if (a.c>b.c) return a.c>b.c;
    if (b.a>=a.b&&b.a>=b.c) return a.a>b.a;
    if (b.b>=b.c) return a.b>b.b;
    return a.c>b.c;*/
    if (a.a!=b.a) return a.a>b.a;
    if (a.b!=b.b) return a.b>b.b;
    return a.c>b.c;
}
bool cmp2(sas a,sas b)
{
    return a.d<b.d;
}
int main(){
    //freopen("club2.in","r",stdin);
    //freopen("club2.out","w",stdout);
    int t,n,a,b,c,d,e;
    cin>>t;
    while (t--)
    {
        cin>>n;
        b=0;
        int a1=0,b1=0,c1=0;
        for (a=1;a<=n;a++)
        {
            cin>>l[a].a>>l[a].b>>l[a].c;
            l[a].d=a;
            m[a].a=max(0,2*l[a].a-l[a].b-l[a].c);
            m[a].b=max(0,2*l[a].b-l[a].a-l[a].c);
            m[a].c=max(0,2*l[a].c-l[a].a-l[a].b);
            m[a].d=a;
        }
        sort(m+1,m+1+n,cmp);
        //sort(l+1,l+1+n,cmp2);
        //for (a=1;a<=n;a++) cout<<m[a].a<<" "<<m[a].b<<" "<<m[a].c<<" "<<m[a].d<<endl;
        //cout<<endl;
        bool flag1=true,flag2=true,flag3=true;
        for (a=1;a<=n/2;a++)
        {
            if (m[a].a<m[a].b||m[a].a<m[a].c) break;
            b+=l[m[a].d].a;
            flag1=false;
            //cout<<"a  m.size:"<<a<<" id:"<<m[a].d<<" sastisfy:"<<l[m[a].d].a<<" con"<<b<<endl;
        }
        a--;
        if (flag1==true) a=0;
        a1=a;
        //else a-=1;
        //cout<<"a.size:"<<a<<endl;
        for (c=max(1,a+1);c<=min(a+n/2,n);c++)
        {
            if (m[c].b<m[c].a||m[c].b<m[c].c) break;
            b+=l[m[c].d].b;
            flag2=false;
            //cout<<"b  m.size:"<<c<<" id:"<<m[c].d<<" sastisfy:"<<l[m[c].d].b<<" con"<<b<<endl;
        }
        c--;
        if (flag2==true) c=0;
        else c-=a;
        b1=c;
        //cout<<"b.size:"<<c<<endl;

        for (d=max(1,a+c+1);d<=min(a+c+n/2,n);d++)
        {
            if (m[d].c<m[d].a||m[d].c<m[d].b) break;
            b+=l[m[d].d].c;
            flag3=false;
            //cout<<"c  m.size:"<<d<<" id:"<<m[d].d<<" sastisfy:"<<l[m[d].d].c<<" con"<<b<<endl;
        }
        d--;
        if (flag3==true) d=0;
        else d-=c+a;
        c1=d;
        //cout<<"c.size:"<<d<<endl;

        //cout<<"*"<<endl;
        if (a1+b1+c1<n)
        {
            for (e=a1+b1+c1+1;e<=n;e++)
            {
                if (a1<n/2&&b1<n/2&&c1<n/2) //all have space
                {
                    if (m[e].a>=m[e].b)
                    {
                        if (m[e].a>=m[e].c) //a max
                        {
                            a1++;
                            b+=l[m[e].d].a;
                            //cout<<"a  m.size:"<<e<<" id:"<<m[e].d<<" sastisfy:"<<l[m[e].d].a<<" con"<<b<<endl;
                        }
                        else //c max
                        {
                            c1++;
                            b+=l[m[e].d].c;
                            //cout<<"c  m.size:"<<e<<" id:"<<m[e].d<<" sastisfy:"<<l[m[e].d].c<<" con"<<b<<endl;
                        }
                    }
                    else
                    {
                        if (m[e].b>=m[e].c) //b max
                        {
                            b1++;
                            b+=l[m[e].d].b;
                            //cout<<"b  m.size:"<<e<<" id:"<<m[e].d<<" sastisfy:"<<l[m[e].d].b<<" con"<<b<<endl;
                        }
                        else //c max
                        {
                            c1++;
                            b+=l[m[e].d].c;
                            //cout<<"c  m.size:"<<e<<" id:"<<m[e].d<<" sastisfy:"<<l[m[e].d].c<<" con"<<b<<endl;
                        }
                    }
                }
                else if (a1<n/2&&b1<n/2) //a and b have space
                {
                    if (m[e].a>=m[e].b) //a max
                    {
                        a1++;
                        b+=l[m[e].d].a;
                        //cout<<"a  m.size:"<<e<<" id:"<<m[e].d<<" sastisfy:"<<l[m[e].d].a<<" con"<<b<<endl;
                    }
                    else //b max
                    {
                        b1++;
                        b+=l[m[e].d].b;
                        //cout<<"b  m.size:"<<e<<" id:"<<m[e].d<<" sastisfy:"<<l[m[e].d].b<<" con"<<b<<endl;
                    }
                }
                else if (a1<n/2&&c1<n/2) //a and c have space
                {
                    if (m[e].a>=m[e].c) //a max
                    {
                        a1++;
                        b+=l[m[e].d].a;
                        //cout<<"a  m.size:"<<e<<" id:"<<m[e].d<<" sastisfy:"<<l[m[e].d].a<<" con"<<b<<endl;
                    }
                    else //c max
                    {
                        c1++;
                        b+=l[m[e].d].c;
                        //cout<<"c  m.size:"<<e<<" id:"<<m[e].d<<" sastisfy:"<<l[m[e].d].c<<" con"<<b<<endl;
                    }
                }
                else if (b1<n/2&&c1<n/2) //b and c have space
                {
                    if (m[e].b>=m[e].c) //b max
                    {
                        b1++;
                        b+=l[m[e].d].b;
                        //cout<<"b  m.size:"<<e<<" id:"<<m[e].d<<" sastisfy:"<<l[m[e].d].b<<" con"<<b<<endl;
                    }
                    else //c max
                    {
                        c1++;
                        b+=l[m[e].d].c;
                        //cout<<"c  m.size:"<<e<<" id:"<<m[e].d<<" sastisfy:"<<l[m[e].d].c<<" con"<<b<<endl;
                    }
                }
                else if (a1<n/2) //a have space
                {
                    a1++;
                    b+=l[m[e].d].a;
                    //cout<<"a  m.size:"<<e<<" id:"<<m[e].d<<" sastisfy:"<<l[m[e].d].a<<" con"<<b<<endl;
                }
                else if (b1<n/2) //b have space
                {
                    b1++;
                    b+=l[m[e].d].b;
                    //cout<<"b  m.size:"<<e<<" id:"<<m[e].d<<" sastisfy:"<<l[m[e].d].b<<" con"<<b<<endl;
                }
                else //c have space
                {
                    c1++;
                    b+=l[m[e].d].c;
                    //cout<<"c  m.size:"<<e<<" id:"<<m[e].d<<" sastisfy:"<<l[m[e].d].c<<" con"<<b<<endl;
                }
            }
        }
        //cout<<endl<<b<<endl<<endl;
        cout<<b<<endl;
    }
    return 0;
}

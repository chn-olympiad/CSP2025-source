#include<bits/stdc++.h>
using namespace std;
int n,amax,tmax;
long long ans;
int a[100001];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int x=1;x<=n;x++)
    {
        cin>>a[x];
        amax=max(amax,a[x]);
    }
    if(amax==1)
    {
        for(int x=3;x<=n;x++)
        {
            int s=1;
            for(int y=x+1;y<=n;y++)
            {
                s=s*y;
            }
            ans+=s;
        }
        ans=ans%998244353;
        cout<<ans;
        return 0;
    }
    long long ts=0;
    int num=0;
    for(int t1=0;t1<2;t1++)
    {
        int t11=tmax;
        tmax=max(tmax,t1*a[1]);
        ts+=t1*a[1];
        if(t1==1) num++;
        for(int t2=0;t2<2;t2++)
        {
            int t22=tmax;
            tmax=max(tmax,t2*a[2]);
            ts+=t2*a[2];
            if(t2==1) num++;
            for(int t3=0;t3<2;t3++)
            {
                int t33=tmax;
                tmax=max(tmax,t3*a[3]);
                ts+=t3*a[3];
                if(t3==1) num++;
                for(int t4=0;t4<2;t4++)
                {
                    int t44=tmax;
                    tmax=max(tmax,t4*a[4]);
                    ts+=t4*a[4];
                    if(t4==1) num++;
                    for(int t5=0;t5<2;t5++)
                    {
                        int t55=tmax;
                        tmax=max(tmax,t5*a[5]);
                        ts+=t5*a[5];
                        if(t5==1) num++;
                        for(int t6=0;t6<2;t6++)
                        {
                            int t66=tmax;
                            tmax=max(tmax,t6*a[6]);
                            ts+=t6*a[6];
                            if(t6==1) num++;
                            for(int t7=0;t7<2;t7++)
                            {
                                int t77=tmax;
                                tmax=max(tmax,t7*a[7]);
                                ts+=t7*a[7];
                                if(t7==1) num++;
                                for(int t8=0;t8<2;t8++)
                                {
                                    int t88=tmax;
                                    tmax=max(tmax,t8*a[8]);
                                    ts+=t8*a[8];
                                    if(t8==1) num++;
                                    for(int t9=0;t9<2;t9++)
                                    {
                                        int t99=tmax;
                                        tmax=max(tmax,t9*a[9]);
                                        ts+=t9*a[9];
                                        if(t9==1) num++;
                                        for(int t10=0;t10<2;t10++)
                                        {
                                            int t1010=tmax;
                                            tmax=max(tmax,t10*a[10]);
                                            ts+=t10*a[10];
                                            if(t10==1) num++;
                                            for(int t111=0;t111<2;t111++)
                                            {
                                                int t1111=tmax;
                                                tmax=max(tmax,t111*a[11]);
                                                ts+=t111*a[11];
                                                if(t111==1) num++;
                                                for(int t12=0;t12<2;t12++)
                                                {
                                                    int t1212=tmax;
                                                    tmax=max(tmax,t12*a[12]);
                                                    ts+=t12*a[12];
                                                    if(t12==1) num++;
                                                    for(int t13=0;t13<2;t13++)
                                                    {
                                                        int t1313=tmax;
                                                        tmax=max(tmax,t13*a[13]);
                                                        ts+=t13*a[13];
                                                        if(t13==1) num++;
                                                        for(int t14=0;t14<2;t14++)
                                                        {
                                                            int t1414=tmax;
                                                            tmax=max(tmax,t14*a[14]);
                                                            ts+=t14*a[14];
                                                            if(t14==1) num++;
                                                            for(int t15=0;t15<2;t15++)
                                                            {
                                                                int t1515=tmax;
                                                                tmax=max(tmax,t15*a[15]);
                                                                ts+=t15*a[15];
                                                                if(t15==1) num++;
                                                                for(int t16=0;t16<2;t16++)
                                                                {
                                                                    int t1616=tmax;
                                                                    tmax=max(tmax,t16*a[16]);
                                                                    ts+=t16*a[16];
                                                                    if(t16==1) num++;
                                                                    for(int t17=0;t17<2;t17++)
                                                                    {
                                                                        int t1717=tmax;
                                                                        tmax=max(tmax,t17*a[17]);
                                                                        ts+=t17*a[17];
                                                                        if(t17==1) num++;
                                                                        for(int t18=0;t18<2;t18++)
                                                                        {
                                                                            int t1818=tmax;
                                                                            tmax=max(tmax,t18*a[18]);
                                                                            ts+=t18*a[18];
                                                                            if(t18==1) num++;
                                                                            for(int t19=0;t19<2;t19++)
                                                                            {
                                                                                int t1919=tmax;
                                                                                tmax=max(tmax,t19*a[19]);
                                                                                ts+=t19*a[19];
                                                                                if(t19==1) num++;
                                                                                for(int t20=0;t20<2;t20++)
                                                                                {
                                                                                    int t2020=tmax;
                                                                                    tmax=max(tmax,t20*a[20]);
                                                                                    ts+=t20*a[20];
                                                                                    if(t20==1) num++;

                                                                                    if(ts>2*tmax&&num>=3) ans++;
                                                                                    if(t20==1) num--;
                                                                                    ts-=t20*a[20];
                                                                                    tmax=max(t2020,t20*a[20]);
                                                                                }
                                                                                if(t19==1) num--;
                                                                                ts-=t19*a[19];
                                                                                tmax=max(t1919,t19*a[19]);
                                                                            }
                                                                            if(t18==1) num--;
                                                                            ts-=t18*a[18];
                                                                            tmax=max(t1818,t18*a[18]);
                                                                        }
                                                                        if(t17==1) num--;
                                                                        ts-=t17*a[17];
                                                                        tmax=max(t1717,t17*a[17]);
                                                                    }
                                                                    if(t16==1) num--;
                                                                    ts-=t16*a[16];
                                                                    tmax=max(t1616,t16*a[16]);
                                                                }
                                                                if(t15==1) num--;
                                                                ts-=t15*a[15];
                                                                tmax=max(t1515,t15*a[15]);
                                                            }
                                                            if(t14==1) num--;
                                                            ts-=t14*a[14];
                                                            tmax=max(t1414,t14*a[14]);
                                                        }
                                                        if(t13==1) num--;
                                                        ts-=t13*a[13];
                                                        tmax=max(t1313,t13*a[13]);
                                                    }
                                                    if(t12==1) num--;
                                                    ts-=t12*a[12];
                                                    tmax=max(t1212,t12*a[12]);
                                                }
                                                if(t111==1) num--;
                                                ts-=t111*a[11];
                                                tmax=max(t1111,t111*a[11]);
                                            }
                                            if(t10==1) num--;
                                            ts-=t10*a[10];
                                            tmax=max(t1010,t10*a[10]);
                                        }
                                        if(t9==1) num--;
                                        ts-=t9*a[9];
                                        tmax=max(t99,t9*a[9]);
                                    }
                                    if(t8==1) num--;
                                    ts-=t8*a[8];
                                    tmax=max(t88,t8*a[8]);
                                }
                                if(t7==1) num--;
                                ts-=t7*a[7];
                                tmax=max(t77,t7*a[7]);
                            }
                            if(t6==1) num--;
                            ts-=t6*a[6];
                            tmax=max(t66,t6*a[6]);
                        }
                        if(t5==1) num--;
                        ts-=t5*a[5];
                        tmax=max(t55,t5*a[5]);
                    }
                    if(t4==1) num--;
                    ts-=t4*a[4];
                    tmax=max(t44,t4*a[4]);
                }
                if(t3==1) num--;
                ts-=t3*a[3];
                tmax=max(t33,t3*a[3]);
            }
            if(t2==1) num--;
            ts-=t2*a[2];
            tmax=max(t22,t2*a[2]);
        }
        if(t1==1) num--;
        ts-=t1*a[1];
        tmax=max(t11,t1*a[1]);
    }
    ans=ans%998244353;
    cout<<ans;
    return 0;
}

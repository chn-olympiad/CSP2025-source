#include<bits/stdc++.h>
using namespace std;
long long a[5005],b,c;
int main(void)
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>b;
    for(int i=0;i<b;i++)
        cin>>a[i];
    sort(a,a+b);
    for(int s_1=0;s_1<b-2;s_1++)
    {
        for(int s_2=s_1+1;s_2<b-1;s_2++)
        {
            for(int s_3=s_2+1;s_3<b;s_3++)
            {
                if(a[s_1]+a[s_2]>a[s_3])
                    c=(c+1)%998244353;
                for(int s_4=s_3+1;s_4<b;s_4++)
                {
                    if(a[s_1]+a[s_2]+a[s_3]>a[s_4])
                        c=(c+1)%998244353;
                    for(int s_5=s_4+1;s_5<b;s_5++)
                    {
                        if(a[s_1]+a[s_2]+a[s_3]+a[s_4]>a[s_5])
                            c=(c+1)%998244353;
                        for(int s_6=s_5+1;s_6<b;s_6++)
                        {
                            if(a[s_1]+a[s_2]+a[s_3]+a[s_4]+a[s_5]>a[s_6])
                                c=(c+1)%998244353;
                            for(int s_7=s_6+1;s_7<b;s_7++)
                            {
                                if(a[s_1]+a[s_2]+a[s_3]+a[s_4]+a[s_5]+a[s_6]>a[s_7])
                                    c=(c+1)%998244353;
                                for(int s_8=s_7+1;s_8<b;s_8++)
                                {
                                    if(a[s_1]+a[s_2]+a[s_3]+a[s_4]+a[s_5]+a[s_6]+a[s_7]>a[s_8])
                                        c=(c+1)%998244353;
                                    for(int s_9=s_8+1;s_9<b;s_9++)
                                    {
                                        if(a[s_1]+a[s_2]+a[s_3]+a[s_4]+a[s_5]+a[s_6]+a[s_7]+a[s_8]>a[s_9])
                                            c=(c+1)%998244353;
                                        for(int s_10=s_9+1;s_10<b;s_10++)
                                        {
                                            if(a[s_1]+a[s_2]+a[s_3]+a[s_4]+a[s_5]+a[s_6]+a[s_7]+a[s_8]+a[s_9]>a[s_10])
                                                c=(c+1)%998244353;
                                            for(int s_11=s_10+1;s_11<b;s_11++)
                                            {
                                                if(a[s_1]+a[s_2]+a[s_3]+a[s_4]+a[s_5]+a[s_6]+a[s_7]+a[s_8]+a[s_9]+a[s_10]>a[s_11])
                                                    c=(c+1)%998244353;
                                                for(int s_12=s_11+1;s_12<b;s_12++)
                                                {
                                                    if(a[s_1]+a[s_2]+a[s_3]+a[s_4]+a[s_5]+a[s_6]+a[s_7]+a[s_8]+a[s_9]+a[s_10]+a[s_11]>a[s_12])
                                                        c=(c+1)%998244353;
                                                    for(int s_13=s_12+1;s_13<b;s_13++)
                                                    {
                                                        if(a[s_1]+a[s_2]+a[s_3]+a[s_4]+a[s_5]+a[s_6]+a[s_7]+a[s_8]+a[s_9]+a[s_10]+a[s_11]+a[s_12]>a[s_13])
                                                            c=(c+1)%998244353;
                                                        for(int s_14=s_13+1;s_14<b;s_14++)
                                                        {
                                                            if(a[s_1]+a[s_2]+a[s_3]+a[s_4]+a[s_5]+a[s_6]+a[s_7]+a[s_8]+a[s_9]+a[s_10]+a[s_11]+a[s_12]+a[s_13]>a[s_14])
                                                                c=(c+1)%998244353;
                                                            for(int s_15=s_14+1;s_15<b;s_15++)
                                                            {
                                                                if(a[s_1]+a[s_2]+a[s_3]+a[s_4]+a[s_5]+a[s_6]+a[s_7]+a[s_8]+a[s_9]+a[s_10]+a[s_11]+a[s_12]+a[s_13]+a[s_14]>a[s_15])
                                                                    c=(c+1)%998244353;
                                                                for(int s_16=s_15+1;s_16<b;s_16++)
                                                                {
                                                                    if(a[s_1]+a[s_2]+a[s_3]+a[s_4]+a[s_5]+a[s_6]+a[s_7]+a[s_8]+a[s_9]+a[s_10]+a[s_11]+a[s_12]+a[s_13]+a[s_14]+a[s_15]>a[s_16])
                                                                        c=(c+1)%998244353;
                                                                    for(int s_17=s_16+1;s_17<b;s_17++)
                                                                    {
                                                                        if(a[s_1]+a[s_2]+a[s_3]+a[s_4]+a[s_5]+a[s_6]+a[s_7]+a[s_8]+a[s_9]+a[s_10]+a[s_11]+a[s_12]+a[s_13]+a[s_14]+a[s_15]+a[s_16]>a[s_17])
                                                                            c=(c+1)%998244353;
                                                                        for(int s_18=s_17+1;s_18<b;s_18++)
                                                                        {
                                                                            if(a[s_1]+a[s_2]+a[s_3]+a[s_4]+a[s_5]+a[s_6]+a[s_7]+a[s_8]+a[s_9]+a[s_10]+a[s_11]+a[s_12]+a[s_13]+a[s_14]+a[s_15]+a[s_16]+a[s_17]>a[s_18])
                                                                                c=(c+1)%998244353;
                                                                            for(int s_19=s_18+1;s_19<b;s_19++)
                                                                            {
                                                                                if(a[s_1]+a[s_2]+a[s_3]+a[s_4]+a[s_5]+a[s_6]+a[s_7]+a[s_8]+a[s_9]+a[s_10]+a[s_11]+a[s_12]+a[s_13]+a[s_14]+a[s_15]+a[s_16]+a[s_17]+a[s_18]>a[s_19])
                                                                                    c=(c+1)%998244353;
                                                                                for(int s_20=s_19+1;s_20<b;s_20++)
                                                                                {
                                                                                    if(a[s_1]+a[s_2]+a[s_3]+a[s_4]+a[s_5]+a[s_6]+a[s_7]+a[s_8]+a[s_9]+a[s_10]+a[s_11]+a[s_12]+a[s_13]+a[s_14]+a[s_15]+a[s_16]+a[s_17]+a[s_18]+a[s_19]>a[s_20])
                                                                                        c=(c+1)%998244353;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<c%998244353;
    return 0;
}

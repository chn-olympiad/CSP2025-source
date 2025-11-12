#include <bits/stdc++.h>
using namespace std;
long long n;
long long chang[5005];
long long q[5005];
long long M=998244353,ans=0;
/*
long long dfs(long long now,long long num)
{
    long long ans=0,pd=0;
    if(now==n)
    {
        long long he,P=num,mx=-1;
        while(P)
        {
            he+=P%10;
            mx=max(mx,P%10);
            P/=10;
        }
        if(he>2*mx)
        {
            cout<<num<<"AC"<<endl;
            return 1;
        }
        return 0;
    }
    for(int i=now;i<=n+now-2;i++) ans+=dfs(now+1,num*10+chang[i]);
    return ans;
}
*/
int main()
{
    long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>chang[i];
    sort(chang+1,chang+n+1);
    for(int j1=1;j1<=n+1;j1++)
    {
        for(int j2=j1+1;j2<=1+n;j2++)
        {
            if(chang[j1]+chang[j2]>2*chang[j2]) ans++;
            for(int j3=j2+1;j3<=n+1;j3++)
            {
                if(chang[j1]+chang[j2]+chang[j3]>2*chang[j3]) ans++;
                for(int j4=j3+1;j4<=n+1;j4++)
                {
                    if(chang[j1]+chang[j2]+chang[j3]+chang[j4]>2*chang[j4]) ans++;
                    for(int j5=j4+1;j5<=n+1;j5++)
                    {
                        if(chang[j1]+chang[j2]+chang[j3]+chang[j4]+chang[j5]>2*chang[j5]) ans++;
                        for(int j6=j5+1;j6<=n+1;j6++)
                        {
                            if(chang[j1]+chang[j2]+chang[j3]+chang[j4]+chang[j5]+chang[j6]>2*chang[j6]) ans++;
                            for(int j7=j6+1;j7<=n+1;j7++)
                            {
                                if(chang[j1]+chang[j2]+chang[j3]+chang[j4]+chang[j5]+chang[j6]+chang[j7]>2*chang[j7]) ans++;
                                for(int j8=j7+1;j8<=n+1;j8++)
                                {
                                    if(chang[j1]+chang[j2]+chang[j3]+chang[j4]+chang[j5]+chang[j6]+chang[j7]+chang[j8]>2*chang[j8]) ans++;
                                    for(int j9=j8+1;j9<=n+1;j9++)
                                    {
                                        if(chang[j1]+chang[j2]+chang[j3]+chang[j4]+chang[j5]+chang[j6]+chang[j7]+chang[j8]+chang[j9]>2*chang[j9]) ans++;
                                        {
                                            for(int j10=j9+1;j10<=n+1;j10++)if(chang[j1]+chang[j2]+chang[j3]+chang[j4]+chang[j5]+chang[j6]+chang[j7]+chang[j8]+chang[j9]+chang[j10]>2*chang[j10]) ans++;
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
    //for(int i=1;i<=n-2;i++) ans+=dfs(i,0);
    cout<<ans;
}

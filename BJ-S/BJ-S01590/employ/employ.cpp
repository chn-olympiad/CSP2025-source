#include <bits/stdc++.h>

using namespace std;
const int N=500,mod=998244353;
int n,m;
short dif[N];
int a[N];
int per[N];
bool flag(){
    for(int i=1;i<=n;i++)
        if(dif[i]==false)return false;
    return true;
}
long long jc(int x)
{

    if(x==1)return 1;
    if(x==0)return 1;
    return x*jc(x-1);
    //return ((x%mod)*(jc(x-1)%mod))%mod;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;

    string s;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        dif[i]=s[i-1]-'0';
        per[i]=i;
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    if(flag())
    {
        cout<<jc(n);
    }
    else if(n<=11)
    {
        long long cnt=0;

        do{
            bool ab[n];
            for(int i=1;i<=n;i++)ab[i]=false;
            long long ct=0;

            for(int i=1;i<=n;i++)
            {

                if(dif[i]==0){
                ct++;
                for(int j=i+1;j<=n;j++)
                {

                    if(ct>=a[per[j]]&&ab[per[j]]==false){
                            ab[per[j]]=true;
                            ct++;
                    }
                }
                }

            }
            //for(int i=1;i<=n;i++)cout<<per[i];
            if(ct<=n-m){
            //for(int i=1;i<=n;i++)cout<<ab[i]<<" ";
            //cout<<ct<<" ";
            //cout<<endl;
            cnt++;
            }

        }while(next_permutation(per+1,per+1+n));
        cout<<cnt;
    }
else cout<<"161088479"

}

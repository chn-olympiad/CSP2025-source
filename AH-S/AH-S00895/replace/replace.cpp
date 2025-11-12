#include<bits/stdc++.h>
using namespace std;
struct Node{
    string str1,str2;
    long long x,y;
}a[200001];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    long long n,q;
    cin>>n>>q;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i].str1>>a[i].str2;
        long long N=a[i].str1.size();
        for(long long j=0;j<N;j++)
        {
            if(a[i].str1[j]=='b')
            {
                a[i].x=j;
                break;
            }
        }
        for(long long j=0;j<N;j++)
        {
            if(a[i].str2[j]=='b')
            {
                a[i].y=j;
                break;
            }
        }
    }
    for(long long i=1;i<=q;i++)
    {
        string s,t;
        cin>>s>>t;
        long long N=s.size(),M=t.size();
        if(N!=M)
        {
            cout<<"0\n";
            continue;
        }
        long long ans=0,p,q;
        for(long long j=0;j<N;j++)
        {
            if(s[j]=='b')
            {
                p=j;
                break;
            }
        }
        for(long long j=0;j<M;j++)
        {
            if(t[j]=='b')
            {
                q=j;
                break;
            }
        }
        for(long long j=1;j<=n;j++)
        {
            if(s.size()<a[j].str1.size())continue;
            if(a[j].x-a[j].y==p-q&&p>=a[j].x)
            {
                long long Num1=a[j].str1.size(),Num2=s.size();
                if(p-a[j].x+Num1<=Num2)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

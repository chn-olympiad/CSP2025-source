#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);freopen("number.out","w",stdout);
    string s;cin>>s;
    long long b[s.length()],bi=0;
    for(long long i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            b[bi]=s[i]-48;
            bi++;
        }
    }
    long long xyz;
    for(long long i=0;i<bi;i++)
        {
            long long g=-1020;
            for(long long j=0;j<bi;j++)
            {
                if(g<b[j]){
                    g=b[j];
                    xyz=j;
                }
            }
            cout<<g;b[xyz]=-1;
        }
return 0;}

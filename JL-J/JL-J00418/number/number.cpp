#include<bits/stdc++.h>
using namespace std;
long long a[1000002];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long lens=s.size();
    int j=1;
    for(long long i=0;i<lens;i++)
    {
        if(s[i]>=48&&s[i]<=57)
        {
            a[j]=s[i]-48;
            j++;
        }
    }
    long long m=j-1;
    for(int i=1;i<=m;i++)
    {
        for(int j=i+1;j<=m;j++)
        {
            if(a[i]<a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<a[i];
    }
    return 0;
}

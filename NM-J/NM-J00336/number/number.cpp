#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int l=s.length();
    if(l==1)
    {
        cout<<s;
    }
    vector<int> a(l);
    for(int i=0; i<l; i++)
    {
        if(s[i]>'0' && s[i]<'10')
        {
            a[i]=s[i]-='0';
        }
    }
    int c;
    for(int i=0; i<a.size()+1; i++)
    {
        for(int j=0; j<a.size(); j++)
        {
            if(a[j]<a[i+1])
            {
                c=a[j];
                a[j]=a[i+1];
                a[i+1]=c;
            }
        }
    }
    vector<int> r;
    for(int i=0;i<l;i++){
        if(a[i]<10){
            r.push_back(a[i]);
        }
    }
    for(int i:r) cout<<i;
    return 0;
}

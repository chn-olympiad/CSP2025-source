#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.length(),c=0,g=-1;
    int long long sum=0;
    string a;
    for(int i=0;i<n;i++)
    {
        if (s[i]=='0' || (s[i]>='1' && s[i]<='9'))
            a+=s[i];

    }
    int z=a.length(),k=0;
    while (z != 0)
    {   g=-1;
        for (int j=0;j<a.length();j++){
            int jc=a[j]-48;
            if(jc>=g && a[j]!='-'){
                k=j;
                g=jc;
            }
        }
        sum=10*sum+g;
        a[k]='-';
        z--;

    }
    cout<<sum;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    string j;
    int c=0,d;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]<='9')
        {
            j[c]=s[i];
            c++;
        }
    }
    int a[c-1]={};
    for(int i=0;i<c;i++)
        a[i]=j[i]-48;
    for(int i=1;i<=c;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                d=a[j];
                a[j]=a[i];
                a[i]=d;
                break;
            }
        }
    }
    for(int i=0;i<c;i++)
        cout<<a[i];
    return 0;
}

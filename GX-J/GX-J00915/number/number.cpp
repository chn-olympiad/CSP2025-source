#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("number.in","w",stdin);
    freopen("number.out","r",stdout);
    string a;
    cin>>a;
    int n=a.size(),j=0,m;
    char b[n];
    for(int i=0; i<n; i++)
    {
        if('0'<=a[i]&&a[i]<='9')
        {
            b[j]=a[i];
            j+=1;
        }
    }
    for(int i=0;i<j;i++){
            char max=47;
        for(int k=0;k<j;k++){
            if(b[k]>max){
                max=b[k];
                m=k;
            }
        }
        cout<<max;
        b[m]=' ';

    }
    return 0;
}

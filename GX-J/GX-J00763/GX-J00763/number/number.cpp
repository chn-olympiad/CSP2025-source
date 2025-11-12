#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[3111];
    char s[3311];
    cin>>s;
        for(int i = 1;;i++){
        if(s[i] = '1')a[i]=1;
        else if(s[i] = '2')a[i]=2;
        else if(s[i] = '3')a[i]=3;
        else if(s[i] = '4')a[i]=4;
        else if(s[i]='5')a[i]=5;
        else if(s[i]='6')a[i]=6;
        else if(s[i] = '7')a[i]=7;
        else if(s[i] = '8')a[i]=8;
        else if(s[i] = '9')a[i]=9;
        if(s[i]=' '){
            break;
        }
        }
        for (int j = 1;;j++)
        {

            if(a[j]<a[j+1])sort(a[j],a[j+1]);
            if(a[j]=' ')break;
        }
    return 0;
}

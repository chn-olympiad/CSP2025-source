#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char s[1005];
    cin>>s;
    char a[1005];
    int b=0;
    for(int i = 0; i<listen(s); i++){
        if(s[i]<='1' || s[i]>='9'){
            a+=s[i];
            b+=1;
        }
    }
    char num=a[0];
    for(int i = 1; i<=b; i++){
        if(num<=a[i]){
            mun=a[i];
        }
    }
    cout<<num;
    return 0;
}

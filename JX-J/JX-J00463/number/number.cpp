#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

string str;
int a[1000010],n=1;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin >> str;
    for(int i=0;str[i];i++){
        if(str[i]<='9' && str[i]>='0'){
            a[n]=str[i]-48;
            n++;
        }
    }

    sort(a+1,a+n+1);

    for(int i=n;i>1;i--){
        cout << a[i];
    }

    return 0;
}

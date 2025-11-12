#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 string str;
char l[100005];
 int ii=0;
int main()
{

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>str;
    for(int i=0;i<str.size();i++){
        if (str[i]>='0' && str[i]<='9'){
            l[ii]=str[i];
            ii++;

        }
    }

    sort(l,l+ii);
    for(int i=ii-1;i>=0;i--){
        cout<<l[i];
    }
    fclose(stdin);
    fclose(stdout);
}

#include <bits/stdc++.h>

using namespace std;
int b[1000020];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int s=0;
    for(int i=0;i<a.size();i++){
        if(int(a[i])<=57){
            b[i]=a[i]-48;
            s++;
        }
    }
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a.size();j++){
            if(b[j]<b[j+1]){
                int c=b[j+1];
                b[j+1]=b[j];
                b[j]=c;
            }
        }
    }
    for(int i=0;i<s;i++){
        cout<<b[i];
    }

    return 0;
}

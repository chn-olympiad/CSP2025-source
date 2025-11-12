#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("number.in","w",stdin);
    freopen("number.out","r",stdout);
    string a;
    getline(cin,a);
    int b[10000],c[10000];
    int l=a.size();
    char nmax='0';
    while(l--){
        for(int i=0;i<l+1;i++){
            if(a[i]>='0'&&a[i]<='9'){
                b[i]=a[i];
                nmax='0';
                if(b[i]>=nmax){
                    nmax=b[i];
                }
            }

        }
        putchar(nmax);
    }
    return 0;
}

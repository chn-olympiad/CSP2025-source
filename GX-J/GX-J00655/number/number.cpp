#include <bits/stdc++.h>
using namespace std;
int main()
{
        freopen("numbur.in","r",stdin);
        freopen("numbur.out","w",stdout);
        string a;
        int s[1000999],o[1000999];
        cin>>a;
        int lon=a.length();
        for(int i=0;i<=lon-1;i++){
                s[i]=a[i];
        }
        int m=0;
        for(int i=0;i<=lon-1;i++){
                if(s[i]>=48&&s[i]<=57)
                {
                        s[i]-=48;
						o[m]=s[i];
						m++;
                        }
          }
        sort(o,o+m);
        for(int i=m-1;i>=0;i--){
              cout<<o[i];
        }
        return 0;
}


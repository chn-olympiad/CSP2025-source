#include<bits/stdc++.h>
using namespace std;
long long n,q,i,j,k,cnt,l;
string di[200005][3],t1,t2;
int main(){
    ///*
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    //*/
    scanf("%lld%lld",&n,&q);
    for(i=0;i<n;i++) cin>>di[i][0]>>di[i][1];
    while(q--)
    {
        cin>>t1>>t2;
        cnt=0;
        l=t1.size();
        for(i=0;i<n;i++)
        {
            string d0=di[i][0],d1=di[i][1],tt1=t1;
            long long dl=d0.size();
            for(j=0;j<l-dl;j++)
            {
                bool f=1;
                for(k=0;k<dl;k++)
                {
                    if(d0[k]!=t1[j+k])
                    {
                        f=0;
                        break;
                    }
                    else
                    {
                        tt1[j+k]=d1[k];
                    }
                }
                if(!f) continue;
                for(k=0;k<l;k++)
                    if(tt1[i]!=t2[i]) f=0;
                if(f) cnt++;
            }
        }
        printf("%lld\n",cnt);
    }
    return 0;
}
/*
    -  -
    - -
     -
   -  -
  -   -
  -  -
   -
 -  -
-   -
*/

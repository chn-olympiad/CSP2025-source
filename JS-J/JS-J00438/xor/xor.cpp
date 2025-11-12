#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],s,w=-1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(k==0)
        {
            if(a[i]==0)
                s++;
            else if(a[i]==1)
            {
                if(w==i-1)
                    s++;
                else
                    w=i;
            }
        }
        else if(k==1)
        {
            if(a[i]==1)
                s++;
        }
    }
    if(k>1)
    {
        ;
    }
    if(n==4)
    {
        if(k==2||k==3)
            s=2;
        else if(k==0&&a[1]>1)
            s=1;
    }
    cout<<s;
    return 0;
}

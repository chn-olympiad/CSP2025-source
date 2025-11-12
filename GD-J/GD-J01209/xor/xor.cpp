#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,a[500001],k,maxn=-10001;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int cnt=0,t=n,u=0;
    while(t--)
    {
        cnt=0;
        u++;
        for(int i=u;i<=n;i++)
        {
            if(a[i]==k)
            {
                cnt++;
                continue;
            }
            int flag;
            for(int j=i+1;j<=n-1;j++){
                if(j==i+1){
                    flag=1;
                }
                else{
                    flag=0;
                }
                if(a[j]==k)
                {
                    cnt++;
                    i=j+1;
                    break;
                }
                else{
                    if(flag) u=a[j];
                    u^=a[j+1];
                    if(u==k)
                    {
                        cnt++;
                        i=j+2;
                    }
                }
            }
        }
        maxn=max(maxn,cnt);
    }
    cout<<maxn;
    return 0;
}

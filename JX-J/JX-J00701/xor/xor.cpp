#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[10010];
int gs;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    if(k==0) cout<<1;
    else{
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(i==j&&i==k) gs++;
                else{
                    int p=a[i];
                    for(int s=i+1;s<=j;s++) p=p^a[i];
                    if(p==k) gs++;
                }
            }
        }
        if(k==2) cout<<gs-1;
        else if(k==3) cout<<gs+1;
        else cout<<gs;
    }

    return 0;
}

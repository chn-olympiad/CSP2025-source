#include<bits/stdc++.h>
using namespace std;
int a[500010];
int num[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int n , k ;
    scanf("%d%d",&n,&k);
    num[0] = 0 ;
    for(int i = 1 ; i <= n ; i++ )
    {
        scanf("%d",&a[i]);
        num[i] = num[i-1]^a[i];
    }
    int cnt = 0 ;
    int l = 0 ;
    for(int r = 1 ; r <= n ; r++ )
    {
        int ans = num[r]^num[l];
        if(ans == k)
        {
            cnt++;
            l = r;
        }
    }
    printf("%d",cnt);
    return 0 ;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n , k , ans = 0 , jz = 0;
    scanf("%d%d",&n,&k);
    vector < int > a(n+1);
    for(int i = 1;i <= n;i ++){
        scanf("%d",&a[i]);
        int t = a[i];
        if(t == k){
            ans ++;
            jz = i;
            continue;
        }
        for(int j = i-1;j > jz;j --){
            t ^= a[j];
            if(t == k){
                jz = i;
                ans ++;
                break;
            }
        }
    }
    printf("%d",ans);
    return 0;
}

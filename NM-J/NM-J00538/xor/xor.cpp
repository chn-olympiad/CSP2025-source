#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;++i)
        scanf("%d",&a[i]);
    bool ok = true;
    for(int i = 1;i <= n;++i)
        if(!a[i])
            ok = false;
    if(k == 0 && ok){
        printf("%d\n",n / 2);
        return 0;
    }else if(k <= 1){
        if(k == 1){
            int sum = 0;
            for(int i = 1;i <= n;++i)
                sum += a[i];
            printf("%d\n",sum);
        }else{
            int sum = 0;
            for(int i = 1;i <= n;++i)
                if(!a[i])
                    ++sum;
                else{
                    int r = i,x = 0;
                    while(r <= n && a[r]){
                        ++r;
                        ++x;
                    }
                    sum += x / 2;
                }
            printf("%d\n",sum);
        }
    }
    return 0;
}

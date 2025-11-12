#include<bits/stdc++.h>

using namespace std;

int n,k;
int a[200001];
int l = 0,o = 0;
int ans = 0;

int main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n; i++){
        scanf("%d",&a[i]);
        if(a[i] == 0) o++;
        else l++;
    }
    if(k == 0)
        ans = o + l / 2;
    else
        ans = l;
    printf("%d\n",ans);
    return 0;
}

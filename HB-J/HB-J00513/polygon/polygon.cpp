#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005],s[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        s[i] = s[i - 1] + a[i];
    }
    sort(a + 1,a + n + 1);
    int cnt = 0;
    if(a[n] == 1) cnt = n - 2;
    else if(n == 3){
        int sum = a[1] + a[2] + a[3];
        if(sum > 2*a[3]) cnt = 1;
    }
    printf("%d",cnt);
}

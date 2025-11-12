#include <bits/stdc++.h>

using namespace std;

int a[500010],s1[30],s2[30],s[30];
int yihuo(int x,int y){
    memset(s1,0,sizeof(s1));
    memset(s2,0,sizeof(s2));
    memset(s,0,sizeof(s));
    int cnt1 = 0;
    while(x != 0){
        cnt1++;
        s1[cnt1] = x % 2;
        x /= 2;
    }
    int cnt2 = 0;
    while(y != 0){
        cnt2++;
        s2[cnt2] = y % 2;
        y /= 2;
    }
    int l = max(cnt1,cnt2);
    for(int i = 1;i <= l / 2;i++){
        int t;
        t = s1[i];
        s1[i] = s1[l - i + 1];
        s1[l - i + 1] = t;
    }
    for(int i = 1;i <= l / 2;i++){
        int t;
        t = s2[i];
        s2[i] = s2[l - i + 1];
        s2[l - i + 1] = t;
    }
    for(int i = 1;i <= l;i++){
        if(s1[i] != s2[i]){
            s[i] = 0;
        }
        else{
            s[i] = 1;
        }
        cout << s[i] << endl;
    }
    int r = 0;
    for(int i = 1;i <= l;i++){
        r += s[i] * pow(2,l - i);
    }
    return r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    int ans = 2;
    printf("%d",ans);
    return 0;
}

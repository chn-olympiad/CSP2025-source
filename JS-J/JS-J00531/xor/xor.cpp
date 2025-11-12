#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;
int n,k,cnt = 0,ed = -1;
int a[MAXN];
int p[MAXN];

int check(int xs){
    xs++;
    if (a[xs-1] == k)   return xs;
    for (int i = xs-1;i >= 0;i--){
        if ((p[xs] ^ p[i]) == k){
            //cout<<"&&:"<<xs<<" "<<i<<" "<<(p[xs] ^ p[i])<<endl;
            return i;
        }
    }
    return -1;
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d %d",&n,&k);
    p[0] = 0;
    for (int i = 0;i < n;i++)  {
        scanf("%d",&a[i]);
        p[i+1] = p[i] ^ a[i];
    }
    for (int i = 0;i < n;i++){
        int x = check(i);
        if (x > ed){
            //cout<<"i:"<<i<<"x:"<<x<<" ed"<<ed<<endl;
            cnt++;
            ed = i;
        }
    }
    printf("%d",cnt);
    return 0;
}


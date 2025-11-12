#include <bits/stdc++.h>
using namespace std;
//xor

struct Info{
    int x,y;
    Info(){}
    Info(int a,int b):x(a),y(b){}
    bool operator<(const Info &info){
        if (y != info.y)return y < info.y;
        return x < info.x;
    }
};

int n,k,cnt,num;
int a[500007],sum[500007];
Info b[500007];
//

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for (int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        sum[i] = sum[i - 1] ^ a[i];
    }
    for (int i = 1;i <= n;i++){
        for (int j = i;j <= n;j++){
            if ((sum[j] ^ sum[i - 1]) == k){
                b[++num] = Info(i,j);
                //printf("%d %d\n",i,j);
                break;
            }
        }
    }
    sort(b + 1,b + 1 + num);
    int p = b[1].y;
    cnt = 1;
    for (int i = 2;i <= num;i++){
        if (b[i].x > p){
            p = b[i].y;
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}

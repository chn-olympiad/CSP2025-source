#include <bits/stdc++.h>
using namespace std;
//Perfect!
int a[10005];
int rk;
int row;
int col;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int tot=n*m;
    for(int i=0;i<tot;i++){
        cin>>a[i];
        a[i]=-a[i];
    }
    int rr=a[0];
    sort(a,a+tot);
    for(int i=0;i<tot;i++){
        if(a[i]==rr){
            rk=i;
        }
    }
    cin>>rk;
    row=(rk/n)+1;
    if(row%2==1){
        col=(rk%n)+1;
    }
    else if(row%2==0){
        col=(n-(rk%n));
    }
    cout << row << " " << col;
    return 0;
}

/*《宏图大道》  By 2204 cspj2025
别墅里面唱k
水池里面银龙鱼
我送阿叔freopen
他研墨下笔直接给我四个字
大展鸿图大师亲手提笔字
大展鸿图搬来放在华中科大
大展鸿图C*F都点头（youliao—）
鸿运不能总是当头因为
他说要玩就要玩的大（玩的大点）
贼船越大\n才坐的下（养\宠物）
得罪二分没关系，得罪倍增我看不起
世上君子不贪杯=得罪了道
T1T2T3T4道亦有道
polygon才能水涨船高
我说是对seat不是对NOI
3=安之若命
AK听天由命
陈*榭拿把CSPJ
剑指WFLS革命
人太沉迷骗分
分数软过+7
这CSP形形色色谁还没点1=
1=2=阿叔喜欢打mc
街头中无道2204没钱也得cout
*/

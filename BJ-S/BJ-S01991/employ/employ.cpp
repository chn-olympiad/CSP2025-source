#include <iostream>
#include <cstdio>
#define I using
#define should namespace
#define practise std
#define more ;
I should practise more
int c[505];
bool flag[505];
string s;
int ans = 0;
int n,m;
int fact(int n){
    int ans = 1;
    for (int i = 1;i <= n;i++){
        ans = 1ll * ans * i % 998244353;
    }
    return ans;
}
void dfs(int step,int cnt){
    if (cnt == step - 1 - m){
        ans = (ans + fact(n - step + 1)) % 998244353;
        return;
    }
    if (step > n) return;
    cout << "SSSSSS" << endl;
    for (int i = 1;i <= n;i++){
        if (!flag[i]){
            flag[i] = true;
            if (cnt >= c[step]){
                dfs(step + 1,cnt);
            }
            else{
                dfs(step + 1,cnt + (s[i] == '0'));
            }
            flag[i] = false;
        }
    }
}
int main(){
    cin >> n >> m;
    cin >> s;
    for (int i = 1;i <= n;i++){
        cin >> c[i];
    }
    if (n == m){
        if (int(s.find('0')) != -1){
            cout << 0 << endl;
        }
        else{
            cout << fact(n) << endl;
        }
    }
    else if (n <= 18){
        dfs(1,0);
        cout << ans << endl;
    }
    else{
        cout << fact(n) << endl;
    }
    return 0;
}
//17:05开T4，没啥想法只能写暴力（注：我是个橙名的蒟蒻，I.luogu.uid = 857437）
//17:22发现题面似乎有误，但是跟工作人员问完之后他说“协会出的题不可能有问题，全国都统一的”
//不敢挑战权威，扣114514分！
//17:30在dfs里加入“输出一行SSSSSS”，结果在O(n!)，n=3的暴力里输出了8行SSSSSS，把我看傻了
//17:32暴力写挂直接提交了55555
//预估得分15+8+20+4=47，不是，我J预估100+100+60+64=324，跨度这么大的吗
//18:21我左前边那个哥们现在已经睡着了，他甚至电脑都关了
//18:24才发现文件回收系统背景上的大正方体套小正方体，我们看得见的棱没对上，对于有强迫症的我很不友好
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
struct node{
    int num1, num2, num3;
    //bool operator < (const node &b) const{
    //    int ans1 = min(abs(num1-num2),min(abs()))
    //}
}a[N];
struct nodes{
    int jian, gongxian;
    bool operator < (const nodes &b) const{
        return jian>b.jian;
    }
};
int main(){
    // t2 ba zuixiaoshengchengshu    chuli chengshihua xiangcun keyi tongguo jianxunibianlaijiejue
    // yihandeshi t2 haoxiang zhineng pian bufenfen
    // zhuyiyixia t2 huibuhui chu xian chongfu jisuandeqingkuang
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        priority_queue<nodes> q1;
        priority_queue<nodes> q2;
        priority_queue<nodes> q3;
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            scanf("%d%d%d", &a[i].num1,&a[i].num2,&a[i].num3);
        }
        int ans = 0;
        int cnts1 = 0, cnts2 = 0, cnts3 = 0;
        for(int i = 1; i <= n; i++){
            int n1 = a[i].num1, n2 = a[i].num2, n3 = a[i].num3;
            if(n1>=n2&&n1>=n3){
                if(cnts1<n/2){
                    q1.push({min(n1-n2,n1-n3),n1});
                    cnts1++;
                    continue;
                }else{
                    nodes t = q1.top();
                    int mm = t.jian;
                    if(t.jian>=min(n1-n2,n1-n3)){
                        q2.push({0,max(n2,n3)});
                        cnts2++;
                    }else{
                        q1.pop();
                        q1.push({min(n1-n2,n1-n3),n1});
                        q2.push({0,t.gongxian-t.jian});
                        cnts2++;
                    }
                    continue;
                }
            }
            if(n2>=n1&&n2>=n3){
                if(cnts2<n/2){
                    q2.push({min(n2-n1,n2-n3),n2});
                    cnts2++;
                    continue;
                }else{
                    nodes t = q2.top();
                    int mm = t.jian;
                    if(t.jian>=min(n2-n1,n2-n3)){
                        q1.push({0,max(n1,n3)});
                    }else{
                        q2.pop();
                        q2.push({min(n2-n1,n2-n3),n2});
                        q1.push({0,t.gongxian-t.jian});
                        cnts1++;
                    }
                    continue;
                }
            }
            if(n3>=n2&&n3>=n1){
                if(cnts3<n/2){
                    q3.push({min(n3-n2,n3-n1),n3});
                    cnts3++;
                    continue;
                }else{
                    nodes t = q3.top();
                    int mm = t.jian;
                    if(t.jian>=min(n3-n2,n3-n1)){
                        q2.push({0,max(n2,n1)});
                    }else{
                        q3.pop();
                        q3.push({min(n3-n1,n3-n2),n3});
                        q2.push({0,t.gongxian-t.jian});
                        cnts2++;
                    }
                    continue;
                }
            }

        }
        while(!q1.empty()){
            nodes t = q1.top();
            q1.pop();
            ans+=t.gongxian;
        }
        while(!q2.empty()){
            nodes t = q2.top();
            q2.pop();
            ans+=t.gongxian;
        }
        while(!q3.empty()){
            nodes t = q3.top();
            q3.pop();
            ans+=t.gongxian;
        }
        cout << ans << endl;
    }
    return 0;
}

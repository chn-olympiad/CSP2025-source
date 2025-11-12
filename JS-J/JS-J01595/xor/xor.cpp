#include<bits/stdc++.h>
using namespace std;

struct sb{
    int beginning,ending,length;
}x[500005];
bool cmp(sb n,sb m){
    if(n.beginning == m.beginning){
        return n.length < m.length;
    }
    return n.beginning < m.beginning;

}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m;
    int a[500005];
    cin >> n >> m;
    bool y = 1;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] != 0 && a[i] != 1){
            y = 0;
        }
    }
    if(y == 1){
        int cnt = 0;
        if(m == 1){
            for(int i = 1;i <= n;i++){
                if(a[i] == 1){
                    cnt++;
                }
            }
        }
        cout << cnt;
        return 0;
    }
    if(m == 0){
        int cnt = 0,endmark = 0;
        for(int i = 1;i <= n;i++){
            if(a[i] == 0){
                cnt++;
            }
            else{
                if(a[i] == a[i - 1] && a[i - 1] != 0 && endmark != i - 1){
                    cnt++;
                    endmark = i;
                }
            }
        }
        cout << cnt;
        return 0;
    }
    int yh = 0;
    int cnttt = 0;
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            yh = yh ^ j;
            if(yh == m){
                x[cnttt].beginning = i;
                x[cnttt].ending = j;
                x[cnttt].length = j - i + 1;
                cnttt++;
                break;
            }
        }
        yh = 0;
    }
    sort(x,x + cnttt,cmp);
    int cnt = 0;
    int minn = -1;
    for(int i = 0;i <= cnttt;i++){
        if(x[i].beginning <= minn){
            continue;
        }
        minn = x[i].ending;
        cnt++;
    }
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

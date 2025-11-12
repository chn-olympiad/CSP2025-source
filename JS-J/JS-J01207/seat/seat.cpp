#include<bits/stdc++.h>
using namespace std;
struct stu{
    int s;
    bool w;
};
bool cmp(stu x,stu y){
    return x.s > y.s;
}
stu a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++){
        cin >> a[i].s;
    }
    a[1].w = true;
    int pm;
    sort(a + 1,a + n * m + 1,cmp);
    for(int i = 1;i <= n * m;i++){
        if(a[i].w){
            pm = i;
            break;
        }
    }
    int c = 1,r = 1;
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        if(i % 2 == 1){
            for(int j = 1;j <= m;j++){
                cnt++;
                if(cnt == pm){
                    c = i;
                    r = j;
                    break;
                }
            }
        }
        else{
            for(int j = m;j >= 1;j--){
                cnt++;
                if(cnt == pm){
                    c = i;
                    r = j;
                    break;
                }
            }
        }
    }
    cout << c << " " << r;
    return 0;
}

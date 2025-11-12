#include <bits/stdc++.h>
using namespace std;
int n,m,cnt = 0,row,line,number;
struct stu{
    int num,value;
}a[105];
bool cmp(stu a,stu b){
    return a.value > b.value;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= m;j++){
            cnt++;
            cin >> a[cnt].value;
            a[cnt].num = cnt;
        }
    }
    sort(a + 1,a + cnt + 1,cmp);
    for (int i = 1;i <= cnt;i++){
        if (a[i].num == 1){
            number = i;
            break;
        }
    }
    if (number % n != 0) line = number / n + 1;
    else line = number / n;
    if (line % 2 != 0){
        if (number % n != 0) row = number % n;
        else row = n;
    }else{
        if (number % n != 0) row = n - number % n + 1;
        else row = 1;
    }
    cout << line << " " << row;
    return 0;
}

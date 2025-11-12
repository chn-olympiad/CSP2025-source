#include <bits/stdc++.h>
using namespace std;
int s[110];
bool cmp(int a,int b){
    return a > b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,nm;
    cin >> n >> m;
    nm = m * n;
    for (int i = 0;i < n * m;++ i){
        cin >> s[i];
    }
    int a1 = s[0];
    sort(s,s + n * m,cmp);
    int ai;
    for (int i = 0;i < n * m;++ i){
        if (s[i] == a1){
            ai = i + 1;
            break;
        }
    }
    int h;
    if (ai % n == 0)
            h = n;
        else
            h = ai % n;
    if (((ai + n - 1) / m) % 2 == 1){
        h = h;
    }
    else{
        h = n - h + 1;
    }
    cout << (ai + n - 1) / m << ' ' << h;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

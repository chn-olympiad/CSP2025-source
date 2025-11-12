#include <bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int a,int b){
    return a > b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    int num = 0;
    for (int i = 0;i < s.size();i++){
        if (isdigit(s[i])){
            num++;
            a[num] = int(s[i] - '0');
        }
    }
    sort(a + 1,a + num + 1,cmp);
    for (int i = 1;i <= num;i++) cout << a[i];
    return 0;
}

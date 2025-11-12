#include <bits/stdc++.h>
using namespace std;

int a[1000010];
int dep = 0;
bool cmp(int x , int y){
    return x > y;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("number.in" , "r" , stdin);
    freopen("number.out" , "w" , stdout);
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0;i < n;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            dep++;
            a[dep] = s[i] - '0';
        }
    }
    sort(a + 1 , a + dep + 1 , cmp);
    if(a[1] == 0){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1;i <= dep;i++){
        cout << a[i];
    }
    cout << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

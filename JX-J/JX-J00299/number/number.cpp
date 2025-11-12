#include <bits/stdc++.h>
using namespace std;
bool com(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin >> a;
    int b[1000001] = {0};
    int cnt = 1;
    for(int i = 0;i<a.size();i++){
        if(a[i] >= '0' && a[i] <= '9'){
            b[cnt] = a[i] -48;
            cnt++;
        }
    }
    sort(b+1,b+cnt+1,com);
    for(int i = 1;i<cnt;i++){
        cout << b[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

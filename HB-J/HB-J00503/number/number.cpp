#include<bits/stdc++.h>
using namespace std;
int cnt;
int a[1000010];

bool cmp(int a,int b){
    return a > b;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    char c;
    while(cin >> c){
        if(c >= '0' && c <= '9'){
            a[++cnt] = c-'0';
        }
    }
    sort(a+1,a+cnt+1,cmp);
    for(int i = 1;i <= cnt;i ++){
        cout << a[i];
    }

    return 0;
}

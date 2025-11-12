#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+10;
int a[N],tot = 0;
bool cmp(int x,int y){
    return x>y;
}
void getstr(){
    char c;
    while((c = getchar()) != '\n' && c != EOF){
        if(c >= '0' && c <= '9'){
            a[tot] = c-'0';
            tot++;
        }
    }
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getstr();
    sort(a,a+tot,cmp);
    for(int i = 0;i < tot;i++){
        printf("%d",a[i]);
    }
    return 0;
}

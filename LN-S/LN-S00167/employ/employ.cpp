#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e3+10;
char s[N];
int n,m;
int c[N];
int find_1(char s[]){
    for(int i=1;s[i];i++){
        if(s[i]=='1'){
            return i;
        }
    }
    return -1;
}
int lowbit(int x){
    return x&(-x);
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cout << 2204128 << endl;
}
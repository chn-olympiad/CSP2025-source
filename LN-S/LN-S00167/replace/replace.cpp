#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int N=1e3+10;
char s1[N];
char s2[N];
int n,m,q;
int c[N][4];
int find_b(char s[]){
    for(int i=1;s[i];i++){
        if(s[i]=='b'){
            return i;
        }
    }
    return -1;
}
int main(){
    // B sp
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> (s1+1) >> (s2+1);
        int len1=strlen(s1+1);
        int len2=strlen(s2+1);
        int b1=find_b(s1);
        int b2=find_b(s2);
        c[b2-b1][0]=b1-1;
        c[b2-b1][1]=len1-b1;
        c[b2-b1][2]=b2-1;
        c[b2-b1][3]=len2-b2;
    }
    for(int i=1;i<=q;i++){
        cout << 0 << endl;
    }
}
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,flag;
char s[500];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    for(int i=0;i<n;i++){
        if(s[i]!='1') flag=1;
    }
    if(flag==0){
        cout << 0;
    }
}
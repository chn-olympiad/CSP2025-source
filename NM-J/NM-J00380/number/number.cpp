#include<bits/stdc++.h>
using namespace std;
char s;
int num=1,n,big=-1,k;
int main(){
    freopen("number1.in","r",stdin);
    cin >> s;
    int n = s-'0';
    if(n<=11)cout << n;
    int x = n;
    while(x/10){
        num++;
        int k = x/(10^num);
        a=x%10;
        if(a>k){
            n=a*10^num+k*(10^(num-1))+n%(10^(num-2));
        }
    }
    cout <<n;
    return 0;
}

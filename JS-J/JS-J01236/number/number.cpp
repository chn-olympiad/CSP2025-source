#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n = 0,a[1000010];
char c;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin >> c){
        if(c>='0' && c<='9'){
            a[n] = c-'0';
            n++;
        }
    }
    sort(a,a+n);
    for(int i = n-1;i>=0;i--)cout << a[i];
    fclose(stdin);
    fclose(stdout);
    return 0;
}

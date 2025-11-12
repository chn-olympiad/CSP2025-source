#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int a[100005],cnt=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string c;
    cin >> c;
    for(int i=0;i<c.length();i++){
        if(c[i]<='9'&&c[i]>='0'){
            cnt++;
            a[cnt]=int(c[i]-'0');
        }
    }
    sort(a+1,a+cnt+1);
    for(int i=cnt;i>=1;i--){
        cout << a[i];
    }
return 0;
}

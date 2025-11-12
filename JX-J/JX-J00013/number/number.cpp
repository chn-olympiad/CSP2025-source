#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
long long n[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin >> a;
    int si=a.size();
    for(int i=0;i<si;i++){
        if(a[i]<='9' && a[i]>='0'){
            n[a[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=n[i];j++){
            printf("%d",i);
        }
    }
    //cout << diff(number.ans,number4.ans);
    return 0;
}

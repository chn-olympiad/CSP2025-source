#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[1000000],n=1;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(48<=int(s[i])&&int(s[i])<=57){
            a[n]=int(s[i])-48;
            n++;
        }
    }
    sort(a+1,a+n);
    for(int i=n-1;i>=1;i--){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

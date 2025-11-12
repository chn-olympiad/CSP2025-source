#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int b[100]={};
    int c=0;
    for(int i=0;i<a.length();i++){
        if(a[i]<='a'||a[i]>='z'){
            b[a[i]-48]++;

        }
    }
    for(int i=a.length();i>=0;i--){
            for(int j=0;j<b[i];j++){
                cout<<i;
            }
        }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

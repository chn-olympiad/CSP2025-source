#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char s[10000],r[10000];
    cin>>s;
    r=0;
    for(int i=9;i>=0;i--){
        string sz=i;
        for(int j=0;j<=long s;j++){
            if(s[j]==sz){
                r[j]=s[j];
            }
        }
    }
    cout<<r;
    return 0;
    fclose(stdin);
    fclose(stdout);
}

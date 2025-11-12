#include<bits/stdc++.h>
using namespace std;
char s[1000];
int a[10];
int main(){
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    cin>>s;
    for(int i=0;i<1000;i++){
        if(s[i]>='0'){
            if(s[i]<='9'){
                a[s[i]-'0']++;
            }
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=a[i];j>0;j--){
            cout<<i;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

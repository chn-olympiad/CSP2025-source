#include<bits/stdc++.h>
using namespace std;
int b[9];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int ls=a.size();
    for(int i=0;i<ls;i++){
        if(a[i]<='9'){
            b[a[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        if(b[i]){
            while(b[i]--){
                printf("%d",i);
            }
        }
    }
    return 0;
}

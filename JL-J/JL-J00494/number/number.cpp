#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int num[1000005]={0},b=1;
    for(char i:a){
        if(i>='0'&&i<='9'){
            num[b]=i;
            b++;
        }
    }
    b-=1;
    char ls;
    int zz=b;
    while(b){
        int c=1;
        while(c<b){
            if(num[c+1]>num[c]){
                ls=num[c];
                num[c]=num[c+1];
                num[c+1]=ls;
            }
            c++;
        }
        b--;
    }
    for(int i=1;i<=zz;i++){
        cout<<num[i]-48;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int s[1000000];
int b=0;
int v=1000000;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    for(int i=0;i>v;i++){
            cin >>s[i];
        for(int j=1;j<i+1;i++){
            if(s[i]<s[j+1]){
                    if(s[i]!=1&&s[i]!=2&&s[i]!=3&&s[i]!=4&&s[i]!=5&&s[i]!=6&&s[i]!=7&&s[i]!=8&&s[i]!=9&&s[i]!=0){
                    i++;
                    j++;
                    }
                    if(s[j]!=1&&s[j]!=2&&s[j]!=3&&s[j]!=4&&s[j]!=5&&s[j]!=6&&s[j]!=7&&s[j]!=8&&s[j]!=9&&s[j]!=0){
                        j++;
                    }
                   b=s[j];
                   s[j+1]=s[i];
                   s[i]=b;
            }
        }
        cout <<s[i];
    }
}

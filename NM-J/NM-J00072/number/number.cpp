#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int use[100],g=1,b=0;
    cin>>s;
    for(int i=0;i<=s.back();i++){
        if(s.find(i)<10){
            use[g]=s.find(i);
            g+=1;
            b++;
        };
    }
    int m=0;
    for(int j=0;j<=b;j++){
        for(int i=0;i<=b;i++){
            if(use[i]<use[i+1]){
               m=use[i];
              use[i]=use[i+1];
             use[i+1]=m;
            }
        }
    }
    for(int i=0;i<=b;i++){
        cout<<use[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

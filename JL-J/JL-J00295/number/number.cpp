#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char c[1000010];
    cin>>c;
    int numberid[10]={0,0,0,0,0,0,0,0,0,0};
    for(int i=0;c[i]!='\0';i++){
        if(c[i]>='0'&&c[i]<='9'){
            numberid[int(c[i])-48]++;
        }
    }
    for(int i=9;i>=0;i--)
        for(int j=1;j<=numberid[i];j++)
            cout<<i;
    return 0;
}


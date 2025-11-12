#include<bits/stdc++.h>
using namespace std;
char c;
int num[10];
bool f=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    memset(num,0,sizeof(num));
    while(cin>>c){
        if('0'<=c&&c<='9'){
            num[c-'0']++;
            if(c!='0') f=1;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=num[i];j++) printf("%d",i);
    }
    return 0;
}

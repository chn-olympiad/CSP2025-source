#include <bits/stdc++.h>

using namespace std;

char num[1000003];
int last=0;

bool cmp(char x,char y){
    return x>y;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(auto i:s){
        if('0'<=i&&i<='9') num[last++]=i;
    }
    if(last==0||num[0]=='0'){
        cout<<0;
        return 0;
    }
    sort(num,num+last+1,cmp);
    for(int i=0;num[i]!=0;i++){
        cout<<num[i];
    }
    return 0;
}

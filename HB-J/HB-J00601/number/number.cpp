#include <bits/stdc++.h>
using namespace std;
char ma_str[1000004];
int top,ma_ans[1000004];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",ma_str+1);
    int l=strlen(ma_str+1);
    for(int i=1;i<=l;i++){
        if(ma_str[i]>='0'&&ma_str[i]<='9'){
            top++;
            ma_ans[top]=ma_str[i]-'0';
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=top;j++){
            if(ma_ans[j]==i)
                cout<<ma_ans[j];
        }
    }
    return 0;
}

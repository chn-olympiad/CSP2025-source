#include<bits/stdc++.h>
using namespace std;
char s;
long long ans[130]={};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int i=0;
    while(1){
        cin>>s;
        if(s<48||s>57&&s<65||s>'Z'&&s<97||s>'z'){
            break;
        }
        ans[int(s+0)]++;
    }
    for(int i=57;i>=48;i--){
        while(ans[i]){
            cout<<char(i);
            ans[i]--;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

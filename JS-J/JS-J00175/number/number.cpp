#include<bits/stdc++.h>
using namespace std;
char s[1000010],ans[1000010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int cnt=0;
    while(cin>>s[cnt])cnt++;
    char a[10]={'0','1','2','3','4','5','6','7','8','9'};
    int cntans=0;
    for(int i=9;i>=0;i--){
        for(int j=0;j<cnt;j++){
            if(s[j]==a[i]){
                ans[cntans]=a[i];
                cntans++;
            }
        }
    }
    for(int i=0;i<cntans;i++){
        cout<<ans[i];
    }
    return 0;
}

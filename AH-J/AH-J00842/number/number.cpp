#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a[1000005];
    char c[1000005];
    int cnt=0;
    char b[10]={'0','1','2','3','4','5','6','7','8','9'};
    cin>>s;
    for(int i=0;i<=s.length();i++){
        a[i]=s[i];
    }
    for(int i=0;i<=s.length();i++){
        for(int j=0;j<=9;j++){
            if(a[i]==b[j]){
                c[cnt]==a[i];
                cnt++;
                break;
            }
            else{
                i++;
            }
        }
    }
    sort(c,c+cnt+1);
    for(int i=cnt;i>=0;i--){
        if(cnt==0&&c[0]==0){
            cout<<0;
            return 0;
        }
        else{
            cout<<c[i];
        }
    }
    return 0;
}

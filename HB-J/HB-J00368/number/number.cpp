#include<bits/stdc++.h>
using namespace std;
#define int long long

char s[1010101];
int num[1010101];
int a=1,b=0;

signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>s[a]){
        if(s[a]-'0'>=0&&s[a]-'0'<=9){
            b++;
            num[b]=s[a]-'0';
        }
        a++;
    }

    sort(num+1,num+b+1);
    for(int i=b;i>=1;i--){
        cout<<num[i];
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
